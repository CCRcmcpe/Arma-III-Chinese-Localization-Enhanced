$bin = '@Arma III Chinese Localization Enhanced'
$copyItems = '../docs/简体中文 使用说明.txt', '../docs/繁體中文 使用說明.txt', '../LICENSE', 'keys', 'mod.cpp', 'mod.paa'

if (Test-Path $bin) {
    Write-Warning '清除旧构建结果'
    Remove-Item -Recurse $bin
}

$include = Resolve-Path 'include.txt'
function Build-Addons {
    param (
        [string] $srcName
    )
    $addonDest = New-Item (Join-Path $bin $srcName) -ItemType Directory
    foreach ($addonSrc in Get-ChildItem $srcName) {
        AddonBuilder.exe $addonSrc $addonDest -include="$include" -binarizeAllTextures -clear
        if (!$?) {
            Write-Error "构建 $srcName 失败"
            return
        }
    }
}

Build-Addons 'addons'
Build-Addons 'dta'

Copy-Item -Recurse $copyItems $bin

Write-Information '构建成功'