#pragma once

#include <string>
#include <vector>
#include "Files/Files.hpp"
#include "Resources/Resources.hpp"
#include "Maths/Vector3.hpp"
#include "Audio.hpp"

namespace acid
{
	/// <summary>
	/// Class that represents a sound buffer.
	/// </summary>
	class FL_EXPORT SoundBuffer :
		public IResource
	{
	private:
		std::string m_filename;
		unsigned int m_buffer;
	public:
		static std::shared_ptr<SoundBuffer> Resource(const std::string &filename)
		{
			std::string realFilename = Files::Get()->SearchFile(filename);
			auto resource = Resources::Get()->Get(realFilename);

			if (resource != nullptr)
			{
				return std::dynamic_pointer_cast<SoundBuffer>(resource);
			}

			auto result = std::make_shared<SoundBuffer>(realFilename);
			Resources::Get()->Add(std::dynamic_pointer_cast<IResource>(result));
			return result;
		}

		SoundBuffer(const std::string &filename);

		~SoundBuffer();

		std::string GetFilename() override { return m_filename; };

		unsigned int GetBuffer() const { return m_buffer; };

	private:
		static unsigned int LoadBufferWav(const std::string &filename);

		static unsigned int LoadBufferOgg(const std::string &filename);
	};
}
