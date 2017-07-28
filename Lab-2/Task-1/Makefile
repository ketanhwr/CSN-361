crc: crc.cpp
	g++ -c crc.cpp -o crc

generator: crc
	g++ generator.cpp crc.cpp -o generator

all: crc generator

clean:
	rm generator crc