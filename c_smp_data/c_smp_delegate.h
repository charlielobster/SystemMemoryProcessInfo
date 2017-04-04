#ifndef _SMP_DATA_DELEGATE_H_
#define _SMP_DATA_DELEGATE_H_

#include <windows.h>
#include "process_info.h"

namespace c_smp_data 
{
	class c_smp_delegate
	{
	public:
		~c_smp_delegate();
		SYSTEM_INFO getSystemInfo();
		FILETIME getSystemTime();
		MEMORYSTATUSEX getGlobalMemoryStatus();
		process_info *getProcessInfos(DWORD &count);

	private:
		FILETIME systemTime;
		SYSTEM_INFO sysInfo;
		MEMORYSTATUSEX globalMemoryStatus;
		DWORD processIds[1024];
		DWORD processCount;
		process_info *process_infos;
	};
};

#endif