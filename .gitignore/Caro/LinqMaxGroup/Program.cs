using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LinqMaxGroup
{
    public class Row
    {
        public int Id1;
        public int Id2;
        public int Value;
    }

    public class Column
    {
        public int id2;
        public String name;
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<Row> rows = new List<Row>(){
                new Row(){Id1=1,Id2=9,Value=12},
                new Row(){Id1=2,Id2=9,Value=6},
                new Row(){Id1=3,Id2=11,Value=8},
                new Row(){Id1=4,Id2=11,Value=87}
            };

            List<Column> cols = new List<Column>()
            {
                new Column() {id2=9,name="n1" },
                new Column() {id2=11,name="n2" }
            };

            int max = rows.GroupBy(a => a.Id2).Select(a => a.Sum(b => b.Value)).Max();

            Console.WriteLine(max);

            List<int> idCol = rows.GroupBy(a => a.Id2)
                          .Where(c =>c.Sum(d=>d.Value) == max)
                          .Select(z => z.Key).ToList();

            foreach (var item in idCol)
            {
                Console.WriteLine(item);
            }

            List<Column> linq = (from c in cols
                                 join r in idCol on c.id2 equals r
                                 select c).ToList();

            foreach (var item in linq)
            {
                Console.WriteLine(item.id2 +"  "+item.name);
            }
        }
    }
}
