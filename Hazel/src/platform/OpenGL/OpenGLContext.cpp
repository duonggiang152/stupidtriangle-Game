#include "hzpch.h"
#include "OpenGLContext.h"
#include "glad/glad.h"
#include "Hazel/Core.h"

namespace Hazel {
	bool OpenGLContext::isInited = false;
	OpenGLContext::OpenGLContext(GLFWwindow* WindowHandle)
	{
		m_WindowHandle = WindowHandle;
		HZ_CORE_ASSERT(m_WindowHandle, "Window Handle is NULL");
	}
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		if (status) OpenGLContext::isInited = true;
		HZ_CORE_ASSERT(status, "Failed initialized OpenGL");
	}
	void OpenGLContext::SwapBuffer()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

	
}