// 合并新版语言文件到模组
// 作者 RcINS 2022-1-12

using System.Xml.Linq;
using System.Xml.XPath;

var translationsToCopy = new[] { "Original", "Chinese", "Chinesesimp" };

DirectoryInfo? vanillaRoot = null;
DirectoryInfo? modRoot = null;
try
{
    vanillaRoot = new DirectoryInfo(args[0]);
    modRoot = new DirectoryInfo(args[1]);
}
catch (Exception ex)
{
    Console.WriteLine(ex);
    Console.WriteLine("合并新版语言文件到模组。");
    Console.WriteLine("用法：Merge.exe <解包完毕的语言文件路径> <模组路径>");
}

static DirectoryInfo[] GetAddons(DirectoryInfo modDirectory)
{
    return modDirectory.EnumerateDirectories().SelectMany(d => d.EnumerateDirectories()).ToArray();
}

DirectoryInfo[] vanillaAddons = GetAddons(vanillaRoot!);
DirectoryInfo[] modAddons = GetAddons(modRoot!);

foreach (DirectoryInfo vanillaAddon in vanillaAddons)
{
    DirectoryInfo? modAddon = modAddons.FirstOrDefault(modAddon => modAddon.Name == vanillaAddon.Name);
    if (modAddon == null)
    {
        Console.WriteLine($"需要翻译新 Addon: \"{vanillaAddon}\"");
        continue;
    }

    string vanillaXmlPath = Path.Combine(vanillaAddon.FullName, "stringtable.xml");
    XDocument vanillaXml = XDocument.Load(vanillaXmlPath);
    XDocument modXml = XDocument.Load(Path.Combine(modAddon.FullName, "stringtable.xml"));
    XElement[] vanillaKeys = vanillaXml.XPathSelectElements("Project/Package//Key").ToArray();
    XElement[] modKeys = modXml.XPathSelectElements("Project/Package//Key").ToArray();
    foreach (XElement modKey in modKeys)
    {
        XElement? vanillaKey = vanillaKeys.FirstOrDefault(vanillaKey => vanillaKey.Attribute("ID")!.Value ==
                                                                        modKey.Attribute("ID")!.Value);
        if (vanillaKey == null)
        {
            // 已经翻译了但是没出现在新版，说明已经被删除
            Console.WriteLine($"键 \"{modKey.Attribute("ID")}\" 已被删除");
            continue;
        }

        foreach (string translationToCopy in translationsToCopy)
        {
            XElement? modTranslation = modKey.Descendants(translationToCopy).FirstOrDefault();
            if (modTranslation == null)
            {
                continue;
            }

            XElement? vanillaTranslation = vanillaKey.Descendants(translationToCopy).FirstOrDefault();
            if (vanillaTranslation != null)
            {
                vanillaTranslation.ReplaceWith(modTranslation);
            }
            else
            {
                vanillaKey.Add(modTranslation);
            }
        }
    }

    vanillaXml.Save(vanillaXmlPath);
}