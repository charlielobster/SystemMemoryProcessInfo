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
		clr_smp_delegate() {
			c_smp_delegate delegate;
			systemTime.clone(delegate.getSystemTime());
			systemInfo.clone(delegate.getSystemInfo());
			globalMemoryStatus.clone(delegate.getGlobalMemoryStatus());

		}
		system_info systemInfo;
		global_memory_status globalMemoryStatus;
		file_time systemTime;
		array< clr_process_info^ >^ processInfos;
	};
};

