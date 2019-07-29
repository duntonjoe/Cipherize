
cipherize: cipherize.o polybius.o caesar.o rot13.o
	g++ cipherize.o polybius.o caesar.o rot13.o -o cipherize

cipherize.o: cipherize.cpp
	g++ -c cipherize.cpp cipherize.h

polybius.o: polybius.cpp
	g++ -c polybius.cpp

caesar.o: caesar.cpp
	g++ -c caesar.cpp caesar.h

rot13.o: rot13.cpp
	g++ -c rot13.cpp

clean:
	rm *.o *.gch cipherize
