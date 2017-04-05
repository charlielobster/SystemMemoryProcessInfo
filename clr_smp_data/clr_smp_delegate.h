// clr_smp_data.h
#pragma once
#include "file_time.h"
#include "clr_process_info.h"
#include "system_info.h"
#include "global_memory_status.h"
#include "process_memory_counter.h"

namespace clr_smp_data 
{
	public ref class clr_smp_delegate 
	{
	public:
		property file_time ^systemTime;
		property system_info ^systemInfo;
		property global_memory_status ^globalMemoryStatus;
		property array< clr_process_info^ >^ processInfos;
		property int infoCount;
		clr_smp_delegate()
		{
			c_smp_delegate delegate;

			systemTime = gcnew file_time(delegate.getSystemTime());
			systemInfo = gcnew system_info(delegate.getSystemInfo());
			globalMemoryStatus = gcnew global_memory_status(delegate.getGlobalMemoryStatus());

			DWORD processCount;
			process_info *c_processInfos = delegate.getProcessInfos(processCount);
			infoCount = delegate.getInfoCount();
			processInfos = gcnew array< clr_process_info ^>(infoCount);
			int j = 0;
			for (DWORD i = 0; i < processCount; i++) {
				if (c_processInfos[i].processId != 0) {
					processInfos[j++] = gcnew clr_process_info(c_processInfos[i]);
				}
			}
		}	
		~clr_smp_delegate()
		{
			delete systemTime;
			delete systemInfo;
			delete globalMemoryStatus;
			for (int i = 0; i < infoCount; i++) {
				delete processInfos[i];
			}
		}
	};
};

