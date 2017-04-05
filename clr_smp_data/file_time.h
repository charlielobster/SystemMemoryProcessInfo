#pragma once
#include <windows.h>
using namespace System;

namespace clr_smp_data 
{
	public ref class file_time 
	{
	public:
		file_time(FILETIME f) 
		{
			dwLowDateTime = f.dwLowDateTime;
			dwHighDateTime = f.dwHighDateTime;
		}	
		property unsigned __int64 dwLowDateTime;
		property unsigned __int64 dwHighDateTime;
	};
};