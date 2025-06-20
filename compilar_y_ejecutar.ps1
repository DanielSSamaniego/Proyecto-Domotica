# Limpia la consola para mayor claridad
Clear-Host

# Cambia la ruta de QT_BIN y MINGW_BIN si tu versión es diferente
$QT_BIN = "C:\msys64\mingw64\bin"
$MINGW_BIN = "C:\msys64\ucrt64\bin"
$env:PATH = "$QT_BIN;$MINGW_BIN;" + $env:PATH

# Asegúrate de estar en la raíz del proyecto
Set-Location -Path "C:\Users\herod\Documents\GitHub\Proyecto-Domotica"

Write-Host "[1/4] Generando Makefile con qmake..."
$qmakeResult = qmake domotica_app.pro 2>&1
if ($LASTEXITCODE -ne 0) {
    Write-Host "ERROR en qmake:\n$qmakeResult"
    Read-Host 'Presiona Enter para salir...'
    exit 1
}

Write-Host "[2/4] Compilando con mingw32-make..."
$makeResult = mingw32-make 2>&1
if ($LASTEXITCODE -ne 0) {
    Write-Host "ERROR en mingw32-make:\n$makeResult"
    Read-Host 'Presiona Enter para salir...'
    exit 1
}

Write-Host "[3/4] Ejecutando windeployqt..."
& "$QT_BIN\windeployqt.exe" --dir "$PWD\release" "$PWD\release\domotica_app.exe" --qmldir . 2>&1 | Tee-Object -FilePath "$PWD\windeployqt.log"

# Verifica que la carpeta platforms y qwindows.dll existan
if (!(Test-Path "$PWD\release\platforms\qwindows.dll")) {
    Write-Host "ERROR: Falta platforms/qwindows.dll en release. Revisa tu instalación de Qt."
    Read-Host 'Presiona Enter para salir...'
    exit 1
}

Write-Host "[4/4] Ejecutando la aplicación..."
Start-Process -FilePath ".\release\domotica_app.exe"
Read-Host 'Presiona Enter para continuar...'
