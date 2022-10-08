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
    int size = 0;

    while (!in.eof())
    {
        in >> str;
        strcpy_s(words[size], str);
        size++;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < strlen(words[i]); j++)
        {
            if (127 < words[i][j] < 160)
                words[i][j] += 32;
        }
        std::cout << words[i] << std::endl;
    }
    //char tmp[100] = "";
    //for (int i = 0; i < strlen(str); i++) {
        //char letter[100] = { str[i] };
        //strcat_s(tmp, letter);
    //}
}
