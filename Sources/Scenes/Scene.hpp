#pragma once

#include <memory>
#include "Uis/UiSelector.hpp"
#include "Camera.hpp"
#include "ScenePhysics.hpp"
#include "SceneStructure.hpp"

namespace acid
{
	/// <summary>
	/// A object used to represent a scene.
	/// </summary>
	class ACID_EXPORT Scene
	{
	public:
		/// <summary>
		/// Creates a new scene.
		/// </summary>
		/// <param name="camera"> The scenes camera. </param>
		/// <param name="virtualJoystick"> The joystick virtual controller for UI selectors. </param>
		Scene(Camera *camera, VirtualJoystick *virtualJoystick) :
			m_camera(camera),
			m_virtualJoystick(virtualJoystick),
			m_physics(std::make_unique<ScenePhysics>()),
			m_structure(std::make_unique<SceneStructure>()),
			m_started(false)
		{
		}

		virtual void Start() = 0;

		/// <summary>
		/// Run when updating the scene.
		/// </summary>
		virtual void Update() = 0;

		/// <summary>
		/// Gets the current camera object.
		/// </summary>
		/// <returns> The current camera. </returns>
		Camera *GetCamera() const { return m_camera.get(); }

		/// <summary>
		/// Sets the current camera to a new camera.
		/// </summary>
		/// <param name="camera"> The new camera. </param>
		void SetCamera(Camera *camera) { m_camera.reset(camera); }

		/// <summary>
		/// Gets the virtual joystick controller for UI selectors.
		/// </summary>
		/// <returns> The virtual joystick selector. </returns>
		VirtualJoystick *GetVirtualJoystick() const { return m_virtualJoystick.get(); };

		/// <summary>
		/// Sets the virtual joystick controller for UI selectors.
		/// </summary>
		/// <param name="virtualJoystick"> The new virtual joystick selector. </param>
		/// <returns> The virtual joystick selector. </returns>
		void SetVirtualJoystick(VirtualJoystick *virtualJoystick) { m_virtualJoystick.reset(virtualJoystick); }

		/// <summary>
		/// Gets the scene physics system.
		/// </summary>
		/// <returns> The scenes physics system. </returns>
		ScenePhysics *GetPhysics() const { return m_physics.get(); }

		/// <summary>
		/// Gets the scene object structure.
		/// </summary>
		/// <returns> The scene object structure. </returns>
		SceneStructure *GetStructure() { return m_structure.get(); }

		/// <summary>
		/// Gets if the scene is paused.
		/// </summary>
		/// <returns> If the scene is paused. </returns>
		virtual bool IsPaused() const = 0;
	private:
		friend class Scenes;

		std::unique_ptr<Camera> m_camera;
		std::unique_ptr<VirtualJoystick> m_virtualJoystick;
		std::unique_ptr<ScenePhysics> m_physics;
		std::unique_ptr<SceneStructure> m_structure;
		bool m_started;
	};
}
