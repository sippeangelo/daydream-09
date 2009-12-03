#include <windows.h>

namespace System
{

class Time
{
public:
	Time();
	Time(int start);
	int GetTime();
	float GetDifference();
private:
	int m_LastTick;
};

}