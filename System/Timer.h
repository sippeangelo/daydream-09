#include <windows.h>

namespace System
{

class Timer
{
public:
	struct TimerInfo
	{
		int Delta;
		int FPS;
	};

	Timer();
	Timer(int start);
	TimerInfo Update();
	int Delta;
	int FPS;
	int StartTime;
private:
	int m_LastTick;

	// My FPS counter
	static const int MAXSAMPLES = 100;
	int m_TickLog[100];
};

}