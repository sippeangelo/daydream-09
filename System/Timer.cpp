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

	// FPS counter
	//memset(m_TickLog, 0, MAXSAMPLES);
	for (int i = 0; i < MAXSAMPLES; i++)
		m_TickLog[i] = 0;
	m_TickSum = 0;
	m_TickLogIndex = 0;
	m_TickLogCurrentValueCount = 0;

	QueryPerformanceFrequency(&m_TicksPerSecond);
}

Timer::TimerInfo Timer::Update()
{
	TimerInfo info;

	// Get current tick
	int ThisTick; 
	LARGE_INTEGER liThisTick; 
	QueryPerformanceCounter(&liThisTick);
	ThisTick = liThisTick.QuadPart;

	// Delta
	int diff = (ThisTick - m_LastTick);
	Delta = diff;
	info.Delta = Delta;

	// FPS Counter
	/*if (diff == 0)
		diff = 1;

	m_TickSum += diff;
	m_TickSum -= m_TickLog[m_TickLogIndex];
	m_TickLog[m_TickLogIndex] = diff;
	if (++m_TickLogIndex == MAXSAMPLES)
		m_TickLogIndex = 0;
	if (m_TickLogCurrentValueCount <= MAXSAMPLES)
		m_TickLogCurrentValueCount++;

	FPS = m_TicksPerSecond.QuadPart / ((float)m_TickSum / m_TickLogCurrentValueCount);

	info.FPS = FPS;*/

	// Update last tick
	m_LastTick = ThisTick;

	return info;
}