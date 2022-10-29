coverage:
	cd Histogram/ && make run && gcov prog.c && valgrind --leak-check=yes ./prog test.in test.out
	cd Statistics/ && make run && gcov prog.c && valgrind --leak-check=yes ./prog test.in test.out
	cd Transpose/ && make run && gcov prog.c && valgrind --leak-check=yes ./prog test.in test.out