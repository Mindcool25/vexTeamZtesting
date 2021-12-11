@echo off
git pull
if %ERRORLEVEL% == 0 pros upload

