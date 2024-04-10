#pragma once
#include <Hazel.h>
#include <random>

class Triangle
{
public:
	
	Triangle(float position);
	
	void OnUpdate(Hazel::TimeStep ts);
	void Draw();
	static void SetColorTriangle(glm::vec4 color) { m_Color = color; }
	glm::vec2 GetStride();
	std::vector<glm::vec2> GetTopTriangleVertices();
	std::vector<glm::vec2> GetBottomTriangleVertices();

	float& GetPosition() { return m_Position; }

	void Remove(float backstrike) { m_Position = m_Position - backstrike; }
	static void SetColor(glm::vec4 color) { m_Color = color; }
	static Hazel::Ref<Hazel::Texture> m_Texture;
private:
	void DrawTriangle(float position, float toptop, float bottomtop);
private:
	float m_TopTopTriangle , m_TopBottomTriangle;

	float m_Position;

	glm::vec2 m_Scaletop;
	glm::vec2 m_PosTop;

	glm::vec2 m_ScaleBottom;
	glm::vec2 m_PosBottom;
	
	static glm::vec4 m_Color;
	
};
class Random
{
public:
	static float Randomab(float a, float b)
	{
		static std::default_random_engine e;
		static std::uniform_real_distribution<> dis(a, b); // rage 0 - 1
		return dis(e);
	}
};
class TriangleLib
{
public:
	void Push(Triangle& triangle) { m_Trianglelib.push_back(triangle); }
	void OnUpdate(glm::vec2 CameraPos, Hazel::TimeStep ts);
	void Draw();
	bool CheckGameOver(std::vector<glm::vec2> shipconorpos);
	void Reset() { m_Trianglelib.clear(); }
private:
	float area(float x1, float y1, float x2, float y2, float x3, float y3);
	bool PointInTriangle(glm::vec2 point, std::vector<glm::vec2> triangleCoridnate);
	bool CheckAdd(glm::vec2 CameraPos);
	bool CheckDelete(glm::vec2 CameraPos);
private:
	std::vector<Triangle> m_Trianglelib;

};
