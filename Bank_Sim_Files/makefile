
all: tdQ

all2: tdH

all3: tdPQ

all4: bsim

bsim: BankSimApp.o PriorityQueue.h BinaryHeap.h Queue.h Event.o EmptyDataCollectionException.o
	g++ -Wall -o bsim BankSimApp.o Event.o EmptyDataCollectionException.o

BankSimApp.o: BankSimApp.cpp
	g++ -Wall -c BankSimApp.cpp  

tdQ: testDriver_Q.o Queue.h Event.o EmptyDataCollectionException.o
	g++ -o tdQ -Wall testDriver_Q.o Event.o EmptyDataCollectionException.o

tdH: BinaryHeapTest.o BinaryHeap.h Event.o EmptyDataCollectionException.o
	g++ -o tdH -Wall BinaryHeapTest.o Event.o EmptyDataCollectionException.o
	
tdPQ: testDriver_PQ.o PriorityQueue.h Event.o EmptyDataCollectionException.o
	g++ -o tdPQ -Wall testDriver_PQ.o Event.o EmptyDataCollectionException.o

testDriver_Q.o: testDriver_Q.cpp 
	g++ -c -Wall testDriver_Q.cpp
	
testDriver_PQ.o: testDriver_PQ.cpp 
	g++ -c -Wall testDriver_PQ.cpp

Event.o: Event.cpp Event.h
	g++ -c -Wall Event.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h 
	g++ -c -Wall EmptyDataCollectionException.cpp

BinaryHeap.o: BinaryHeap.cpp BinaryHeap.h
	g++ -c -Wall BinaryHeap.cpp
clean:	
	rm -f tdQ *.o
	rm -f tdH *.o
	rm -f tdPQ *.o
	rm -f bsim *.o


# all: bsim

# bsim: BankSimApp.o PriorityQueue.h BinaryHeap.h Queue.h Event.o EmptyDataCollectionException.o
# 	g++ -Wall -o bsim BankSimApp.o Event.o EmptyDataCollectionException.o

# BankSimApp.o: BankSimApp.cpp
# 	g++ -Wall -c BankSimApp.cpp  
	
# Event.o: Event.h Event.cpp
# 	g++ -Wall -c Event.cpp

# EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
# 	g++ -Wall -c EmptyDataCollectionException.cpp

# clean:	
# 	rm -f bsim *.o












	