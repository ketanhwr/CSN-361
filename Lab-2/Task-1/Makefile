crc: src/crc.h src/crc.cpp
	g++ -c src/crc.cpp -o crc.o

generator: crc src/generator.cpp
	g++ src/generator.cpp crc.o -o generator

verifier: crc src/verifier.cpp
	g++ src/verifier.cpp crc.o -o verifier

alter: src/alter.cpp
	g++ src/alter.cpp -o alter

all: crc generator verifier alter

clean:
	rm generator crc.o verifier alter