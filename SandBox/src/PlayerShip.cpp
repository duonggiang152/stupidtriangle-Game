
#include "PlayerShip.h"

void PlayerShip::Init()
{
	m_Ship = Hazel::Texture::Create("assets/texture/Ship.png");
	float temp = m_Time.CurrentTime();
	m_Time.SetTimeStart(temp);
}

void PlayerShip::OnUpdate(Hazel::TimeStep ts)
{
	m_Position.x += m_Speed * ts;
	if (Hazel::Input::IsKeyPressed(HZ_KEY_SPACE))
	{
		if (m_Time.Tonow() > 0.1)
		{
			m_Particlelib.push_back(Paricle(m_Position, m_Particletexture));
			float temp = m_Time.CurrentTime();
			m_Time.SetTimeStart(temp);
		}
		m_Position.y += (m_PowerEngine * float(ts));
		UpdateRotation(m_PowerEngine * float(ts));
	}
	else
	{
		m_Position.y += (m_Gravity * float(ts));
		UpdateRotation(m_Gravity * float(ts));
	}
	for (int i = 0; i < m_Particlelib.size(); i++)
	{
		while (i < m_Particlelib.size() && m_Particlelib[i].GetOpacity() <= 0.0f)
		{
			m_Particlelib.erase(m_Particlelib.begin() + i);
		}
	}
	for (int i = 0; i < m_Particlelib.size(); i++)
	{
		m_Particlelib[i].OnUpdate(ts);
	}
}

void PlayerShip::Render()
{
	for (auto i : m_Particlelib)
		i.Draw();
	Hazel::Renderer2D::DrawRotatedQuad({ m_Position }, m_Scale, m_Rotate, m_Ship);
}

std::vector<glm::vec2> PlayerShip::GetPositioncordinate()
{
	std::vector<glm::vec4> tri(4); 
	tri[0] = { 0.5f, -0.5f, 0.0f, 1.0f };
	tri[1] = { -0.5f, -0.5f, 0.0f, 1.0f };
	tri[2] = { 0.5f, 0.5f, 0.0f, 1.0f };
	tri[3] = { -0.5f, 0.5f, 0.0f, 1.0f };
	std::vector<glm::vec2> result(4);
	for (int i = 0; i < 4; i++)
	{
		result[i] = glm::translate(glm::mat4(1.0f), { m_Position.x, m_Position.y, 0.0f })
			* glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotate), { 0.0f, 0.0f, 1.0f })
			* glm::scale(glm::mat4(1.0f), { m_Scale.x, m_Scale.y, 1.0f })
			* tri[i];
	}
	return result;
}

void PlayerShip::UpdateRotation(float y)
{
	float angle = 0.0f;
	if (y >= 0)
	{
		angle = y * 4.0f;
	}
	else if (y <= 0)
	{
		angle = y * 3.75f;
	}
	m_Rotate += angle;
	if (m_Rotate >= 75) m_Rotate = 75;
	else if (m_Rotate <= -30) m_Rotate = -30;
}
