/*#include <iostream>

int main()
{
    int a;
    int b;
    int c;
    std::cin >> a >> b >> c;

    if (((a + b) % c == 0) and (c % b == 0))
    {
        int s = (a + b) / c - c / b;
        std::cout << s;
    }
    else if (((a + b) % c == 0) and (c % b > 0))
    {
        int s = (a + b) / c + b * c;
        std::cout << s;
    }
    else
    {
        int s = a - b + c;
        std::cout << s;
    }
}*/

#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    switch (n)
    {
        case 1:
            std::cout << "Apple";
            break;
        case 2:
            std::cout << "Mango";
            break;
        case 3:
            std::cout << "Milk";
            break;
        case 4:
            std::cout << "Juice";
            break;
        case 5:
            std::cout << "Cornflakes";
            break;
        default: 
            std::cout << "No product";
    }
}
