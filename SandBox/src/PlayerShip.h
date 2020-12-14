#pragma once
#include "Hazel.h"
#include "ParticleSystem.h"
class PlayerShip
{
public:
	void Init();
	void OnUpdate(Hazel::TimeStep ts);
	void Render();

	void SetShipSpeed(float speed) { m_Speed = 0; }
	std::vector<glm::vec2> GetPositioncordinate();
	glm::vec2 GetPos() { return m_Position; }
	void Reset() { m_Position = { 0.0f,0.0f }; }
private:
	void UpdateRotation(float y);
private:
	Hazel::Time m_Time;
	Hazel::Ref<Hazel::Texture> m_Ship;
	glm::vec2 m_Position = { 0.0f,0.0f };
	glm::vec2 m_Scale = { 15.0f * 0.4,10.0 * 0.6f };
	float m_PowerEngine = 30.0f;
	float m_Gravity = -30.5f;
	float m_Rotate = 6.0f;
	float m_Speed;
	Hazel::Ref<Hazel::Texture> m_Particletexture;
	std::vector<Paricle> m_Particlelib;
};