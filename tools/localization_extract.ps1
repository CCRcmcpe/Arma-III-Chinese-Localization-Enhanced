$destination = 'D:/Dev/Arma3/Extract/'
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

if (Test-Path $destination) {
    Write-Warning 'Removing old files'
    Remove-Item -Recurse $destination
}
$dest = New-Item -ItemType Directory $destination

$combined = $core + ($expansions | ForEach-Object {Join-Path $_ 'Addons'})
$pbos = Get-ChildItem $combined | Where-Object {$_.Extension -eq '.pbo' -and $_.Name -match 'language'}

Write-Information 'Extracting...'
$pbos | ForEach-Object {
    & $bankRev -folder $dest -time $_.FullName
}

Write-Information 'Debinarize Configs...'
Get-ChildItem "$dest/**/*.bin" | ForEach-Object {
    $cppDest = Join-Path $_.DirectoryName "$([IO.Path]::GetFileNameWithoutExtension($_)).cpp"
    & $binToCpp -txt -dst $cppDest $_.FullName
    Remove-Item $_
}

Write-Information 'Cleaning XML...'
Get-ChildItem "$dest/**/*.xml" | ForEach-Object {
    & $xmlCleaner $_.FullName
}

Write-Information 'Done'