using System.Data.Entity;

namespace CsSmpData
{
    public class SmpContext : DbContext
    {
        public SmpContext() : base("name=smp_context")
        {
        }

        public virtual DbSet<SystemInfo> SystemInfos { get; set; }
        public virtual DbSet<ProcessMemoryCounter> PMCs { get; set; }

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
        }
    }
}
