using CsSmpData;
using clr_smp_data;
using System;
using System.Linq;

namespace CsSmpTest
{
    class Program
    {
        static void Main(string[] args)
        {
            var smp_delegate = new clr_smp_delegate();
            var systemItem = smp_delegate.systemTime;
            var memoryStatus = smp_delegate.globalMemoryStatus;
            var processInfos = smp_delegate.processInfos;

            using (var context = new SmpContext())
            {
                for (var i = 0; i < smp_delegate.infoCount; i++)
                {                 
                    var cliProcessInfo = smp_delegate.processInfos[i];
                  
                    var creationTime = new FileTime(cliProcessInfo.creationTime);
                    context.FileTimes.Add(creationTime);

                    var exitTime = new FileTime(cliProcessInfo.exitTime);
                    context.FileTimes.Add(exitTime);

                    var kernelTime = new FileTime(cliProcessInfo.kernelTime);
                    context.FileTimes.Add(kernelTime);

                    var userTime = new FileTime(cliProcessInfo.userTime);
                    context.FileTimes.Add(userTime);

                    var pmc = new ProcessMemoryCounter(cliProcessInfo.counter);
                    context.ProcessMemoryCounters.Add(pmc);

                    var processInfo = new ProcessInfo();
                    processInfo.ProcessId = (Int64)cliProcessInfo.processId;
                    processInfo.CreationTime = creationTime;
                    processInfo.ExitTime = exitTime;
                    processInfo.KernelTime = kernelTime;
                    processInfo.UserTime = userTime;
                    processInfo.ProcessMemoryCounter = pmc;
                    context.ProcessInfos.Add(processInfo);
                }
                context.SaveChanges();

                var maxFaultCount = context.ProcessMemoryCounters.Max(p => p.PageFaultCount);
                var mostPageFaults = context.ProcessInfos.Where(p => p.ProcessMemoryCounter.PageFaultCount == maxFaultCount);
                Console.WriteLine("The process Id with the most page faults is " + 
                    mostPageFaults.FirstOrDefault().ProcessId + " with " + maxFaultCount + " faults. ");
            }
            Console.WriteLine("Press any key to exit...");
            Console.ReadKey();

        }
    }
}
