#include "hzpch.h"

#include "Texture.h"
#include "platform/OpenGL/OpenGLTexture.h"
namespace Hazel {
	Ref<Texture> Texture::Create(uint32_t width, uint32_t height)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None: HZ_ASSERT(false, "HazelAPI:: NONE");
		case RendererAPI::API::OpenGL: return std::make_shared<OpenGLTexture2D>(width, height);
		}
		return nullptr;
	}
	Ref<Texture> Texture::Create(const std::string& path)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None: HZ_ASSERT(false, "HazelAPI:: NONE");
		case RendererAPI::API::OpenGL: return std::make_shared<OpenGLTexture2D>(path);
		}
		return nullptr;
	}


}