#include <iostream>
#include <string>
using namespace std;

char intToHex(int val)
{
	if (val <= 9)
		return '0' + val;
	else
		return 'A' + (val-10);
}

string ipv6(string ipv4)
{
	int v1 = 0;
	int v2 = 0;
	int v3 = 0;
	int v4 = 0;

	int j = 0;
	int dig;

	while (ipv4[j] != '.') {
		dig = ipv4[j] - '0';
		v1 = v1 * 10 + dig;
		j++;
	}

	j++;
	while (ipv4[j] != '.') {
		dig = ipv4[j] - '0';
		v2 = v2 * 10 + dig;
		j++;
	}

	j++;
	while (ipv4[j] != '.') {
		dig = ipv4[j] - '0';
		v3 = v3 * 10 + dig;
		j++;
	}

	j++;
	while (j < ipv4.size()) {
		dig = ipv4[j] - '0';
		v4 = v4 * 10 + dig;
		j++;
	}

	string ans = "0:0:0:0:0:FFFF:";

	ans.push_back(intToHex(v1/16));
	ans.push_back(intToHex(v1%16));
	ans.push_back(intToHex(v2/16));
	ans.push_back(intToHex(v2%16));
	ans.push_back(':');
	ans.push_back(intToHex(v3/16));
	ans.push_back(intToHex(v3%16));
	ans.push_back(intToHex(v4/16));
	ans.push_back(intToHex(v4%16));

	return ans;
}

int main(int argc, char **argv)
{
	string ipv4;
	cin >> ipv4;

	cout << "Corresponding IPv6 address --> " << ipv6(ipv4) << endl;

	return 0;
}
