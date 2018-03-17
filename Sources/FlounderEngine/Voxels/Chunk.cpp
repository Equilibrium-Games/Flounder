#include "Chunk.hpp"

#include "../Scenes/Scenes.hpp"
#include "../Worlds/Worlds.hpp"

namespace Flounder
{
	const int Chunk::CHUNK_WIDTH = 32;
	const int Chunk::CHUNK_HEIGHT = 32;
	const float Chunk::VOXEL_SIZE = 1.0f;
	const Vector3 *Chunk::CHUNK_SIZE = new Vector3(VOXEL_SIZE * CHUNK_WIDTH, VOXEL_SIZE * CHUNK_HEIGHT, VOXEL_SIZE * CHUNK_WIDTH);

	Chunk::Chunk(const ChunkMesh &chunkMesh, const bool &generate) :
		Component(),
		m_chunkMesh(chunkMesh),
		m_blocks(new BlockVector()),
		m_surrounding(new std::vector<Chunk *>()),
		m_generate(generate),
		m_rebuild(true)
	{
		for (unsigned int x = 0; x < CHUNK_WIDTH; x++)
		{
			m_blocks->push_back(std::vector<std::vector<Block*>>(CHUNK_WIDTH));

			for (unsigned int z = 0; z < CHUNK_WIDTH; z++)
			{
				m_blocks->at(x).push_back(std::vector<Block*>(CHUNK_WIDTH));

				for (unsigned int y = 0; y < CHUNK_HEIGHT; y++)
				{
					m_blocks->at(x).at(z).push_back(new Block(this, VOXEL_SIZE * Vector3(x, y, z), 0));
				}
			}
		}
	}

	Chunk::~Chunk()
	{
		for (auto x : *m_blocks)
		{
			for (auto z : x)
			{
				for (auto y : z)
				{
					delete y;
				}
			}
		}

		delete m_blocks;
		delete m_surrounding;
	}

	void Chunk::Update()
	{
		if (m_generate)
		{
			Generate();
			m_generate = false;
		}

		if (m_rebuild)
		{
			m_surrounding->clear();

			std::vector<Chunk *> chunkList = std::vector<Chunk *>();
			Scenes::Get()->GetStructure()->QueryComponents<Chunk>(&chunkList);

			Vector3 thisCoord = *GetGameObject()->GetTransform()->GetPosition() / *CHUNK_SIZE;

			for (auto other : chunkList)
			{
				if (other == this)
				{
					continue;
				}

				Vector3 otherCoord = *other->GetGameObject()->GetTransform()->GetPosition() / *CHUNK_SIZE;
				Vector3 distance = (thisCoord - otherCoord) / 2.0f;

			//	printf("(%i, %i, %i)\n", (int)thisPosition.m_x, (int)thisPosition.m_y, (int)thisPosition.m_z);

				if (std::fabs(distance.m_x) == 1.0f || std::fabs(distance.m_z) == 1.0f)
				{
					m_surrounding->push_back(other);
				}
			}

			GenerateMesh();
			m_rebuild = false;
		}

		// TODO: Wrap chunk positions around planet to follow camera.
	}

	void Chunk::Load(LoadedValue *value)
	{
		// TODO: Not from game object but from saved values.
	}

	void Chunk::Write(LoadedValue *value)
	{
		// TODO: Not to game object but to saves.
	}

	Block *Chunk::GetBlock(const int &x, const int &y, const int &z, const bool &onlyThis)
	{
		if (x >= 0 && x < CHUNK_WIDTH && z >= 0 && z < CHUNK_WIDTH && y >= 0 && y < CHUNK_HEIGHT)
		{
			return m_blocks->at(x).at(z).at(y);
		}

		/*if (!onlyThis)
		{
			Vector3 thisPosition = *GetGameObject()->GetTransform()->GetPosition() / 2.0f;
			int x1 = x + (int)thisPosition.m_x;
			int y1 = y + (int)thisPosition.m_y;
			int z1 = z + (int)thisPosition.m_z;
	//		printf("(%i, %i, %i)\n", (int)thisPosition.m_x, (int)thisPosition.m_y, (int)thisPosition.m_z);

			for (auto other : *m_surrounding)
			{
				Vector3 otherPosition = *other->GetGameObject()->GetTransform()->GetPosition() / 2.0f;
				Block *otherBlock = other->GetBlock(x1 - (int)otherPosition.m_x, y1 - (int)otherPosition.m_y, z1 - (int)otherPosition.m_z, true);

				if (otherBlock != nullptr)
				{
					return otherBlock;
				}
			}
		}*/

		return nullptr;
	}

	bool Chunk::IsBlockFilled(const int &x, const int &y, const int &z, const bool &onlyThis)
	{
		Block *block = GetBlock(x, y, z, onlyThis);
		return block == nullptr || block->GetType() != 0;
	}

	bool Chunk::IsFaceVisible(const int &x, const int &y, const int &z, const FaceSide &faceType, const bool &onlyThis)
	{
		switch (faceType)
		{
		case FaceFront:
			return IsBlockFilled(x, y, z - 1, onlyThis);
		case FaceBack:
			return IsBlockFilled(x, y, z + 1, onlyThis);
		case FaceTop:
			return IsBlockFilled(x, y + 1, z, onlyThis);
		case FaceBottom:
			return IsBlockFilled(x, y - 1, z, onlyThis);
		case FaceLeft:
			return IsBlockFilled(x - 1, y, z, onlyThis);
		case FaceRight:
			return IsBlockFilled(x + 1, y, z, onlyThis);
		default:
			return false;
		}
	}

	void Chunk::Generate()
	{
		auto position = *GetGameObject()->GetTransform()->GetPosition() / 2.0f;
		auto noise = Worlds::Get()->GetNoise();

		for (unsigned int x = 0; x < CHUNK_WIDTH; x++)
		{
			for (unsigned int z = 0; z < CHUNK_WIDTH; z++)
			{
				for (unsigned int y = 0; y < CHUNK_HEIGHT; y++)
				{
					if (noise->GetValue(x + position.m_x, y + position.m_y, z + position.m_z) >= 0.03f)
					{
						m_blocks->at(x).at(z).at(y)->SetType(1);
					}
				}
			}
		}
	}

	void Chunk::GenerateMesh()
	{
#if FLOUNDER_VERBOSE
		const auto debugStart = Engine::Get()->GetTimeMs();
#endif

		auto mesh = GetGameObject()->GetComponent<Mesh>();

		if (mesh == nullptr)
		{
			return;
		}

		std::vector<Vertex> vertices = {};
		std::vector<uint32_t> indices = {};

		switch (m_chunkMesh)
		{
		case MeshGreedy:
			CreateGreedyMesh(&vertices, &indices);
			break;
		case MeshSimple:
			CreateSimpleMesh(&vertices, &indices);
			break;
		}

		delete mesh->GetModel();

		if (!vertices.empty() || !indices.empty())
		{
			Model *model = new Model(vertices, indices, GetName());
			mesh->SetModel(model);
		}

#if FLOUNDER_VERBOSE
		const auto debugEnd = Engine::Get()->GetTimeMs();

		if (debugEnd - debugStart > 22.0f)
		{
			printf("Chunk %s built in %fms\n", GetName().c_str(), debugEnd - debugStart);
		}
#endif
	}

	void Chunk::CreateSimpleMesh(std::vector<Vertex> *vertices, std::vector<uint32_t> *indices)
	{
		int u, v;
		FaceSide currentFace;

		std::vector<int> du = std::vector<int>{0, 0, 0};
		std::vector<int> dv = std::vector<int>{0, 0, 0};

		// We start with the lesser-spotted boolean for-loop (also known as the old flippy floppy).
		for (bool backFace = true, b = false; b != backFace; backFace = backFace && b, b = !b)
		{
			// We sweep over the 3 dimensions - most of what follows is well described by Mikola Lysenko in his post.
			for (int d = 0; d < 3; d++)
			{
				u = (d + 1) % 3;
				v = (d + 2) % 3;

				// Here we're keeping track of the side that we're meshing.
				if (d == 0)
				{
					currentFace = backFace ? FaceLeft : FaceRight;
				}
				else if (d == 1)
				{
					currentFace = backFace ? FaceBottom : FaceTop;
				}
				else if (d == 2)
				{
					currentFace = backFace ? FaceFront : FaceBack;
				}

				// We move through all of the blocks in the chunk.
				for (int x = 0; x < CHUNK_WIDTH; x++)
				{
					for (int z = 0; z < CHUNK_WIDTH; z++)
					{
						for (int y = 0; y < CHUNK_HEIGHT; y++)
						{
							// Here we filter out invisible faces.
							if (!IsFaceVisible(x, y, z, currentFace))
							{
								continue;
							}

							Block *block = GetBlock(x, y, z);

							if (block == nullptr || block->GetType() != 0)
							{
								continue;
							}

							du[0] = 0;
							du[1] = 0;
							du[2] = 0;
							du[u] = 1;

							dv[0] = 0;
							dv[1] = 0;
							dv[2] = 0;
							dv[v] = 1;

							// And here we call the quad function in order to render a merged quad in the scene.
							Vector3 bottomLeft = Vector3(x, y, z);
							Vector3 topLeft = Vector3(x + dv[0], y + dv[1], z + dv[2]);
							Vector3 topRight = Vector3(x + du[0] + dv[0], y + du[1] + dv[1], z + du[2] + dv[2]);
							Vector3 bottomRight = Vector3(x + du[0], y + du[1], z + du[2]);
							GenerateQuad(vertices, indices, bottomLeft, topLeft, topRight, bottomRight, 1, 1, block->GetType(), currentFace, backFace);
						}
					}
				}
			}
		}
	}

	void Chunk::CreateGreedyMesh(std::vector<Vertex> *vertices, std::vector<uint32_t> *indices)
	{
		// This method is based off of Robert O'Leary's implementation (https://github.com/roboleary/GreedyMesh)

        // These are just working variables for the algorithm - almost all taken
		// directly from Mikola Lysenko's javascript implementation.
		int i, j, k, l, w, h, u, v, n;
		FaceSide currentFace;

		std::vector<int> x = std::vector<int>{0, 0, 0};
		std::vector<int> q = std::vector<int>{0, 0, 0};
		std::vector<int> du = std::vector<int>{0, 0, 0};
		std::vector<int> dv = std::vector<int>{0, 0, 0};

		// We create a mask - this will contain the groups of matching voxel faces
		// as we proceed through the chunk in 6 directions - once for each face.
		std::vector<short> mask = std::vector<short>(CHUNK_WIDTH * CHUNK_HEIGHT);

 		// These are just working variables to hold two faces during comparison.
		short voxelFace, voxelFace1;

		// We start with the lesser-spotted boolean for-loop (also known as the old flippy floppy).
		// The variable backFace will be TRUE on the first iteration and FALSE on the second - this allows
		// us to track which direction the indices should run during creation of the quad.
		// This loop runs twice, and the inner loop 3 times - totally 6 iterations - one for each voxel face.
		for (bool backFace = true, b = false; b != backFace; backFace = backFace && b, b = !b)
		{
			// We sweep over the 3 dimensions - most of what follows is well described by Mikola Lysenko in his post.
			for (int d = 0; d < 3; d++)
			{
				u = (d + 1) % 3;
				v = (d + 2) % 3;

				x[0] = 0;
				x[1] = 0;
				x[2] = 0;

				q[0] = 0;
				q[1] = 0;
				q[2] = 0;
				q[d] = 1;

				// Here we're keeping track of the side that we're meshing.
				if (d == 0)
				{
					currentFace = backFace ? FaceLeft : FaceRight;
				}
				else if (d == 1)
				{
					currentFace = backFace ? FaceBottom : FaceTop;
				}
				else if (d == 2)
				{
					currentFace = backFace ? FaceFront : FaceBack;
				}

				// We move through the dimension from front to back.
				for (x[d] = -1; x[d] < CHUNK_WIDTH;)
				{
					// We compute the mask.
					n = 0;

					for (x[v] = 0; x[v] < CHUNK_HEIGHT; x[v]++)
					{
						for (x[u] = 0; x[u] < CHUNK_WIDTH; x[u]++)
						{
							// Here we retrieve two voxel faces for comparison.
						//	voxelFace = (x[d] >= 0 ) ? GetVoxelFace(x[0], x[1], x[2], currentFace) : (short)0;
						//	voxelFace1 = (x[d] < CHUNK_WIDTH - 1) ? GetVoxelFace(x[0] + q[0], x[1] + q[1], x[2] + q[2], currentFace) : (short)0;
							voxelFace = GetVoxelFace(x[0], x[1], x[2], currentFace);
							voxelFace1 = GetVoxelFace(x[0] + q[0], x[1] + q[1], x[2] + q[2], currentFace);

							// We choose the face to add to the mask depending on whether we're moving through on a backface or not.
							mask[n++] = ((voxelFace != 0 && voxelFace1 != 0 && voxelFace == voxelFace1))
								? (short)0
								: backFace ? voxelFace1 : voxelFace;
						}
					}

					x[d]++;

					// Now we generate the mesh for the mask.
					n = 0;

					for (j = 0; j < CHUNK_HEIGHT; j++)
					{
						for (i = 0; i < CHUNK_WIDTH;)
						{
							if (mask[n] != 0)
							{
								// We compute the width.
								for (w = 1; i + w < CHUNK_WIDTH && mask[n + w] != 0 && mask[n + w] == mask[n]; w++)
								{
								}

								// Then we compute height.
								bool done = false;

								for (h = 1; j + h < CHUNK_HEIGHT; h++)
								{
									for (k = 0; k < w; k++)
									{
										if (mask[n + k + h * CHUNK_WIDTH] == 0 || mask[n + k + h * CHUNK_WIDTH] != mask[n])
										{
											done = true;
											break;
										}
									}

									if (done)
									{
										break;
									}
								}

								// Here we check if the BlockFace is transparent, we don't mesh any culled faces.
							//	if (!mask[n].transparent)
								{
									// Add quad.
									x[u] = i;
									x[v] = j;

									du[0] = 0;
									du[1] = 0;
									du[2] = 0;
									du[u] = w;

									dv[0] = 0;
									dv[1] = 0;
									dv[2] = 0;
									dv[v] = h;

									// And here we call the quad function in order to render a merged quad in the scene.
									Vector3 bottomLeft = Vector3(x[0], x[1], x[2]);
									Vector3 topLeft = Vector3(x[0] + dv[0], x[1] + dv[1], x[2] + dv[2]);
									Vector3 bottomRight = Vector3(x[0] + du[0], x[1] + du[1], x[2] + du[2]);
									Vector3 topRight = Vector3(x[0] + du[0] + dv[0], x[1] + du[1] + dv[1], x[2] + du[2] + dv[2]);
									GenerateQuad(vertices, indices, bottomLeft, topLeft, topRight, bottomRight, w, h, mask[n], currentFace, backFace);
								}

								// We zero out the mask.
								for (l = 0; l < h; ++l)
								{
									for(k = 0; k < w; ++k)
									{
										mask[n + k + l * CHUNK_WIDTH] = 0;
									}
								}

								// And then finally increment the counters and continue.
								i += w;
								n += w;
							}
							else
							{
								i++;
								n++;
							}
						}
					}
				}
			}
		}
	}

	short Chunk::GetVoxelFace(const int &x, const int &y, const int &z, const FaceSide &faceType)
	{
	//	if (!IsFaceVisible(x, y, z, faceType))
	//	{
	//		return 0;
	//	}

		Block *block = GetBlock(x, y, z);
		return block != nullptr ? block->GetType() : (short)0;
	}

	void Chunk::GenerateQuad(std::vector<Vertex> *vertices, std::vector<uint32_t> *indices,
							 const Vector3 &bottomLeft, const Vector3 &topLeft, const Vector3 &topRight, const Vector3 &bottomRight,
							 const int &width, const int &height,
							 const short &mask, const FaceSide &faceSide, const bool &backFace)
	{
		// Gets where to start indices from.
		unsigned int indexStart = vertices->size();

		Colour colour = *BlockFace::FindColour(mask);

		// Calculates the quads normal direction.
		Vector3 normal = Vector3();
		Vector3::Cross(topRight - bottomRight, topLeft - bottomRight, &normal);

		// Flips normal x and z when x is present, I have no clue why.
		if (normal.m_x != 0.0f)
		{
			float tempX = normal.m_x;

			normal.m_x = normal.m_z;
			normal.m_z = tempX;
		}

		normal.Normalize();

		if (backFace)
		{
			normal.Negate();
		}

		// Pushes vertices and indices from quad.
		vertices->push_back(Vertex(VOXEL_SIZE * bottomLeft, Vector2(), normal, colour));
		vertices->push_back(Vertex(VOXEL_SIZE * topLeft, Vector2(), normal, colour));
		vertices->push_back(Vertex(VOXEL_SIZE * bottomRight, Vector2(), normal, colour));
		vertices->push_back(Vertex(VOXEL_SIZE * topRight, Vector2(), normal, colour));

		indices->push_back(indexStart + 2);
		indices->push_back(indexStart + (backFace ? 0 : 3));
		indices->push_back(indexStart + 1);
		indices->push_back(indexStart + 1);
		indices->push_back(indexStart + (backFace ? 3 : 0));
		indices->push_back(indexStart + 2);
	}
}
