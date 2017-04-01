namespace CsSmpData
{
    using clr_smp_info;

    public class SystemInfo
    {
        public SystemInfo (system_info info)
        {
            wProcessorArchitecture = info.wProcessorArchitecture;
            dwPageSize = info.dwPageSize;
            lpMinimumApplicationAddress = info.lpMinimumApplicationAddress;
            lpMaximumApplicationAddress = info.lpMaximumApplicationAddress;
            dwActiveProcessorMask = info.dwActiveProcessorMask;
            dwNumberOfProcessors = info.dwNumberOfProcessors;
            dwProcessorType = info.dwProcessorType;
            dwAllocationGranularity = info.dwAllocationGranularity;
            wProcessorLevel = info.wProcessorLevel;
            wProcessorRevision = info.wProcessorRevision;
        }
        public uint wProcessorArchitecture { get; set; }
        public ulong dwPageSize { get; set; }
        public long lpMinimumApplicationAddress { get; set; }
        public long lpMaximumApplicationAddress { get; set; }
        public ulong dwActiveProcessorMask { get; set; }
        public ulong dwNumberOfProcessors { get; set; }
        public ulong dwProcessorType { get; set; }
        public ulong dwAllocationGranularity { get; set; }
        public uint wProcessorLevel { get; set;  }
        public uint wProcessorRevision { get; set; }
    }
}
