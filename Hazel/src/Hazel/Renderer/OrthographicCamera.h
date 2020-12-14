#pragma once

#include "glm/glm.hpp"

namespace Hazel {
	class OrthographicCamera
	{
	public:
		OrthographicCamera() {};
		OrthographicCamera(float left, float right, float bottom, float top);
		void SetProjection(float left, float right, float bottom, float top);
		
		const glm::vec3& GetPostion() const { return m_Positon; }
		void SetPosition(const glm::vec3& Position) { m_Positon = Position; RecaculateViewMatrix(); }
		float GetRotation() const { return m_Rotation; }
		void SetRotation(const float& Rotation) { m_Rotation = Rotation; RecaculateViewMatrix(); }

		const glm::mat4 GetProjectionMatrix() const { return m_ProjectionMatrix; }
		const glm::mat4 GetViewMatrix() const { return m_ViewMatrix; }
		const glm::mat4 GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }
	private:
		void RecaculateViewMatrix();
	private:
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix;

		glm::vec3 m_Positon = { 0.0f,0.0f,0.0f };
		float m_Rotation = 0.0f;

	};
		
}