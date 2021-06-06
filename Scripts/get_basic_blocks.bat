set IDA64_PATH="C:\Program Files\IDA 7.0\ida64.exe"
set IDAPYTHON_SCRIPT_PATH="C:\Users\alon\source\repos\Archer\Scripts\ida_get_basic_blocks.py"

if "%1"=="" goto :missing_arg

%IDA64_PATH% -A -S"\"%IDAPYTHON_SCRIPT_PATH%\" \"%1\"" %1  -t
goto end

:missing_arg
echo "Usage: ./get_basic_blocks.bat <analyzed-binary-full-path>"

:end