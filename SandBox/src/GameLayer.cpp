#include "GameLayer.h"

void GameLayer::OnAttach()
{
	Init();
	m_Level.Init();
	
}

void GameLayer::DeAttach()
{
}

void GameLayer::OnUpdate(Hazel::TimeStep ts)
{
	
	Hazel::RenderCommand::SetClearColor({ 0.0f, 0.0f, 0.0f, 1 });
	Hazel::RenderCommand::ClearColor();
	
	m_Level.OnUpdate(ts);

	Hazel::Renderer2D::BeginScene(m_Level.GetCamera());
	m_Level.Renderer();

	Hazel::Renderer::EndScene();

}

void GameLayer::OnImGuiLayer()
{
	
	m_Level.OnImguiUpdate();
	
}

void GameLayer::OnEvent(Hazel::Event& event)
{

}

void GameLayer::Init()
{
	

}
