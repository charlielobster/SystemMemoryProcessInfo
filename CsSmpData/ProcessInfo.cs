using System;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using clr_smp_data;

namespace CsSmpData
{
    public class ProcessInfo
    {
        public ProcessInfo() { }
        public ProcessInfo(clr_process_info processInfo)  
        {
            ProcessId = (Int64)processInfo.processId;
            Path = processInfo.path;
            CreationTime = new FileTime(processInfo.creationTime);
            ExitTime = new FileTime(processInfo.exitTime);
            KernelTime = new FileTime(processInfo.kernelTime);
            UserTime = new FileTime(processInfo.userTime);
            ProcessMemoryCounter = new ProcessMemoryCounter(processInfo.processMemoryCounter);
        }
        [Key]
        public int Id { get; set; }
        public UInt64 uProcessId { get { return (UInt64)ProcessId; } }
        public Int64 ProcessId { get; set; }
        [MaxLength(260)]
        public String Path { get; set; }
        public virtual FileTime CreationTime { get; set; }
        public virtual FileTime ExitTime { get; set; }
        public virtual FileTime KernelTime { get; set; }
        public virtual FileTime UserTime { get; set; }
        public virtual ProcessMemoryCounter ProcessMemoryCounter { get; set; }
    }
}
