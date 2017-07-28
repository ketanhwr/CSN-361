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
