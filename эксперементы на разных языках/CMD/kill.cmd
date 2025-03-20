@echo off
SET /P number="enter natural nember: "
SET /P digit="enter namber digit: "

SET /A count=0
SET "number=%number%"
SET "digit=%digit%"
:loop
IF "%number%"=="" GOTO end
SET "current=%number:~0,1%"
IF "%current%"=="%digit%" SET /A count+=1
SET "number=%number:~1%"
GOTO loop
:end

echo nember: %digit% meets %count% in numbers %number%
pause