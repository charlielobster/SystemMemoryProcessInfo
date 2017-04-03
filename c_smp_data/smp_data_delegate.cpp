#include "smp_data_delegate.h"

#include <stdio.h>
#include <psapi.h>
#include <d3d12.h>
#include <tchar.h>
#include <pdh.h>

using namespace c_smp_data;

smp_data_delegate::smp_data_delegate() 
{
	GetAndPrintSystemTimeAsFileTime();

	// Print System Info	
	GetAndPrintSystemInfo();

	// Print Global Memory Info
	if (!GetAndPrintGlobalMemoryInfo()) {
		printf("GET AND PRINT GLOBAL MEMORY INFO FAILURE");
	}

	GetAndPrintProcessInfo();
}

void smp_data_delegate::GetAndPrintSystemTimeAsFileTime()
{
	GetSystemTimeAsFileTime(&fileTime);
	printf("\n	\
		System As File Time: Low: %lu\t\tHigh: %lu\n \
		\n",
		fileTime.dwLowDateTime,
		fileTime.dwHighDateTime);
}

void smp_data_delegate::GetAndPrintProcessTimes(HANDLE hProcess)
{
	FILETIME creationTime, exitTime, kernelTime, userTime;
	GetProcessTimes(hProcess, &creationTime, &exitTime, &kernelTime, &userTime);
	printf("\n\t    \
		Handle:               0x%016llx\n\t \
		Creation Time:        Low: %lu\t\tHigh: %lu\n\t \
		Exit Time             Low: %lu\t\tHigh: %lu\n\t \
		Kernel Time           Low: %lu\t\tHigh: %lu\n\t \
		User Time             Low: %lu\t\tHigh: %lu\n \
		\n",
		hProcess,
		creationTime.dwLowDateTime,
		creationTime.dwHighDateTime,
		exitTime.dwLowDateTime,
		exitTime.dwHighDateTime,
		kernelTime.dwLowDateTime,
		kernelTime.dwHighDateTime,
		userTime.dwLowDateTime,
		userTime.dwHighDateTime);
}

void smp_data_delegate::GetAndPrintProcessMemoryInfo(HANDLE hProcess)
{
	PROCESS_MEMORY_COUNTERS pmc;
	if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc))) {

		printf("\n\
			Handle:                          0x%016llx\n \
			Page Fault Count:                %lu\n \
			Peak Working Set Size:           %lu\n \
			Working Set Size:                %lu\n \
			Quota Peak Paged Pool Usage:     %lu\n \
			Quota Paged Pool Usage:          %lu\n \
			Quota Peak Non Paged Pool Usage: %lu\n \
			Quota Non Paged Pool Usage:      %lu\n \
			Pagefile Usage:                  %lu\n \
			Peak Pagefile Usage:             %lu\n \
			\n",
			hProcess,
			pmc.PageFaultCount,
			pmc.PeakWorkingSetSize,
			pmc.WorkingSetSize,
			pmc.QuotaPeakPagedPoolUsage,
			pmc.QuotaPagedPoolUsage,
			pmc.QuotaPeakNonPagedPoolUsage,
			pmc.QuotaNonPagedPoolUsage,
			pmc.PagefileUsage,
			pmc.PeakPagefileUsage);

	}
	else {
		printf("\tFailed to get process memory info for %u\n", hProcess);
	}
}

void smp_data_delegate::ProcessInfo(DWORD processID)
{
	HANDLE hProcess;

	// Print the process identifier.
	printf("\t\t\tProcess ID: %lu\n", processID);

	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);
	if (hProcess == NULL) {
		printf("\t\t\tFailed to open handle to %lu\n", processID);
		return;
	}

	TCHAR path[MAX_PATH];
	if (GetModuleFileNameEx(hProcess, 0, path, MAX_PATH)) {
		printf("\t\t\tPath: %s\n", path);
	}

	GetAndPrintProcessTimes(hProcess);
	GetAndPrintProcessMemoryInfo(hProcess);

	CloseHandle(hProcess);
}

void smp_data_delegate::GetAndPrintSystemInfo()
{
	GetSystemInfo(&sysInfo);
	printf("\n \
		\tSystem Info:\n \
		\tOEM ID:                      %lu\n \
		\tProcessor Architecture:      %u\n \
		\tPage Size:                   %lu\n \
		\tMinimum Application Address: 0x%016llx\n \
		\tMaximum Application Address: 0x%016llx\n \
		\tActive Processor Mask:       %lu\n \
		\tNumber of Processors:        %lu\n \
		\tAllocation Granularity:      %lu\n \
		\tProcessor Type:              %lu\n \
		\tProcessor Level:             %u\n \
		\tProcessor Revision:          %u\n \
		\n",
		sysInfo.dwOemId,
		sysInfo.wProcessorArchitecture,
		sysInfo.dwPageSize,
		sysInfo.lpMinimumApplicationAddress,
		sysInfo.lpMaximumApplicationAddress,
		sysInfo.dwActiveProcessorMask,
		sysInfo.dwNumberOfProcessors,
		sysInfo.dwAllocationGranularity,
		sysInfo.dwProcessorType,
		sysInfo.wProcessorLevel,
		sysInfo.wProcessorRevision
	);
}

bool smp_data_delegate::GetAndPrintGlobalMemoryInfo()
{
	globalMemoryInfo.dwLength = sizeof(MEMORYSTATUSEX);
	if (GlobalMemoryStatusEx(&globalMemoryInfo)) {
		printf("\n \
			Global Memory Info:\n \
			Length:                     %lu\n \
			Memory Load:                %lu\n \
			Total Physical:             %llu\n \
			Available Physical:         %llu\n \
			Total Page File:            %llu\n \
			Available Page File:        %llu\n \
			Total Virtual:              %llu\n \
			Available Virtual:          %llu\n \
			Available Extended Virtual: %llu\n \
			\n",
			globalMemoryInfo.dwLength,
			globalMemoryInfo.dwMemoryLoad,
			globalMemoryInfo.ullTotalPhys,
			globalMemoryInfo.ullAvailPhys,
			globalMemoryInfo.ullTotalPageFile,
			globalMemoryInfo.ullAvailPageFile,
			globalMemoryInfo.ullTotalVirtual,
			globalMemoryInfo.ullAvailVirtual,
			globalMemoryInfo.ullAvailExtendedVirtual
		);
		return true;
	}
	return false;
}

void smp_data_delegate::GetAndPrintProcessInfo()
{
	DWORD processBufferSize = 0;
	printf("\n\t\t\tProcess Info:\n");

	// Get the list of process identifiers
	if (EnumProcesses(processIds, sizeof(processIds), &processBufferSize)) {

		// Calculate how many process identifiers were actually returned.
		processCount = processBufferSize / sizeof(DWORD);
		printf("\t\t\tReturned %lu processes in array of size %lu\n", processCount, processBufferSize);
		for (unsigned int i = 0; i < processCount; i++) {
			printf("\n\t\t\tInfo for the %dth process\n", i);
			ProcessInfo(processIds[i]);
		}
	}
}