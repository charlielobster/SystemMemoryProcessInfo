#pragma once
#include "c_smp_delegate.h"
#include "file_time.h"
#include "process_memory_counter.h"

using namespace c_smp_data;

namespace clr_smp_data {
	public ref class clr_process_info {
	public:
		clr_process_info(process_info p) : 
			processId(p.processId),
			creationTime(p.creationTime), 
			exitTime(p.exitTime),
			kernelTime(p.kernelTime),
			userTime(p.userTime),
			counter(p.processMemoryCounter) { }
		unsigned __int64 processId;
		file_time creationTime;
		file_time exitTime;
		file_time kernelTime;
		file_time userTime;
		process_memory_counter counter;
	};
};