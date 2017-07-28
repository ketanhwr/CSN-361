#include <iostream>
#include <string>
#include <vector>

using namespace std;

int hexToDec(char c)
{
	if (c >= '0' && c <= '9') return (int)(c - '0');
	else return (10 + (int)(c - 'a'));
}

bool check(int value)
{
	int bits = 0;

	while (value) {
		bits++;
		value >>= 1;
	}

	return (bits <= 16);
}

int modify(int value)
{
	vector<int> bits;

	while (value) {
		bits.push_back(value % 2);
		value /= 2;
	}

	int value1 = 0;
	for (int i = 15; i >= 0; i--)
		value1 = value1 * 2 + bits[i];

	int value2 = 0;
	for (int i = bits.size() - 1; i >= 16; i--)
		value2 = value2 * 2 + bits[i];

	return value1 + value2;
}

int main(int argc, char **argv)
{
	string header;

	cin >> header;

	// Add all the 16-bit header values and skip the 6th one.
	int result = 0;
	int currentHeader = 0;
	int currentValue = 0;
	int currentIndex = 0;

	while (currentIndex <= header.size()) {
		if (currentIndex%4 == 0 && currentIndex != 0) {
			currentHeader++;
			if (currentHeader != 6)
				result += currentValue;

			currentValue = 0;
		}

		if (currentIndex == header.size())
			break;

		currentValue = currentValue * 16 + hexToDec(header[currentIndex]);
		currentIndex++;
	}

	while (!check(result)) {
		result = modify(result);
	}

	vector<int> bits;
	for (int i = 0; i < 16; i++) {
		bits.push_back(result % 2);
		result /= 2;
	}

	for (int i = 0; i < 16; i++) {
		bits[i] = !bits[i];
	}

	for (int i = 15; i >= 0; i--) {
		result = result * 2 + bits[i];
	}

	cout << std::hex << result << endl;

	return 0;
}