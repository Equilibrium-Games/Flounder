set(FLOUNDERENGINE_HEADERS_
	"Camera/Camera.hpp"
	"Camera/ICamera.hpp"
	"Camera/IPlayer.hpp"
	"Deferred/RendererDeferred.hpp"
	"Deferred/UbosDeferred.hpp"
	"Devices/Audio.hpp"
	"Devices/Display.hpp"
	"Devices/Joysticks.hpp"
	"Devices/Keyboard.hpp"
	"Devices/Mouse.hpp"
	"Engine/Engine.hpp"
	"Engine/IModule.hpp"
	"Engine/IUpdater.hpp"
	"Engine/ModuleUpdate.hpp"
	"Entities/Components/ComponentCollider.hpp"
	"Entities/Components/ComponentCollision.hpp"
	"Entities/Components/ComponentGlow.hpp"
	"Entities/Components/ComponentLight.hpp"
	"Entities/Components/ComponentMaterial.hpp"
	"Entities/Components/ComponentModel.hpp"
	"Entities/Components/ComponentSun.hpp"
	"Entities/Components/ComponentSway.hpp"
	"Entities/Entities.hpp"
	"Entities/Entity.hpp"
	"Entities/EntityRender.hpp"
	"Entities/IComponent.hpp"
	"Entities/RendererEntities.hpp"
	"Entities/UbosEntities.hpp"
	"Events/EventChange.hpp"
	"Events/Events.hpp"
	"Events/EventStandard.hpp"
	"Events/EventTime.hpp"
	"Events/IEvent.hpp"
	"Flounder.hpp"
	"Fonts/Character.hpp"
	"Fonts/FontFamily.hpp"
	"Fonts/FontType.hpp"
	"Fonts/Justify.hpp"
	"Fonts/Line.hpp"
	"Fonts/Metafile.hpp"
	"Fonts/RendererFonts.hpp"
	"Fonts/Text.hpp"
	"Fonts/UbosFonts.hpp"
	"Fonts/Word.hpp"
	"Guis/Gui.hpp"
	"Guis/RendererGuis.hpp"
	"Guis/UbosGuis.hpp"
	"Helpers/HelperArray.hpp"
	"Helpers/HelperFile.hpp"
	"Helpers/HelperString.hpp"
	"Inputs/AxisButton.hpp"
	"Inputs/AxisCompound.hpp"
	"Inputs/AxisJoystick.hpp"
	"Inputs/ButtonCompound.hpp"
	"Inputs/ButtonJoystick.hpp"
	"Inputs/ButtonKeyboard.hpp"
	"Inputs/ButtonMouse.hpp"
	"Inputs/IAxis.hpp"
	"Inputs/IButton.hpp"
	"Lights/Fog.hpp"
	"Lights/Light.hpp"
	"Maths/Colour.hpp"
	"Maths/Delta.hpp"
	"Maths/Maths.hpp"
	"Maths/Matrix2.hpp"
	"Maths/Matrix3.hpp"
	"Maths/Matrix4.hpp"
	"Maths/Quaternion.hpp"
	"Maths/Timer.hpp"
	"Maths/Transform.hpp"
	"Maths/Vector2.hpp"
	"Maths/Vector3.hpp"
	"Maths/Vector4.hpp"
    "Models/CreateCube.hpp"
	"Models/CreateMesh.hpp"
	"Models/CreateSphere.hpp"
	"Models/Model.hpp"
	"Models/Vertex.hpp"
	"Models/VertexData.hpp"
	"Noise/NoiseFast.hpp"
	"Particles/Particle.hpp"
	"Particles/Particles.hpp"
	"Particles/ParticleSystem.hpp"
	"Particles/ParticleType.hpp"
	"Particles/RendererParticles.hpp"
	"Particles/Spawns/ISpawnParticle.hpp"
	"Particles/Spawns/SpawnCircle.hpp"
	"Particles/Spawns/SpawnLine.hpp"
	"Particles/Spawns/SpawnPoint.hpp"
	"Particles/Spawns/SpawnSphere.hpp"
	"Physics/Aabb.hpp"
	"Physics/Frustum.hpp"
	"Physics/ICollider.hpp"
	"Physics/Intersect.hpp"
	"Physics/Ray.hpp"
	"Physics/Sphere.hpp"
	"Platforms/Platform.hpp"
	"Platforms/PlatformUpdater.hpp"
	"Post/Filters/FilterBloom1.hpp"
	"Post/Filters/FilterBloom2.hpp"
	"Post/Filters/FilterBlurHorizontal.hpp"
	"Post/Filters/FilterBlurVertical.hpp"
	"Post/Filters/FilterCombine.hpp"
	"Post/Filters/FilterCrt.hpp"
	"Post/Filters/FilterDarken.hpp"
	"Post/Filters/FilterDefault.hpp"
	"Post/Filters/FilterEmboss.hpp"
	"Post/Filters/FilterFxaa.hpp"
	"Post/Filters/FilterGrain.hpp"
	"Post/Filters/FilterGrey.hpp"
	"Post/Filters/FilterLensflare.hpp"
	"Post/Filters/FilterMotion.hpp"
	"Post/Filters/FilterNegative.hpp"
	"Post/Filters/FilterPixel.hpp"
	"Post/Filters/FilterSepia.hpp"
	"Post/Filters/FilterTiltshift.hpp"
	"Post/Filters/FilterTone.hpp"
	"Post/Filters/FilterWobble.hpp"
	"Post/IPostFilter.hpp"
	"Post/IPostPipeline.hpp"
	"Post/Pipelines/PipelineBloom.hpp"
	"Post/Pipelines/PipelineGaussian.hpp"
	"Post/Pipelines/PipelinePaused.hpp"
	"Processing/Graphic/ProcessorGraphic.hpp"
	"Processing/Graphic/RequestGraphic.hpp"
	"Processing/IProcessor.hpp"
	"Processing/IRequest.hpp"
	"Processing/Processing.hpp"
	"Processing/Queue.hpp"
	"Processing/Resource/ProcessorResource.hpp"
	"Processing/Resource/RequestResource.hpp"
	"Renderer/Buffers/Buffer.hpp"
	"Renderer/Buffers/IndexBuffer.hpp"
	"Renderer/Buffers/UniformBuffer.hpp"
	"Renderer/Buffers/VertexBuffer.hpp"
	"Renderer/IManagerRender.hpp"
	"Renderer/IRenderer.hpp"
	"Renderer/Pass/RenderPass.hpp"
	"Renderer/Pipelines/Pipeline.hpp"
	"Renderer/Pipelines/PipelineCreate.hpp"
	"Renderer/Queue/QueueFamily.hpp"
	"Renderer/Renderer.hpp"
	"Renderer/Stencils/DepthStencil.hpp"
	"Renderer/Swapchain/Framebuffers.hpp"
	"Renderer/Swapchain/Swapchain.hpp"
	"Shadows/RendererShadows.hpp"
	"Shadows/ShadowBox.hpp"
	"Shadows/Shadows.hpp"
	"Shadows/UbosShadows.hpp"
	"Skyboxes/RendererSkyboxes.hpp"
	"Skyboxes/Skybox.hpp"
	"Skyboxes/Skyboxes.hpp"
	"Skyboxes/UbosSkyboxes.hpp"
	"Sounds/Sound.hpp"
	"Space/ISpatialObject.hpp"
	"Space/ISpatialStructure.hpp"
	"Space/StructureBasic.hpp"
	"Standards/IStandard.hpp"
	"Standards/Standards.hpp"
	"Stb/stb_image.h"
	"Tasks/Tasks.hpp"
	"Terrains/RendererTerrains.hpp"
	"Terrains/Terrain.hpp"
	"Terrains/Terrains.hpp"
	"Terrains/UbosTerrains.hpp"
	"Textures/Cubemap.hpp"
	"Textures/Texture.hpp"
	"Uis/IManagerUis.hpp"
	"Uis/InputButton.hpp"
	"Uis/InputDelay.hpp"
	"Uis/InputGrabber.hpp"
	"Uis/InputSlider.hpp"
	"Uis/InputText.hpp"
	"Uis/UiStartLogo.hpp"
	"Uis/UiBound.hpp"
	"Uis/UiObject.hpp"
	"Uis/Uis.hpp"
	"Uis/UiSelector.hpp"
	"Visual/DriverBounce.hpp"
	"Visual/DriverConstant.hpp"
	"Visual/DriverFade.hpp"
	"Visual/DriverLinear.hpp"
	"Visual/DriverSinwave.hpp"
	"Visual/DriverSlide.hpp"
	"Visual/IDriver.hpp"
	"Visual/Interpolation/SmoothFloat.hpp"
	"Waters/RendererWaters.hpp"
	"Waters/UbosWaters.hpp"
	"Waters/Water.hpp"
	"Waters/Waters.hpp"
	"Worlds/Worlds.hpp"
)

set(FLOUNDERENGINE_SOURCES_
	"Camera/Camera.cpp"
	"Deferred/RendererDeferred.cpp"
	"Devices/Audio.cpp"
	"Devices/Display.cpp"
	"Devices/Joysticks.cpp"
	"Devices/Keyboard.cpp"
	"Devices/Mouse.cpp"
	"Engine/Engine.cpp"
	"Entities/Components/ComponentCollider.cpp"
	"Entities/Components/ComponentCollision.cpp"
	"Entities/Components/ComponentGlow.cpp"
	"Entities/Components/ComponentLight.cpp"
	"Entities/Components/ComponentMaterial.cpp"
	"Entities/Components/ComponentModel.cpp"
	"Entities/Components/ComponentSun.cpp"
	"Entities/Components/ComponentSway.cpp"
	"Entities/Entities.cpp"
	"Entities/Entity.cpp"
	"Entities/RendererEntities.cpp"
	"Events/EventChange.cpp"
	"Events/Events.cpp"
	"Events/EventStandard.cpp"
	"Events/EventTime.cpp"
	"Fonts/Character.cpp"
	"Fonts/FontFamily.cpp"
	"Fonts/FontType.cpp"
	"Fonts/Line.cpp"
	"Fonts/Metafile.cpp"
	"Fonts/RendererFonts.cpp"
	"Fonts/Text.cpp"
	"Fonts/Word.cpp"
	"Guis/Gui.cpp"
	"Guis/RendererGuis.cpp"
	"Helpers/HelperArray.cpp"
	"Helpers/HelperFile.cpp"
	"Helpers/HelperString.cpp"
	"Inputs/AxisButton.cpp"
	"Inputs/AxisCompound.cpp"
	"Inputs/AxisJoystick.cpp"
	"Inputs/ButtonCompound.cpp"
	"Inputs/ButtonJoystick.cpp"
	"Inputs/ButtonKeyboard.cpp"
	"Inputs/ButtonMouse.cpp"
	"Lights/Fog.cpp"
	"Lights/Light.cpp"
	"Maths/Colour.cpp"
	"Maths/Delta.cpp"
	"Maths/Matrix2.cpp"
	"Maths/Matrix3.cpp"
	"Maths/Matrix4.cpp"
	"Maths/Quaternion.cpp"
	"Maths/Timer.cpp"
	"Maths/Transform.cpp"
	"Maths/Vector2.cpp"
	"Maths/Vector3.cpp"
	"Maths/Vector4.cpp"
    "Models/CreateCube.cpp"
	"Models/CreateMesh.cpp"
	"Models/CreateSphere.cpp"
	"Models/Model.cpp"
	"Models/Vertex.cpp"
	"Models/VertexData.cpp"
	"Noise/NoiseFast.cpp"
	"Particles/Particle.cpp"
	"Particles/Particles.cpp"
	"Particles/ParticleSystem.cpp"
	"Particles/ParticleType.cpp"
	"Particles/RendererParticles.cpp"
	"Particles/Spawns/SpawnCircle.cpp"
	"Particles/Spawns/SpawnLine.cpp"
	"Particles/Spawns/SpawnPoint.cpp"
	"Particles/Spawns/SpawnSphere.cpp"
	"Physics/Aabb.cpp"
	"Physics/Frustum.cpp"
	"Physics/Ray.cpp"
	"Physics/Sphere.cpp"
	"Platforms/Platform.cpp"
	"Platforms/PlatformUpdater.cpp"
	"Post/Filters/FilterBloom1.cpp"
	"Post/Filters/FilterBloom2.cpp"
	"Post/Filters/FilterBlurHorizontal.cpp"
	"Post/Filters/FilterBlurVertical.cpp"
	"Post/Filters/FilterCombine.cpp"
	"Post/Filters/FilterCrt.cpp"
	"Post/Filters/FilterDarken.cpp"
	"Post/Filters/FilterDefault.cpp"
	"Post/Filters/FilterEmboss.cpp"
	"Post/Filters/FilterFxaa.cpp"
	"Post/Filters/FilterGrain.cpp"
	"Post/Filters/FilterGrey.cpp"
	"Post/Filters/FilterLensflare.cpp"
	"Post/Filters/FilterMotion.cpp"
	"Post/Filters/FilterNegative.cpp"
	"Post/Filters/FilterPixel.cpp"
	"Post/Filters/FilterSepia.cpp"
	"Post/Filters/FilterTiltshift.cpp"
	"Post/Filters/FilterTone.cpp"
	"Post/Filters/FilterWobble.cpp"
	"Post/IPostFilter.cpp"
	"Post/IPostPipeline.cpp"
	"Post/Pipelines/PipelineBloom.cpp"
	"Post/Pipelines/PipelineGaussian.cpp"
	"Post/Pipelines/PipelinePaused.cpp"
	"Processing/Graphic/ProcessorGraphic.cpp"
	"Processing/Processing.cpp"
	"Processing/Resource/ProcessorResource.cpp"
	"Renderer/Buffers/Buffer.cpp"
	"Renderer/Buffers/IndexBuffer.cpp"
	"Renderer/Buffers/UniformBuffer.cpp"
	"Renderer/Buffers/VertexBuffer.cpp"
	"Renderer/Pass/RenderPass.cpp"
	"Renderer/Pipelines/Pipeline.cpp"
	"Renderer/Queue/QueueFamily.cpp"
	"Renderer/Renderer.cpp"
	"Renderer/Stencils/DepthStencil.cpp"
	"Renderer/Swapchain/Framebuffers.cpp"
	"Renderer/Swapchain/Swapchain.cpp"
	"Shadows/RendererShadows.cpp"
	"Shadows/ShadowBox.cpp"
	"Shadows/Shadows.cpp"
	"Skyboxes/RendererSkyboxes.cpp"
	"Skyboxes/Skybox.cpp"
	"Skyboxes/Skyboxes.cpp"
	"Sounds/Sound.cpp"
	"Space/StructureBasic.cpp"
	"Standards/Standards.cpp"
	"Stb/stb_image.c"
	"Tasks/Tasks.cpp"
	"Terrains/RendererTerrains.cpp"
	"Terrains/Terrain.cpp"
	"Terrains/Terrains.cpp"
	"Textures/Cubemap.cpp"
	"Textures/Texture.cpp"
	"Uis/InputButton.cpp"
	"Uis/InputDelay.cpp"
	"Uis/InputGrabber.cpp"
	"Uis/InputSlider.cpp"
	"Uis/InputText.cpp"
	"Uis/UiStartLogo.cpp"
	"Uis/UiBound.cpp"
	"Uis/UiObject.cpp"
	"Uis/Uis.cpp"
	"Uis/UiSelector.cpp"
	"Visual/DriverBounce.cpp"
	"Visual/DriverConstant.cpp"
	"Visual/DriverFade.cpp"
	"Visual/DriverLinear.cpp"
	"Visual/DriverSinwave.cpp"
	"Visual/DriverSlide.cpp"
	"Visual/Interpolation/SmoothFloat.cpp"
	"Waters/RendererWaters.cpp"
	"Waters/Water.cpp"
	"Waters/Waters.cpp"
	"Worlds/Worlds.cpp"
)

source_group("Header Files" FILES ${FLOUNDERENGINE_HEADERS_})
source_group("Source Files" FILES ${FLOUNDERENGINE_SOURCES_})

set(FLOUNDERENGINE_SOURCES
	${FLOUNDERENGINE_HEADERS_}
	${FLOUNDERENGINE_SOURCES_}
)
