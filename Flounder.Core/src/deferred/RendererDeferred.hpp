#pragma once

#include "../renderer/IRenderer.hpp"
#include "../renderer/buffers/UniformBuffer.hpp"
#include "../renderer/pipelines/Pipeline.hpp"
#include "../models/Model.hpp"

namespace Flounder
{
	class RendererDeferred :
		public IRenderer
	{
	private:
		static const DescriptorType typeUboScene;
		static const DescriptorType typeSamplerColour;
		static const DescriptorType typeSamplerNormal;
		static const DescriptorType typeSamplerShadows;
		static const PipelineCreateInfo pipelineCreateInfo;

		UniformBuffer *m_uniformScene;
		Pipeline *m_pipeline;
		Model *m_model;
	public:
		RendererDeferred();

		~RendererDeferred();

		void Render(const VkCommandBuffer *commandBuffer, const Vector4 &clipPlane, const ICamera &camera) override;
	};
}
