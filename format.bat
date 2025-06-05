@echo off
setlocal enabledelayedexpansion

echo Searching for .clang-format...
where clang-format >nul 2>&1
if %errorlevel% neq 0 (
    echo Error: clang-format is not installed or not in PATH.
    pause
    exit /b 1
)

:: Проверяем, существует ли .clang-format в текущей или родительских папках
set "CLANG_PATH=C:\Rogalique\.clang-format"
if not exist "%CLANG_PATH%" -i --style=file "%%f" (
    echo Warning: No .clang-format file found in this directory or parents.
    echo Proceeding with default style...
)

echo Running clang-format on all .cpp, .h, .hpp, .c files...

set count=0
for /r %%f in (*.cpp *.h *.hpp *.c) do (
    clang-format -i --style=file "%%f"
    echo Formatted: %%f
    set /a count+=1
)

if %count% == 0 (
    echo No files found to format.
) else (
    echo Formatting complete. Processed %count% files.
)

pause