#pragma once
#include <windows.h>

namespace clr_smp_data {
	public ref class global_memory_status {
	public:
		global_memory_status() {
			MEMORYSTATUSEX globalMemoryInfo;
			globalMemoryInfo.dwLength = sizeof(MEMORYSTATUSEX);
			if (GlobalMemoryStatusEx(&globalMemoryInfo)) {
				dwLength = globalMemoryInfo.dwLength;
				dwMemoryLoad = globalMemoryInfo.dwMemoryLoad;
				ullTotalPhys = globalMemoryInfo.ullTotalPhys;
				ullAvailPhys = globalMemoryInfo.ullAvailPhys;
				ullTotalPageFile = globalMemoryInfo.ullTotalPageFile;
				ullAvailPageFile = globalMemoryInfo.ullAvailPageFile;
				ullTotalVirtual = globalMemoryInfo.ullTotalVirtual;
				ullAvailVirtual = globalMemoryInfo.ullAvailVirtual;
				ullAvailExtendedVirtual = globalMemoryInfo.ullAvailExtendedVirtual;
			}
		}
		unsigned long dwLength;
		unsigned long dwMemoryLoad;
		unsigned long ullTotalPhys;
		unsigned long ullAvailPhys;
		unsigned long ullTotalPageFile;
		unsigned long ullAvailPageFile;
		unsigned long ullTotalVirtual;
		unsigned long ullAvailVirtual;
		unsigned long ullAvailExtendedVirtual;
	};
};