
#pragma once
#include "Hazel/Window.h"
#include "GLFW/glfw3.h"

#include "platform/OpenGL/OpenGLContext.h"

namespace Hazel
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; };
		inline unsigned int GetHeight() const override { return m_Data.Height; };

		inline void SetEventCallBack(const EventCallbackFn& callback) override { m_Data.EventCallBack = callback; };
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		virtual void* GetNativeWindow() const { return m_Window; }
	private:
		virtual void Init(const WindowProps& props);
		virtual void ShutDown();
	private:
		GLFWwindow* m_Window;
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallBack;
		};
		WindowData m_Data;
		OpenGLContext* m_Context;
	};
}