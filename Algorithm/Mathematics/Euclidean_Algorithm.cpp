#include <iostream>

using namespace std;

int gcd(int a, int b) {
	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {

	int a = 24, b = 12;

	cout << gcd(a, b);

	return 0;
}
