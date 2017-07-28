#include <iostream>
#include <string>

using namespace std;

class CRC
{
public:
	CRC(string polynomial) : mPolynomial(polynomial) {}

	string polynomial() const { return mPolynomial; }

	void setPolynomial(string function) { mPolynomial = function; }

	string generate(string message) const;

private:
	string mPolynomial;
};

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

int main(int argc, char **argv)
{
	string message;
	string polynomial;

	cin >> message >> polynomial;

	CRC *crc = new CRC(polynomial);

	cout << crc->generate(message) << endl;
	cout << crc->polynomial() << endl;

	return 0;
}