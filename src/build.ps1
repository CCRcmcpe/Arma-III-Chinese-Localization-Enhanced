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
    $addonSrcs = Get-ChildItem $srcName

    $count = $addonSrcs.Length
    $sync = [hashtable]::Synchronized(@{ i = 0 })
    $addonSrcs | ForEach-Object -ThrottleLimit ([System.Environment]::ProcessorCount) -Parallel {
        $sync = $using:sync
        AddonBuilder.exe $_ $using:addonDest -include="$using:include" -clear
        if (!$?) {
            Write-Error "构建 $using:srcName 失败"
            return
        }
        $sync.i++;
        Write-Progress -Activity "构建 Addons" -PercentComplete ($sync.i / $using:count * 100)
    }
}

Build-Addons 'addons'
Build-Addons 'dta'

Copy-Item -Recurse $copyItems $bin

Write-Information '构建成功'