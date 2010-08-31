#include <process.h>
#include <windows.h>

namespace System
{
	class Thread
	{
	public:
		Thread(LPTHREAD_START_ROUTINE function); // LPTHREAD_START_ROUTINE is already a pointer
		void Start();
		void Stop();
		void Pause();
		void Resume();
	private:
		HANDLE m_hThread;
		LPTHREAD_START_ROUTINE m_ThreadAddress;
	};
}