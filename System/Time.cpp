#include "Time.h"

namespace System
{

Time::Time()
{
	m_LastTick = (int)GetTickCount();
}

Time::Time(int start)
{
	m_LastTick = start;
}

float Time::GetDifference()
{
	int ThisTick = GetTickCount(); 
	float diff = (ThisTick - m_LastTick);
	m_LastTick = ThisTick;

	/*time_t newTime = time(NULL);
	float deltaTime = newTime - currentTime;
    currentTime = newTime;*/

	return diff;
}

}