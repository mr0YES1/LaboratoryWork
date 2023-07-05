#include "tasks.h"
#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <windows.h>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

// ! Все методы классов должны быть вызваны и проверены в соответсвeующей задаче.

// Реализовать классы треугольника, круга и прямоугольника. Каждый класс должен реализовывать методы получения
// периметра, площади, а так же проверку возможности существования фигуры с переданными параметрами.
// Параметры треугольника - 3 стороны
// Параметры прямоугольника - 2 стороны
// Парыметры круга - радиус
//
// Примеры :
//   Triangle tr(3, 5, 9)->вывод "Невозможная фигура"
//   Reactangle rec(3, 0)->вывод "Невозможная фигура"
//   Circle cir(-2)->вывод "Невозможная фигура"
//
//   Reactangle rec(3, 4)
//   rec.area() -> 12
//   rec.perimeter() -> 14

class Triangle // Создаём класс треугольник 
{
    private:
        int _a, _b, _c;
        bool _posFig = true;


        void _CLTr() // Закрытый метод проверки
        {
            if (((_a + _b) <= _c) || ((_a + _c) <= _b) || ((_b + _c) <= _c))
            {
                cout << "An impossible figure";
                _posFig = false;
            }
        }

        void _Per() // Закрытый метод нахождения периметра
        {
            if (_posFig)
            {
                cout << "Perimeter -> " << _a + _b + _c << "\n";
            }
        }

        void _Square() // Закрытый метод нахождения площади 
        {
            float p;

            if (_posFig)
            {
                p = _a + _b + _c;
                p /= 2;
                cout.precision(2); // Выводим два знака
                cout << "Square -> " << sqrt(p * (p - _a) * (p - _b) * (p - _c)) << "\n";
            }
        }

    public:
        void Set(int valueA, int valueB, int valueC)
        {
            _a = valueA;
            _b = valueB;
            _c = valueC;
        }
        void OpTr()
        {
            _CLTr();
        }
        void OpSquare()
        {
            _Square();
        }
        void OpPer()
        {
            _Per();
        }
};

class Reactangle // Создаём класс прямоугольник
{
    private:
        int _a, _b;
        bool _posFig = true;

        void _ClRec()
        {
            if ((_a == 0) || (_b == 0))
            {
                cout << "An impossible figure";
                _posFig = false;
            }
        }

        void _Per() // Закрытый метод нахождения периметра
        {
            if (_posFig)
            {
                cout << "Perimeter -> " << (_a + _b) * 2 << "\n";
            }
        }

        void _Square() // Закрытый метод нахождения площади 
        {
            if (_posFig)
            {
                cout << "Square -> " << _a * _b << "\n";
            }
        }

    public:
        void Set(int valueA, int valueB)
        {
            _a = valueA;
            _b = valueB;
        }
        void OpRec()
        {
            _ClRec();
        }
        void OpPer()
        {
            _Per();
        }
        void OpSquare()
        {
            _Square();
        }
};

class Circle
{
    private:
        const float _pi = 3.14f;
        
        int _r;
        bool _posFig = true;

        void _ClCir()
        {
            if (_r < 1)
            {
                cout << "An impossible figure";
                _posFig = false;
            }
        }

        void _Per() // Закрытый метод нахождения периметра
        {
            if (_posFig)
            {
                cout.precision(4); // Выводим четыре знака
                cout << "Perimeter -> " << _r * _pi * 2 << "\n";
            }
        }

        void _Square() // Закрытый метод нахождения площади 
        {
            if (_posFig)
            {
                cout.precision(4); // Выводим четыре знака
                cout << "Square -> " << _r * _r * _pi << "\n";
            }
        }

    public:
        void Set(int valueR)
        {
            _r = valueR;
        }
        void OpCir()
        {
            _ClCir();
        }
        void OpPer()
        {
            _Per();
        }
        void OpSquare()
        {
            _Square();
        }
};


int CheckingTheNumber(string x)
{
    int i, val = 0;
    stringstream ss;

    if (x.length() > 3)
    {
        return val;
    }

    for (i = 0; i < x.length(); i++)
    {
        if ((x[i] < '0') || (x[i] > '9'))
        {
            break;
        }
        else if (i == x.length() - 1)
        {
            ss << x;
            ss >> val;
            ss.clear();
        }
    }

    return val;
}

void task1()
{
    Triangle firstTriang; // Создаём объект треугольник
    Reactangle firstReact;
    Circle firstCircle;

    string a, b, c, r;

    cout << "Enter the side of the triangle a: "; // Вводим значения сторон треугольника
    getline(cin, a);
    cout << "Enter the side of the triangle b: ";
    getline(cin, b);
    cout << "Enter the side of the triangle c: ";
    getline(cin, c);

    firstTriang.Set(CheckingTheNumber(a), CheckingTheNumber(b), CheckingTheNumber(c)); // Вписываем значения
    firstTriang.OpTr(); // Проверяем 
    firstTriang.OpPer(); // Выводим периметр
    firstTriang.OpSquare(); // Выводим площадь

    cout << "\nEnter the side of the rectangle a: "; // Вводим значения сторон прямоугольника
    getline(cin, a);
    cout << "Enter the side of the rectangle b: ";
    getline(cin, b);

    firstReact.Set(CheckingTheNumber(a), CheckingTheNumber(b)); // Вписываем значения
    firstReact.OpRec(); // Проверяем
    firstReact.OpPer(); // Выводим периметр
    firstReact.OpSquare(); // Выводим площадь

    cout << "\nEnter the radius of the circle r: "; // Вводим значение радиуса для круга
    getline(cin, r);

    firstCircle.Set(CheckingTheNumber(r)); // Вписываем значения
    firstCircle.OpCir(); // Проверяем
    firstCircle.OpPer(); // Выводим периметр
    firstCircle.OpSquare(); // Выводим площадь
}

// Написать собственный класс реализующий стэк(Stack) — абстрактный тип данных, представляющий собой список элементов,
// организованных по принципу LIFO(англ.last in — first out, «последним пришёл — первым вышел»).
// Класс должен содержать методы pop(), push(), top(), count(), empty() :
// pop() - достать самый верхний элемент.Метод возвращает значение, а верхним элементом становится предыдущий
// push() - положить элемент наверх.Переданное значение становится новым верхним элементом стэка
// top() - узнать верхний элемент.В отличие от pop() значене верхнего элемента не удаляется из стэка
// count() - узнать количество элеменотов в стэке
// emty() - проверить, не является ли стэк пустым
// 
// Примеры :
//   Stack stack([])
//   stack.empty() -> true
//   stack.push(3) ->[3]
//   stack.push(9) ->[3, 9]
//   stack.push(2) ->[3, 9, 2]
//   a = stack.pop() ->[3, 9]; a = 2
//   stack.count() -> 2
//   stack.emty() -> false

class Stack
{
private:
    list <int> _mylist;
public:
    Stack() // Конструктор 
    {
        cout << "\nStack stack([])\n"; // Показываем что стэк создан 
    }
    
    void push(int a)
    {
        int i = 1;
        
        cout << "\nstack.push(" << a << ") -> [";
        _mylist.push_back(a); // Добавляем в стэк элемент
        for (auto v : _mylist)
        {
            if (i == _mylist.size())
            {
                cout << v << "]\n";
            }
            else
            {
                cout << v << ", ";
            }
            i++;
        }
    }

    int pop()
    {
        int i = 1, val = NULL;
        
        if (_mylist.size() == 0) // Если стэк пуст 
        {
            cout << "\nError!\nStack is empty\n";
        }
        else // Если там есть значения 
        {
            cout << "\na = stack.pop() -> [";
            val = _mylist.back(); // Передаём верхний элемент из стэка
            _mylist.pop_back(); // Удаляем верхний элемент из стэка
            for (auto v : _mylist) 
            {
                if (i == _mylist.size())
                {
                    cout << v;
                }
                else
                {
                    cout << v << ", ";
                }
                i++;
            }
            cout << "]; a = " << val << "\n";
        }

        return val;
    }

    int top()
    {
        int i = 1, val = NULL;
        
        if (_mylist.size() == 0) // Если пустота 
        {
            cout << "\nError!\nStack is empty\n";;
        }
        else // Иначе просто выводим 
        {
            cout << "\na = stack.top() -> [";
            val = _mylist.back();
            for (auto v : _mylist)
            {
                if (i == _mylist.size())
                {
                    cout << v << "]; a = " << val << "\n";
                }
                else
                {
                    cout << v << ", ";
                }
                i++;
            }
        }

        return val;
    }

    void count() // Считаем колличество элементов 
    {
        cout << "\nstack.count() -> " << _mylist.size() << "\n";
    }

    void emty() // Проверка пустоты стэка 
    {
        if (_mylist.size() == 0) // Если стэк пустой 
        {
            cout << "\nstack.emty() -> True\n";
        }
        else
        {
            cout << "\nstack.emty() -> False\n";
        }
    }
};

void task2()
{
    string сheckingstr;
    int a;
    bool key = true;

    while (key) // Начинаем приложение 
    {
        cout << "\nWant to create a stack\ny - yes\nn - no\n\n"; // Спрашиваем у пользователя хочет ли он создать стэк 
        getline(cin, сheckingstr);

        if ((сheckingstr.length() == 1) && (сheckingstr[0] == 'y'))
        {
            system("cls");
            
            Stack  stack; // Создаём стэк
            
            while (true)
            {
                cout << "\npush - put the element up\npop - get the topmost element\ntop - find out the top element\ncount - find out the number of slots in the stack\nemty - check if the stack is empty\ndel - end the program\n\nstack.";
                getline(cin, сheckingstr);
                if (сheckingstr == "push") // Добавляем элемент в стэк
                {
                    cout << "Enter a number: ";
                    getline(cin, сheckingstr);
                    stack.push(CheckingTheNumber(сheckingstr));
                    Sleep(2000);
                }
                else if (сheckingstr == "pop") // Выводим верхний элемент стэка с удалением
                {
                    a = stack.pop();
                    Sleep(2000);
                }
                else if (сheckingstr == "top") // Выводим верхний элемент стэка без удаления 
                {
                    a = stack.top();
                    Sleep(2000);
                }
                else if (сheckingstr == "count") // Подсчитываем колличество элементов в стэке 
                {
                    stack.count();
                    Sleep(2000);
                }
                else if (сheckingstr == "emty") // Проверяем пустой ли стэк
                {
                    stack.emty();
                    Sleep(2000);
                }
                else if (сheckingstr == "del") // Если завершаем программу
                {
                    key = false;
                    break;
                }
                else
                {
                    cout << "\nInput error!\n";
                    Sleep(2000);
                }
            }
        }
        else if ((сheckingstr.length() == 1) && (сheckingstr[0] == 'n')) // Если не хотим создавать стэк 
        {
            break;
        }
    }
}

// Создать класс словаря, принимающего в конструкторе массив из строк. Реализовать методы сортировки значений в алфавитном порядке,
// вывода значений на экран, поиска самого длинного слова в словаре, а так же объединения с другим объектом словаря :
// sort() - сортировка в алфавитном порядке
// max() - найти слово с максимальной длинной
// print() - вывести словарь на экран в виде одной строки
// get() - получить массив строк из словаря.
// merge(dict) - слить два словаря.
// add() - добавить элемент.
// Все свойства объекта должны быть приватными и доступ должен осуществляться при помощи соответствующих сеттеров и геттеров.
// Элементы в словарях не должны повторяться.
// 
// Примеры:
//   Dictionary dict1(['hello', 'world', 'alf', 'alfa'])
//   Dictionary dict2(['john', 'amogus', 'morgenshtern'])
//   dict1.sort() ->['alf', 'alfa', 'hello', 'world']
//   dict2.max() -> 'morgenshtern'
//   dict2.add('oxxxymiron') ->['john', 'amogus', 'morgenshtern', 'oxxxymiron']
//   dict1.merge(dict2) ->['hello', 'world', 'alf', 'alfa', 'john', 'amogus', 'morgenshtern', 'oxximiron']

class Dictionary
{
private:
    string* _words;
    int _sizeDict;
public:
    Dictionary(string* words, int sizeDict, int numDict) // Принимает готовые значения - размер словаря и его содержание
    {
        _words = new string[sizeDict]; // Создаём массив слов 
        _sizeDict = sizeDict; // Заполняем значения

        cout << "\nDictionary dict" << numDict << " -> [";
        
        for (int i = 0; i < sizeDict; i++)
        {
            _words[i] = words[i];// Заполняем массив
            if (i == _sizeDict - 1) 
            {
                cout << _words[i] << "]\n\n"; // Вывод результата
            }
            else
            {
                cout << _words[i] << ", "; // Вывод результата
            }
        }
    }

    string get()// Метод считывания 
    {
        string words = "";
        
        for (int i = 0; i < _sizeDict; i++)
        {
            words += _words[i];

            if (i != _sizeDict - 1)
            {
                words += ", ";
            }
        }

        return words;
    }

    void add(string newWord)// Метод добавления
    {
        string *temp = new string[_sizeDict];
        int i;

        for (i = 0; i < _sizeDict; i++)
        {
            temp[i] = _words[i];
        }

        delete[] _words;
        _sizeDict++;
        _words = new string[_sizeDict];

        for (i = 0; i < _sizeDict - 1; i++)
        {
            _words[i] = temp[i];
        }

        _words[_sizeDict - 1] = newWord;
    
        cout << "["; // Открываем скобки 

        for (i = 0; i < _sizeDict; i++)
        {
            if (i == _sizeDict - 1)
            {
                cout << _words[i] << "]\n"; // Закрываем скобки
            }
            else
            {
                cout << _words[i] << ", "; // Выводим элементы
            }
        }
    }

    void maxWord() // Находим максимальное значение
    {
        int i, ind = 0, maxInt = 0;

        for (i = 0; i < _sizeDict; i++) // Проходим по массиву 
        {
            if (maxInt < _words[i].length())
            {
                maxInt = _words[i].length();
                ind = i;
            }
        }

        cout << _words[ind];
    }

    void sortDict()
    {
        int i, j, k;
        string temp;

        if (_sizeDict > 1)
        {
            for (i = 0; i < _sizeDict - 1; i++)
            {
                for (j = i + 1; j < _sizeDict; j++)
                {
                    if (_words[i].length() <= _words[j].length())
                    {
                        for (k = 0; k < _words[i].length(); k++)
                        {
                            if (_words[i][k] > _words[j][k])
                            {
                                temp = _words[j];
                                _words[j] = _words[i];
                                _words[i] = temp;
                                break;
                            }
                            else if (_words[i][k] < _words[j][k])
                            {
                                break;
                            }
                        }
                    }
                    else
                    {
                        for (k = 0; k < _words[j].length(); k++)
                        {
                            if (_words[i][k] > _words[j][k])
                            {
                                temp = _words[j];
                                _words[j] = _words[i];
                                _words[i] = temp;
                                break;
                            }
                            else if (_words[i][k] < _words[j][k])
                            {
                                break;
                            }
                        }
                    }
                }
            }
        }

        cout << "["; // Открываем скобки 

        for (i = 0; i < _sizeDict; i++)
        {
            if (i == _sizeDict - 1)
            {
                cout << _words[i] << "]\n"; // Закрываем скобки
            }
            else
            {
                cout << _words[i] << ", "; // Выводим элементы
            }
        }
    }

    void print()
    {
        cout << "["; // Открываем скобки 

        for (int i = 0; i < _sizeDict; i++)
        {
            if (i == _sizeDict - 1)
            {
                cout << _words[i] << "]\n"; // Закрываем скобки
            }
            else
            {
                cout << _words[i] << ", "; // Выводим элементы
            }
        }
    }

    void merge(string dict)
    {
        int i, j, dopSize = 1;
        string* temp = new string[_sizeDict];
        string tempDop = "";

        for (i = 0; i < dict.length(); i++)
        {
            if (dict[i] == ',') dopSize++;
        }

        for (i = 0; i < _sizeDict; i++)
        {
            temp[i] = _words[i];
        }

        delete[] _words;
        j = _sizeDict;
        _sizeDict += dopSize;
        _words = new string[_sizeDict];

        for (i = 0; i < j; i++)
        {
            _words[i] = temp[i];
        }

        for (i = 0; i < dict.length(); i++)
        {
            if (dict[i] == ',')
            {
                j++;
            }
            else if (dict[i] != ' ')
            {
                _words[j] += dict[i];
            }
        }

        cout << "["; // Открываем скобки 

        for (i = 0; i < _sizeDict; i++)
        {
            if (i == _sizeDict - 1)
            {
                cout << _words[i] << "]\n"; // Закрываем скобки
            }
            else
            {
                cout << _words[i] << ", "; // Выводим элементы
            }
        }
    }
};


string EnteringAWord( int num)
{
    string ch;
    
    while (true)
    {   
        cout << "Word " << num << " -> "; // Ввод слова
        getline(cin, ch);

        for (int i = 0; i < ch.length(); i++)
        {
            if ((((ch[i] < 'a') || (ch[i] > 'z')) && ((ch[i] < 'A') || (ch[i] > 'Z'))) && ((ch.length() != 1) || (ch[0] != '-'))) // Елси это не английское слово и не -
            {
                cout << "\nError!\n\n"; // Выводим ошибку
                break;
            }
            else if (i == ch.length() - 1) // Проверяем до последнего элемента 
            {
                return ch; // возврашаем верное слово
            }
        }
    }
}

void task3()
{
    string ch, *words, *temp; // Создаём принмающее слово; список слов: список слов, для расширения оригинального списка
    int qust, qust_2, i, sizeDict, numDict = 0; // i - переменная для цикла; коллисество слов в одном словаре, коллисество словарей и какой словарь хотим использовать (для вопроса) 
    
    vector <Dictionary> dict; // Веклор словарей 
    
    while (true) // Начинаем приложение
    {
        cout << "\nDo you want to create a dictionary ?\ny - yes\nn - no\n\n"; // Спрашиваем у пользователя хочет ли он создать словарь
        getline(cin, ch);

        if ((ch.length() == 1) && (ch[0] == 'y')) // Если ответ да
        {
            numDict++;// Считаем словарь
            sizeDict = 1;// Начальное количество слов в словаре
            words = new string[1]; // Создаём массив из слов 
            
            system("cls"); // Очишаем программу
            cout << "\nTo complete, enter: -\n\n"; // Для завершения введите -

            while (true)// Заполнение словаря 
            {
                ch = EnteringAWord(sizeDict); // Получаем правильное слово
                if (ch == "-")// Если закрываем словарь
                {
                    dict.push_back(Dictionary(words, sizeDict - 1, numDict));// Создаём словарь
                    system("pause"); // Просматриваем результат
                    system("cls"); // Очишаем программу
                    break;// Завершаем заполнение словаря
                }
                else if (sizeDict == 1) // Если это первое слово 
                {
                    words[0] = ch; // присваиваем первому элементу массива это значение 
                }
                else // Если надо добавить слово, то расширяем массив слов
                {
                    temp = new string[sizeDict - 1]; // Создаём временное хранение данных 

                    for (i = 0; i < sizeDict - 1; i++)
                    {
                        temp[i] = words[i]; // Перебрасываем слова 
                    }

                    delete[] words; // Удаляем массив слов 

                    words = new string[sizeDict]; // И создаём новый но с возможностью добавить слово 

                    for (i = 0; i < sizeDict - 1; i++)
                    {
                        words[i] = temp[i]; // Перебрасываем имеющиеся слова
                    }

                    words[sizeDict - 1] = ch; // Добавляем новое слово

                    delete[] temp; // Удаляем временный массив
                }

                sizeDict++;
            }
        }
        else if ((ch.length() == 1) && (ch[0] == 'n')) // Если не хотим создавать словарь
        {
            if (numDict > 0) // Проверяем если создан один словарь 
            {
                while (true) // Начинаем просматривать методы
                {
                    system("cls"); // Очишаем программу

                    cout << "\nget - get an array of strings from the dictionary\nadd - add an element\nmax  - find the word with the maximum length\nsort- sort in alphabetical order\nprint - print the dictionary to the screen as a single line\nmerge - merge two dictionaries\ndel - shut down\n\ndict.";
                    getline(cin, ch); // Получаем действия

                    if (ch == "get") // Получить значение 
                    {
                        while (true) // Делаем проверку на ввод числа
                        {
                            cout << "\nWhich dictionary do you want to take ?\nYou have " << numDict << " dict\nEnter the dictionary number : ";

                            getline(cin, ch);

                            qust = CheckingTheNumber(ch); // Получаем число, если оно не верное, то выводим 0

                            if ((qust == 0) || (qust > numDict))
                            {
                                cout << "\nError!\nThere is no such dictionary\n"; // Пишим, что такого словаря нет
                            }
                            else
                            {
                                cout << "\ndict" << qust << " -> " << dict[qust - 1].get() << "\n\n"; // Если всё хорошо, то выводим метод get
                                system("pause");
                                break;
                            }
                        }
                    }

                    if (ch == "add")
                    {
                        while (true)
                        {
                            cout << "\nWhich dictionary do you want to take ?\nYou have " << numDict << " dict\nEnter the dictionary number: ";

                            getline(cin, ch);

                            qust = CheckingTheNumber(ch); // Получаем число, если оно не верное, то выводим 0

                            if ((qust == 0) || (qust > numDict))
                            {
                                cout << "\nError!\nThere is no such dictionary\n"; // Пишим, что такого словаря нет
                            }
                            else
                            {
                                ch = EnteringAWord(1);
                                cout << "\ndict" << qust << " -> ";
                                dict[qust - 1].add(ch);
                                cout << "\n";
                                system("pause");
                                break;
                            }
                        }
                    }

                    if (ch == "max")
                    {
                        while (true)
                        {
                            cout << "\nWhich dictionary do you want to take ?\nYou have " << numDict << " dict\nEnter the dictionary number: ";

                            getline(cin, ch);

                            qust = CheckingTheNumber(ch); // Получаем число, если оно не верное, то выводим 0

                            if ((qust == 0) || (qust > numDict))
                            {
                                cout << "\nError!\nThere is no such dictionary\n"; // Пишим, что такого словаря нет
                            }
                            else
                            {
                                cout << "\ndict" << qust << " -> ";
                                dict[qust - 1].maxWord();
                                cout << "\n";
                                system("pause");
                                break;
                            }
                        }
                    }
                
                    if (ch == "sort")
                    {
                        while (true)
                        {
                            cout << "\nWhich dictionary do you want to take ?\nYou have " << numDict << " dict\nEnter the dictionary number: ";

                            getline(cin, ch);

                            qust = CheckingTheNumber(ch); // Получаем число, если оно не верное, то выводим 0

                            if ((qust == 0) || (qust > numDict))
                            {
                                cout << "\nError!\nThere is no such dictionary\n"; // Пишим, что такого словаря нет
                            }
                            else
                            {
                                cout << "\ndict" << qust << " -> ";
                                dict[qust - 1].sortDict();
                                cout << "\n";
                                system("pause");
                                break;
                            }
                        }
                    }
                
                    if (ch == "print")
                    {
                        while (true)
                        {
                            cout << "\nWhich dictionary do you want to take ?\nYou have " << numDict << " dict\nEnter the dictionary number: ";

                            getline(cin, ch);

                            qust = CheckingTheNumber(ch); // Получаем число, если оно не верное, то выводим 0

                            if ((qust == 0) || (qust > numDict))
                            {
                                cout << "\nError!\nThere is no such dictionary\n"; // Пишим, что такого словаря нет
                            }
                            else
                            {
                                cout << "\ndict" << qust << " -> ";
                                dict[qust - 1].print();
                                cout << "\n";
                                system("pause");
                                break;
                            }
                        }
                    }

                    if ((ch == "merge") && (numDict > 1))
                    {
                        while (true)
                        {
                            cout << "\nWhich dictionary do you want to take ?\nYou have " << numDict << " dict\nEnter the dictionary number: ";

                            getline(cin, ch);

                            qust = CheckingTheNumber(ch); // Получаем число, если оно не верное, то выводим 0

                            if ((qust == 0) || (qust > numDict))
                            {
                                cout << "\nError!\nThere is no such dictionary\n"; // Пишим, что такого словаря нет
                            }
                            else
                            {
                                while (true)
                                {
                                    cout << "\nWhich dictionary do you want to add to " << qust << " ?\nYou have " << numDict - 1 << " dict\nEnter the dictionary number: ";

                                    getline(cin, ch);

                                    qust_2 = CheckingTheNumber(ch); // Получаем число, если оно не верное, то выводим 0

                                    if ((qust_2 == 0) || (qust_2 > numDict) || (qust_2 == qust))
                                    {
                                        cout << "You can't do that";
                                    }
                                    else
                                    {
                                        dict[qust - 1].merge(dict[qust_2 - 1].get());
                                        break;
                                    }
                                }
                            
                                cout << "\n";
                                system("pause");
                                break;
                            }
                        }
                    }

                    else if (ch == "merge")
                    {
                        cout << "\nYou don't have enough dictionaries\n";
                        cout << "\n";
                        system("pause");
                    }

                    if (ch == "del")
                    {
                        break;
                    }
                }     
            }
            
            break;
        }
    }
}

// Реализовать класс Дробное число со знаком(Fractions).Число должно быть представлено двумя полями : целая часть - длинное целое со знаком,
// дробная часть - беззнаковое короткое целое. Реализовать арифметические операции сложения, вычитания, умножения и операции сравнения,
// а так же вывод на экран в фомате обычного float.
// Арифметические операции могут быть реализованы как при помощи отдельных методов, так и при помощи перегрузки операторов.
// Результатом операций так же является объект типа Fractions.
//  
// Примеры :
//   Fractions num1(12, 23), num2(-3, 13)
//   num1 + num2->num3; num3.print() -> 9, 1
//   или
//   num1.add(num2)->num3; num3.print() -> 9, 1

class Fractions
{
private:
    int _num;
    int _fraction;
public:
    Fractions(int fraction, int num)
    {
        _num = num;
        _fraction = fraction;
    }
    
    float get()
    {
        float a;

        if (_num < 0)
        {
            a = _num * 100 - _fraction;
            a /= 100;
        }
        else
        {
            a = _num * 100 + _fraction;
            a /= 100;
        }

        return a;
    }

    Fractions sum(Fractions a)
    {
        float sum;
        int i;

        sum = a.get();
        sum += this->get();

        i = sum;

        return Fractions(abs((sum - i) * 100) + 0.5f, i);
    }

    Fractions subtraction(Fractions a)
    {
        float sub;
        int i;

        sub = this->get();
        sub -= a.get();

        i = sub;

        return Fractions(abs((sub - i) * 100) + 0.5f, i);
    }

    Fractions multiplication(Fractions a)
    {
        float mul;
        int i;

        mul = this->get();
        mul *= a.get();

        i = mul;

        return Fractions(abs((mul - i) * 100) + 0.5f, i);
    }

    void comparison(Fractions a, Fractions b)
    {
        system("cls");
        
        if ((a._num == b._num) && (a._fraction == b._fraction))
        {
            cout << "\nTrue\n\n";
        }
        else
        {
            cout << "\nFalse\n\n";
        }

        system("pause");
    }

    void print(int num)
    {
        system("cls");
        cout <<"\nnum" << num << " -> " << this->get() << "\n\n";
        system("pause");
    }
};

int EnteringTheNumerator(int numFraction)
{
    string ch;
    stringstream ss;
    int i, num;
    
    while (true)
    {
        cout << "num" << numFraction << "\n\nEnter the numerator\nInput: ";
        getline(cin, ch);

        if ((ch.length() > 8) || (ch.length() == 0))
        {
            cout << "\nError!\nThe number is not definite!\n\n";
            system("pause");
            system("cls");
        }
        else if ((ch[0] == '-') && (ch.length() > 1))
        {
            for (i = 1; i < ch.length(); i++)
            {
                if ((ch[i] < '0') || (ch[i] > '9'))
                {
                    cout << "\nError!\nIt's not a number!\n\n";
                    system("pause");
                    system("cls");
                    break;
                }
                else if (i == ch.length() - 1)
                {
                    ss << ch;
                    ss >> num;
                    ss.clear();

                    return num;
                }
            }
        }
        else
        {
            for (i = 0; i < ch.length(); i++)
            {
                if ((ch[i] < '0') || (ch[i] > '9'))
                {
                    cout << "\nError!\nIt's not a number!\n\n";
                    system("pause");
                    system("cls");
                    break;
                }
                else if (i == ch.length() - 1)
                {
                    ss << ch;
                    ss >> num;
                    ss.clear();
                    cout << "\n";

                    return num;
                }
            }
        }
    }
}

int EnteringTheDenominator(int numFraction)
{
    string ch;
    stringstream ss;
    int i, num;
    
    while (true)
    {
        cout << "num" << numFraction << "\n\nEnter the denominator\nInput: ";
        getline(cin, ch);

        if ((ch.length() > 2) || (ch.length() == 0))
        {
            cout << "\nError!\nThe number is not definite!\n\n";
            system("pause");
            system("cls");
        }
        else
        {
            for (i = 0; i < ch.length(); i++)
            {
                if ((ch[i] < '0') || (ch[i] > '9'))
                {
                    cout << "\nError!\nIt's not a number!\n\n";
                    system("pause");
                    system("cls");
                    break;
                }
                else if (i == ch.length() - 1)
                {
                    ss << ch;
                    ss >> num;
                    ss.clear();

                    return num;
                }
            }
        }
    }
}

int CheckingTheNumberOfFractions(int numFraction, int temp)
{
    string ch;
    stringstream ss;

    int i, num;
    
    while (true)
    {
        system("cls");
        
        cout << "\nWhat fraction do you want to use " << temp << " ? \nYou have " << numFraction << " num\nEnter the fraction number : ";

        getline(cin, ch);

        for (i = 0; i < ch.length(); i++)
        {
            if ((ch[i] < '1') || (ch[i] > '9'))
            {
                cout << "\nError!\nIt's not a number!\n\n";
                system("pause");
                break;
            }
            else if (i == ch.length() - 1)
            {
                ss << ch;
                ss >> num;
                ss.clear();

                if (num > numFraction)
                {
                    cout << "\nError!\nThe number is not definite!\n\n";
                    system("pause");
                    break;
                }
                else
                {
                    return num;
                }
            }
        }
    }
}

void task4()
{
    vector <Fractions> num;
    string ch;
    int qust_1, qust_2, numFraction = 0;
    float temp;

    while (true)
    {
        cout << "\nDo you want to create a fractional number ?\ny - yes\nn - no\n\n";
        getline(cin, ch);

        if ((ch.length() == 1) && (ch[0] == 'y')) 
        {
            system("cls");

            numFraction++;
            num.push_back(Fractions(EnteringTheDenominator(numFraction), EnteringTheNumerator(numFraction)));
            system("cls"); // Очишаем программу
        }
        else if ((ch.length() == 1) && (ch[0] == 'n'))
        {
            if (numFraction > 0)
            {
                while (true)
                {
                    system("cls");

                    cout << "\nYou have " << numFraction << " num\n\nsum - count fractions\nsubtraction - subtract fractions\nmultiplication - multiply fractions\ncomparison - compare fractions\nget - Get a fraction\nprint - print a fraction\ndel - completion of work\n\nnum.";
                    getline(cin, ch);

                    if (ch == "sum")
                    {
                        qust_1 = CheckingTheNumberOfFractions(numFraction, 1);
                        qust_2 = CheckingTheNumberOfFractions(numFraction, 2);

                        numFraction++;
                        num.push_back(num[qust_1 - 1].sum(num[qust_2 - 1]));
                    }

                    if (ch == "subtraction")
                    {
                        qust_1 = CheckingTheNumberOfFractions(numFraction, 1);
                        qust_2 = CheckingTheNumberOfFractions(numFraction, 2);

                        numFraction++;
                        num.push_back(num[qust_1 - 1].subtraction(num[qust_2 - 1]));
                    }

                    if (ch == "multiplication")
                    {
                        qust_1 = CheckingTheNumberOfFractions(numFraction, 1);
                        qust_2 = CheckingTheNumberOfFractions(numFraction, 2);

                        numFraction++;
                        num.push_back(num[qust_1 - 1].multiplication(num[qust_2 - 1]));
                    }

                    if (ch == "comparison")
                    {
                        qust_1 = CheckingTheNumberOfFractions(numFraction, 1);
                        qust_2 = CheckingTheNumberOfFractions(numFraction, 2);

                        num[qust_1 - 1].comparison(num[qust_1 - 1], num[qust_2 - 1]);
                    }

                    if (ch == "get")
                    {
                        qust_1 = CheckingTheNumberOfFractions(numFraction, 1);

                        temp = num[qust_1 - 1].get();

                        system("cls");
                        cout << "temp -> " << temp << "\n\n";
                        system("pause");
                    }

                    if (ch == "print")
                    {
                        qust_1 = CheckingTheNumberOfFractions(numFraction, 1);

                        num[qust_1 - 1].print(qust_1);
                    }

                    if (ch == "del")
                    {
                        break;
                    }
                }
            
                break;
            }
            
            break;
        }
    }
}

// Реализовать классы, хранящие в себе число, строку и массив строк(MyNumber, MyString, MyArray).Данные должны храниться в приватных свойствах, для их установки и чтения
// должны быть реализованы соответсвующие геттеры и сеттеры.Так же необходимо реализовать класс объединитель(MyJoin), принимающий в кострукторе объекты всех 3 - х типов.
// В классе соединителе должен быть реализован метод join(), возвращающий строку, сосотоящую из "склеенных" элементов, переданных в конструктор, сформированную по следующим правилам :
//  - после числа дописывается символ '%d'
//  - после строки символ '%s'
//  - каждый элемент массива дописывается в строку по очереди и после каждого элемента дописывается символ '%a'
// !В методе join() не должны использоваться if или switch, каждый класс отдельного типа должен сам знать как вывести себя корректно.
//
// Примеры :
//   MyNumber myNum(3)
//   MyString myStr('hello')
//   MyArray myArr(['some', 'array', 'of', 'strings'])
//   MyJoin myJoin(myNum, myStr, myArr)
//   myJoin.join() -> '3%d hello%s some%a array%a of%a strings%a'

class MyNumber
{
private:

    int _num;

public:

    MyNumber()
    {
        _num = 0;
    }
    
    MyNumber(int num)
    {
        _num = num;
    }
    
    int get()
    {
        return _num;
    }
    
    void set(int num)
    {
        _num = num;
    }
};

class MyString
{
private:

    string _word;

public:

    MyString()
    {
        _word = "";
    }

    MyString(string word)
    {
        _word = word;
    }

    string get()
    {
        return _word;
    }

    void set(string word)
    {
        _word = word;
    }
};

class MyArray
{
private:

    vector<string> _words;

public:

    MyArray()
    {
        _words = {};
    }

    MyArray(vector<string> words)
    {
        _words = words;
    }

    vector<string> get()
    {
        return _words;
    }

    void set(vector<string> words)
    {
        int i;

        for (i = 0; i < _words.size(); i++)
        {
            _words[i] = words[i];
        }
    }
};

class MyJoin
{
private:

    MyNumber _a;
    MyString _b;
    MyArray _c;

public:
    MyJoin(MyNumber a, MyString b, MyArray c)
    {
        _a = a;
        _b = b;
        _c = c;
    }

    string join()
    {
        string words;
        stringstream ss;
        
        vector<string> temp = _c.get();

        ss << _a.get();
        ss >> words;
        ss.clear();

        words += "%d " + _b.get() + "%s ";

        for (int i = 0; i < temp.size(); i++)
        {
            words += temp[i] + "%a ";
        }
    
        return words;
    }
};

void task5()
{
    MyNumber myNum(10);
    MyString myStr("hello");
    MyArray myArr({ "some", "array", "of", "strings" });

    vector<string> a;

    cout << myNum.get() << endl;
    cout << myStr.get() << endl;
    a = myArr.get();

    for (vector<string>::iterator it = a.begin(); it != a.end(); ++it)
        cout << *it << " ";

    cout << "\n\n";

    MyJoin myJoin(myNum, myStr, myArr);

    cout << myJoin.join() << "\n\n";
}

// Реализовать класс игры на реакцию(ReactionGame).Суть игры - в начале игрок выбирает количество и тип символов(буквы или цифры), после чего игроку в консоль
// по очереди по одному выводятся случайно сгенерированные элементы(буквы или цифры).Игрок должен как можно быстрее ввести данный символ в консоль.При вводе верного символа
// игра замеряет время(в секундах), которое понадобилось игроку на ввод, с момента появления символа на экране(если игрок ошибся, игра прерывается и игрок проигрывает).
// После вывода всех символов, подсчитывается и выводится общее время реакции и средний результат на каждый элемент.Класс должен иметь методы :
// startGame() - начало игры
// setAmount() - выбор количества символов для игры
// generateNext() - сгенерировать следуюший символ
// calculate() - посчитать общее время реакции и среднее значение
// От данного класса должны наследовать классы игры с латинскими буквами(CharReactionGame) и цифрами(NumberReactionGame).Каждый из классов должен реализовать только
// уникальную для него логику, тогда как одинаковый функционал должен быть реализован в родительском классе ReactionGame.
// * Для получения текущего времени в секундах с момента 01 - Jan - 1970 можно использовать метод time(0) из библиотеки ctime(#include<ctime>).
//
// Примеры:
//   CharReactionGame charGame()
//   charGame().setAmount(4)
//   charGame().startGame() -> (charGame().generateNext()) -> "A" -> (input A : ) 2 sec -> "Z" -> 4 sec -> "S" -> 1 sec -> "j" -> 5 sec
//   ->total : 12 sec average : 3 sec
//
//   NumberReactionGame numGame()
//   numGame().setAmount(4)
//   numGame().startGame() -> (numGame().generateNext()) -> "9" -> (input 9:) 1 sec -> "3" -> 1 sec -> "6" -> 2 sec -> "8" -> 2 sec
//   ->total : 6 sec average : 1, 5 sec

class ReactionGame
{
protected: 

    int _amount, _time = 0;
    string _chars;

public:

    void setAmount(int amount)
    {
        _amount = amount;

        if (_amount == 0)
        {
            cout << "\n\nYOU LOSE !!!\n\n";
            exit(0);
        }
    }

    void startGame()
    {
        
        int i;
        string ch1, ch2;

        for (i = 0; i < _amount; i++)
        {
            ch1 = generateNext();
            cout << "Input " << ch1 << ": ";
            clock_t t1 = clock();
            getline(cin, ch2);
            clock_t t2 = clock();

            if (ch1 != ch2)
            {
                cout << "\n\nYOU LOSE !!!\n\n";
                exit(0);
            }

            _time += (t2 - t1) / CLOCKS_PER_SEC;
            //cout << "\n" << (t2 - t1) / CLOCKS_PER_SEC << " sec\n\n"; 

            //system("pause");
            system("cls");
        }
    }

    void calculate()
    {
        cout << "\n total: " << _time << " sec\n average: " << setprecision(3) << ((double)_time / (double)_amount) << " sec" << "\n\n";
    }

private:

    char generateNext()
    {
        int r = rand() % _chars.length();
        
        return _chars[r];
    }
};

class CharReactionGame : public ReactionGame
{
public:
    CharReactionGame()
    {
        _chars = { "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    }
};

class NumberReactionGame : public ReactionGame
{
public:
    NumberReactionGame()
    {
        _chars = { "0123456789"};
    }
};

void task6()
{
    string ch;

    while (true)
    {
        cout << "\nWhat symbols do you want to play with\n\ni - ineger\nl - letter\n\nInput: ";

        getline(cin, ch);

        if (ch.length() == 1 && ch[0] == 'l')
        {
            system("cls");
            
            CharReactionGame charGame;

            cout << "\nWhat is the number of characters in the game ?\n\nInput: ";

            getline(cin, ch);

            charGame.setAmount(CheckingTheNumber(ch));

            system("cls");

            charGame.startGame();

            charGame.calculate();

            break;
        }
        else if (ch.length() == 1 && ch[0] == 'i')
        {
            system("cls");
            
            NumberReactionGame numGame;

            cout << "\nWhat is the number of characters in the game ?\n\nInput: ";

            getline(cin, ch);

            numGame.setAmount(CheckingTheNumber(ch));

            system("cls");

            numGame.startGame();

            numGame.calculate();
            
            break;
        }

        system("cls");
    }
}