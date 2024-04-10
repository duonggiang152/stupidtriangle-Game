#include "Level.h"
#include "imgui.h"
void Level::Init()
{
	m_PlayerShip.Init();
	m_Camera = std::make_unique<Hazel::OrthographicCamera>(-75.0f, 75.0f, -50.0f, 50.0f);
	m_Camera->SetPosition(m_CameraPosition);
	m_PlayerShip.SetShipSpeed(m_SpeedCamera);
	Triangle::m_Texture = Hazel::Texture::Create("assets/texture/Triangle.png");
	Triangle Frist = Triangle(50.0f);
	m_Tlib.Push(Frist);
	ImGuiIO io = ImGui::GetIO();
	m_Font = io.Fonts->AddFontFromFileTTF("assets/OpenSans-Regular.ttf", 120.0f);
}

void Level::OnUpdate(Hazel::TimeStep ts)
{
	if (m_GameState ==  GameState::Play)
	{
		m_PlayerShip.OnUpdate(ts);
		m_Tlib.OnUpdate(m_Camera->GetPostion(), ts);
		if (m_Tlib.CheckGameOver(m_PlayerShip.GetPositioncordinate()))
		{
			this->m_GameState = GameState::MainMenu;
		}
		m_Camera->SetPosition({ m_PlayerShip.GetPos(),0.0f });
		this->OnUpdateColor(ts);
		Triangle::SetColor(m_color);
	}
	if (m_GameState == GameState::MainMenu)
	{
		if (Hazel::Input::IsKeyPressed(HZ_KEY_S))
		{
			m_GameState = GameState::Play;
			ResetLevel();
		}
	}
}

void Level::Renderer()
{
	if (m_GameState == GameState::Play)
	{
		Hazel::Renderer2D::DrawQuad({ m_CameraPosition.x, m_CameraPosition.y + 70.0f }, { 1280.0f,60.0f }, m_color);
		Hazel::Renderer2D::DrawQuad({ m_CameraPosition.x, m_CameraPosition.y - 70.0f }, { 1280.0f,60.0f }, m_color);
		m_Tlib.Draw();
		m_PlayerShip.Render();
	}
	else if (m_GameState == GameState::MainMenu)
	{
		Hazel::Renderer2D::DrawQuad({ m_CameraPosition.x, m_CameraPosition.y + 70.0f }, { 1280.0f,60.0f }, m_color);
		Hazel::Renderer2D::DrawQuad({ m_CameraPosition.x, m_CameraPosition.y - 70.0f }, { 1280.0f,60.0f }, m_color);
		m_Tlib.Draw();
		m_PlayerShip.Render();
		// Draw mainmenu Text
	}
	
}

void Level::OnImguiUpdate()
{

	if (Level::m_GameState == GameState::MainMenu)
	{
		ImVec2 pos = ImGui::GetWindowPos();
		auto width = Hazel::Application::Get().GetWindow().GetWidth();
		auto height = Hazel::Application::Get().GetWindow().GetHeight();
		pos.x += width * 0.5f - 400.0f;
		pos.y += 50.0f;
		ImGui::GetForegroundDrawList()->AddText(NULL, 100.0f, pos, 0xffffffff, "Press S to play!");
	}
	
}

void Level::ResetLevel()
{
	m_Tlib.Reset();
	Triangle Frist = Triangle(50.0f);
	m_Tlib.Push(Frist);
	m_PlayerShip.Reset();
	m_Camera->SetPosition(m_CameraPosition);
}

void Level::OnUpdateColor(Hazel::TimeStep ts)
{
	
	if (!m_greenmax)
	{
		m_color.y += m_changleColor * ts;
		if (m_color.y >= 1.0f) m_greenmax = true;
	}
	else 
	{
		m_color.y -= m_changleColor * ts;
		if (m_color.y <= 0.0f) m_greenmax = false;
	}
	if (m_color.x >= 1.0f) m_color.x = 1.0f;
	if (m_color.y >= 1.0f) m_color.y = 1.0f;
	if (m_color.x <= 0.0f) m_color.x = 0.0f;
	if (m_color.y <= 0.0f) m_color.y = 0.0f;
}
