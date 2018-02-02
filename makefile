matproj: es.o mat.o op.o
	cc err.o es.o mat.o op.o -o matproj

err.o: err.c err.h
	cc -c err.c

es.o: es.c mat.h es.h err.h
	cc -c es.c

mat.o: mat.c mat.h
	cc -c mat.c

op.o: mat.h err.h op.h
	cc -c op.c
