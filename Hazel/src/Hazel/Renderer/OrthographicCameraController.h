#pragma once
#include "OrthographicCamera.h"
#include "Hazel/Core/TimeStep.h"

#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Events/MouseEvent.h"

#include "glm/glm.hpp"
namespace Hazel {
	
	class OrthographicCameraController
	{
	public:
		OrthographicCameraController(float aspecRatio, bool rotation = false);

		void OnUpdate(TimeStep ts);	
		void OnEvent(Event& e);

		OrthographicCamera& GetCamera() { return m_Camera; };
		const OrthographicCamera& GetCamera() const { return m_Camera; };

	private:
		bool OnMouseScrolled(MouseScrolledEvent& e);
		bool OnWindowResized(WindowResizeEvent& e);
	private:
		float m_Aspecratio;
		float m_ZoomLevel = 1.0f;
		OrthographicCamera m_Camera;

		bool m_Rotation = false;
		glm::vec3 m_CameraPosition = { 0.0f,0.0f,0.0f };
		float m_CameraRoutation = 0.0f;

		float m_CameraSpeed = 0.5f;
		float m_RoutationCameraSpeed = 10.0f;
	};
}