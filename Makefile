bin/pruebaEntradas: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	g++ -o testTableEntry.cpp TableEntry.h

bin/pruebaHash: testHashTable.cpp HashTable.h TableEntry.h
	mkdir -p bin
	g++ -o testHashTable.cpp HashTable.cpp

