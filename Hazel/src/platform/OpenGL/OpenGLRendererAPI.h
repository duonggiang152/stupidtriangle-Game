#pragma once
#include "Hazel/Renderer/RendererAPI.h"

namespace Hazel {
	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void Init() override;
		virtual void SetClearColor(const glm::vec4& color) override;
		virtual void ClearColor() override;
		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
	};
}