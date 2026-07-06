#include<iostream>
#include"func_template.hpp"

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