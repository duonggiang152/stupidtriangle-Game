#pragma once
#include "Hazel.h"
class Paricle
{
public:
	Paricle(glm::vec2 pos);
	void OnUpdate(Hazel::TimeStep ts);
	void Draw();
	
	float GetOpacity() { return m_Opacity; }
private:
	float m_Opacity = 1.0f;
	Hazel::Ref<Hazel::Texture> m_triangle;
	std::vector<glm::vec2> m_TexturePosLib;
	glm::vec2 m_Pos;
};
