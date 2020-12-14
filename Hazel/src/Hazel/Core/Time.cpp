#include "hzpch.h"
#include "Time.h"
#include "GLFW/glfw3.h"
namespace Hazel
{
	float Time::CurrentTime()
	{
		return (float)glfwGetTime();
	}
}