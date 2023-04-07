@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by AMONITOR.HPJ. >"hlp\AMonitor.hm"
echo. >>"hlp\AMonitor.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\AMonitor.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\AMonitor.hm"
echo. >>"hlp\AMonitor.hm"
echo // Prompts (IDP_*) >>"hlp\AMonitor.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\AMonitor.hm"
echo. >>"hlp\AMonitor.hm"
echo // Resources (IDR_*) >>"hlp\AMonitor.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\AMonitor.hm"
echo. >>"hlp\AMonitor.hm"
echo // Dialogs (IDD_*) >>"hlp\AMonitor.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\AMonitor.hm"
echo. >>"hlp\AMonitor.hm"
echo // Frame Controls (IDW_*) >>"hlp\AMonitor.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\AMonitor.hm"
REM -- Make help for Project AMONITOR


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\AMonitor.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\AMonitor.hlp" goto :Error
if not exist "hlp\AMonitor.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\AMonitor.hlp" Debug
if exist Debug\nul copy "hlp\AMonitor.cnt" Debug
if exist Release\nul copy "hlp\AMonitor.hlp" Release
if exist Release\nul copy "hlp\AMonitor.cnt" Release
echo.
goto :done

:Error
echo hlp\AMonitor.hpj(1) : error: Problem encountered creating help file

:done
echo.
