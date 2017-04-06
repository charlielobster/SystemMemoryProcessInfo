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

            var systemTime = smp_delegate.systemTime;
            Console.WriteLine("System As File Time: " + 
                "Low: " +  systemTime.dwLowDateTime + 
                "\tHigh: " + systemTime.dwHighDateTime);

            var systemInfo = smp_delegate.systemInfo;
            Console.WriteLine(
                "\tSystem Info:\n" +
                "\tOEM ID:                        {0,16:0}\n" +
                "\tProcessor Architecture:        {1,16:0}\n" +
                "\tPage Size:                   0x{2,16:X16}\n" +
                "\tMinimum Application Address: 0x{3,16:X16}\n" +
                "\tMaximum Application Address: 0x{4,16:X16}\n" +
                "\tActive Processor Mask:       0x{5,16:X16}\n" +
                "\tNumber of Processors:          {6,16}\n" +
                "\tAllocation Granularity:      0x{7,16:X16}\n" +
                "\tProcessor Type:                {8,16}\n" +
                "\tProcessor Level:               {9,16}\n" +
                "\tProcessor Revision:            {10,16}\n ",
                systemInfo.dwOemId,
                systemInfo.wProcessorArchitecture,
                systemInfo.dwPageSize,
                systemInfo.lpMinimumApplicationAddress,
                systemInfo.lpMaximumApplicationAddress,
                systemInfo.dwActiveProcessorMask,
                systemInfo.dwNumberOfProcessors,
                systemInfo.dwAllocationGranularity,
                systemInfo.dwProcessorType,
                systemInfo.wProcessorLevel,
                systemInfo.wProcessorRevision);

            var globalMemoryStatus = smp_delegate.globalMemoryStatus;
            Console.WriteLine(
                "\tGlobal Memory Info:\n" +
                "\tLength:                        {0,16}\n" +
                "\tMemory Load:                   {1,16}\n" +
                "\tTotal Physical:                {2,16}\n" +
                "\tAvailable Physical:            {3,16}\n" +
                "\tTotal Page File:               {4,16}\n" +
                "\tAvailable Page File:           {5,16}\n" +
                "\tTotal Virtual:                 {6,16}\n" +
                "\tAvailable Virtual:             {7,16}\n" +
                "\tAvailable Extended Virtual:    {8,16}\n",
                globalMemoryStatus.dwLength,
                globalMemoryStatus.dwMemoryLoad,
                globalMemoryStatus.ullTotalPhys,
                globalMemoryStatus.ullAvailPhys,
                globalMemoryStatus.ullTotalPageFile,
                globalMemoryStatus.ullAvailPageFile,
                globalMemoryStatus.ullTotalVirtual,
                globalMemoryStatus.ullAvailVirtual,
                globalMemoryStatus.ullAvailExtendedVirtual);

            var processInfos = smp_delegate.processInfos;
            using (var context = new SmpContext())
            {
                for (var i = 0; i < smp_delegate.infoCount; i++)
                {                 
                    var cliProcessInfo = smp_delegate.processInfos[i];
                    var processInfo = new ProcessInfo(cliProcessInfo);
                    context.ProcessInfos.Add(processInfo);
                }
                context.SaveChanges();

                var maxWorkingSetSizeProcessId = context.ProcessInfos
                    .OrderByDescending(p => p.ProcessMemoryCounter.WorkingSetSize)
                    .FirstOrDefault();
                Console.WriteLine("The process with the largest working set size is " +
                    maxWorkingSetSizeProcessId.Path + " with " +
                    maxWorkingSetSizeProcessId.ProcessMemoryCounter.uWorkingSetSize + ".\n");

                var maxPeakPagefileUsageProcessId = context.ProcessInfos
                    .OrderByDescending(p => p.ProcessMemoryCounter.PeakPagefileUsage)
                    .FirstOrDefault();
                Console.WriteLine("The process with the largest peak pagefile usage is " +
                    maxPeakPagefileUsageProcessId.Path + " with " +
                    maxPeakPagefileUsageProcessId.ProcessMemoryCounter.uPeakPagefileUsage + ".\n");

                var maxPagefileUsageProcessId = context.ProcessInfos
                    .OrderByDescending(p => p.ProcessMemoryCounter.PagefileUsage)
                    .FirstOrDefault();
                Console.WriteLine("The process with the largest pagefile usage is " +
                    maxPagefileUsageProcessId.Path + " with " +
                    maxPagefileUsageProcessId.ProcessMemoryCounter.uPagefileUsage + ".\n");

                var maxPageFaultCountProcessId = context.ProcessInfos
                     .OrderByDescending(p => p.ProcessMemoryCounter.PageFaultCount)
                     .FirstOrDefault();
                Console.WriteLine("The process with the largest page fault count is " +
                    maxPageFaultCountProcessId.Path + " with " +
                    maxPageFaultCountProcessId.ProcessMemoryCounter.uPageFaultCount + ".\n");

                var maxQuotaPeakPagedPoolUsageProcessId = context.ProcessInfos
                    .OrderByDescending(p => p.ProcessMemoryCounter.QuotaPeakPagedPoolUsage)
                    .FirstOrDefault();
                Console.WriteLine("The process with the largest quota peak paged pool usage is " +
                    maxQuotaPeakPagedPoolUsageProcessId.Path + " with " +
                    maxQuotaPeakPagedPoolUsageProcessId.ProcessMemoryCounter.uQuotaPeakPagedPoolUsage + ".\n");

                var maxPageFaultUsageProcessId = context.ProcessInfos
                    .OrderByDescending(p => p.ProcessMemoryCounter.PageFaultUsage)
                    .FirstOrDefault();
                if (maxPageFaultUsageProcessId.ProcessMemoryCounter.uPageFaultUsage > 0)
                {
                    Console.WriteLine("The process with the most pagefile usage is " +
                        maxPageFaultUsageProcessId.Path + " with " +
                        maxPageFaultUsageProcessId.ProcessMemoryCounter.uPageFaultUsage + ".\n");
                }
            }
            Console.WriteLine("Press any key to exit...");
            Console.ReadKey();

        }
    }
}
