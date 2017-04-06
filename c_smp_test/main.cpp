#include "c_smp_delegate.h"
#include <stdio.h>

using namespace c_smp_data;

int main(void)
{	
	c_smp_delegate delegate;

	FILETIME fileTime = delegate.getSystemTime();
	printf("\n	\
		System As File Time: Low: %lu\t\tHigh: %lu\n \
		\n",
		fileTime.dwLowDateTime,
		fileTime.dwHighDateTime
	);

	SYSTEM_INFO sysInfo = delegate.getSystemInfo();
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

	MEMORYSTATUSEX globalMemoryStatus = delegate.getGlobalMemoryStatus();
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
		globalMemoryStatus.dwLength,
		globalMemoryStatus.dwMemoryLoad,
		globalMemoryStatus.ullTotalPhys,
		globalMemoryStatus.ullAvailPhys,
		globalMemoryStatus.ullTotalPageFile,
		globalMemoryStatus.ullAvailPageFile,
		globalMemoryStatus.ullTotalVirtual,
		globalMemoryStatus.ullAvailVirtual,
		globalMemoryStatus.ullAvailExtendedVirtual
	);

	DWORD processCount; 
	process_info *infos;
	infos = delegate.getProcessInfos(processCount);
	printf("\t\t\t\tReturned %lu processes\n", processCount);

	for (unsigned int i = 0; i < processCount; i++) {

		process_info info = infos[i];
		if (info.processId != 0) {
			printf("\t\t\t\tProcess Information for index %d and Id %lu\n", i, info.processId);
			printf("\t\t\t\tPath: %s\n", info.path);
			printf("\n    \
				Creation Time:        Low: %lu\t\tHigh: %lu\n \
				Exit Time             Low: %lu\t\tHigh: %lu\n \
				Kernel Time           Low: %lu\t\tHigh: %lu\n \
				User Time             Low: %lu\t\tHigh: %lu\n \
				\n",
				info.creationTime.dwLowDateTime,
				info.creationTime.dwHighDateTime,
				info.exitTime.dwLowDateTime,
				info.exitTime.dwHighDateTime,
				info.kernelTime.dwLowDateTime,
				info.kernelTime.dwHighDateTime,
				info.userTime.dwLowDateTime,
				info.userTime.dwHighDateTime
			);

			printf("\n \
				Process Memory Counter Information:\n \
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
				info.processMemoryCounter.PageFaultCount,
				info.processMemoryCounter.PeakWorkingSetSize,
				info.processMemoryCounter.WorkingSetSize,
				info.processMemoryCounter.QuotaPeakPagedPoolUsage,
				info.processMemoryCounter.QuotaPagedPoolUsage,
				info.processMemoryCounter.QuotaPeakNonPagedPoolUsage,
				info.processMemoryCounter.QuotaNonPagedPoolUsage,
				info.processMemoryCounter.PagefileUsage,
				info.processMemoryCounter.PeakPagefileUsage
			);
		}
	}

	return 0;
}


