#include "c_smp_delegate.h"
#include <psapi.h>

using namespace c_smp_data;

c_smp_delegate::~c_smp_delegate() 
{
	free(process_infos);
}

SYSTEM_INFO c_smp_delegate::getSystemInfo()
{
	GetSystemInfo(&sysInfo);
	return sysInfo;
}

FILETIME c_smp_delegate::getSystemTime()
{
	GetSystemTimeAsFileTime(&systemTime);
	return systemTime;
}

MEMORYSTATUSEX c_smp_delegate::getGlobalMemoryStatus()
{
	globalMemoryStatus.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&globalMemoryStatus);
	return globalMemoryStatus;
}

process_info *c_smp_delegate::getProcessInfos(DWORD &count)
{
	HANDLE hProcess;
	DWORD processBufferSize = 0;
	wchar_t path[MAX_PATH];

	if (EnumProcesses(processIds, sizeof(processIds), &processBufferSize)) {

		processCount = processBufferSize / sizeof(DWORD);
		process_infos = (process_info *)malloc(processCount * sizeof(process_info));

		for (unsigned int i = 0; i < processCount; i++) {	
			DWORD processId = processIds[i];
			hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processId);
			if (hProcess != NULL) {

				(process_infos[i]).processId = processId;

				GetModuleFileNameEx(hProcess, 0, path, MAX_PATH);
				int charCount = wcstombs((process_infos[i]).path, path, MAX_PATH);

				GetProcessTimes(hProcess,
					&(process_infos[i]).creationTime,
					&(process_infos[i]).exitTime,
					&(process_infos[i]).kernelTime,
					&(process_infos[i]).userTime);

				GetProcessMemoryInfo(hProcess,
					&(process_infos[i]).processMemoryCounter,
					sizeof((process_infos[i]).processMemoryCounter));

				CloseHandle(hProcess);
			}
			else {
				(process_infos[i]).processId = 0;
			}
		}
	}
	count = processCount;
	return process_infos;
}
