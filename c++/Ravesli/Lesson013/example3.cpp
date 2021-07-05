#include <iostream>

int doubleNumber(int a) {
	return 2 * a;
}

int main() {
	int a;
	std::cout << "Enter a number: ";
	std::cin >> a;
	std::cout << doubleNumber(a) << std::endl;
	return 0;
}

