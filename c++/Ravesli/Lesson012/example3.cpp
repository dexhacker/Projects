#include <iostream>

int getValueFromUser() {
	std::cout << "Enter an integer: ";
	int x;
	std::cin >> x;
	return x;
}

int main() {
	int a = getValueFromUser();
	int b = getValueFromUser();

	std::cout << a << " + " << b << " = " << a + b << std::endl;
	return 0;
}

