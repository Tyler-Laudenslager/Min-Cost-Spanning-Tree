debugFlag=-g
complier=g++

make: pDs pLib

pDs: Heap_ADT.o primDS.o
	$(complier) -o pDs primDS.o Heap_ADT.o $(debugFlag)

pLib: primLib.o
	$(complier) -o pLib primLib.o $(debugFlag)

primLib.o: primLib.cpp
	$(complier) -c primLib.cpp $(debugFlag)

primDS.o: primDS.cpp  Heap_ADT.h Edge.h
	$(complier) -c primDS.cpp $(debugFlag)

Heap_ADT.o: Heap_ADT.cpp Heap_ADT.h Edge.h
	$(complier) -c Heap_ADT.cpp $(debugFlag)


clean:
	rm *.o pLib pDs

