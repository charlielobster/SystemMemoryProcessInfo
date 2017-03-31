using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Data.Entity;
using System.Data.Entity.ModelConfiguration.Conventions;

namespace cs_smp_data
{
    public class smp_context : DbContext
    {
        public smp_context() : base("name=smp_context")
        {
        }

        public virtual DbSet<ProcessMemoryCounter> PMCs { get; set; }

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
        }
    }
}
