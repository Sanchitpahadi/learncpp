#include<iostream>
#include"func_template.hpp"
#include"class_template.hpp"


void func_temp()
{
    int max = Max<int>(10,20);
    double maxd = Max<double>(20.33333,20.3334);

    double x = zero<double>(20.3); 

    double dd = add(20.33 , 20);

    std::cout << max << std::endl;
    std::cout << maxd << std::endl;
    std::cout << x << std::endl;
    std::cout << dd << std::endl;
}

void class_temp()
{
Box<int> intBox(42);
Box<std::string> strBox("hello");

int num = intBox.get();
std::string str = strBox.get();

std::cout << num << std::endl;
std::cout << str << std::endl;


}