#include "crc.h"

inline static char findXOR(char a, char b)
{
	return (a == b) ? '0' : '1';
}

string CRC::generate(string message) const
{
	int size = message.size();
	int currentIndex = 0;

	string result(message);
	result += string(mPolynomial.size() - 1, '0');

	while (currentIndex < size) {
		// Increament until encounter a 1
		for (; currentIndex < size; ++currentIndex) {
			if (result[currentIndex] == '1')
				break;
		}

		if (currentIndex == size)
			break;

		// Calculate XOR
		for (int i = currentIndex; i < currentIndex + mPolynomial.size(); ++i) {
			result[i] = findXOR(result[i], mPolynomial[i - currentIndex]);
		}

		currentIndex++;
	}

	result.replace(result.begin(), result.begin() + size, message);

	return result;
}

bool CRC::verify(string message) const
{
	int size = message.size();
	int currentIndex = 0;

	message += string(mPolynomial.size() - 1, '0');

	string result(message.size(), '0');

	while (currentIndex < size) {
		// Increament until encounter a 1
		for (; currentIndex < size; ++currentIndex) {
			if (message[currentIndex] == '1')
				break;
		}

		if (currentIndex == size)
			break;

		// Calculate XOR
		for (int i = currentIndex; i < currentIndex + mPolynomial.size(); ++i) {
			message[i] = findXOR(message[i], mPolynomial[i - currentIndex]);
		}

		currentIndex++;
	}

	return (message == result);
}
