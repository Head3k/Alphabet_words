@echo off
color 0a

echo Welcome in install menu Alphabet_words		 

:start
echo Function menu:
echo 1) compile Alphabet_words
echo 2) run Alphabet_words
echo 3) clean temporary files 

::set /p digit = Inter Number :
set /p digit="Enter number ==> "

if "%digit%"=="1" call :1
if "%digit%"=="2" call :2
if "%digit%"=="3" call :3

:1
  win_c\bin\dmc.exe src\main
  move main.exe bin\main.exe
  move main.map build\src\main.map
  move main.obj build\src\main.obj
  ::set /p k = key :
  set /p k="Enter q for quit or r restart ==> "
  if "%k%"=="q" call :q
  if "%k%"=="r" call :r
  :q
    exit
  :r
    goto start
  

:2
  cls
  bin\main.exe
  ::set /p k = key :
  set /p k="Enter q for quit or r restart ==> "
  if "%k%"=="q" call :q
  if "%k%"=="r" call :r
  :q
    exit
  :r
    goto start

:3
  cls 
  del bin\main.exe
  del build\src\main.map
  del build\src\main.obj
  ::set /p k = key :
  set /p k="Enter q for quit or r restart ==> "
  if "%k%"=="q" call :q
  if "%k%"=="r" call :r
  :q
    exit
  :r
    goto start

