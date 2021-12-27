#include<iostream>
#include"Net.hpp"

int main(void)
{
    srand(1);
    Net net({2, 4, 1});
    net.Print(3);
    return 0;
} 