
#include "hzpch.h"
#include "OrthographicCameraController.h"
#include "RenderCommand.h"
#include "Hazel/Input.h"
#include "Keycode.h"
namespace Hazel {
	OrthographicCameraController::OrthographicCameraController(float aspecRatio, bool rotation)
		:m_Aspecratio(aspecRatio),m_Camera(-m_Aspecratio * m_ZoomLevel, m_Aspecratio* m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel), m_Rotation(rotation)
	{
		
	}
	void OrthographicCameraController::OnUpdate(TimeStep ts)
	{
		if (Input::IsKeyPressed(HZ_KEY_UP))
			m_CameraPosition.y -= m_CameraSpeed * (float)ts;
		else if (Input::IsKeyPressed(HZ_KEY_DOWN))
			m_CameraPosition.y += m_CameraSpeed * (float)ts;
		if (Input::IsKeyPressed(HZ_KEY_LEFT))
			m_CameraPosition.x += m_CameraSpeed * (float)ts;
		else if (Input::IsKeyPressed(HZ_KEY_RIGHT))
			m_CameraPosition.x -= m_CameraSpeed * (float)ts;
		if (m_Rotation)
		{
			if (Input::IsKeyPressed(HZ_KEY_A))
				m_CameraRoutation -= m_RoutationCameraSpeed * (float)ts;
			else if (Input::IsKeyPressed(HZ_KEY_D))
				m_CameraRoutation += m_RoutationCameraSpeed * (float)ts;
			m_Camera.SetRotation(m_CameraRoutation);
		}
		
		m_Camera.SetPosition(m_CameraPosition);
	}
	void OrthographicCameraController::OnEvent(Event& e)
	{
		EventDispatcher dispathcher(e);
		dispathcher.Dispatch<MouseScrolledEvent>(HZ_BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
		dispathcher.Dispatch<WindowResizeEvent>(HZ_BIND_EVENT_FN(OrthographicCameraController::OnWindowResized));
	}
	bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& e)
	{
		
		m_ZoomLevel -= e.GetYOffset() * 0.5f;
		m_ZoomLevel = std::max(0.25f,m_ZoomLevel);
		m_Camera.SetProjection(-m_Aspecratio * m_ZoomLevel, m_Aspecratio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}
	bool OrthographicCameraController::OnWindowResized(WindowResizeEvent& e)
	{
		RenderCommand::SetViewport(0, 0, e.GetWidth(), e.GetHeight());
		m_Aspecratio = (float)e.GetWidth()/(float)e.GetHeight();
		m_Camera.SetProjection(-m_Aspecratio * m_ZoomLevel, m_Aspecratio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}
}