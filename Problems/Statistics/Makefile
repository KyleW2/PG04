run:
	gcc -fprofile-arcs -ftest-coverage -g -o prog prog.c -lm
	./prog
	./prog test.in
	./prog test.in test.out