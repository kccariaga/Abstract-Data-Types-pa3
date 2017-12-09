#Karen Cariaga
#CruzID: kccariag
#pa2 makefile


CC     = gcc
CFLAGS = -g -Wall -O0 -std=c99 -D_SVID_SOURCE


scc03:	scc03.o  intVec.o  loadGraph.o  edge.o  dfsTrace1.o  dfsPhase2.o
	${CC}  -o scc03  ${CFLAGS} scc03.o  intVec.o  loadGraph.o  edge.o  dfsTrace1.o  dfsPhase2.o

edge:	edge.o  scc03.o
	${CC}  -o edge  ${CFLAGS} scc03.o  intVec.o

loadGraph:	loadGraph.o  scc03.o
	${CC}  -o loadGraph  ${CFLAGS} scc03.o  intVec.o

scc03.o:	scc03.c  intVec.h  edge.h loadGraph.h
	${CC}  -c ${CFLAGS} scc03.c

edge.o:	edge.c  intVec.h  edge.h loadGraph.h
	${CC}  -c ${CFLAGS} edge.c

intVec.o:	intVec.c  intVec.h  edge.h loadGraph.h
	${CC}  -c  ${CFLAGS}  intVec.c

loadGraph.o:	loadGraph.c  intVec.h  edge.h  loadGraph.h
	${CC}  -c  ${CFLAGS}  loadGraph.c

clean:
	rm -f *.o
	rm -f "scc03"

