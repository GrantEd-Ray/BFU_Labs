#include <iostream>

int main()
{
    float n;
    float x;
    
    std::cout << "Enter root: ";
    std::cin >> n;

    std::cout << "Enter number: ";
    std::cin >> x;

    float a = pow(x, 1 / n);
    std::cout << "" << a;
}
