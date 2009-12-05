#include <windows.h>

namespace System
{

class Timer
{
public:
	struct TimerInfo
	{
		int Delta;
		float FPS;
	};

	Timer();
	Timer(int start);
	TimerInfo Update();
	int Delta;
	float FPS;
	int StartTime;
private:
	int m_LastTick;

	// FPS counter
	static const int MAXSAMPLES = 100;
	int m_TickLog[MAXSAMPLES];
	int m_TickSum;
	int m_TickLogIndex;
	int m_TickLogCurrentValueCount;
};

}