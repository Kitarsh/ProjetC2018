matproj: matproj.o es.o mat.o op.o
	gcc matproj.o err.o es.o mat.o op.o -o matproj

matproj.o: matproj.c mat.h op.h es.h
	gcc -c matproj.c

err.o: err.c err.h
	gcc -c err.c

es.o: es.c mat.h es.h err.h
	gcc -c es.c

mat.o: mat.c mat.h
	gcc -c mat.c

op.o: op.c mat.h err.h op.h
	gcc -c op.c
