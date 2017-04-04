using System;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace CsSmpData
{
    public class ProcessInfo
    {
        [Key]
        public UInt64 Key { get; set; }

        [ForeignKey("CreateTime")]
        public UInt64 CreateTime_Key { get; set; }
        public virtual FileTime CreateTime { get; set; }

        [ForeignKey("ExitTime")]
        public UInt64 ExitTime_Key { get; set; }
        public virtual FileTime ExitTime { get; set; }

        [ForeignKey("ProcessMemoryCounter")]
        public UInt64 ProcessMemoryCounter_Key { get; set; }
        public virtual ProcessMemoryCounter ProcessMemoryCounter { get; set; }

    }
}
