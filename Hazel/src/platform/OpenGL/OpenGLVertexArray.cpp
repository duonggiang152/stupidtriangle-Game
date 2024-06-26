#include "hzpch.h"

#include "OpenGlVertexArray.h"
#include "glad/glad.h"
namespace Hazel {
	static GLenum ShaderDataTypeToOpenGLType(ShaderDataType type)
	{

		switch (type)
		{
		case Hazel::ShaderDataType::Float: return GL_FLOAT;
		case Hazel::ShaderDataType::Float2: return GL_FLOAT;
		case Hazel::ShaderDataType::Float3: return GL_FLOAT;
		case Hazel::ShaderDataType::Float4: return GL_FLOAT;
		case Hazel::ShaderDataType::Mat3: return GL_FLOAT;
		case Hazel::ShaderDataType::Mat4: return GL_FLOAT;
		case Hazel::ShaderDataType::Int: return GL_INT;
		case Hazel::ShaderDataType::Int2: return GL_INT;
		case Hazel::ShaderDataType::Int3: return GL_INT;
		case Hazel::ShaderDataType::Int4: return GL_INT;
		case Hazel::ShaderDataType::Bool: return GL_BOOL;
		}
		HZ_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;

	}
	OpenGLVertexArray::OpenGLVertexArray()
	{
		glGenVertexArrays(1, &m_RendererID);

	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);
	}
	void OpenGLVertexArray::UnBind() const
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) 
	{
		glBindVertexArray(m_RendererID);
		vertexBuffer->Bind();
		HZ_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "VertexBuffer has no Elements");
		uint32_t index = 0;
		auto& layout = vertexBuffer->GetLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index,
			element.GetComponentCount(),
			ShaderDataTypeToOpenGLType(element.Type),
			element.Normalized ? GL_TRUE : GL_FALSE,
			layout.GetStride(),
			(const void*)element.OffSet);
			index++;
		}
		m_vertexBuffers.push_back(vertexBuffer);
	}
	void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
	{
		glBindVertexArray(m_RendererID);

		indexBuffer->Bind();

		m_indexBuffer = indexBuffer;
	}
	std::shared_ptr<IndexBuffer> OpenGLVertexArray::GetIndexBuffer() const
	{
		return m_indexBuffer;
	}

}