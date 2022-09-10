#include <iostream>

int main()
{
    int n;
	int s = 0;
	int a_min = 1000000;
	int i_min = -1;

    std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		std::cin >> a;
		if (a % 10 != 1) 
		{
			s = s + a;
			if (a < a_min) 
			{
				a_min = a;
				i_min = i;
			}
		}
	}
	std::cout << "Sum: " << s << std::endl;
	std::cout << "Min: " << a_min << std::endl;
	std::cout << "Index: " << i_min << std::endl;
}
