#pragma once

namespace Hazel {
	class TimeStep
	{
	public:
		TimeStep(float time = 0.0f)
			:m_Time(time)
		{

		}
		operator float() { return m_Time; }
		float GetSecond() const { return m_Time; }
		float GetMiliSecond() const { return m_Time * 1000; }
	private:
		float m_Time;

	};
}
