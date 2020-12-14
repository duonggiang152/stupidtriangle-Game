#pragma once

#include "OrthographicCamera.h"
#include "Texture.h"
#include "Hazel/Core.h"
namespace Hazel  {

	class Renderer2D
	{
	public:
		static void Init();
		static void Shutdown();

		static void BeginScene(const OrthographicCamera& Camera);
		static void EndScence();

		// primitives
		static void DrawQuad(const glm::vec2 &position, const glm::vec2 &size, const glm::vec4 &color);
		static void DrawQuad(const glm::vec3 &position, const glm::vec2 &size, const glm::vec4 &color);
		static void DrawQuad(const glm::vec2 &position, const glm::vec2 &size, const Ref<Texture> &texture,const float tilingFactor = 1, glm::vec4 tintColor = glm::vec4(1.0f));
		static void DrawQuad(const glm::vec3 &position, const glm::vec2 &size, const Ref<Texture> &texture,const float tilingFactor = 1, glm::vec4 tintColor = glm::vec4(1.0f));
		
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float rotation, const glm::vec4& color);
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const glm::vec4& color);
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float rotation, const Ref<Texture>& texture,const float tilingFactor = 1, glm::vec4 tintColor = glm::vec4(1.0f));
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const Ref<Texture>& texture,const float tilingFactor = 1, glm::vec4 tintColor = glm::vec4(1.0f));
		
	};
}