#ifndef _SMP_DATA_DELEGATE_H_
#define _SMP_DATA_DELEGATE_H_

#include <windows.h>

namespace c_smp_data 
{
	class smp_data_delegate 
	{
	public:
		smp_data_delegate();

		// system info container
		SYSTEM_INFO sysInfo;

		// current system time as file time
		FILETIME fileTime;

		// global memory info container
		MEMORYSTATUSEX globalMemoryInfo;

		// process Id info
		DWORD processIds[1024];
		DWORD processCount;

	private:
		void GetAndPrintSystemTimeAsFileTime();
		void GetAndPrintProcessTimes(HANDLE hProcess);
		void GetAndPrintProcessMemoryInfo(HANDLE hProcess);
		void ProcessInfo(DWORD processID);
		void GetAndPrintSystemInfo();
		bool GetAndPrintGlobalMemoryInfo();
		void GetAndPrintProcessInfo();
	};
};

#endif