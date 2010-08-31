#include "Thread.h"

using namespace System;

Thread::Thread(LPTHREAD_START_ROUTINE function)
{
	// LPTHREAD_START_ROUTINE is already a pointer
	m_ThreadAddress = function;
}

void Thread::Start()
{
	m_hThread = CreateThread(NULL, NULL, *m_ThreadAddress, NULL, 0, NULL);
}

void Thread::Stop()
{
	TerminateThread(m_hThread, 1);
}

void Thread::Pause()
{
	SuspendThread(m_hThread);
}

void Thread::Resume()
{
	ResumeThread(m_hThread);
}