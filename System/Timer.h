#include <windows.h>
#include <stdio.h>

namespace System
{

class Timer
{
public:
	/*struct TimerInfo
	{
		int Delta;
		int Delta_min;
		int Delta_max;
		float FPS;
	};*/

	Timer();
	bool SmoothFPS();
	void SmoothFPS(bool mode);
	void Update();
	float GetDelta();
	float GetFPS();

	/*
	float Time;
	float DeltaTime;
	float FPS;
	float TPS;
	int StartTime;*/
private:
	/*int m_LastTick;

	LARGE_INTEGER m_TicksPerSecond;
	*/

	// FPS counter
	static const int MAXSAMPLES = 100;
	float m_TickLog[MAXSAMPLES];
	float m_TickSum;
	int m_TickLogIndex;
	int m_TickLogCurrentValueCount;

	__int64 m_Frequency;
	__int64 m_LastTick;
	__int64 m_ThisTick;
	float m_DeltaTime;
	float m_FPS;
	bool m_SmoothFPS;
};

}