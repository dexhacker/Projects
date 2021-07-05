#include <iostream>

void printO() {
	std::cout << "O" << std::endl;
}

void printK() {
	std::cout << "K" << std::endl;
}

void printOK() {
	printO();
	printK();
}

int main() {
	std::cout << "Starting main()" << std::endl;
	printOK();
	std::cout << "Ending main()" << std::endl;
	return 0;
}

