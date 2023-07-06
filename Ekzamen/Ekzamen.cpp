#include<ctime>
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<Windows.h>
#include <fstream>




class Caesar
{
    char* str;
    char str2[50];
    int size;
    int temp[50];
    

public:
    Caesar(char* str1, int size1)
    {
        str = str1;
        size = size1;
        str = new char[size];
        for (int i = 0; i < size; i++)
        {
            str[i] = str1[i];
        }
    }
    //Зашифровать
    void Encrypt()
    {
        for (int i = 0; i < size; i++)
        {
            //str2[i] = str[i];
            temp[i] = str[i] + 3;
        }
    }
    //что получилось
    void itog()
    {
        for (int i = 0; i < size; i++)
        {
            str2[i] = temp[i];
        }
    }
    //Возврат готового шифра
    char* getStr()
    {
        return str2;
    }
    ~Caesar()
    {
        //std::cout << std::endl << "Вызван деструктор!";
        delete str;
    }
    //Вывод в консоль (проверка)
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << str[i];
        }
        
    }
};

class Record
{
    char* str;
    int size;
public:
    Record(char* str1, int size1)
    {
        str = str1;
        size = size1;
    }
    void record()
    {
        std::ofstream out; //поток записи
        out.open("words.txt", std::ios::app); //открытие файла
        if (out.is_open())
        {
            out << str << std::endl;
            //out << str2 << std::endl;
        }
        else
            std::cout << "File is NOT open!!!";

        out.close();
        std::cout << "Слово записано!" << std::endl;
    }
    ~Record()
    {
        
    }
};

void xapis(char str[])
{
    int b[50];

    //пересчет символов
    int t = strlen(str);

    //преобразование в число +1
    for (int i = 0; i < t; i++)
    {
        b[i] = str[i] + 3;
    }

    //Провека какое число получилось
    /*for (int i = 0; i < t; i++)
    {
        std::cout << b[i] << "\n";
    }*/

    //Запись зашифрованного текста в источник
    for (int i = 0; i < t; i++)
    {
        str[i] = b[i];
    }

    //Проверка на корректность Шифрования
    /*for (int i = 0; i < t; i++)
    {
        std::cout << str[i];
    }*/
}

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int num{ 50 };
    char* p;
    int size;
    p = new char[num];
    std::cin.getline(p,num);
    size = strlen(p);
    std::cout << size;
    Caesar a(p,size);
    a.Encrypt();
    a.itog();
    a.print();
    delete[] p;

    p = a.getStr();
    Record r(p, size);
    r.record();
}