#include "tasks.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

// Написать программу, которая принимает от пользователя символ, добавляет его к строке, выводит получившуюся строку и 
// снова просит у пользователя букву, повторяя операцию. Выполнять данные действия неопределенное кличесвто раз, пока 
// пользователем не будет введено число 0.
//
// Пример (символ ">" означает строку ввода пользователя):
// > a
// a
// > b
// ab
// > 0
// ab0
// Выполнение завершено.
void task1()
{
    string receivingstr, str = "";

    cout << "Enter the character > and the letter you want to enter\nTo complete, enter 0\nExample: > a\n";
    getline(cin, receivingstr);

    while (true)
    {
        if ((receivingstr.length() == 3) && (receivingstr[0] == '>') && (receivingstr[1] == ' ') )
        {
            if (((receivingstr[2] >= 'a') && (receivingstr[2] <= 'z')) || ((receivingstr[2] >= 'A') && (receivingstr[2] <= 'Z')))
            {
                str += receivingstr[2];
                cout << str << "\n";
                getline(cin, receivingstr);
            }
            else if (receivingstr[2] == '0')
            {
                str += receivingstr[2];
                cout << str;
                break;
            }
            else
            {
                cout << "\nError!\nEnter the character > and the letter you want to enter\nTo complete, enter 0\nExample: > a\n";
                getline(cin, receivingstr);
            }
        }
        else
        {
            cout << "\nError!\nEnter the character > and the letter you want to enter\nTo complete, enter 0\nExample: > a\n";
            getline(cin, receivingstr);
        }
    }
}

// Написать программу, которая вычисляет последовательность Фибоначчи и записывает её в массив. Длина
// последовательности определена пользователем. Массив с последовательностью вывести на экран.
// 
// Пример:
// > 6
// 0, 1, 1, 2, 3, 5, 8
void task2()
{
    string receivingstr;
    int s = 0, temp, i, *ar;
    bool key = true;

    stringstream ss;

    cout << "Enter the length of the masive\nThe number must be >= 2\nExample: > 6\n";
    getline(cin, receivingstr);

    while (key) // Проверка на ввод.
    {
        if ((receivingstr.length() > 2) && (receivingstr[0] == '>') && (receivingstr[1] == ' ') && (receivingstr.length() < 5))
        {
            if ((receivingstr.length() == 3) && ((receivingstr[2] == '0') || (receivingstr[2] == '1')))
            {
                cout << "\nError!\nEnter the length of the masive\nThe number must be >= 2\nExample: > 6\n";
                getline(cin, receivingstr);
                continue;
            }
            for (i = 2; i < receivingstr.length(); i++)
            {
                if ((receivingstr[i] < '0') || (receivingstr[i] > '9'))
                {
                    cout << "\nError!\nEnter the length of the masive\nThe number must be >= 2\nExample: > 6\n";
                    getline(cin, receivingstr);
                    break;
                }
                else if (i == receivingstr.length() - 1)
                {
                    key = false;
                }
            }
        }
        else
        {
            cout << "\nError!\nEnter the length of the masive\nThe number must be >= 2\nExample: > 6\n";
            getline(cin, receivingstr);
        }
    }

    for (i = 2; i < receivingstr.length(); i++) // Выделяем размер массива
    {
        ss << receivingstr[i];
        ss >> temp;
        ss.clear();

        s = s * 10 + temp;
    }

    s++;

    ar = new int[s]; // Создаём динамический массив
    
    ar[0] = 0;
    ar[1] = 1;

    cout << ar[0] << ", " << ar[1];

    for (i = 2; i < s; i++)
    {
        ar[i] = ar[i - 1] + ar[i - 2]; // Заполняем массив, последовательностью фибоначи
        cout << ", " << ar[i]; // Вывод массива
    }

    cout << "\n";
    delete[]ar;
}

// Написать программу, сортирующую набор чисел, интерактивно наполняемый пользователем. При запуске программа
// запрашивает у пользователя число, оно выводится на экран. Затем, у пользователя снова запрашивается число, которое
// добавляется к остальным, введенным ранее числам. Набор выводится на экран в отсортированном виде, а затем
// запрашивается очередное число. Запрос числа от пользователя и сортировку перед выводом повторять до ввода
// пользователем числа "-1". Пользователь вводит только неотрицательные целые числа.
// 
// Пример:
// > 5
// 5
// > 2
// 2 5
// > 8
// 2 5 8
// > 3
// 2 3 5 8
// > -1
// Выполнение завершено.
void task3()
{
    string receivingstr;
    int  i, temp, numberOfDigits = 0, *arrayOfDigits;

    arrayOfDigits = new int[1]; // Создаём динамический массив

    stringstream ss;

    cout << "Enter a number > 0 and < 10\nTo end the program, enter -1\nExample: > 5\n";

    while (true) // Запуск програмы до ввода > -1
    {
        getline(cin, receivingstr);
        
        if ((receivingstr[0] == '>') && (receivingstr[1] == ' ')) // Если соблюдаются первые условия > 
        {
            if ((receivingstr[2] == '-') && (receivingstr[3] == '1') && (receivingstr.length() == 4))
            {
                cout << "Execution completed\n";
                delete[] arrayOfDigits;
                break; // Завершаем программу
            }
            else if ((receivingstr[2] > '0') && (receivingstr[2] <= '9') && (receivingstr.length() == 3)) // Если введено число
            {
                if (numberOfDigits == 0) // Если оно первое, то заполняем. Делается для того что-бы была хотя бы опора для изменнеия размера массива
                {
                    ss << receivingstr[2];
                    ss >> arrayOfDigits[0];
                    ss.clear();

                    cout << arrayOfDigits[0] << "\n";
                }
                else // Если в массиве что-то есть, то мы увеличиваем его на + 1
                {
                    int* arrayTemp;
                    arrayTemp = new int[numberOfDigits]; // Создаём временный массив с такиз же размером как и у оригинала

                    for (i = 0; i < numberOfDigits; i++) // Заполняем массив.
                    {
                        arrayTemp[i] = arrayOfDigits[i];
                    }

                    delete[] arrayOfDigits; // Удаляем оригинал

                    arrayOfDigits = new int[numberOfDigits + 1]; // Вновь создаём оригинал с дополнительным значением.

                    for (i = 0; i < numberOfDigits; i++) // Возвращаем ему его значения
                    {
                        arrayOfDigits[i] = arrayTemp[i];
                    }

                    ss << receivingstr[2];
                    ss >> temp;
                    ss.clear();

                    arrayOfDigits[numberOfDigits] = temp; // Добавляем недостающее значение
                    sort(arrayOfDigits, arrayOfDigits + numberOfDigits + 1); // Сортируем массив

                    for (i = 0; i < numberOfDigits + 1; i++) // Выводим новый массив
                    {
                        cout << arrayOfDigits[i] << " ";
                    }

                    delete []arrayTemp;// Удаляем временный массив
                    cout << "\n";
                }

                numberOfDigits++;
            }
            else
            {
                cout << "\nError!\nEnter a number > 0 and < 10\nTo end the program, enter -1\nExample: > 5\n";
            }
        }
        else
        {
            cout << "\nError!\nEnter a number > 0 and < 10\nTo end the program, enter -1\nExample: > 5\n";
        }
    }
}

// Написать программу, которая рисует дерево интерактивно, в зависимости от пользовательского ввода. При запуске
// выводится ствол дерева с помощью символа "|", затем выводится разветвление с помощью строки из символов "\ /".
// После вывода у пользователя запрашивается число 1 или 0. Если пользователь вводит 0, то дерево продолжит рост левее,
// а если 1 - правее. После этого вывести на экран дерево с новой высотой. Повторять, пока пользователь не введет "-1".
//
// Пример:
// \ /
//  |
// > 0
// \ /
//  \ /
//   |
// > 1
//  \ /
// \ / 
//  \ /
//   |
// > -1
void task4()
{
    string temp, receivingstr, tree = "\\ /\n |\n"; // temp - Переменная для здвига дерева, receivingstr - Принимающая действия переменная, tree - само дерево
    int i, shift = 0; // Переменная для счётчика и для проверки необходимости сдвига.

    
    cout << "Let's plant a tree\nTo add a branch to the right, enter: > 1\nTo add a branch to the left, enter: > 0\nTo complete the work, enter: > -1\n\n";
    cout << tree;

    while (true) // Сама программа
    {
        getline(cin, receivingstr);

        if ((receivingstr[0] == '>') && (receivingstr[1] == ' ')) // Если соблюдаються начальные условия ввода > 
        {
            if ((receivingstr[2] == '0') && (receivingstr.length() == 3)) // Если происходит сдвиг влево
            {
                shift--; // Уменьшаем возвозное колличество пробелов.
                reverse(tree.begin(), tree.end()); // Переворачиваем дерево для добавления к нему веток
                tree += "\n/ \\";// Добавляем ветку

                if (shift >= 0)// Проверяем нужны ли ей пробелы 
                {
                    for (i = 0; i < shift; i++)
                    {
                        tree += " ";
                    }

                    reverse(tree.begin(), tree.end());
                }
                else // Если пробелы не нужны, то нужно двигать дерево 
                {
                    reverse(tree.begin(), tree.end()); // Переворачиваем дерево для пересадки во временный горшок

                    for (i = 0; i < tree.length(); i++)
                    {
                        if (tree[i] == '\n')
                        {
                            temp += "\n "; // Двигаем каждую веточку на пробел
                        }
                        else
                        {
                            temp += tree[i];
                        }
                    }

                    tree = temp;
                    shift = 0;
                    temp = "";
                }
                
                cout << tree; // выводим дерево
            }
            else if ((receivingstr[2] == '1') && (receivingstr.length() == 3)) // Если сдвиг происходит вправо
            {
                shift++; // Добавляем пробелы

                reverse(tree.begin(), tree.end()); // Так-же переворачиваем дерево, для добавления веточек.
                
                tree += "\n/ \\"; 
                for (i = 0; i < shift; i++) // Ставим нужное колличество пробелов.
                {
                    tree += " ";
                }

                reverse(tree.begin(), tree.end());
                cout << tree; // Выводим дерево.
            }
            else if ((receivingstr[2] == '-') && (receivingstr[3] == '1') && (receivingstr.length() == 4))
            {
                break; // Завершаем программу при вводе: > -1
            }
            else // Если пользователь ввёл что-то не правильно
            {
                cout << "\nError!\n";
            }
        }
        else // Если пользователь ввёл что-то не правильно
        {
            cout << "\nError!\n";
        }
    }
}

// Написать программу, которая запрашивает от пользователя набор слов, отправка каждого слова подтверждается нажатием
// клавиши Enter. Запрашивать слова, пока пользователь не введет символ "0". Затем, вывести на экран топ самых часто
// встречаемых букв в введенных словах от наиболее частой до наименее частой, в формате "буква = количество".
//
// Пример:
// > амогус
// > апорт
// > агент
// > 0
// а = 3
// г = 2
// о = 2
// е = 1
// м = 1
// н = 1
// п = 1
// р = 1
// с = 1
// т = 1
// у = 1
void task5()
{
    string tempText, text = "";
    int i;

    map <char, int> m; // Создаём контейнер сохраняющий букву (ключ) и значение (коллическтво)

    cout << "Enter the words\nExample: > amogus\nTo complete, enter > 0\n";

    while (true)
    {
        getline(cin, tempText);

        if ((tempText[0] == '>') && (tempText[1] == ' ') && (tempText.length() > 2) && (tempText.length() < 15))
        {
            if ((tempText[2] == '0') && (tempText.length() == 3))
            {
                for (i = 0; i < text.length(); i++)
                {
                    if (isupper(text[i])) text[i] = tolower(text[i]); // Если большая буква, то делаем её маленькой.
                    if (isalpha(text[i])) m[text[i]]++; // Если это буква, то добавляем в контейнер букву.
                }

                for (auto j = m.begin(); j != m.end(); j++)
                {
                    cout << j->first << " = " << j->second << "\n";
                }
                
                break;
            }
            
            for (i = 2; i < tempText.length(); i++)
            {
                if (((tempText[i] < 'a') || (tempText[i] > 'z')) && ((tempText[i] < 'A') || (tempText[i] > 'Z')))
                {
                    cout << "Error!\n";
                    break;
                }
                else if (i == tempText.length() - 1)
                {
                    text += tempText;
                }
            }
        }
        else
        {
            cout << "Error!\n";
        }
    }
}

// Написать программу, которая запрашивает от пользователя набор чисел, отправка каждого числа подтверждается нажатием
// клавиши Enter. Запрашивать числа, пока пользователь не введет символ "0". Числа целые и строго больше нуля. После
// окончания ввода программа объединяет цифры всех чисел последовательно в одно большое число, возводит его в степень
// числа 2, затем разворачивает получившееся значение и берет у результата квадратный корень. Результат всех операций
// вывести на экран.
//
// Пример:
// > 2
// > 4
// > 1
// > 0
// 134
// Программа завершена.
// Комментарий к результату примера: 241^2 -> 58081 -> 18085 -> 134 (округлить до целого)
// В решении использовать динамически выделяемую память - как и во всех остальных задачах :)

int Upheaval(int x)
{
    int y = 0;
    while (x)
    {
        y = y * 10 + x % 10;
        x /= 10;
    }
    return y;
}

void task6()
{
    string receivingstr, numberstr = ""; // Создаём две переменных, принимаюшая и основная
    int numberint = NULL;// Создаём число и присваиваем ему значение null что-бы не было ошибки, если пользователь решит сразу ввести > 0

    stringstream ss;// Преобразование в int

    cout << "Enter a number\nNumber > 0 and < 10\nExample: > 2\nTo complete, enter > 0\n";

    while (true)
    {
        getline(cin, receivingstr);

        if ((receivingstr.length() == 3) && (receivingstr[0] == '>') && (receivingstr[1] == ' '))// Проверяем начальное условие: > 
        {
            if ((receivingstr[2] > '0') && (receivingstr[2] <= '9'))// Если это число 
            {
                numberstr += receivingstr[2]; // Добавляем в основной список чисел
            }
            else if (receivingstr[2] == '0') // Если пользователь решил завершить программу
            {
                ss << numberstr;
                ss >> numberint;
                ss.clear();

                numberint *= numberint; // Производим преобразования, которые заданы в условии

                numberint = Upheaval(numberint);

                numberint = sqrt(numberint);
                
                cout << numberint;// Выводим результат
                break;// Завершаем программу 
            }
            else
            {
                cout << "Error!\n";
            }
        }
        else
        {
            cout << "Error!\n";
        }
    }
}

// Написать небольшую игру для двух игроков за одной клавиатурой. Правила - при старте программы вводится предельное
// число. Затем, программа запрашивает от каждого игрока по очереди число. Введенные числа суммируются. Игрок, который
// ввел последнее число, сделавшее текущую сумму очков превышающей предельное число проигрывает. При каждом вводе числа
// от игрока выводить на экран текущий набор ранее введенных чисел.
//
// Пример:
// > 12
// Player 1 > 3
// 3
// Player 2 > 5
// 3 5
// Player 1 > 5
// 3 5 5
// Player 1 lost.
// Программа завершена.
void task7()
{
    string receivingstr, sum;
    int i, temp, numint = 0;
    bool key = true;

    stringstream ss;

    cout << "Enter a number =>10 and <=100\nExample: > 12\n";

    while (true) // Проверка на ввод 
    {
        getline(cin, receivingstr);

        if ((receivingstr[0] == '>') && (receivingstr[1] == ' ')) // Если соблюдаются начальные условия: > 
        {
            if (((receivingstr.length() == 4) && (receivingstr[2] > '0') && (receivingstr[2] <= '9') && (receivingstr[3] >= '0') && (receivingstr[3] <= '9')) || ((receivingstr.length() == 5) && (receivingstr[2] == '1') && (receivingstr[3] == '0') && (receivingstr[4] == '0')))
            {
                for (i = 2; i < receivingstr.length(); i++)// Если число >= 10 и <= 100
                {
                    ss << receivingstr[i];
                    ss >> temp;
                    ss.clear();

                    numint = numint * 10 + temp;
                }

                break;
            }
            else
            {
                cout << "Error!\n";
            }
        }
        else
        {
            cout << "Error!\n";
        }
    }

    cout << "\nLet's start the game\nThe number is entered > 0 and < 10\nExample: > 3\nThe one who last entered a number exceeding loses -> " << numint << "\n"; // Начинаем игру

    while (key)
    {
        for (i = 0; i < 2; i++)
        {
            while (true) // Проверка на ввод, число должно быть > 0 и < 10
            {
                cout << "Player " << i + 1 << " ";
                getline(cin, receivingstr);

                if ((receivingstr.length() == 3) && (receivingstr[0] == '>') && (receivingstr[1] == ' ') && (receivingstr[2] > '0') && (receivingstr[2] <= '9'))
                {
                    sum = sum + receivingstr[2] + " ";
                    break;
                }
                else
                {
                    cout << "Error!\n";
                }
            }

            cout << sum << "\n"; // Выводим числа

            ss << receivingstr[2];
            ss >> temp;
            ss.clear();

            numint -= temp;

            if (numint < 0) // Если достигли предела
            {
                cout << "Player " << i + 1 << " lost\n";
                key = false;
                break;
            }
        }
    }
}