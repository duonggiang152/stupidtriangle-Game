#pragma once

#include "RendererAPI.h"
#include "Renderer.h"

namespace Hazel {

	class Texture
	{
	public:
		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		virtual void Bind(uint32_t slot) const = 0;
		
		virtual void SetData(void* data, uint32_t size) = 0;

		static Ref<Texture> Create(const std::string& path);
		static Ref<Texture> Create(uint32_t width, uint32_t height);
	};
}