crc: crc.h crc.cpp
	g++ -c crc.cpp -o crc

generator: crc generator.cpp
	g++ generator.cpp crc.cpp -o generator

verifier: crc verifier.cpp
	g++ verifier.cpp crc.cpp -o verifier

all: crc generator verifier

clean:
	rm generator crc verifier