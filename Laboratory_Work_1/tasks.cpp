#include "tasks.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <windows.h>

using namespace std;

// В данном файле содержатся функции с будущими решениями. Решайте каждую задачу в теле функции и вызывайте её в 
// файле "cpp_lab1.cpp"

// Напишите программу, которая запрашивает у пользователя целочисленное значение n и выводит на экран сумму всех
// чисел от 1 до n
void task1()
{
    stringstream ss;
    string s;
    int i, n, sum = 0;
    cout << "Input n: ";
    cin >> s;

    for (i = 0; i < s.length(); i++)
    {
        if (!isdigit(s[i]))
        {
            if (s[i] == '-') continue;
            else
            {
                cout << "Error!";
                i = -1;
                cout << "\nInput n: ";
                cin >> s;
            }

        }
    }

    ss << s;
    ss >> n;

    if (n < 1) for (i = 1; i >= n; i--) sum += i;
    else sum = (1 + n) * n / 2;

    cout << sum;

}

// Напишите программу, которая будет проверять, является ли введеное пользователем слово палиндромом
void task2()
{
    string word;
    size_t  n;
    bool check = true;

    cout << "Enter the word: ";
    cin >> word;

    n = word.length();

    for (int i = 0; i < n / 2; i++)
    {
        if (word[i] != word[n - i - 1])
        {
            check = false;
            break;
        }
    }

    if (check)
    {
        cout << "Word is polindrom.";
    }
    else
    {
        cout << "Word is not polindrom";
    }
}

// Напишите программу, которая принимает набор строковых значений у пользователя, а затем выводит их в консоль в
// рамочке из любого символа, например:
// ***********
// * Гаррош  *
// * не      *
// * виноват *
// * !       *
// ***********
void task3()
{
    string str1;
    string str2 = "";
    char sym;
    int i, k = 0, max = 0;

    cout << "Enter the text: ";
    getline(cin, str1);
    cout << "Enter symbols: ";
    cin >> sym;

    for (i = 0; i < str1.length(); i++)
    {
        if (str1[i] != ' ')
        {
            k++;
        }
        else
        {
            if (max < k)
            {
                max = k;
            }

            k = 0;
        }
    }

    if (max < k)
    {
        max = k;
    }

    k = 0;

    for (i = 0; i < max + 4; i++)
    {
        str2 += sym;
    }

    cout << str2 << '\n' << sym << ' ';

    for (i = 0; i < str1.length(); i++)
    {
        if (str1[i] != ' ')
        {
            cout << str1[i];
            k++;
        }
        else
        {
            while (k < max)
            {
                cout << " ";
                k++;
            }

            cout << " " << sym << '\n' << sym << ' ';
            k = 0;
        }
    }

    while (k < max)
    {
        cout << " ";
        k++;
    }

    cout << ' ' << sym << '\n' << str2;
}

// Напишите программу, которая принимает на вход от пользователя количество байт и выводит их в более читаемом виде,
// например, в килобайтах, мегабайтах или гигабайтах
void task4()
{
    long long b;
    string sym;
    bool key = true;

    cout << "Enter the number of bytes: ";

    while (!(cin >> b) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Enter the number of bytes: ";
    }

    getline(cin, sym);

    while (key)
    {
        if (sym.length() > 1)
        {
            cout << "Enter K for Kilobytes\nEnter M for Megabytes\nEnter G for Gigabytes\nInput: ";
            getline(cin, sym);
            continue;
        }
        switch (sym[0])
        {
        case 'K':
            cout << (b >> 10) << "K";
            key = false;
            break;
        case 'M':
            cout << (b >> 20) << "M";
            key = false;
            break;
        case 'G':
            cout << (b >> 30) << "G";
            key = false;
            break;
        default:
            cout << "Enter K for Kilobytes\nEnter M for Megabytes\nEnter G for Gigabytes\nInput: ";
            getline(cin, sym);
            break;
        }
    }
}

// Напишите программу, которая принимает на вход список номеров автомобилей в формате "А000АА77" (где 77 - регион),
// и выводит на экран все номера из указанного пользователем региона
void task5()
{
    string sym, num1, num2 = "";

    while (true)
    {
        cout << "Do you want to enter the car number?\ny - yes\nn - no\n";
        getline(cin, sym);

        if ((sym[0] == 'y') && (sym.length() == 1))
        {
            cout << "Enter the number in the format A000AA77: ";
            getline(cin, num1);

            while (true)
            {
                if (((num1[0] >= 'A') && (num1[0] <= 'Z')) && ((num1[1] >= '0') && (num1[1] <= '9')) && ((num1[2] >= '0') && (num1[2] <= '9')) && ((num1[3] >= '0') && (num1[3] <= '9')) && ((num1[4] >= 'A') && (num1[4] <= 'Z')) && ((num1[5] >= 'A') && (num1[5] <= 'Z')) && ((num1[6] >= '0') && (num1[6] <= '9')) && ((num1[7] >= '0') && (num1[7] <= '9')) && (num1.length() == 8) && (num2.find(num1) == string::npos))
                {

                    num2 += num1 + ' ';
                    break;
                }
                else
                {
                    cout << "Error!\nEnter the number in the format A000AA77: ";
                    getline(cin, num1);
                }
            }
        }
        else if ((sym[0] == 'n') && (sym.length() == 1))
        {
            break;
        }
    }


    cout << "Enter the region: ";
    getline(cin, sym);

    while (true)
    {
        if ((sym.length() == 2) && (sym[0] >= '0') && (sym[0] <= '9') && (sym[1] >= '0') && (sym[1] <= '9'))
        {
            for (size_t i = 0; i < num2.length(); i += 9)
            {
                if ((sym[0] == num2[i + 6]) && (sym[1] == num2[i + 7]))
                {
                    cout << num2[i] << num2[i + 1] << num2[i + 2] << num2[i + 3] << num2[i + 4] << num2[i + 5] << num2[i + 6] << num2[i + 7] << ' ';
                }
            }

            break;
        }

        cout << "Error!\nEnter the region: ";
        getline(cin, sym);
    }
}

// Программа принимает на вход список цен на товар за 10 дней. Необходимо вывести на экран интервал цен за 3 дня,
// в течение которых произошел наибольший рост цены
void task6()
{
    string pri;
    int d1 = 1, d2 = 2, price[10];
    int i, j, max = 0;
    bool key;

    stringstream ss;

    for (i = 0; i < 10; i++)
    {
        key = true;
        cout << "Price in " << i + 1 << " day: ";
        getline(cin, pri);
        while (key)
        {
            for (j = 0; j < pri.length(); j++)
            {
                if ((pri[j] < '0') || (pri[j] > '9') || (pri.length() > 9))
                {
                    cout << "Error!\nPrice in " << i + 1 << " day: ";
                    getline(cin, pri);
                    break;
                }
                else if (j == pri.length() - 1)
                {
                    key = false;
                }
            }
        }

        ss << pri;
        ss >> price[i];
        ss.clear();
    }

    for (i = 3; i < 10; i++)
    {
        for (j = 1; j < 4; j++)
        {
            if (abs(price[i] - price[i - j]) > max)
            {
                d1 = i + 1;
                d2 = i - j + 1;
                max = abs(price[i] - price[i - j]);
            }
        }
    }

    cout << "Between " << d1 << " and " << d2 << " days, the largest price increase is " << max;
}

// Напишите программу, которая принимает на вход целочисленное значение, а затем выводит на экран массив из цифр
// 1 и 0, являющийся представлением данного числа в двоичной системе исчисления, например:
// Ввод: 34, Вывод: [1,0,0,0,1,0]
void task7()
{
    int i, numi;
    string nums;
    bool key = true;

    stringstream ss;

    cout << "Input: ";
    getline(cin, nums);

    while (key)
    {
        for (i = 0; i < nums.length(); i++)
        {
            if ((nums[i] < '0') || (nums[i] > '9') || (nums.length() > 9))
            {
                cout << "Erorr!\nInput: ";
                getline(cin, nums);
                break;
            }
            else if (i == nums.length() - 1)
            {
                key = false;
            }
        }
    }

    ss << nums;
    ss >> numi;

    nums = "";

    while (numi > 1)
    {
        if (numi % 2)
        {
            nums += '1';
        }
        else
        {
            nums += '0';
        }
        numi /= 2;
    }

    cout << "[1";

    numi = nums.length() - 1;

    for (i = numi; i >= 0; i--)
    {
        cout << ", " << nums[i];
    }

    cout << "]";
}

// * Напишите программу, которая принимает на вход от пользователя количество секунд, затем отсчитывает заданное
// количество секунд с выводом счета на экран
void task8()
{
    int i, num;
    string str;
    bool key = true;

    stringstream ss;

    cout << "Enter seconds: ";
    getline(cin, str);

    while (key)
    {
        for (i = 0; i < str.length(); i++)
        {
            if ((str[i] < '0') || (str[i] > '9') || (str.length() > 9))
            {
                cout << "Erorr!\nEnter seconds: ";
                getline(cin, str);
                break;
            }
            else if (i == str.length() - 1)
            {
                key = false;
            }
        }
    }

    ss << str;
    ss >> num;

    while (num > 0)
    {
        system("cls");
        cout << num << " s";
        Sleep(1000);
        num--;
    }

    system("cls");
    cout << num << " s";
}
