Set-StrictMode -Version Latest

$extractDest = 'D:/Dev/Arma3/Extract/'
$tools = 'D:\SteamLibrary\steamapps\common\Arma 3 Tools'

# In Arma 3 root execute: ls -Directory | ? {((ls $_) | ? {$_.Name -eq 'Addons'}).Length -gt 0}
$core = 'Addons', 'Dta'
$expansions = 'AoW', 'Argo', 'Contact', 'Curator', 'Enoch', 'Expansion', 'Heli', 'Jets', 'Kart', 'Mark', 'Orange', 'Tacops', 'Tank'

$bankRev = Join-Path $tools 'BankRev\BankRev.exe'
$binToCpp = Join-Path $tools 'CfgConvert\CfgConvert.exe'
if (!$PSScriptRoot) {
    Write-Error 'Unable to determine PSScriptRoot'
    return
}
$xmlCleaner = Join-Path $PSScriptRoot 'XmlCleaner\XmlCleaner.exe'
$merge = Join-Path $PSScriptRoot 'Merge\Merge.exe'

if (Test-Path $extractDest) {
    Write-Warning 'Removing old files'
    Remove-Item -Recurse $extractDest
    if (!$?) {
        Write-Error 'Cannot remove old files. Check handles.'
        return
    }
}

$combined = $core + ($expansions | ForEach-Object { Join-Path $_ 'Addons' })
$pbos = Get-ChildItem $combined | Where-Object { $_.Extension -eq '.pbo' -and $_.Name -match 'language' }

Write-Information 'Extracting...'
$pbos | ForEach-Object {
    $addonDest = if ($_ -notmatch 'Dta') { Join-Path $dest 'Addons' } else { Join-Path $dest 'Dta' }
    & $bankRev -folder $addonDest -time $_.FullName
}

Write-Information 'Debinarize Configs...'
Get-ChildItem "$extractDest/**/**/*.bin" | ForEach-Object {
    $cppDest = Join-Path $_.DirectoryName "$([IO.Path]::GetFileNameWithoutExtension($_)).cpp"
    & $binToCpp -txt -dst $cppDest $_.FullName
    Remove-Item $_
}

Write-Information 'Cleaning XML...'
Get-ChildItem "$extractDest/**/**/*.xml" | ForEach-Object {
    & $xmlCleaner $_.FullName
}

Write-Warning 'Before merging, make sure the working tree is clean, this will remove current sources!'
$choice = Read-Host 'Merge to current branch? [y/n] (Default: n)'
if ($choice -eq 'y') {
    $src = Join-Path $PSScriptRoot '../src'
    & $merge $extractDest $src
    Remove-Item -Recurse (Get-ChildItem $extractDest | ForEach-Object {Join-Path $src $_.Name})
    Copy-Item -Recurse "$extractDest/**" -Exclude '*.txt' $src
}

Write-Information 'Done'