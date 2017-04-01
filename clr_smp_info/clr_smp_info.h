// clr_smp_info.h
#pragma once
#include "system_info.h"

namespace clr_smp_info {

	public ref class c_smp_info
	{
		system_info systemInfo;
		c_smp_info(SYSTEM_INFO info) : systemInfo(info) { 
		}
	};
};
