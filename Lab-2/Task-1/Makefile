crc: src/crc.h src/crc.cpp
	g++ -c src/crc.cpp -o crc

generator: crc src/generator.cpp
	g++ src/generator.cpp src/crc.cpp -o generator

verifier: crc src/verifier.cpp
	g++ src/verifier.cpp src/crc.cpp -o verifier

alter: src/alter.cpp
	g++ src/alter.cpp -o alter

all: crc generator verifier alter

clean:
	rm generator crc verifier alter