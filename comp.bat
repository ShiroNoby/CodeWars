set /p name="name: "
set /p var1="main: "
set /p var2="headers: "

(	
	@echo set name=%name%
	@echo set var1=%var1%
	@echo set var2=%var2%
	@echo g++ %var1% %var2% -o test_%name%.exe 
	) > make_%name%.bat

g++ %var1% %var2% -o test_%name%.exe 