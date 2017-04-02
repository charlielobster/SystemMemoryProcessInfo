using CsSmpData;
using clr_smp_data;
using System;

namespace CsSmpTest
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var context = new SmpContext())
            {
                var info = new system_info();
                var sysInfo = new SystemInfo(info);

                var time = new file_time();
                var fileTime = new FileTime(time);

                var status = new global_memory_status();
                var memStatus = new GlobalMemoryStatus(status);

                context.SystemInfoes.Add(sysInfo);
                context.FileTimes.Add(fileTime);
                context.MemoryStatuses.Add(memStatus);
                context.SaveChanges();

                foreach (var si in context.SystemInfoes)
                {
                    Console.WriteLine(si.Key);
                }
            }

            Console.WriteLine("Press any key to exit...");
            Console.ReadKey();

        }
    }
}
