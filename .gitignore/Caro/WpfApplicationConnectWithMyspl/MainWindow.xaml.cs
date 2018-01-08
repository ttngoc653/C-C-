using Devart.Data.MySql;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfApplicationConnectWithMyspl
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            //https://mysql8.db4free.net/phpMyAdmin/index.php?token=52bd69a916bc82fdc5ad7d031cdb0992
            string connectString = "server=85.10.205.173;user=joss653;database=bobjess656;port=3307;password=db4free653;charset=utf8";

            MySqlConnection connection = new MySqlConnection(connectString);

            string insertStr = "INSERT INTO hang_sx(tenhangsx, truso, mota, an) VALUES (\"Bkav\",\"Tầng 2, tòa nhà HH1-khu đô thị Yên Hòa, Phường Yên Hoà, Quận Cầu Giấy, Thành phố Hà Nội\",\"Bkav là công ty công nghệ hoạt động trong các lĩnh vực an ninh mạng, phần mềm, chính phủ điện tử, nhà sản xuất smartphone và các thiết bị điện tử thông minh, cung cấp dịch vụ điện toán đám mây. Công ty được biết đến nhiều với phần mềm diệt virus Bkav (Bách Khoa Antivirus) cũng như người sáng lập và điều hành, ông Nguyễn Tử Quảng.\",0)";
            string deleteStr = "DELETE FROM hang_sx WHERE tenhangsx=\"Bkav\"";
            
            MySqlCommand cmd = new MySqlCommand("select * from hang_sx", connection);
            MySqlCommand cmdDelete = new MySqlCommand(deleteStr, connection);
            MySqlCommand cmdInsert = new MySqlCommand(insertStr, connection);
                        
            connection.Open();
            DataTable dt = new DataTable();

            int numDelete = 0;
            numDelete = cmdDelete.ExecuteNonQuery();

            int numAdded = 0;
            numAdded = cmdInsert.ExecuteNonQuery();

            dt.Load(cmd.ExecuteReader());

            connection.Close();

            MessageBox.Show("Đã thêm " + numAdded + " dòng dữ liệu.","THÀNH CÔNG");

            dataGrid.DataContext = dt;
        }
    }
}
