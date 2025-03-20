@echo off

set /p n="enter namber 1)open kill.cmd 2)write it down in a notebook"

IF "%n%"=="1" start kill.cmd

IF "%n%"=="2" start notepad.exe < bd.txt  
pause

