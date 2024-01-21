
CC = gcc
FLAGS = -Wall -g

AR = ar
OBJECTS_MAIN = main.o
OBJECTS_ACL = advancedClassificationLoop.o
OBJECTS_ACR = advancedClassificationRecursion.o
OBJECTS_BC = basicClassification.o
HEADER = NumClass.h


all: loops recursives recursived loopd mains maindloop maindrec

loops: $(OBJECTS_BC) $(OBJECTS_ACL)
	$(AR) rcs libclassloops.a $^
	
recursives: $(OBJECTS_BC) $(OBJECTS_ACR)
	$(AR) rcs libclassrec.a $^
	
recursived: $(OBJECTS_BC) $(OBJECTS_ACR)
	$(CC) $(FLAGS) -shared -fPIC -o libclassrec.so $^
	
loopd: $(OBJECTS_BC) $(OBJECTS_ACL)
	$(CC) $(FLAGS) -shared -fPIC -o libclassloops.so $^

mains: $(OBJECTS_MAIN) libclassrec.a
	$(CC) $(FLAGS) -o $@ $< libclassrec.a

maindloop: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o $@ $< ./libclassloops.so

maindrec: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o $@ $< ./libclassrec.so


main.o: main.c $(HEADER)
	$(CC) $(FLAGS) -c main.c

advancedClassificationLoop.o: advancedClassificationLoop.c $(HEADER)
	$(CC) $(FLAGS) -fPIC -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c $(HEADER)
	$(CC) $(FLAGS) -fPIC -c advancedClassificationRecursion.c

basicClassification.o: basicClassification.c $(HEADER)
	$(CC) $(FLAGS) -fPIC -c basicClassification.c


clean:
	rm -f *.o *.so *.a mains maindloop maindrec