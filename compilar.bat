@echo off
title Compilando Midnight Torque...
echo.
echo  ========================================
echo   Compilando: gamemodes/main.pwn
echo  ========================================
echo.

pawno\pawncc.exe gamemodes\main.pwn -i pawno\include -r -o gamemodes\main

if %ERRORLEVEL% == 0 (
    echo.
    echo  [OK] Compilado com sucesso!
) else (
    echo.
    echo  [ERRO] Falha na compilacao. Verifique os erros acima.
)

echo.
pause
