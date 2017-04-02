// clr_smp_data.h

#pragma once
#include <windows.h>

using namespace System;

namespace clr_smp_data {

	public ref class file_time {
	public:
		file_time() {
			FILETIME fileTime;
			GetSystemTimeAsFileTime(&fileTime);
			dwLowDateTime = fileTime.dwLowDateTime;
			dwHighDateTime = fileTime.dwHighDateTime;
		}
		unsigned long dwLowDateTime;
		unsigned long dwHighDateTime;
	};

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

	public ref class system_info {
	public:
		system_info() {
			SYSTEM_INFO info;
			GetSystemInfo(&info);
			wProcessorArchitecture = info.wProcessorArchitecture;
			dwPageSize = info.dwPageSize;
			lpMinimumApplicationAddress = (unsigned long)info.lpMinimumApplicationAddress;
			lpMaximumApplicationAddress = (unsigned long)info.lpMaximumApplicationAddress;
			dwActiveProcessorMask = info.dwActiveProcessorMask;
			dwNumberOfProcessors = info.dwNumberOfProcessors;
			dwProcessorType = info.dwProcessorType;
			dwAllocationGranularity = info.dwAllocationGranularity;
			wProcessorLevel = info.wProcessorLevel;
			wProcessorRevision = info.wProcessorRevision;
		}
		unsigned int wProcessorArchitecture;
		unsigned long dwPageSize;
		unsigned long lpMinimumApplicationAddress;
		unsigned long lpMaximumApplicationAddress;
		unsigned long dwActiveProcessorMask;
		unsigned long dwNumberOfProcessors;
		unsigned long dwProcessorType;
		unsigned long dwAllocationGranularity;
		unsigned int wProcessorLevel;
		unsigned int wProcessorRevision;
	};
}
