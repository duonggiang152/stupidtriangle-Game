#pragma once
#include "VertexArray.h"
#include "RendererAPI.h"
#include "glm/glm.hpp"
namespace Hazel {
	class RenderCommand
	{
	public:
		static void SetClearColor(const glm::vec4& color)
		{
			s_RendererAPI->SetClearColor(color);
		}
		static void ClearColor()
		{
			s_RendererAPI->ClearColor();
		}
		static void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)
		{
			s_RendererAPI->DrawIndexed(vertexArray);
		}
		inline static void Init()
		{
			s_RendererAPI->Init();
		}
		static void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
		{
			s_RendererAPI->SetViewport(x, y, width, height);
		}
	private:
		static RendererAPI* s_RendererAPI;
	};
}