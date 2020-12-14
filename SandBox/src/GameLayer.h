#include "Hazel.h"

#include "Level.h"
#include "imgui.h"
class GameLayer : public Hazel::Layer
{
public:
	virtual void OnAttach();
	virtual void DeAttach();
	virtual void OnUpdate(Hazel::TimeStep ts);
	virtual void OnImGuiLayer();
	virtual void OnEvent(Hazel::Event& event);

	void Init();
	void GameState();
private:
	
	
	
	Level m_Level;
	
	ImFont* m_Font;
};