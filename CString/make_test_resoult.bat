mkdir temp

cd temp
g++ -c CString.o ..\src\CString.cpp
g++ -c main.o ..\test\main.cpp
g++ -o resoult CString.o main.o

resoult.exe
cd ..

rd /s /q temp 


