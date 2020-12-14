#include "hzpch.h"
#include "VertexArray.h"
#include "Renderer.h"

#include "platform/OpenGL/OpenGLVertexArray.h"
namespace Hazel {
		
	Ref<VertexArray>  VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: HZ_CORE_ASSERT(false, "RendererAPI::None is currently return null ptr"); return nullptr;
		case RendererAPI::API::OpenGL: return std::make_shared<OpenGLVertexArray>();
		}
		return nullptr;
	}
}