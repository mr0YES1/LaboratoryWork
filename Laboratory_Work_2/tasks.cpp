#include "tasks.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

// Написать функцию, проверяющую 2 любых элемента на равенство. Оба элемента передаются как аргументы функции, могут 
// быть целым числом (int), строкой (string) или массивом (array) и могут быть переданы в любом порядке. Оба элемента
// считаются равными если:
// - оба числа - если они равны: 5 = 5, 5 != 7
// - обе сторки - если строки равны, без учета регистра: "hello" = "hello" = "hElLO", "hello" != "world"
// - оба массивы - все элементы массивов совпадают и стоят на тех же местах:
//   ["h", "e", "l", "l", "o"] = ["h", "e", "l", "l", "o"], ["h", "e", "l", "l", "o"] != ["h", "l", "e", "l", "o"]
// - число и массив - длинна массива равна числу:
//   ["h", "e", "l", "l", "o"] = 5, ["h", "e", "l", "l", "o"] != 8
// - число и строка - длинна строки равна числу:
//   ["h", "e", "l", "l", "o"] = "hello", ["h", "e", "l", "l", "o"] = "abcde", ["h", "e", "l", "l", "o"] != "abcdefg"
// - строка и массив - каждый элемент массива равен соответствующему элементу строки:
//   "hello" = ["h", "e", "l", "l", "o"], "hlelo" != ["h", "e", "l", "l", "o"]
// Результат работы функции вывести на экран.
// 
// Пример функции:
// equal(5, 5) -> true
// equal(5, 7) -> false

void equal(int num1, int num2);
void equal(string str1, string str2);
void equal(int num1, string str2);
void equal(string str1, int num2);

void task1()
{
    size_t i, j;
    int num1, num2;
    string sym, str1, str2;
    bool i1 = false, i2 = false, s1 = false, s2 = false, key = true;

    stringstream ss;

    for (j = 0; j < 2; j++)
    {
        cout << "Enter the desired type of the " << j + 1 << "st/nd element\nExample:\ni - integer;\ns - string;\na - array;\n";
        getline(cin, sym);

        while (true)
        {
            if (((sym[0] != 'i') && (sym[0] != 's') && (sym[0] != 'a')) || (sym.length() > 1))
            {
                cout << "\nError!\nEnter the desired type of the " << j + 1 << "st/nd element\nExample:\ni - integer;\ns - string;\na - array;\n";
                getline(cin, sym);
            }
            else
            {
                break;
            }
        }

        switch (sym[0])
        {
        case 'i':
            cout << "\nEnter the " << j + 1 << "st/nd integer: ";
            getline(cin, sym);

            while (key)
            {
                if ((sym[0] == '-') && (sym.length() > 1))
                {
                    for (i = 1; i < sym.length(); i++)
                    {
                        if ((sym[i] < '0') || (sym[i] > '9') || (sym.length() > 9))
                        {
                            cout << "\nError!\nEnter the " << j + 1 << "st/nd integer: ";
                            getline(cin, sym);
                            break;
                        }
                        else if (i == sym.length() - 1)
                        {
                            key = false;
                        }
                    }
                }
                else
                {
                    for (i = 0; i < sym.length(); i++)
                    {
                        if ((sym[i] < '0') || (sym[i] > '9') || (sym.length() > 9))
                        {
                            cout << "\nError!\nEnter the " << j + 1 << "st/nd integer: ";
                            getline(cin, sym);
                            break;
                        }
                        else if (i == sym.length() - 1)
                        {
                            key = false;
                        }
                    }
                }
            }

            if (j == 0)
            {
                ss << sym;
                ss >> num1;
                ss.clear();
                i1 = true;
            }
            else
            {
                ss << sym;
                ss >> num2;
                ss.clear();
                i2 = true;
            }

            break;
        case 's':
            cout << "\nEnter the " << j + 1 << "st/nd word: ";
            getline(cin, sym);

            while (key)
            {
                for (i = 0; i < sym.length(); i++)
                {
                    if (((sym[i] < 'a') || (sym[i] > 'z')) && ((sym[i] < 'A') || (sym[i] > 'Z')) || (sym.length() > 10))
                    {
                        cout << "\nError!\nEnter the " << j + 1 << "st/nd word: ";
                        getline(cin, sym);
                        break;
                    }
                    else if (i == sym.length() - 1)
                    {
                        key = false;
                    }
                }
            }

            if (j == 0)
            {
                str1 = sym;
                s1 = true;
            }
            else
            {
                str2 = sym;
                s2 = true;
            }

            break;

        case 'a':
            cout << "\nEnter the " << j + 1 << "st/nd array : \nExample : [\"A\", \"B\", \"C\"]\n";
            getline(cin, sym);

            while (key)
            {
                if ((sym[0] != '[') || (sym[1] != '\"') || (sym[sym.length() - 1] != ']') || (sym[sym.length() - 2] != '\"') || (sym.length() < 5))
                {
                    cout << "\nError!\nEnter the " << j + 1 << "st/nd array : \nExample : [\"A\", \"B\", \"C\"]\n";
                    getline(cin, sym);
                    continue;
                }

                for (i = 2; i < sym.length(); i += 5)
                {
                    if (i == sym.length() - 3)
                    {
                        key = false;
                        break;
                    }

                    if ((i == sym.length() - 1) || (i == sym.length() - 2))
                    {
                        cout << "\nError!\nEnter the " << j + 1 << "st/nd array : \nExample : [\"A\", \"B\", \"C\"]\n";
                        getline(cin, sym);
                        break;
                    }

                    if ((sym[i + 1] != '\"') || (sym[i + 2] != ',') || (sym[i + 3] != ' ') || (sym[i + 4] != '\"'))
                    {
                        cout << "\nError!\nEnter the " << j + 1 << "st/nd array : \nExample : [\"A\", \"B\", \"C\"]\n";
                        getline(cin, sym);
                        break;
                    }
                }
            }

            if (j == 0)
            {
                str1 = sym;
                s1 = true;
            }
            else
            {
                str2 = sym;
                s2 = true;
            }

            break;
        default:
            break;
        }

        key = true;
        cout << "\n";
    }

    if ((i1) && (i2))
    {
        equal(num1, num2);
    }
    else if ((i1) && (s2))
    {
        equal(num1, str2);
    }
    else if ((s1) && (i2))
    {
        equal(str1, num2);
    }
    else if ((s1) && (s2))
    {
        equal(str1, str2);
    }
}

void equal(int num1, int num2)
{
    if (num1 == num2)
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }
}

void equal(string str1, string str2)
{
    int count = 0;

    if ((str1[0] == '[') && (str2[0] == '['))
    {
        if (str1 == str2)
        {
            cout << "true\n";
        }
        else
        {
            cout << "false\n";
        }
    }
    else if (str1[0] == '[')
    {
        for (int i = 2; i < str1.length(); i += 5)
        {
            count++;
        }

        if (count == str2.length())
        {
            for (int i = 2, j = 0; j < count; i += 5, j++)
            {
                if (str1[i] != str2[j])
                {
                    cout << "false\n";
                    break;
                }
                else if (j == count - 1)
                {
                    cout << "true\n";
                }
            }
        }
    }
    else if (str2[0] == '[')
    {
        for (int i = 2; i < str2.length(); i += 5)
        {
            count++;
        }

        if (count == str1.length())
        {
            for (int i = 2, j = 0; j < count; i += 5, j++)
            {
                if (str2[i] != str1[j])
                {
                    cout << "false\n";
                    break;
                }
                else if (j == count - 1)
                {
                cout << "true\n";
                }
            }
        }
    }
    else if (_stricmp(str1.c_str(), str2.c_str()) == 0)
    {
    cout << "true\n";
    }
    else
    {
    cout << "false\n";
    }
}

void equal(int num1, string str2)
{
    int count = 0;

    if (str2[0] == '[')
    {
        for (int i = 2; i < str2.length(); i += 5)
        {
            count++;
        }

        if (count == num1)
        {
            cout << "true\n";
        }
        else
        {
            cout << "fasle\n";
        }
    }
    else if (str2.length() == num1)
    {
        cout << "true\n";
    }
    else
    {
        cout << "fasle\n";
    }
}

void equal(string str1, int num2)
{
    int count = 0;

    if (str1[0] == '[')
    {
        for (int i = 2; i < str1.length(); i += 5)
        {
            count++;
        }

        if (count == num2)
        {
            cout << "true\n";
        }
        else
        {
            cout << "fasle\n";
        }
    }
    else if (str1.length() == num2)
    {
        cout << "true\n";
    }
    else
    {
        cout << "fasle\n";
    }
}

// Написать функцию сортировки одномерного массива. Алгоритм сортировки может быть любой (не использовать стандартные
// функции сортировки из встроенных или сторонних библиотек). Функция должна МОДИФИЦИРОВАТЬ исходный массив,
// а не возвращать новый. Результат работы функции вывести на экран.
// 
// Пример:
// arr = [2, 4, 1, 3, 6, 5]
// sort(arr)
// arr = [1, 2, 3, 4, 5, 6]

void sort(int* arr, int count);

void task2()
{
    int i, j, temp = 0, count1 = 1, count2 = 0;
    string arrstr;
    bool whitespace = false, key = true;

    stringstream ss;

    cout << "Enter an array containing integer digits\nExample: 1 2 34 21 22\n\n";

    getline(cin, arrstr);

    while (key)
    {
        if (arrstr == "")
        {
            cout << "Error!\nEnter an array containing integer digits\nExample: 1 2 34 21 22\n\n";
            getline(cin, arrstr);
            continue;
        }

        for (i = 0; i < arrstr.length(); i++)
        {
            count2++;
            
            if ((arrstr[i] == ' ') && (i != 0) && (!whitespace) && (i != arrstr.length() - 1))
            {
            whitespace = true;
            count1++;
            count2 = 0;
            continue;
            }
            else if ((arrstr[i] < '0') || (arrstr[i] > '9') || count2 > 5)
            {
                cout << "Error!\nEnter an array containing integer digits\nExample: 1 2 34 21 22\n\n";
                count1 = 1;
                count2 = 0;
                getline(cin, arrstr);
                break;
            }
            else if (i == arrstr.length() - 1)
            {
                key = false;
                break;
            }
            else
            {
                whitespace = false;
            }
        }
    }

    int* arri = new int[count1];
    count2 = 0;
    
    for (i = 0; i < count1; i++)
    {
        arri[i] = 0;
        
        for (j = count2; j < arrstr.length(); j++)
        {
            if (arrstr[j] != ' ')
            {
                ss << arrstr[j];
                ss >> temp;
                ss.clear();
                arri[i] = arri[i] * 10 + temp;
                temp = 0;  
            }
            else
            {
                count2 = j + 1;
                break;
            }

        }
    }
    
    sort(arri, count1);

    for (i = 0; i < count1; i++)
    {
        cout << arri[i] << " ";
    }

    cout << "\n";
}

void sort(int *arr, int count)
{   
    int i, j, temp;
    
    for (i = 1; i < count; i++)
    {
        for (j = 0; j < count - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Написать функцию переводящую входную строку в верхний регистр.Функция может принимать 1, 2 или 3 аргумента. Первый
// аргумент всегда строка.Если передано 2 аргумента, то второй означает порядковый номер буквы, которая должна быть
// переведена в верхний регистр вместо всей строки.Если передано 3 аргумента, то 3ий это количество букв, которые
// должны быть переведены в верхний регистр после той что указана во 2ом.
// Сигнатура у функции должна быть только ОДНА. Результат работы функции вывести на экран.
// 
// Примеры:
// upper("helloworld") -> HELLOWORLD
// upper("helloworld", 5) -> heLloWorld
// upper("helloworld", 5, 3) -> heLloWORld

void upper(string word, int two, int three);

void task3()
{
    string word, ch, twos, threes;
    long int j;
    int i, twoi = -1, threei = -1;
    bool key = true;

    stringstream ss;

    cout << "Enter the word\nExample: helloworld\n";
    getline(cin, word);

    while (key)
    {
        for (i = 0; i < word.length(); i++)
        {
            if ((word[i] < 'a') || (word[i] > 'z'))
            {
                cout << "\nError!\nEnter the word\nExample: helloworld\n";
                getline(cin, word);
                break;
            }
            else if (i == word.length() - 1)
            {
                key = false;
                break;
            }
        }
    }

    cout << "\nDo you want to enter the " << 2 << "nd/rd argument?\ny - yes;\nn - no.\n";
    getline(cin, ch);

    for (i = 0; i < 2; i++)
    {
        if ((i == 1) && (ch[0] == 'y'))
        {
            cout << "\nDo you want to enter the " << i + 2 << "nd/rd argument?\ny - yes;\nn - no.\n";
            getline(cin, ch);
        }
        else if ((i == 1) && (ch[0] == 'n'))
        {
            break;
        }
        
        while (true)
        {
            if ((ch.length() > 1) || ((ch[0] != 'y') && (ch[0] != 'n')))
            {
                cout << "\nError!\nDo you want to enter the " << i + 2 << "nd/rd argument?\ny - yes;\nn - no.\n";
                getline(cin, ch);
            }
            else
            {
                break;
            }
        }

        switch (ch[0])
        {
        case 'y':
            if (i == 0)
            {
                cout << "Enter the argument(number 0 - 9)\n";
                getline(cin, twos);

                while (true)
                {
                    if ((twos[0] < '0') || (twos[0] > '9') || (twos.length() > 1))
                    {
                        cout << "\nError!\nEnter the argument(number 1 - 10)\n";
                        getline(cin, twos);
                        continue;
                    }

                    ss << twos;
                    ss >> twoi;
                    ss.clear();

                    if (twoi > word.length() - 1)
                    {
                        cout << "\nError! Going beyond the word boundary!\nEnter the argument(number 1 - 10)\n";
                        getline(cin, twos);
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                cout << "Enter the argument(number 0 - 9)\n";
                getline(cin, threes);

                while (true)
                {
                    if ((threes[0] < '0') || (threes[0] > '9') || (threes.length() > 1))
                    {
                        cout << "\nError!\nEnter the argument(number 1 - 10)\n";
                        getline(cin, threes);
                        continue;
                    }

                    ss << threes;
                    ss >> threei;
                    ss.clear();

                    j = threei + twoi;
                    
                    if (j > word.length())
                    {
                        cout << "\nError! Going beyond the word boundary!\nEnter the argument(number 1 - 10)\n";
                        getline(cin, threes);
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
            }

        case 'n':
            break;

        default:
            break;
        }
    }
    
    upper(word, twoi, threei);

    cout << "\n";
}

void upper(string word, int two, int three)
{
    long j = two + three;
    int i;
    char ch;

    if (two == -1)
    {
        for (i = 0; i < word.length(); i++)
        {
            ch = toupper(word[i]);
            cout << ch;
        }
    }
    else if (three == -1)
    {
        for (i = 0; i < word.length(); i++)
        {
            if (i == two)
            {
                ch = toupper(word[i]);
                cout << ch;
                continue;
            }

            cout << word[i];
        }
    }
    else
    {
        for (i = 0; i < word.length(); i++)
        {
            if ((i >= two) && (i < j) && (three != 0))
            {
                ch = toupper(word[i]);
                cout << ch;
                continue;
            }

            cout << word[i];
        }
    }
}

// Написать РЕКУРСИВНУЮ (https://ru.wikipedia.org/wiki/%D0%A0%D0%B5%D0%BA%D1%83%D1%80%D1%81%D0%B8%D1%8F#%D0%A4%D1%83%D0%BD%D0%BA%D1%86%D0%B8%D0%B8)
// функцию нахождения максимального числа в массиве. В теле функции не должен использоваться цикл. Результат работы
// функции вывести на экран.
// 
// Примеры:
// [1, 3, 5, 4, 2] -> 5

int MaximumValue(int* arr, int count, int maxi);

void task4()
{
    int i, j, maxi, temp = 0, count1 = 1, count2 = 0;
    string arrstr;
    bool whitespace = false, key = true;

    stringstream ss;
    
    cout << "Enter an array containing integer digits\nExample: 1 2 34 21 22\n\n";

    getline(cin, arrstr);

    while (key) // Проверка на ввод.
    {
        if (arrstr == "") // Если пользователь ничего не вел.
        {
            cout << "\nError!\nEnter an array containing integer digits\nExample: 1 2 34 21 22\n\n";
            getline(cin, arrstr);
            continue;
        }

        for (i = 0; i < arrstr.length(); i++)
        {
            count2++; // Подсчёт колличество цифр в одном элементе массива.

            if ((arrstr[i] == ' ') && (i != 0) && (!whitespace) && (i != arrstr.length() - 1)) // Если пользователь закончил с цифрой и поставил пробел и до этого пробела не было и пробел не является последним в массиве. 
            {
                whitespace = true; // Указываем что пробел поставлен.
                count1++; // Подсчёт цифр.
                count2 = 0; // Цифра закончилась, поэтому обнуляем её размер
                continue;
            }
            else if ((arrstr[i] < '0') || (arrstr[i] > '9') || count2 > 5) // Если это не цифра или размер цифры слишком велик.
            {
                cout << "\nError!\nEnter an array containing integer digits\nExample: 1 2 34 21 22\n\n";
                count1 = 1;// Обнуляем значения: В массиве должна быть хотя-бы одна цифра. 
                count2 = 0;// Обнуляем значения: Размер числа обнуляется.
                getline(cin, arrstr);
                break;
            }
            else if (i == arrstr.length() - 1)// Елси нас всё удовлетворяет и это последняя цифра 
            {
                key = false; // Заканчиваем проверку.
                break;
            }
            else
            {
                whitespace = false; // Разрешаем ставить пробел 
            }
        }
    }

    int* arri = new int[count1];// Создаём реальный массив из цифр с размером указаный в count1(Колличество цифр).
    count2 = 0;

    for (i = 0; i < count1; i++)
    {
        arri[i] = 0; // Заполняем массив нулями.

        for (j = count2; j < arrstr.length(); j++)
        {
            if (arrstr[j] != ' ')// Если не пробел то вписываем цифру.
            {
                ss << arrstr[j];
                ss >> temp;
                ss.clear();
                arri[i] = arri[i] * 10 + temp; // так как строка 123 можно представить как набор цифр которые выглядат так: (1 * 10 ^ 2) + (2 * 10 ^ 1) + (3 * 10 ^ 0)
                temp = 0;
            }
            else
            {
                count2 = j + 1;// Сохраняем значение на котором остановились.
                break;
            }
        }
    }

    maxi = arri[0];

    system("cls");

    cout << "[";

    for (i = 0; i < count1; i++)// Вывод результата 
    {
        if (i != count1 - 1) cout << arri[i] << ", ";
        else cout << arri[i] << "] -> ";
        
    }

    cout << MaximumValue(arri, count1, maxi) << "\n";
}

int MaximumValue(int* arr, int count, int maxi) // Функция нахождения максимального числа в массиве
{
    if (count == 0) return maxi; // Своего рода цикл из функции
    else if (maxi <= arr[count - 1])
    {
        maxi = arr[count - 1];
    }

    count--;
    MaximumValue(arr, count, maxi);
}

// Написать функцию, которая принимает на вход два аргумента - массив и число. Функция должна сдвинуть весь массив
// направо на количество элементов, равное второму числу. Элементы, вышедшие за гарницы массива, добавляются к началу
// массива. Функция должна МОДИФИЦИРОВАТЬ переданный массив, а не возвращать новый. Результат работы функции вывести
// на экран.
// 
// Примеры:
// [1, 2, 3, 4, 5, 6] , 1 -> [6, 1, 2, 3, 4, 5]
// [1, 2, 3, 4, 5, 6] , 3 -> [4, 5, 6, 1, 2, 3]
// [1, 2, 3, 4, 5, 6] , 8 -> [5, 6, 1, 2, 3, 4]

void Moving(int* arr, int arg, int sizear);

void task5()
{
    int i, j, argi, temp = 0, count1 = 1, count2 = 0;
    string arrstr, args;
    bool whitespace = false, key = true;

    stringstream ss;

    cout << "Enter an array containing integer digits\nExample: 1 2 34 21 22\n\n";

    getline(cin, arrstr);

    while (key) // Проверка на ввод.
    {
        if (arrstr == "") // Если пользователь ничего не вел.
        {
            cout << "\nError!\nEnter an array containing integer digits\nExample: 1 2 34 21 22\n\n";
            getline(cin, arrstr);
            continue;
        }

        for (i = 0; i < arrstr.length(); i++)
        {
            count2++; // Подсчёт колличество цифр в одном элементе массива.

            if ((arrstr[i] == ' ') && (i != 0) && (!whitespace) && (i != arrstr.length() - 1)) // Если пользователь закончил с цифрой и поставил пробел и до этого пробела не было и пробел не является последним в массиве. 
            {
                whitespace = true; // Указываем что пробел поставлен.
                count1++; // Подсчёт цифр.
                count2 = 0; // Цифра закончилась, поэтому обнуляем её размер
                continue;
            }
            else if ((arrstr[i] < '0') || (arrstr[i] > '9') || count2 > 5) // Если это не цифра или размер цифры слишком велик.
            {
                cout << "\nError!\nEnter an array containing integer digits\nExample: 1 2 34 21 22\n\n";
                count1 = 1;// Обнуляем значения: В массиве должна быть хотя-бы одна цифра. 
                count2 = 0;// Обнуляем значения: Размер числа обнуляется.
                getline(cin, arrstr);
                break;
            }
            else if (i == arrstr.length() - 1)// Елси нас всё удовлетворяет и это последняя цифра 
            {
                key = false; // Заканчиваем проверку.
                break;
            }
            else
            {
                whitespace = false; // Разрешаем ставить пробел 
            }
        }
    }

    int* arri = new int[count1];// Создаём реальный массив из цифр с размером указаный в count1(Колличество цифр).
    count2 = 0;

    for (i = 0; i < count1; i++)
    {
        arri[i] = 0; // Заполняем массив нулями.

        for (j = count2; j < arrstr.length(); j++)
        {
            if (arrstr[j] != ' ')// Если не пробел то вписываем цифру.
            {
                ss << arrstr[j];
                ss >> temp;
                ss.clear();
                arri[i] = arri[i] * 10 + temp; // так как строка 123 можно представить как набор цифр которые выглядат так: (1 * 10 ^ 2) + (2 * 10 ^ 1) + (3 * 10 ^ 0)
                temp = 0;
            }
            else
            {
                count2 = j + 1;// Сохраняем значение на котором остановились.
                break;
            }
        }
    }

    cout << "\nEnter the argument(number 0 - 9)\n"; 
    getline(cin, args); // Ввод аргумента 

    while (true)
    {
        if ((args[0] < '0') || (args[0] > '9') || (args.length() > 1)) // Аргумент не должен быть больше 9!
        {
            cout << "\nError!\nEnter the argument(number 1 - 10)\n";
            getline(cin, args);
            continue;
        }
        else
        {
            ss << args;
            ss >> argi;
            ss.clear();
            break;
        }
    }

    system("cls");

    cout << "[";

    for (i = 0; i < count1; i++)// Вывод результата 
    {
        if (i != count1 - 1) cout << arri[i] << ", ";
        else cout << arri[i] << "] , " << argi <<" -> [";
    }

    Moving(arri, argi, count1);

    for (i = 0; i < count1; i++)// Вывод результата 
    {
        if (i != count1 - 1) cout << arri[i] << ", ";
        else cout << arri[i] << "]";
    }
}

void Moving(int* arr, int arg, int sizear)
{
    int i, j, temp;

    for (i = 0; i < arg; i++)
    {
        temp = arr[sizear - 1];
        
        for (j = sizear - 1; j > 0; j--)
        {
            arr[j] = arr[j - 1];
        }

        arr[0] = temp;
    }
}

// Написать функцию, складывающую два огромных числа (каждое может быть по 100 знаков и больше). Оба числа передаются
// в виде СТРОК (string) как аргументы функции. Функция должна вернуть верную сумму так же в виде СТРОКИ. Алгоритм
// должен имитировать сложение "в столбик". Результат работы функции вывести на экран.
// 
// Примеры:
// "123123123123123", "56789465732" -> "123179912588855"

string Addition(string word1, string word2);

void task6()
{
    string word1, word2; // Создание двух строк.
    int i;
    bool key = true;

    cout << "Enter a number\n";
    getline(cin, word1);

    while (key) // Проверка на ввод чисел.
    {
        for (i = 0; i < word1.length(); i++)
        {
            if ((word1[i] < '0') || (word1[i] > '9'))
            {
                cout << "Error!\nEnter a number\n";

                getline(cin, word1);
                break;
            }
            else if (i == word1.length() - 1)
            {
                key = false;
            }
        }
    }

    cout << "\nEnter a number\n";
    getline(cin, word2);
    key = true;

    while (key) // Проверка на ввод чисел
    {
        for (i = 0; i < word2.length(); i++)
        {
            if ((word2[i] < '0') || (word2[i] > '9'))
            {
                cout << "Error!\nEnter a number\n";

                getline(cin, word2);
                break;
            }
            else if (i == word2.length() - 1)
            {
                key = false;
            }
        }
    }

    system("cls");
    cout << "\"" << word1 << "\", \"" << word2 << "\" -> \"" << Addition(word1, word2) << "\"";
}

string Addition(string word1, string word2)
{
    string ch, word = ""; // Создаём принимаюший символ и строку
    stringstream ss1, ss2;
    
    int i, num1, num2, sum, inthemind = 0;

    reverse(word1.begin(), word1.end()); // Что бы строка читалась с права на лево, как при счёте, используем функцию перевертышь 
    reverse(word2.begin(), word2.end());

    for (i = 0; (i < word1.length() && i < word2.length()); i++) // Доходим до момента, когда колличество цифр равны, то-есть: 12345 345 -> доходит до 3
    {
        ss1 << word1[i];
        ss2 << word2[i];
        ss1 >> num1;
        ss2 >> num2;
        ss1.clear();
        ss2.clear();

        sum = num1 + num2 + inthemind;

        if (sum > 9)
        {
            inthemind = 1; // Значение в уме, когда надо + 1
            sum %= 10;
        }
        else
        {
            inthemind = 0;
        }

        ss1 << sum;
        ss1 >> ch;
        ss1.clear();
        word += ch;
    }
    
    while (i < word1.length()) // Проходим оставшиеся цифры большего числа, если большее число первое 
    {
        ss1 << word1[i];
        ss1 >> num1;
        ss1.clear();
        sum = num1 + inthemind;

        if (sum > 9)
        {
            inthemind = 1;
            sum %= 10;
        }
        else
        {
            inthemind = 0;
        }

        ss1 << sum;
        ss1 >> ch;
        ss1.clear();
        word += ch;
        i++;
    }
    while (i < word2.length()) // Проходим оставшиеся цифры большего числа, если большее число второе 
    {
        ss1 << word2[i];
        ss1 >> num1;
        ss1.clear();
        sum = num1 + inthemind;

        if (sum > 9)
        {
            inthemind = 1;
            sum %= 10;
        }
        else
        {
            inthemind = 0;
        }

        ss1 << sum;
        ss1 >> ch;
        ss1.clear();
        word += ch;
        i++;
    }

    if (inthemind == 1)// Проверяем не надо ли добавить единицу как в примере: 9 + 1
    {
        word += "1"; // Добавляем
        reverse(word.begin(), word.end());
        return word;
    }
    else
    {
        reverse(word.begin(), word.end());
        return word;
    }
}