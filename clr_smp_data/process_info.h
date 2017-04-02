#pragma once
#include <psapi.h>
#include "process_memory_counter.h"

namespace clr_smp_data {
	public ref class process_info {
	public:
		process_info() {
			DWORD processIds[1024];
			DWORD processBufferSize = 0;
			DWORD processCount;

			// Get the list of process identifiers
			if (EnumProcesses(processIds, sizeof(processIds), &processBufferSize)) {

				// Calculate how many process identifiers were actually returned.
				processCount = processBufferSize / sizeof(DWORD);
				counters = gcnew array< process_memory_counter^ >(processCount);
				for (unsigned int i = 0; i < processCount; i++) {
//					ProcessInfo(processIds[i]);
				}
			}
		}
		array< process_memory_counter^ >^ counters;
	};
};