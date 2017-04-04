#ifndef _PROCESS_INFO_H_
#define _PROCESS_INFO_H_

#include <windows.h>
#include <psapi.h>

namespace c_smp_data
{
	struct process_info
	{
		DWORD processId;
		char path[MAX_PATH];
		FILETIME creationTime;
		FILETIME exitTime;
		FILETIME kernelTime;
		FILETIME userTime;
		PROCESS_MEMORY_COUNTERS processMemoryCounter;
	};
};

#endif