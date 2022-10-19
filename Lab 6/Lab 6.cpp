
#include <iostream>
#include <time.h>
#include <math.h>
#include "has8.h"
#include "num_swap.h"


namespace gd
{
    const int size = 8;

    /*bool has8(int str[size])
    {
        bool is8 = false;
        for (int x = 0; x < size; x++)
        {
            int tmp = abs(str[x]);
            while (tmp > 0)
            {
                if (tmp % 10 == 8)
                {
                    is8 = true;
                    break;
                }
                tmp /= 10;
            }
            if (is8)
                break;
        }
        return is8;
    }*/


    /*void num_swap(int str[size])
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (str[i] > str[j])
                {
                    std::swap(str[i], str[j]);
                }
            }
        }
    }*/

    int main()
    {
        srand(time(NULL));
        int mas[size][size];
        int num;
        int min_num = INT_MAX;
        int max_num = INT_MIN;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                num = rand() - (RAND_MAX / 2);
                if (num < 0)
                {
                    mas[i][j] = num % 100;
                    std::cout << mas[i][j] << " ";
                }
                else
                {
                    mas[i][j] = num % 100;
                    std::cout << mas[i][j] << " ";
                }

                if (mas[i][j] < min_num)
                    min_num = mas[i][j];
                if (mas[i][j] > max_num)
                    max_num = mas[i][j];
            }
            std::cout << "" << std::endl;
        }
        std::cout << min_num << " " << max_num << std::endl;
        std::cout << "" << std::endl;

        if (min_num + max_num == 0)
        {
            for (int i = 0; i < size; i++)
            {
                if (has8(mas[i]))
                {
                    num_swap(mas[i]);
                }
            }
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
                std::cout << mas[i][j] << " ";
            std::cout << "" << std::endl;
        }
    }
}


