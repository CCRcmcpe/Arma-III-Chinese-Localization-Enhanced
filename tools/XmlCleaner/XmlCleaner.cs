using System;
using System.Linq;
using System.Xml;
using System.IO;
using System.Windows.Forms;

// XML瘦身软件

//     本程序用于将Arma 3多语言版本stringtable.XML文件精简化，仅保留默认及中文简繁三种文本。
// 转换后文件将保存为[源文件全名].txt

// 用法：可直接批量选择文件拖至程序图标，或者打开程序后选择文件进行瘦身。
//  ====================================================================================
// 作者：云隐
// 创建时间：2017/8/1      修改时间:2022/1/12（RcINS）
// QQ：519753087

namespace XMLCleaner
{
    public static class Program
    {
       
        public static bool In<T>(this T needle, params T[] haystack)
        {
            if (haystack == null)
                throw new ArgumentNullException("items is null!");
            return haystack.Contains(needle);
        }
        [STAThread]
        static int Main(string[] args)
        {
            OpenFileDialog open = new OpenFileDialog();
            open.Title = "请选择文本"; //打开的文件选择对话框上的标题
            open.Filter = "文本文件(*.xml)|*.xml|所有文件(*.*)|*.*";//设置文件类型
            open.InitialDirectory = @"C:\";//默认打开目录
            open.FilterIndex = 1;//设置默认文件类型显示顺序
            open.RestoreDirectory = false;//是否记忆上次打开的目录
            open.Multiselect = true;//是否允许多选
            string[] filenames;
            XmlDocument xmlDocument = new XmlDocument();
            string[] stringLists = {"German","Czech","Russian","Polish", "Italian","Spanish","French",
                 "Japanese","English","Korean"  ,"Portuguese" ,"Turkish" };
            if (args.Length == 0 && open.ShowDialog() == DialogResult.OK)//按下确定选择的按钮
            {
                filenames = open.FileNames;//获取多个文件的路径及文件名并存入数组
                for (int i = 0; i < filenames.Length; i++) ;
                //    MessageBox.Show(filenames[i]);
               // MessageBox.Show(open.FileName); //获取路径及文件名
              //  MessageBox.Show(open.SafeFileName);//获取文件名
                if (filenames.Length != 0)
                {
                    for (int i = 0; i < filenames.Length; i++)
                    {
                        Console.WriteLine(filenames[i]);

                        xmlDocument.Load(filenames[i]);
                        XmlNode xmlNode = xmlDocument.SelectSingleNode("Project");
                        //  Console.Write("Project：{0}\n", xmlNode.Attributes["name"].Value);
                        XmlNode xmlNode2 = xmlNode.SelectSingleNode("Package");
                        //   Console.Write("Package：{0}\n", xmlNode2.Attributes["name"].Value);
                        XmlNodeList xmlNodeList = xmlDocument.SelectNodes("//Key");
                        for (int j = 0; j < xmlNodeList.Count; j++)
                        {
                            if (xmlNodeList[j].HasChildNodes)
                            {
                                XmlNodeList childNodes = xmlNodeList[j].ChildNodes;
                                bool flag;
                                do
                                {
                                    flag = false;
                                    foreach (XmlNode xmlNode3 in childNodes)
                                    {
                                        if (xmlNode3.Name.In(stringLists))
                                        {
                                            xmlNode3.ParentNode.RemoveChild(xmlNode3);
                                            flag = true;
                                            break;
                                        }
                                    }
                                }
                                while (flag);
                            }//end for
                        }

                        if (filenames.Length != 0)
                        {
                            xmlDocument.Save(filenames[i] + ".txt");
                        }
                        Console.WriteLine("已保存{0}文件!", filenames[i] + ".txt");
                    }
                }
                Console.ReadKey();
                return 0;
            }


            if (args.Length != 0)
            {
                for (int i = 0; i < args.Length; i++)
                {
                    Console.WriteLine(args[i]);

                    xmlDocument.Load(args[i]);
                    XmlNode xmlNode = xmlDocument.SelectSingleNode("Project");
                    //  Console.Write("Project：{0}\n", xmlNode.Attributes["name"].Value);
                    XmlNode xmlNode2 = xmlNode.SelectSingleNode("Package");
                    //   Console.Write("Package：{0}\n", xmlNode2.Attributes["name"].Value);
                    XmlNodeList xmlNodeList = xmlDocument.SelectNodes("//Key");
                    for (int j = 0; j < xmlNodeList.Count; j++)
                    {
                        if (xmlNodeList[j].HasChildNodes)
                        {
                            XmlNodeList childNodes = xmlNodeList[j].ChildNodes;
                            bool flag;
                            do
                            {
                                flag = false;
                                foreach (XmlNode xmlNode3 in childNodes)
                                {
                                    if (xmlNode3.Name.In(stringLists))
                                    {
                                        xmlNode3.ParentNode.RemoveChild(xmlNode3);
                                        flag = true;
                                        break;
                                    }
                                }
                            }
                            while (flag);
                        }//end for
                    }

                    if (args.Length != 0)
                    {
                        xmlDocument.Save(args[i]);
                    }
                    Console.WriteLine("已保存{0}文件!", args[i]);
                }
            }
            return 0;
        }

    }
}
