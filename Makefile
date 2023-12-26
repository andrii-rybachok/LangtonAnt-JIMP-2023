all:
	gcc -Wall --pedantic src/*.c -o bin/langton

test: all
	bin/langton 
