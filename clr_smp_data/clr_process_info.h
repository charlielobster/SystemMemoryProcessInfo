#pragma once
#include "c_smp_delegate.h"
#include "file_time.h"
#include "process_memory_counter.h"

using namespace c_smp_data;

namespace clr_smp_data 
{
	public ref class clr_process_info 
	{
	public:
		clr_process_info(process_info p) 
		{
			processId = (unsigned __int64)p.processId;
			// path = p.path;
			creationTime = gcnew file_time(p.creationTime);
			exitTime = gcnew file_time(p.exitTime);
			kernelTime = gcnew file_time(p.kernelTime);
			userTime = gcnew file_time(p.userTime);
			counter = gcnew process_memory_counter(p.processMemoryCounter);
		}
		~clr_process_info()
		{
			delete creationTime;
			delete exitTime;
			delete kernelTime;
			delete userTime;
			delete counter;
		}
		property unsigned __int64 processId;
		// string path;
		property file_time ^creationTime;
		property file_time ^exitTime;
		property file_time ^kernelTime;
		property file_time ^userTime;
		property process_memory_counter ^counter;
	};
};