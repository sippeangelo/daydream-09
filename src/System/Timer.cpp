#include "Timer.h"

namespace System
{

Timer::Timer(bool smooth)
{
	m_SmoothFPS = smooth;

	// Store performance frequency
	QueryPerformanceFrequency((LARGE_INTEGER*)&m_Frequency);
	// Save current time
	QueryPerformanceCounter((LARGE_INTEGER*)&m_LastTick);

	//m_LastTick = GetTickCount() + start_offset;
	/*int ThisTick = GetTickCount();

	FPS = 0;
	DeltaTime = 0;
	m_LastTick = ThisTick + start_offset;
	StartTime = ThisTick + start_offset;
	*/

	// FPS counter
	memset(m_TickLog, 0, MAXSAMPLES);
	for (int i = 0; i < MAXSAMPLES; i++)
		m_TickLog[i] = 0;
	m_TickSum = 0;
	m_TickLogIndex = 0;
	m_TickLogCurrentValueCount = 0;
}

void Timer::SmoothFPS(bool mode)
{
	m_SmoothFPS = mode;
}

void Timer::Update()
{
	// Save current time
	QueryPerformanceCounter((LARGE_INTEGER*)&m_ThisTick);

	// Calculate difference in MS
	m_DeltaTime = ((float)(m_ThisTick - m_LastTick) * 1000.0f) / m_Frequency;

	// Update last time
	m_LastTick = m_ThisTick;

	// Calculate FPS
	m_FPS = 1000 / m_DeltaTime;

	// FPS smoothing
	if (m_SmoothFPS)
	{	
		m_TickSum -= m_TickLog[m_TickLogIndex];
		m_TickSum += m_FPS;
		m_TickLog[m_TickLogIndex] = m_FPS;
		if (++m_TickLogIndex == MAXSAMPLES)
			m_TickLogIndex = 0;
		if (m_TickLogCurrentValueCount < MAXSAMPLES)
			m_TickLogCurrentValueCount++;

		m_FPS = m_TickSum / m_TickLogCurrentValueCount;
	}


	/*
	__int64 freq, start, end, diff;

	// start
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
	QueryPerformanceCounter((LARGE_INTEGER*)&start);

	printf("QueryPerformanceFrequency = %i\n", freq);
	printf("QueryPerformanceCounter = %i\n", start);

	// code to measure
	Sleep(1234);

	// end
	QueryPerformanceCounter((LARGE_INTEGER*)&end);

	printf("Difference: %u\n", (end - start));

	diff = ((end - start) * 1000) / freq;

	unsigned int milliseconds = (unsigned int)(diff & 0xffffffff);
	printf("It took %i ms\n", diff);*/

	//info.Delta = DeltaTime;

	//TimerInfo info;

	/*
	// FPS Counter
	if (diff == 0)
		diff = 1;

	m_TickSum += diff;
	m_TickSum -= m_TickLog[m_TickLogIndex];
	m_TickLog[m_TickLogIndex] = diff;
	if (++m_TickLogIndex == MAXSAMPLES)
		m_TickLogIndex = 0;
	if (m_TickLogCurrentValueCount < MAXSAMPLES)
		m_TickLogCurrentValueCount++;

	FPS = ((float)m_TickSum / m_TickLogCurrentValueCount);

	info.FPS = FPS;

	// Update last tick
	m_LastTick = ThisTick;
	*/

	//return info;
}

float Timer::GetDelta()
{
	return m_DeltaTime;
}

float Timer::GetFPS()
{
	return m_FPS;
}

}