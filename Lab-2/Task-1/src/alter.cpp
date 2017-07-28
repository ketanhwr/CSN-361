#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

char flip(char c)
{
	return (c == '0') ? '1' : '0';
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		cout << "Not enough arguments!" << endl;
		exit(0);
	}

	int arg = atoi(argv[1]) - 1;

	string message;
	string polynomial;

	cin >> message >> polynomial;

	message[arg] = flip(message[arg]);

	cout << message << endl << polynomial << endl;

	return 0;
}