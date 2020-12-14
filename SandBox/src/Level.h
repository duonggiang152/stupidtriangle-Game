#pragma once
#include "Hazel.h"
#include "PlayerShip.h"
#include "Triangle.h"
#include "imgui.h"
enum class GameState
{
	Play = 0,MainMenu,Over
};
class Level
{
public:
	void Init();
	void OnUpdate(Hazel::TimeStep ts);
	void Renderer();
	Hazel::OrthographicCamera GetCamera() { return *m_Camera; }
	void OnImguiUpdate();
	void ResetLevel();
private:
	void OnUpdateColor(Hazel::TimeStep ts);
private:
	float m_changleColor = 0.3f;
	bool m_greenmax = false;
	Hazel::Scope<Hazel::OrthographicCamera> m_Camera;
	PlayerShip m_PlayerShip;
	glm::vec3 m_CameraPosition = { 0.0f,0.0f,0.0f };
	float m_SpeedCamera = 20.0f;
	float m_Speed = 5.0f;
	TriangleLib m_Tlib;
	glm::vec4 m_color = { 1.0f,0.0f,0.0f,1.0f };
	GameState m_GameState = GameState::MainMenu;
	ImFont* m_Font;
};