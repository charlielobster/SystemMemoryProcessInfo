using System.ComponentModel.DataAnnotations;
using clr_smp_data;
using System;

namespace CsSmpData
{
    public class FileTime
    {
        public FileTime() { }
        public FileTime(file_time time)
        {
            LowDateTime = (Int64)time.dwLowDateTime;
            HighDateTime = (Int64)time.dwHighDateTime;
        }
        [Key]
        public int Id { get; set; }
        public UInt64 uLowDateTime { get { return (UInt64)LowDateTime;  } }
        public UInt64 uHighDateTime { get { return (UInt64)HighDateTime; } }
        public Int64 LowDateTime { get; set; }
        public Int64 HighDateTime { get; set; }
    }
}
