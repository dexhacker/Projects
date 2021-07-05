#include <iostream>

int add(int a, int b) {
	return a + b;
}

int main() {
	int x = 7;
	int y = 8;
	
	std::cout << add(x, y) << std::endl;
	return 0;
}

