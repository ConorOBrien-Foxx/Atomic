#include <iostream>

class N { public: static void f() { std::cout << "hello"; }};

int main() {
	N::f();
}