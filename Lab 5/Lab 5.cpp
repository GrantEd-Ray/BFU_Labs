// #2

#include <iostream>
#include <fstream>

int main()
{
    setlocale(LC_ALL, "Rus");
    char str[100];
    std::ifstream in("Input.txt", std::ios::in);
    std::ofstream out("Output.txt", std::ios::out);
    if (!in.is_open())
    {
        std::cout << "Error!";
        return -1;
    }
    //in.getline(str, 100);
    //std::cout << str;
    int N;
    in >> N;

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
            //std::cout << words3[size2] << std::endl;
            size2++;
        }
    }

    char letters[100];
    int letters_nums[100];
    for (int i = 0; i < 100; i++)
    {
        letters[i] = 0;
        letters_nums[i] = 0;
    }
    // считаем буквы
    for (int i = 0; i < size2; i++)
    {
        //char buff[34];
        //int buff_size = 0;

        if (strlen(words3[i]) == 1)
        {
            std::cout << words3[i] << " " << 1 << std::endl;
            letters[i] = words3[i][0];
            letters_nums[i] = 1;
        }
        else
        {
            char letter = words3[i][0];
            int letter_sum = 1;

            for (int j = 1; j < strlen(words3[i]); j++)
            {
                char tmp = words3[i][j];
                int tmp_num = 1;

                for (int k = 0; k < j; k++)
                    if (words3[i][j] == words3[i][k])
                        tmp_num++;
                if (tmp_num > letter_sum)
                {
                    letter_sum = tmp_num;
                    letter = tmp;
                }
            }

            std::cout << words3[i] << " " << letter << " " << letter_sum << std::endl;
            letters[i] = letter;
            letters_nums[i] = letter_sum;
        }
        
    }
    std::cout << "" << std::endl;

    // сортируем список
    for (int i = 0; i < size2 - 1; i++)
        for (int j = i + 1; j < size2; j++)
            if (letters_nums[i] < letters_nums[j])
            {
                std::swap(words3[i], words3[j]);
                std::swap(letters[i], letters[j]);
                std::swap(letters_nums[i], letters_nums[j]);
            }
    // вывод
    for (int i = 0; i < N; i++)
    {
        std::cout << words3[i] << " " << letters[i] << " " << letters_nums[i] << std::endl;
        out << words3[i] << " " << letters[i] << " " << letters_nums[i] << "\n";
    }
}
