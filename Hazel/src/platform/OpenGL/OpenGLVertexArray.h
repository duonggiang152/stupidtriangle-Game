#pragma once
#include "Hazel/Renderer/VertexArray.h"

namespace Hazel {

	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();

		virtual void Bind() const ;
		virtual void UnBind() const ;

		virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer);
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer);
		virtual std::shared_ptr<IndexBuffer> GetIndexBuffer() const override;
	private:
		uint32_t m_RendererID;
		std::vector<std::shared_ptr<VertexBuffer>> m_vertexBuffers;
		std::shared_ptr<IndexBuffer> m_indexBuffer;
	};

}