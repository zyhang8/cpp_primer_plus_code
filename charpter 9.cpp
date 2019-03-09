#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <new>
#include "sales.h"


using namespace std;


// practice 1
const int Len = 40;
struct golf {
    char fullname[Len];
    int handicap;
};
void setgolf(golf & g, const char * name, int hc)
{
    strcpy(g.fullname, name);
    g.handicap = hc;
}
int setgolf(golf & g)
{
    cout << "Please enter the full name of golf player: ";
    cin.getline(g.fullname, Len);
    if (strcmp(g.fullname, "") == 0)
    {
        return 0;
    }

    cout << "Please enter the hanicap of golf player: ";
    cin >> g.handicap;
    cin.get();

    return 1;
}
void handicap(golf & g, int hc)
{
    g.handicap = hc;
}
void showgolf(const golf & g)
{
    cout << "full name of golf player: " << g.fullname << endl;
    cout << "handicap of golf player: " << g.handicap << endl;
}
void p9_1(void)
{
    golf g[10];
    int n = 0;
    cout << "Enter the information of golf player: " << endl;

    while ((n < 10) && (setgolf(g[n])))
    {
        n++;
        cout << "Next golf player: " << endl;
    }

    cout << "Show all golf player information: " << endl;
    for (int i = 0; i < n; i++)
    {
        showgolf(g[i]);
    }

}


// practice 2
const int ArSize = 10;
void strcount(const string str)
{
    static int total = 0;
    int count = 0;

    cout << "\"" << str.c_str() << "\" contains ";
    while (str[count])
    {
        count++;
    }
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}
void p9_2(void)
{
    string input;

    cout << "Enter a line:\n";
    getline(cin, input);
    while (cin)
    {
        strcount(input);
        cout << "Enter next line (empty line to quit): \n";
        getline(cin, input);
        if (input == "")
        {
            break;
        }
    }

    cout << "Bye\n";
    return;
}


// practice 3
struct chaff {
    char dross[20];
    int slag;
};
char buffer[1024];
void p9_3(void)
{
    chaff *pcha = new (buffer) chaff[2];
    char *pc = new char[1024];
    chaff *pcha2 = new (pc) chaff[2];
    char dross[20] = { 0 };
    int slag = 0;

    for (int i = 0; i < 2; i++)
    {
        cout << "Enter dross of #" << i << " chaff: " << endl;
        cin.getline(dross, 20);
        cout << "Enter slag of #" << i << " chaff: " << endl;
        cin >> slag;
        cin.get();

        strcpy(pcha[i].dross, dross);
        strcpy(pcha2[i].dross, dross);
        pcha[i].slag = pcha2[i].slag = slag;
    }

    for (int i = 0; i < 2; i++)
    {
        cout << "staff #" << (i + 1) << ":" << endl;
        cout << "pcha.dross: " << pcha[i].dross << ". pcha.slag: " << pcha[i].slag << endl;
        cout << "pcha2.dross: " << pcha2[i].dross << ". pcha2.slag: " << pcha2[i].slag << endl;
    }

    cout << "address of buffer: " << (void *)buffer << endl;
    cout << "address of pcha: " << pcha << ". address of pcha[0]: " << &pcha[0] << ". address of pcha[1]: " << &pcha[1] << endl;
    cout << "address of pc: " << (void *)pc << endl;
    cout << "address of pcha2:" << pcha2 << ". address of pcha2[0]: " << &pcha2[0] << ". address of pcha2[1]: " << &pcha2[1] << endl;;

    delete[] pc;
}


// practice 4
void p9_4(void)
{
    SALES::Sales sales1;
    SALES::Sales sales2;

    double ar[3] = { 32.1, 23.2, 65.3 };
    SALES::setSales(sales1, ar, 3);
    SALES::setSales(sales2);

    SALES::showSales(sales1);
    SALES::showSales(sales2);
}


int main(int argc, char **argv)
{
    p9_4();

    while (cin.get());

    return 0;
}


// sales.h

#pragma once
#include <iostream>
namespace SALES
{
    const int QUARTERS = 4;
    struct Sales
    {
        double sales[QUARTERS];
        double average;
        double max;
        double min;
    };
    void setSales(Sales & s, const double ar[], int n);
    void setSales(Sales & s);
    void showSales(const Sales & s);
}


// sales.cpp

#include "sales.h"

namespace SALES
{
    using namespace std;

    void setSales(Sales & s, const double ar[], int n)
    {
        double total = 0.0;
        double max = ar[0];
        double min = ar[0];

        for (int i = 0; i < n; i++)
        {
            total += ar[i];
            s.sales[i] = ar[i];
            if (max < ar[i])
            {
                max = ar[i];
            }
            if (min > ar[i])
            {
                min = ar[i];
            }
        }
        for (int i = n; i < QUARTERS; i++)
        {
            s.sales[i] = 0.0;
        }

        s.average = total / n;
        s.max = max;
        s.min = min;
    }

    void setSales(Sales & s)
    {
        double total = 0.0;
        double max = 0.0;
        double min = 0.0;
        double input = 0.0;

        cout << "Enter 4 double number; " << endl;
        for (size_t i = 0; i < QUARTERS; i++)
        {
            cin >> input;
            if (i == 0)
            {
                max = input;
                min = input;
            }
            if (min > input)
            {
                min = input;
            }
            if (max < input)
            {
                max = input;
            }
            total += input;
            s.sales[i] = input;
        }
        s.average = total / QUARTERS;
        s.max = max;
        s.min = min;
    }

    void showSales(const Sales & s)
    {
        cout << "sales: ";
        for (size_t i = 0; i < QUARTERS; i++)
        {
            cout << s.sales[i] << " ";
        }

        cout << endl;
        cout << "average: " << s.average << endl;
        cout << "max: " << s.max << endl;
        cout << "min: " << s.min << endl;
    }
}
