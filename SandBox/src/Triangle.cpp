#include "Triangle.h"
#include "string"

glm::vec4 Triangle::m_Color = { 1.0f, 0.0f, 0.0f, 1.0f };
Hazel::Ref<Hazel::Texture> Triangle::m_Texture ;

Triangle::Triangle(float position)
{
	m_Position = position;
	//m_Texture = Hazel::Texture::Create("assets/texture/Triangle.png");
	// position of the gate to pass
	glm::vec2 widthG;
	// Get Position of the gate to pass top and botom triangle
	float middleG = Random::Randomab(-25.0f, 25.0f);
	widthG.x = middleG + 3.0f;
	widthG.y = middleG - 3.0f;
	// set top and botom triangle top
	m_TopTopTriangle = widthG.x;
	m_TopBottomTriangle = widthG.y;
}
void Triangle::OnUpdate(Hazel::TimeStep ts)
{
	Remove(30.0f * ts);
	{
		glm::vec2 botompScale;
		// get middle of the box draw
		glm::vec2 pos;
		pos = { m_Position, (float)(-40.0f + m_TopBottomTriangle) / (float)2 };
		// get scale 
		botompScale.y = (40 + pos.y) / 0.5f;
		botompScale.x = botompScale.y;
		if (botompScale.x >= 40) botompScale.x = 40;
		// draw bottom
		pos.y = pos.y - (40 + pos.y) * 2 * 0.1;
		m_ScaleBottom = botompScale;
		m_PosBottom = pos;
	}
	{

		// draw top triangle
		glm::vec2 topScale;
		// get middle of the box draw
		glm::vec2 pos = { m_Position,
		m_TopTopTriangle > 0 ? ((40.0f + m_TopTopTriangle) / (float)2) : ((40.0f / 2.0) - (-m_TopTopTriangle / (float)2)) };
		// get scale 
		topScale.y = (40 - pos.y) / 0.5f;
		topScale.x = topScale.y;
		if (topScale.x >= 40) topScale.x = 40;
		// draw top
		pos.y = pos.y + (40 - pos.y) * 2 * 0.1;
		m_Scaletop = topScale;
		m_PosTop = pos;
	}
}

void Triangle::Draw()
{
	DrawTriangle(m_Position, m_TopTopTriangle, m_TopBottomTriangle);
}

glm::vec2 Triangle::GetStride()
{
	glm::vec2 stride;
	stride.x = m_Position - 15.0f;
	stride.y = m_Position + 15.0f;
	return stride;
}

std::vector<glm::vec2> Triangle::GetTopTriangleVertices()
{
	std::vector<glm::vec2> tri(3);
	glm::vec4 pillarVertices[3] = {
		{ -0.5f + 0.1f, -0.5f + 0.1f, 0.0f, 1.0f },
		{  0.5f - 0.1f, -0.5f + 0.1f, 0.0f, 1.0f },
		{  0.0f + 0.0f,  0.5f - 0.1f, 0.0f, 1.0f },
	};
	for (int i = 0; i < 3; i++)
	{
		tri[i] = glm::translate(glm::mat4(1.0f), { m_PosTop.x, m_PosTop.y, 0.0f })
			* glm::rotate(glm::mat4(1.0f), glm::radians(180.0f), { 0.0f, 0.0f, 1.0f })
			* glm::scale(glm::mat4(1.0f), { m_Scaletop.x, m_Scaletop.y, 1.0f })
			* pillarVertices[i];
	}
	return tri;

}

std::vector<glm::vec2> Triangle::GetBottomTriangleVertices()
{
	std::vector<glm::vec2> tri(3);
	glm::vec4 pillarVertices[3] = {
		{ -0.5f + 0.1f, -0.5f + 0.1f, 0.0f, 1.0f },
		{  0.5f - 0.1f, -0.5f + 0.1f, 0.0f, 1.0f },
		{  0.0f + 0.0f,  0.5f - 0.1f, 0.0f, 1.0f },
	};
	for (int i = 0; i < 3; i++)
	{
		tri[i] = glm::translate(glm::mat4(1.0f), { m_PosBottom.x, m_PosBottom.y, 0.0f })
			* glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), { 0.0f, 0.0f, 1.0f })
			* glm::scale(glm::mat4(1.0f), { m_ScaleBottom.x, m_ScaleBottom.y, 1.0f })
			* pillarVertices[i];
	}
	return tri;
}

void Triangle::DrawTriangle(float position, float toptop, float bottomtop)
{
		Hazel::Renderer2D::DrawQuad(m_PosBottom, m_ScaleBottom, m_Texture,1.0f,m_Color);
		Hazel::Renderer2D::DrawRotatedQuad(m_PosTop, m_Scaletop, 180.0f, m_Texture, 1.0f, m_Color);
}

void TriangleLib::OnUpdate(glm::vec2 CameraPos, Hazel::TimeStep ts)
{
	if (CheckDelete(CameraPos)) m_Trianglelib.erase(m_Trianglelib.begin());
	if (CheckAdd(CameraPos))
	{
		Triangle lastIterator = Triangle(CameraPos.x + 75.0f + 15.0f);
		m_Trianglelib.push_back(lastIterator);
	}
	for (int i = 0; i < m_Trianglelib.size(); i++)
		m_Trianglelib[i].OnUpdate(ts);
}
void TriangleLib::Draw()
{
	for (auto iterator : m_Trianglelib)
		iterator.Draw();
}

bool TriangleLib::CheckGameOver(std::vector<glm::vec2> shipconorpos)
{
	for (auto i : shipconorpos)
	{
		if (i.y >= 42.0f) return true;
		if (i.y <= -42.0f) return true;
	}
	std::vector<glm::vec2> shiptriangle1;
	std::vector<glm::vec2> shiptriangle2;
	shiptriangle1.push_back(shipconorpos[0]);
	shiptriangle1.push_back(shipconorpos[1]);
	shiptriangle1.push_back(shipconorpos[2]);
	shiptriangle2.push_back(shipconorpos[0]);
	shiptriangle2.push_back(shipconorpos[3]);
	shiptriangle2.push_back(shipconorpos[2]);

 	for (auto i : shipconorpos)
	{
		for (auto j : m_Trianglelib)
		{
			glm::vec2 point1 = i;
			std::vector<glm::vec2> triangleTop = j.GetTopTriangleVertices();
			std::vector<glm::vec2> triangleBottom = j.GetBottomTriangleVertices();
			if (PointInTriangle(point1, triangleTop))
				return true;
			else if (PointInTriangle(point1, triangleBottom))
				return true;
		}
	}
	for (auto i : m_Trianglelib)
	{
		std::vector<glm::vec2> tempt = i.GetTopTriangleVertices();
		for (auto j : tempt)
		{
			if (PointInTriangle(j, shiptriangle1)) return true;
			else if (PointInTriangle(j, shiptriangle2)) return true;
		}
		std::vector<glm::vec2> tempb = i.GetBottomTriangleVertices();
		for (auto j : tempb)
		{
			if (PointInTriangle(j, shiptriangle1)) return true;
			else if (PointInTriangle(j, shiptriangle2)) return true;
		}
	}

	return false;
}

bool TriangleLib::CheckDelete(glm::vec2 CameraPos)
{
	std::vector<Triangle>::iterator begin = (m_Trianglelib.begin());
	if ((begin->GetStride().y + 25.0f) <= (CameraPos.x - 75.0f))
		return true;
	else
	return false;
}

bool TriangleLib::CheckAdd(glm::vec2 CameraPos)
{
	std::vector<Triangle>::iterator las = m_Trianglelib.end() - 1;
	if ((las->GetStride().y + 25.0f) <= (CameraPos.x + 75.0f))
		return true;
	else 
		return false;
	
}
float TriangleLib::area(float x1, float y1, float x2, float y2, float x3, float y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

/* A function to check whether point P(x, y) lies inside the triangle formed
   by A(x1, y1), B(x2, y2) and C(x3, y3) */
bool TriangleLib::PointInTriangle(glm::vec2 point, std::vector<glm::vec2> triangleCoridnate )
{
	int x1 = triangleCoridnate[0].x;
	int y1 = triangleCoridnate[0].y;
	int x2 = triangleCoridnate[1].x;
	int y2 = triangleCoridnate[1].y;
	int x3 = triangleCoridnate[2].x;
	int y3 = triangleCoridnate[2].y;
	int x = point.x;
	int y = point.y;

	/* Calculate area of triangle ABC */
	float A = area(x1, y1, x2, y2, x3, y3);

	/* Calculate area of triangle PBC */
	float A1 = area(x, y, x2, y2, x3, y3);

	/* Calculate area of triangle PAC */
	float A2 = area(x1, y1, x, y, x3, y3);

	/* Calculate area of triangle PAB */
	float A3 = area(x1, y1, x2, y2, x, y);

	/* Check if sum of A1, A2 and A3 is same as A */
	return (A == A1 + A2 + A3);
}

