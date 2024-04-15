#include "ParticleSystem.h"


Paricle::Paricle(glm::vec2 pos)
	:m_Pos(pos)
{
	m_TexturePosLib.push_back({ m_Pos.x, m_Pos.y + 1 });
	m_TexturePosLib.push_back({ m_Pos.x, m_Pos.y + 0.5 });
	m_TexturePosLib.push_back({ m_Pos.x,m_Pos.y -1});
	m_TexturePosLib.push_back({ m_Pos.x - 1,m_Pos.y});
}

void Paricle::OnUpdate(Hazel::TimeStep ts)
{
	if (m_Opacity > 0.0f)
		m_Opacity -= 0.4 * ts;
	for (int i = 0; i < m_TexturePosLib.size(); i++)
	{
		m_TexturePosLib[i].x -= 30.0f * ts;
	}
	if (m_Opacity < 0.0f) m_Opacity = 0.0f;
}

void Paricle::Draw()
{
	for (int i = 0; i < m_TexturePosLib.size(); i++)
	{
		if (i == m_TexturePosLib.size() - 1)
			Hazel::Renderer2D::DrawQuad(m_TexturePosLib[i], { 3.0f,3.0f }, { 0.8f,0.2f,0.0f,m_Opacity });
		else
			Hazel::Renderer2D::DrawQuad(m_TexturePosLib[i], { 3.0f,3.0f },{ 0.7f,0.7f,0.7f,m_Opacity });
	}
}

