@echo off
:quickUpload
pros build quick
pros upload

doskey quick = pros build quick
doskey all = pros build all
doskey upload = pros upload
doskey upquick = call :quickUpload 
doskey terminal = pros terminal

