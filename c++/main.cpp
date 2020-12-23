#include <iostream>
#include <cassert>

using namespace std;

int Sum(int x, int y) {
//	return x + y - 1;
	return x + y;
}

void TestSum() {
	assert(Sum(2, 3) == 5);
	cout << "Tests complited!" << endl;
}

int main() {
	TestSum();
	return 0;
}
