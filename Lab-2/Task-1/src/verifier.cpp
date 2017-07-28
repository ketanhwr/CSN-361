#include <iostream>
#include <string>

#include "crc.h"

using namespace std;

int main(int argc, char **argv)
{
	string message;
	string polynomial;

	cin >> message >> polynomial;

	CRC *crc = new CRC(polynomial);

	if (crc->verify(message))
		cout << "Correct!" << endl;
	else
		cout << "Incorrect!" << endl;

	return 0;
}