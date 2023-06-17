#include "MainClass.hpp"
#include "Vector2D.hpp"
// #include <wx/wx.h>

#include <iostream>
int main() {
	std::cout << "hello cmake tests" << std::endl;
	Vector2D v{1,2};
    v.add(v);
    std::cout << v << std::endl;
	return 0;
}

double MainClass::getDeltaTime(){
	return 1;
}