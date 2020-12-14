#pragma once
namespace Hazel
{
	class Time
	{
	public:
		float CurrentTime();
		void SetTimeStart(float& timestart) { m_TimeStart = timestart; }
		
		void SetTimeEnd() {};
		float Tonow() 
		{
			m_TimeEnd = CurrentTime();
			return Strike();
		}
		float Strike() { return m_TimeEnd - m_TimeStart; }
	private:
		float m_TimeEnd;
		float m_TimeStart;
	};
}