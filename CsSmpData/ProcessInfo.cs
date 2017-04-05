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
           //           Path = processInfo.path;
  /*          ProcessId = processInfo.processId;
            CreationTime = new FileTime(processInfo.creationTime);
            ExitTime = new FileTime(processInfo.exitTime);
            KernelTime = new FileTime(processInfo.kernelTime);
            UserTime = new FileTime(processInfo.userTime);
            ProcessMemoryCounter = new ProcessMemoryCounter(processInfo.counter); 
   */     }
        [Key]
        public int Key { get; set; }
        public Int64 ProcessId { get; set; }

//        public String Path { get; set; }

    //    [ForeignKey("CreationTime")]
    //    public int CreationTime_Key { get; set; }
        public virtual FileTime CreationTime { get; set; }

   //     [ForeignKey("ExitTime")]
  //      public int ExitTime_Key { get; set; }
        public virtual FileTime ExitTime { get; set; }

 //       [ForeignKey("KernelTime")]
//        public int KernelTime_Key { get; set; }
        public virtual FileTime KernelTime { get; set; }

 //       [ForeignKey("UserTime")]
 //       public int UserTime_Key { get; set; }
        public virtual FileTime UserTime { get; set; }

//        [ForeignKey("ProcessMemoryCounter")]
//        public int ProcessMemoryCounter_Key { get; set; }
        public virtual ProcessMemoryCounter ProcessMemoryCounter { get; set; }

    }
}
