#include "hzpch.h"
#include "Application.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Log.h"
#include "glad/glad.h"
#include "Hazel/Application.h"
#include "Hazel/Input.h"
#include "Hazel/Renderer/Shader.h"
#include "GLFW/glfw3.h"
#include "Hazel/Renderer/Renderer.h"
#include "glm/glm.hpp"

#include "glm/gtc/type_ptr.hpp"

#include <Hazel/Renderer/OrthographicCamera.h>
namespace Hazel 
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
	
	Application* Application::s_Instance = nullptr;
	Application::Application()
	{
		HZ_CORE_ASSERT(s_Instance, "Application already exist");
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create({"Stupid triangle",720,1280}));
		m_Window->SetEventCallBack(BIND_EVENT_FN(OnEvent));
		Renderer::Init();
		
		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);

		
	}
	Application::~Application()
	{

	}
	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}
	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverLay(layer);
		layer->OnAttach();
	}
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispathcher(e);
		
		dispathcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		dispathcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(OnWindowResize));
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
			{
				e.Handled = false;
			}
		}
		
	}
	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		
		if (e.GetWidth() == 0 && e.GetHeight() == 0)
		{
			m_Minimized = true;
			return true;
		}
		m_Minimized = false;
		return false;
	}
	void Application::Run()
	{
		while (m_Running)
		{
			float time = (float)glfwGetTime();
			TimeStep timestep(time - m_LastFrameTime);

			m_LastFrameTime = time;
			if (!m_Minimized)
			{
				for (Layer* layer : m_LayerStack)
				{
					layer->OnUpdate(timestep);
				}
			}
			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
				layer->OnImGuiLayer();
			m_ImGuiLayer->End();
			m_Window->OnUpdate();
			
		}
	}
}