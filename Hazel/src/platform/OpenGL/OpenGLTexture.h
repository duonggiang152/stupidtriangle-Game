#pragma once
#include "Hazel/Renderer/Texture.h"
namespace Hazel {
	class OpenGLTexture2D : public Texture
	{
	public:
		OpenGLTexture2D(uint32_t width, uint32_t height);
		OpenGLTexture2D(const std::string& path);
		~OpenGLTexture2D();
		virtual void Bind(uint32_t slot = 0) const override;
		virtual uint32_t GetWidth() const override;
		virtual uint32_t GetHeight() const override;

		virtual void SetData(void* data, uint32_t size) override;
	private:
		uint32_t m_RendererID;
		std::string m_Path;
		uint32_t m_Width, m_Height;
		uint32_t m_InternalFormat;
		uint32_t m_DataFormat;
	};
}