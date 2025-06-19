# Cambia la ruta de QT_BIN y MINGW_BIN si tu versión es diferente
$QT_BIN = "C:\msys64\mingw64\bin"
$MINGW_BIN = "C:\msys64\ucrt64\bin"
$env:PATH = "$QT_BIN;$MINGW_BIN;" + $env:PATH

# Asegúrate de estar en la raíz del proyecto
Set-Location -Path "C:\Users\herod\Documents\GitHub\Proyecto-Domotica"

qmake domotica_app.pro
mingw32-make

# Ejecuta windeployqt para copiar las DLLs y plugins necesarios de Qt
& "$QT_BIN\windeployqt.exe" --dir "$PWD\release" "$PWD\release\domotica_app.exe"

# Ejecuta la aplicación
.\release\domotica_app.exe
Read-Host 'Presiona Enter para continuar...'
