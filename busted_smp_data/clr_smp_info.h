// clr_smp_info.h
#pragma once
#include "system_info.h"
#include "file_time.h"

namespace clr_smp_info {

	public ref class clr_smp_info
	{
		system_info systemInfo;
		file_time time;
		clr_smp_info() { }
	};
};
