#include "CreateSphere.hpp"

#include <algorithm>
#include "../Maths/Maths.hpp"

namespace Flounder
{
	Model *CreateSphere::Create(const int &latitudeBands, const int &longitudeBands, const float &radius)
	{
		std::vector<Vertex> vertices = std::vector<Vertex>();
		std::vector<uint32_t> indices = std::vector<uint32_t>();

		for (int latNumber = 0; latNumber <= latitudeBands; latNumber++)
		{
			float theta = latNumber * PI / latitudeBands;
			float sinTheta = static_cast<float>(sin(theta));
			float cosTheta = static_cast<float>(cos(theta));

			for (int longNumber = 0; longNumber <= longitudeBands; longNumber++)
			{
				float phi = longNumber * 2.0f * PI / longitudeBands;
				float sinPhi = static_cast<float>(sin(phi));
				float cosPhi = static_cast<float>(cos(phi));

				Vertex vertex = Vertex();
				vertex.m_normal.m_x = cosPhi * sinTheta;
				vertex.m_normal.m_y = cosTheta;
				vertex.m_normal.m_z = sinPhi * sinTheta;
				vertex.m_uv.m_x = 1.0f - (longNumber / longitudeBands);
				vertex.m_uv.m_y = 1.0f - (latNumber / latitudeBands);
				vertex.m_position.m_x = radius * vertex.m_normal.m_x;
				vertex.m_position.m_y = radius * vertex.m_normal.m_y;
				vertex.m_position.m_z = radius * vertex.m_normal.m_z;

				vertices.push_back(vertex);
			}
		}

		for (int latNumber = 0; latNumber < latitudeBands; latNumber++)
		{
			for (int longNumber = 0; longNumber < longitudeBands; longNumber++)
			{
				uint32_t first = (latNumber * (longitudeBands + 1)) + longNumber;
				uint32_t second = first + longitudeBands + 1;

				indices.push_back(first);
				indices.push_back(second);
				indices.push_back(first + 1);

				indices.push_back(second);
				indices.push_back(second + 1);
				indices.push_back(first + 1);
			}
		}

		std::reverse(indices.begin(),indices.end());

		return new Model(vertices, indices);
	}
}
