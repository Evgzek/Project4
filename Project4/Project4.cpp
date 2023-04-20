#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    // Открываем файл с программой на Си для чтения
    ifstream inputFile("program.c");
    if (!inputFile.is_open())
    {
        cout << "Не удалось открыть файл!" << endl;
        return 1;
    }

    // Инициализируем стек для скобок
    stack<char> bracketsStack;

    // Читаем файл посимвольно и обрабатываем скобки
    char ch;
    int lineNumber = 1;
    while (inputFile.get(ch))
    {
        if (ch == '\n')
        {
            lineNumber++;
        }
        else if (ch == '{')
        {
            bracketsStack.push(ch);
        }
        else if (ch == '}')
        {
            if (bracketsStack.empty())
            {
                cout << "Ошибка: неожиданная закрывающаяся скобка на строке " << lineNumber << endl;
                return 1;
            }
            else
            {
                bracketsStack.pop();
            }
        }
    }

    // Проверяем, остались ли скобки в стеке
    if (!bracketsStack.empty())
    {
        cout << "Ошибка: не хватает закрывающихся скобок" << endl;
        return 1;
    }

    // Закрываем файл с программой на Си
    inputFile.close();

    // Записываем результат проверки в файл
    ofstream outputFile("out.txt");
    if (!outputFile.is_open())
    {
        cout << "Не удалось создать файл для записи!" << endl;
        return 1;
    }

    if (bracketsStack.empty())
    {
        outputFile << "Проверка соответствия скобок завершена успешно" << endl;
        cout << "Проверка соответствия скобок завершена успешно" << endl;
    }
    else
    {
        outputFile << "Ошибка: не хватает закрывающихся скобок" << endl;
        cout << "Ошибка: не хватает закрывающихся скобок" << endl;
    }

    // Закрываем файл для записи
    outputFile.close();

    return 0;
}

