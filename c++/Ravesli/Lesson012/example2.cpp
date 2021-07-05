#include <iostream>

int return7() {
	return 7;
}

int main() {
	std::cout << return7() << std::endl;
	std::cout << return7() + 3 << std::endl;

	return7();

	return 0;
}

