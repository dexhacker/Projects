#include <iostream>

int add(int a, int b) {
	return a + b;
}

int multiply(int c, int d) {
	return c * d;
}

int main() {
	std::cout << add(7, 8) << std::endl;
	std::cout << multiply(4, 5) << std::endl;

	std::cout << add(2 + 3, 4 * 5) << std::endl;

	int x = 4;
	std::cout << add(x, x) << std::endl;

	std::cout << add(1, multiply(2, 3)) << std::endl;
	std::cout << add(1, add(2, 3)) << std::endl;

	return 0;
}

