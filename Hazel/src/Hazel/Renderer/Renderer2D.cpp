#include "hzpch.h"
#include "Renderer2D.h"

#include "VertexArray.h"
#include "Buffer.h"
#include "Shader.h"
#include "RenderCommand.h"

#include "platform/OpenGL/OpenGLShader.h"
#include "glm/gtc/matrix_transform.hpp"
namespace Hazel  {
	struct Renderer2DStorage
	{
		Ref<VertexArray> QuadVertexArray;
		Ref<Shader> TextureShader;
		Ref<Texture> WhiteTexture;
	};
	static Renderer2DStorage* s_Data;
	void Renderer2D::Init()
	{
		s_Data = new Renderer2DStorage();
		s_Data->QuadVertexArray = VertexArray::Create();
		float vertices[5 * 4] = {
				 0.5f, -0.5f, 0.0f, 1.0f,0.0f,
			    -0.5f, -0.5f, 0.0f, 0.0f,0.0f,
			     0.5f, 0.5f, 0.0f, 1.0f,1.0f,
			    -0.5f, 0.5f, 0.0f, 0.0f,1.0f,
		};
		Ref<VertexBuffer> squareVB;
		squareVB.reset(VertexBuffer::Create(vertices, sizeof(vertices)));
		BufferLayout layout = {
				{ShaderDataType::Float3, "a_Position", false},
				{Hazel::ShaderDataType::Float2, "u_TexCoord", false},
		};
		squareVB->SetLayOut(layout);
		unsigned int indices[6] = {
				0,1,2,1,2,3
		};
		Ref<IndexBuffer> squareIB;
		squareIB.reset(IndexBuffer::Create(indices, 6));
		s_Data->QuadVertexArray->AddVertexBuffer(squareVB);
		s_Data->QuadVertexArray->SetIndexBuffer(squareIB);
		s_Data->WhiteTexture = Texture::Create(1, 1);
		uint32_t whiteTextureData = 0xffffffff;
		s_Data->WhiteTexture->SetData(&whiteTextureData, sizeof(uint32_t));
		std::string filepath = "assets/shaders/texture.glsl";
		s_Data->TextureShader = Shader::Create(filepath);
	}
	void Renderer2D::Shutdown()
	{
	}
	void Renderer2D::BeginScene(const OrthographicCamera &Camera)
	{
		
		s_Data->TextureShader->Bind();
		s_Data->TextureShader->SetMat4("u_ViewProjection", Camera.GetViewProjectionMatrix());
		
	}
	void Renderer2D::EndScence()
	{
	}
	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color)
	{
		DrawQuad({ position.x,position.y,0.0f }, size, color);
	}
	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color)
	{

		s_Data->TextureShader->Bind();
		// Bind white texture here
		s_Data->WhiteTexture->Bind(0);
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), position) *
			glm::scale(glm::mat4(1.0f), { size,1.0f });
		s_Data->TextureShader->SetMat4("u_Transform", transform);
		s_Data->TextureShader->SetFloat4("u_Color", color);
		RenderCommand::DrawIndexed(s_Data->QuadVertexArray);
	}
	void Renderer2D::DrawQuad(const glm::vec2 &position, const glm::vec2& size, const Ref<Texture>& texture,const float tilingFactor, glm::vec4 tintColor)
	{
		DrawQuad({position.x,position.y,0.0f}, size, texture, tilingFactor, tintColor);
	}
	void Renderer2D::DrawQuad(const glm::vec3 &position, const glm::vec2& size, const Ref<Texture>& texture,const float tilingFactor, glm::vec4 tintColor)
	{
		s_Data->TextureShader->SetFloat4("u_Color", tintColor);
		s_Data->TextureShader->SetFloat("u_TitlingFactor", tilingFactor);
   		texture->Bind(0);
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), position) *
			glm::scale(glm::mat4(1.0f), { size,1.0f });
		s_Data->TextureShader->SetInt("u_Texture", 0);
		s_Data->TextureShader->SetMat4("u_Transform", transform);
		RenderCommand::DrawIndexed(s_Data->QuadVertexArray);
	}
	void Renderer2D::DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float rotation, const glm::vec4& color)
	{
		DrawRotatedQuad({ position.x,position.y,0.0f }, size, rotation, color);
	}
	void Renderer2D::DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const glm::vec4& color)
	{
		s_Data->TextureShader->Bind();
		// Bind white texture here
		s_Data->WhiteTexture->Bind(0);
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), position)
			* glm::rotate(glm::mat4(1.0f), glm::radians(rotation), { 0.0f,0.0f,1.0f })
			* glm::scale(glm::mat4(1.0f), { size,1.0f });
		s_Data->TextureShader->SetMat4("u_Transform", transform);
		s_Data->TextureShader->SetFloat4("u_Color", color);
		RenderCommand::DrawIndexed(s_Data->QuadVertexArray);
	}
	void Renderer2D::DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float rotation, const Ref<Texture>& texture, float tilingFactor, const glm::vec4 tintColor)
	{
		DrawRotatedQuad({ position.x,position.y,0.0f }, size, rotation, texture, tilingFactor,tintColor);
	}
	void Renderer2D::DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const Ref<Texture>& texture, float tilingFactor, const glm::vec4 tintColor)
	{
		s_Data->TextureShader->SetFloat4("u_Color", tintColor);
		s_Data->TextureShader->SetFloat("u_TitlingFactor", tilingFactor);
		texture->Bind(0);
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), position) *
			glm::rotate(glm::mat4(1.0f), glm::radians(rotation), { 0.0f,0.0f,1.0f}) *
			glm::scale(glm::mat4(1.0f), { size,1.0f });
		s_Data->TextureShader->SetInt("u_Texture", 0);
		s_Data->TextureShader->SetMat4("u_Transform", transform);
		RenderCommand::DrawIndexed(s_Data->QuadVertexArray);
	}
}