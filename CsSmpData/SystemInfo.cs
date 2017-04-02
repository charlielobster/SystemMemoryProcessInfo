using System.ComponentModel.DataAnnotations;
using clr_smp_data;

namespace CsSmpData
{
    public class SystemInfo
    {
        public SystemInfo() { }
        public SystemInfo (system_info info)
        {
            wProcessorArchitecture = (int)info.wProcessorArchitecture;
            dwPageSize = info.dwPageSize;
            lpMinimumApplicationAddress = info.lpMinimumApplicationAddress;
            lpMaximumApplicationAddress = info.lpMaximumApplicationAddress;
            dwActiveProcessorMask = info.dwActiveProcessorMask;
            dwNumberOfProcessors = info.dwNumberOfProcessors;
            dwProcessorType = info.dwProcessorType;
            dwAllocationGranularity = info.dwAllocationGranularity;
            wProcessorLevel = (int)info.wProcessorLevel;
            wProcessorRevision = (int)info.wProcessorRevision;           
        }
        [Key]
        public int Key { get; set;  }
        public int wProcessorArchitecture { get; set; }
        public long dwPageSize { get; set; }
        public long lpMinimumApplicationAddress { get; set; }
        public long lpMaximumApplicationAddress { get; set; }
        public long dwActiveProcessorMask { get; set; }
        public long dwNumberOfProcessors { get; set; }
        public long dwProcessorType { get; set; }
        public long dwAllocationGranularity { get; set; }
        public int wProcessorLevel { get; set;  }
        public int wProcessorRevision { get; set; }
    }
}
