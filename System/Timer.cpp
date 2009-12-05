#include "Timer.h"

using namespace System;

Timer::Timer()
{
	Timer(0);
}

Timer::Timer(int start_offset)
{
	int ThisTick = GetTickCount();

	FPS = 0;
	Delta = 0;
	m_LastTick = ThisTick + start_offset;
	StartTime = ThisTick + start_offset;
}

Timer::TimerInfo Timer::Update()
{
	TimerInfo inf;

	// Get current tick
	int ThisTick = GetTickCount(); 

	// Delta
	int diff = (ThisTick - m_LastTick);
	Delta = diff;
	inf.Delta = Delta;

	// FPS
	// HACK: This FPS counter is choppy and buggy, don't want to use it yet
	/*m_TickSum -= m_TickList[m_TickIndex];
	m_TickSum += diff;
	m_TickList[m_TickIndex] = diff;
	if (++m_TickIndex == MAXSAMPLES)
		m_TickIndex = 0;
	FPS = (int)(1000 / ((float)m_TickSum / MAXSAMPLES));
	inf.FPS = FPS;*/

	if (diff == 0)
		diff = 1;

	FPS = 1000 / diff;

	// Update last tick
	m_LastTick = ThisTick;

	return inf;
}