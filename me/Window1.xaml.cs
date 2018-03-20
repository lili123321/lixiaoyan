using System;
using System.IO;
using System.Collections;
using System.Windows;
using System.Threading;
using System.Windows.Controls;
using System.Runtime.InteropServices;
using System.Collections.ObjectModel;
using System.Collections.Generic;
using System.ComponentModel;
using System.Windows.Input;
using System.Windows.Forms;//打开文件夹会话FolderBrowserDialog

namespace me
{
    /// <summary>
    /// Window1.xaml 的交互逻辑
    /// </summary> 
    public enum LOGTYPE
    {
        error = 0,
        right = 1,
        info = 2
    }
    public static class NativeMethod
    {
        [DllImport("kernel32.dll", EntryPoint = "LoadLibrary")]
        public static extern IntPtr LoadLibrary([MarshalAs(UnmanagedType.LPStr)] string lpLibFileName);

        [DllImport("kernel32.dll", EntryPoint = "GetProcAddress")]
        public static extern IntPtr GetProcAddress(IntPtr hModule, [MarshalAs(UnmanagedType.LPStr)] string lpProcName);

        [DllImport("kernel32.dll", EntryPoint = "FreeLibrary")]
        public static extern bool FreeLibrary(IntPtr hModule);
    }
    
    public class User
    {
        public string id;
        public string name;
        public int age;
        public string Id
        {
            get{return id;}
            set{ id = value;}
        }

        public string Name
        {
            get{ return name;}
            set{ name = value;}
        }

        public int Age
        {
            get{return age;}
            set{age = value;}
        }  
        public User(string id, int age, string name)//构造函数 
        {
            this.id = id;
            this.name = name;
            this.age = age; 
        } 
    }

    public partial class Window1 : Window
    {
        public Window1()
        {
            InitializeComponent();
        }

        private void LoadDlllinfo(string FunctionName)
        {
            //1. 动态加载C++ Dll  atom_comm_lbminfo
            IntPtr hModule = NativeMethod.LoadLibrary(@"D:\BP\jstp\lbm_oracle_Debug\atom_comm_info.dll");

            if (FunctionName == "Createinfo")
            {
                //2. 读取函数指针CreateLbminfo
                IntPtr intPtr = NativeMethod.GetProcAddress(hModule, "Createinfo");

                //3. 将函数指针封装成委托
                Createinfo addFunction = (Createinfo)Marshal.GetDelegateForFunctionPointer(intPtr, typeof(Createinfo));

                //4. 测试
                int nRs = addFunction(SenginePath.Text, KcbpPath.Text, OutputPath.Text);
            }
            else if (FunctionName == "GetbuildInfo")
            {
                 //2. 读取函数指针CreateLbminfo
                IntPtr intPtr = NativeMethod.GetProcAddress(hModule, "GetbuildInfo");

                //3. 将函数指针封装成委托
                GetbuildInfo addFunction = (GetbuildInfo)Marshal.GetDelegateForFunctionPointer(intPtr, typeof(GetbuildInfo));

                //4. 测试
                int nRs = addFunction(SenginePath.Text);
            }

            NativeMethod.FreeLibrary(hModule);
        }

          //加载dll的函数
        delegate int Createinfo(string SenginePath, string KcbpPath,string OutputPath);
        delegate int GetbuildInfo(string SenginePath);
        

        private void SEngineBtn_Click(object sender, RoutedEventArgs e)
        {
            FolderBrowserDialog dilog = new FolderBrowserDialog();
            dilog.ShowDialog();
            if (dilog.SelectedPath != "")
                SenginePath.Text = dilog.SelectedPath;
            
        }
        private void SenginePath_TextChanged(object sender, RoutedEventArgs e)
        {

        }
        private void KcbpBtn_Click(object sender, RoutedEventArgs e)
        {
            FolderBrowserDialog dilog = new FolderBrowserDialog();
            dilog.ShowDialog();
            if (dilog.SelectedPath != "")
                KcbpPath.Text = dilog.SelectedPath;
       
        }
        private void OutputPathBtn_Click(object sender, RoutedEventArgs e)
        {
            FolderBrowserDialog dilog = new FolderBrowserDialog();
            dilog.ShowDialog();
            if (dilog.SelectedPath != "")
                OutputPath.Text = dilog.SelectedPath;
           
        }
        //键盘监听事件
        private void SenginePath_KeyDown(object sender, System.Windows.Input.KeyEventArgs e)
        {
            if (e.Key == Key.Enter)
            {
                LoadDlllinfo("GetbuildInfo");     
                //user = new List<User>();
                //for (int i = 0; i < 10; i++)
                //{       
                //    user.Add(new User("134124", 10, "李白"));
                //}
                //listView1.ItemsSource = user;
            }
        }

        private void ExpStart_Click(object sender, RoutedEventArgs e)
        {
            //远程调用dll生成配置文件
            LoadDlllinfo("Createinfo");           
        }

         private  void DoWork(object x)
         {
            //ArrayList temp = x as ArrayList;
            //WriteLog(LOGTYPE.info, "获取所有 lbm_export.h 文件");
            //string[] st = Directory.GetFiles(temp[0].ToString(), "lbm_export.h", SearchOption.AllDirectories);// //ToString()把object对象转成string类型
            //WriteLog(LOGTYPE.right, "共找到 lbm_export.h 文件 " + st.Length + " 个");

            ////WriteLog(LOGTYPE.info, "开始导出");
            //FileStream fs_1 = null;
            //FileStream fs_2 = null;

            //if (File.Exists(temp[1].ToString()))
            //    fs_1 = new FileStream(temp[1].ToString(), FileMode.Truncate);
            //else
            //    fs_1 = new FileStream(temp[1].ToString(), FileMode.Create);

            //if (File.Exists(temp[2].ToString()))
            //    fs_2 = new FileStream(temp[2].ToString(), FileMode.Truncate);
            //else
            //    fs_2 = new FileStream(temp[2].ToString(), FileMode.Create);

            ////WriteLog(LOGTYPE.right, "文件创建完毕");
            ////WriteLog(LOGTYPE.error, "当前版本只支持 function.xml 的导出");

            //StreamWriter sw_1 = new StreamWriter(fs_1);
            //StreamWriter sw_2 = new StreamWriter(fs_2);

            //Exp(st, sw_1, sw_2);

            //WriteLog(LOGTYPE.right, "function.xml 结果已经导出到 " + temp[1].ToString());
            //WriteLog(LOGTYPE.right, "kcxpconv.xml 结果已经导出到 " + temp[2].ToString());

            //sw_1.Close();
            //sw_2.Close();
            //fs_1.Close();
            //fs_2.Close();

        }
         private void Exp(string[] filelist, StreamWriter fw, StreamWriter xw)
         {
             //string strFilepath = "";
             ////生成批处理脚本
             //CreateBatFiles(strFilepath);
             ////编译代码
             ////ExecuteCmd();
           
             ////远程调用dll生成配置文件
             //LoadDlllinfo();


             //fw.WriteLine("<?xml version=\"1.0\" encoding=\"UTF - 8\" ?>");
             //xw.WriteLine("<?xml version=\"1.0\" encoding=\"UTF - 8\" ?>");

             //XMLNode fw_root = new XMLNode("jstp");
             //XMLNode xw_root = new XMLNode("root");

             //FileStream fs = null;
             //StreamReader sw = null;
             //foreach (var s in filelist)
             //{
             //    fs = new FileStream(s, FileMode.Open);
             //    sw = new StreamReader(fs);
             //    string lbm_name = GetLbmName(s);

             //    string last_line = "";
             //    while (!sw.EndOfStream)
             //    {
             //        string temp = sw.ReadLine();
             //        if (temp.Contains("EXPORT_LBM_FUNC"))
             //        {
             //            XMLNode n_temp = new XMLNode("program");
             //            string module = temp.Substring(temp.IndexOf("EXPORT_LBM_FUNC") + 16, temp.IndexOf(")") - temp.IndexOf("EXPORT_LBM_FUNC") - 16);
             //            if (temp.Contains("//"))
             //            {
             //                string id_contain = temp.Substring(temp.IndexOf("//") + 2);
             //                string id = "";
             //                foreach (char c in id_contain)
             //                    if (c >= '0' && c <= '9')
             //                        id += c;
             //                n_temp.AddAttr("func_id", id);
             //            }
             //            else if (last_line.Contains("//"))
             //            {
             //                string id_contain = last_line.Substring(temp.IndexOf("//") + 2);
             //                string id = "";
             //                foreach (char c in id_contain)
             //                    if (c >= '0' && c <= '9')
             //                        id += c;
             //                n_temp.AddAttr("func_id", id);
             //            }
             //            else
             //                n_temp.AddAttr("func_id", "");
             //            n_temp.AddAttr("path", ".\\function" + lbm_name + ".dll");
             //            n_temp.AddAttr("module", module);
             //            n_temp.AddAttr("type", "trade");
             //            n_temp.AddAttr("timeout", "60");
             //            n_temp.AddAttr("cache", "no");
             //            WriteLog(LOGTYPE.info, "导出函数 " + module);
             //            fw_root.AddChild(n_temp);
             //        }
             //        else
             //            if (temp.Trim() != "")
             //                last_line = temp;
             //    }

             //    sw.Close();
             //    fs.Close();
             //}
             //WriteLog(LOGTYPE.right, "共导出函数 " + fw_root.Children.Count);
             //WriteLog(LOGTYPE.info, "对导出函数按照功能号排序");
             //fw_root.SortChildrenWithAttr("func_id");
             //WriteLog(LOGTYPE.right, "排序完成");
             //fw.WriteLine(fw_root.ToString(""));
             //xw.WriteLine(xw_root.ToString(""));
         }

         //生成批处理脚本
         private void CreateBatFiles(string path)
         { 
             //path = "d:\\compile.bat";
             //m_strBatPath = path;
             //FileStream fs;
             //if (File.Exists(path))
             //    fs = new FileStream(path, FileMode.Truncate);
             //else
             //    fs = new FileStream(path, FileMode.Create);
             //StreamWriter sw = new StreamWriter(fs);
             ////开始写入
             //sw.WriteLine("@echo off");
             //sw.WriteLine(@"set vcpakagespath=HKEY_LOCAL_MACHINE\SOFTWARE\WOW6432Node\Microsoft\VisualStudio\9.0\Setup\VC");
             //sw.WriteLine(@"set vsIdepath=HKEY_LOCAL_MACHINE\SOFTWARE\WOW6432Node\Microsoft\VisualStudio\9.0\Setup\VS\EnvironmentDirectory");
             //sw.WriteLine(@"echo %vcpakagespath%");
             //sw.WriteLine(@"echo %vsIdepath%");
             //sw.WriteLine(@"set PATH = %path%;%vcpakagespath%;%vsIdepath%");
             //sw.WriteLine(@"set MSBuildPath = HKEY_LOCAL_MACHINE\SOFTWARE\WOW6432Node\Microsoft\MSBuild\ToolsVersions\3.5\MSBuildToolsPath");

             //string strDllpath = @"%MSBuildPath%MSBuild ";
             //string projectPath = @"h:\kingdom\JSTPB\trunk\src\sengine\kamc\lbm_kamc_cache\lbm_kamc_cache.vcproj";
             //strDllpath = strDllpath + projectPath + " /p:Configuration=oracle_debug;Platform=x64;DefineConstants=\"LBM_INFO_OUT;USE_NEW_MEMDB_LOG;IN_KCBP_PLATFORM;_WIN64;_DEBUG;_WINDOWS;KCPD_ORA8I;\" /t:rebuild";
             //sw.WriteLine(strDllpath);
             ////写入需要编译的项目

             ////清空缓冲区
             //sw.Flush();
             ////关闭流
             //sw.Close();
             //fs.Close();

         }
        
         private void WriteLog(LOGTYPE logtype, string log)
         {
             //object[] args = { logtype, log };
             //TwoParamDelegate tpd = (x, y) =>
             //{
             //    switch (x)
             //    {
             //        case LOGTYPE.error:
             //            y = " ! " + y;
             //            break;
             //        case LOGTYPE.right:
             //            y = " √ " + y;
             //            break;
             //        case LOGTYPE.info:
             //            y = " * " + y;
             //            break;
             //    }
             //    LogView.Items.Add(DateTime.Now.TimeOfDay + y.ToString());
             //    LogView.ScrollIntoView(LogView.Items[LogView.Items.Count - 1]);
             //};
             //LogView.Dispatcher.Invoke(tpd, args);
         }


      
        private void ReSortXML_Click(object sender, RoutedEventArgs e)
        {

        }

        private void SenginePath_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void OutputPath_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

       private string m_strBatPath;
       private string m_strProjectName;
       private string m_strPlatform;
       private string m_strBuildstatus;
       private List<User> user;  
    }
}
