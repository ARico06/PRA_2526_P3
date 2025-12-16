bin/pruebaEntradas: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	g++ -o testTableEntry.cpp TableEntry.h

bin/pruebaHash: testHashTable.cpp HashTable.h TableEntry.h Dict.h ListLinked.h
	mkdir -p bin
	g++ -o bin/pruebaHash HashTable.h ListLinked.h TableEntry.h Dict.h testHashTable.cpp

bin/testBSTree: testBSTree.cpp BSNode.h BSTree.h
	mkdir -p bin
	g++ -o bin/testBSTree BSTree.h BSNode.h testBSTree.cpp

bin/testBSTreeDict: testBSTreeDict.cpp BSTree.h BSNode.h TableEntry.h Dict.h BSTreeDict.h
	mkdir -p bin
	g++ -o bin/testBSTreeDict testBSTreeDict.cpp BSTree.h BSNode.h TableEntry.h Dict.h BSTreeDict.h






