// #2

#include <iostream>
#include <fstream>

int main()
{
    setlocale(LC_ALL, "Rus");
    char str[100];
    std::ifstream in("Input.txt", std::ios::in);
    if (!in.is_open())
    {
        std::cout << "Error!";
        return -1;
    }
    //in.getline(str, 100);
    //std::cout << str;

    char words[100][100];
    char words2[100][100];
    char words3[100][100];
    for (int a = 0; a < 100; a++)
        for (int b = 0; b < 100; b++)
        {
            words2[a][b] = 0;
            words3[a][b] = 0;
        }
    int size = 0;

    while (!in.eof())
    {
        in >> str;
        strcpy_s(words[size], str);
        size++;
    }

    char symbs[15] = ".,;:!?";
    //преобразуем заглавные буквы в стррочные и убираем знаки препинания
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < strlen(words[i]); j++)
        {
            bool is_symb = false;
            if ((191 < (unsigned char)words[i][j]) and ((unsigned char)words[i][j] < 224))
                words[i][j] += 32;
            for (int k = 0; k < strlen(symbs); k++)
            {
                if (words[i][j] == symbs[k])
                {
                    is_symb = true;
                }
            }
            if (!is_symb)
            {
                words2[i][j] = words[i][j];
            }
        }
    }
    // убираем повторяющиеся слова
    int size2 = 0;
    for (int i = 1; i < size; i++)
    {
        bool is_repeated = false;
        for (int j = 0; j < i; j++)
        {
            if (words2[i] == words2[j])
            {
                is_repeated = true;
                break;
            }

        }
        if (!is_repeated)
        {
            for (int k = 0; k < strlen(words2[i]); k++)
                words3[size2][k] = words2[i][k];
            std::cout << words3[size2] << std::endl;
            size2++;
        }
    }

    for (int i = 0; i < size2; i++)
    {
        char buff[34];

    }

}
