#include <iostream>


namespace gd
{
    void num_swap(int str[8])
    {
        for (int i = 0; i < 8 - 1; i++)
        {
            for (int j = i + 1; j < 8; j++)
            {
                if (str[i] > str[j])
                {
                    std::swap(str[i], str[j]);
                }
            }
        }
    }
}
