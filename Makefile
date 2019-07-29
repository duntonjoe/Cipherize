
cipherize: cipherize.o polybius.o
	g++ cipherize.o polybius.o -o cipherize

cipherize.o: cipherize.cpp
	g++ -c cipherize.cpp

polybius.o:
	g++ -c polybius.cpp

clean:
	rm *.o cipherize
