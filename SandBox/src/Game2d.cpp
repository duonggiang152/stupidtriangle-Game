#include <Hazel.h>
#include "Hazel/EntryPoint.h"
#include "platform/OpenGL/OpenGLShader.h"
#include "imgui.h"
#include "glm/gtc/type_ptr.hpp"
#include "GameLayer.h"
class SandBox : public Hazel::Application
{
public:
	SandBox()
	{
		PushLayer(new GameLayer());
		
		
	}
	~SandBox()
	{

	}
};
Hazel::Application* Hazel::CreateApplication()
{
	return new SandBox();
}
