#pragma once
#include "Hazel/Renderer/Buffer.h"

namespace Hazel {
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* vertices, uint32_t size);

		virtual void Bind() const override;
		virtual void UnBind() const override;
		virtual void SetLayOut(BufferLayout layout) override;
		virtual BufferLayout GetLayout() const override { return m_Layout; }
	private:
		BufferLayout m_Layout;
		uint32_t m_RendererID;
	};
	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);

		virtual void Bind() const override;
		virtual void UnBind() const override;
		virtual uint32_t GetCount() const override;
	private:
		uint32_t m_RendererID;
		uint32_t m_Count;
	};

}