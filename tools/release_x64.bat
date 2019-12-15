REM @echo off
REM
REM Build & release x64
REM

set VERSION=%1

pushd .
if "%VERSION%" == "" goto usage

:setvar
setlocal
set TARGET_NAME=gideon_cs_%VERSION%

set REL_BASE_DIR=release
set REL_DIR=%REL_BASE_DIR%\%TARGET_NAME%

:makedirs
mkdir %REL_BASE_DIR%
mkdir %REL_DIR%

echo copy_files
xcopy /S /Y ..\bin\x64\datatable.dll %REL_DIR%\
xcopy /S /Y ..\bin\x64\datatable.pdb %REL_DIR%\
xcopy /S /Y ..\bin\x64\RandomDungeon.dll %REL_DIR%\
xcopy /S /Y ..\bin\x64\RandomDungeon.pdb %REL_DIR%\

echo zip
cd %REL_BASE_DIR%
c:\cygwin\bin\zip -9 -r %TARGET_NAME%.zip %TARGET_NAME%
if errorlevel 1 goto done

echo remove_dirs
rmdir /s /q %TARGET_NAME%

goto done

:usage
echo "USAGE: %0 <version>"
goto done

:done
popd

if "%2"=="nowait" goto end
pause

:end
