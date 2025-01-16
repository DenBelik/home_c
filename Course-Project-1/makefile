all: prog

prog: report.o temp_function.o
	gcc -o prog report.o temp_function.o

report.o: report.c
	gcc -c -o report.o report.c

temp_function.o: temp_function.c
	gcc -c -o temp_function.o temp_function.c

clean:
	del *.o
	del prog.exe