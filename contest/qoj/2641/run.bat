@echo off

cls

set src_f=%1.cpp
set exe_f=%1.exe

g++ -std=c++23 -O2 -o "%exe_f%" "%src_f%"

if %errorlevel% equ 0 (
    "%exe_f%"
)