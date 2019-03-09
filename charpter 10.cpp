#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

#include "Sales.h"
#include "stack.h"
#include "List.h"

using namespace std;

// practice 1
class BankCount {

private:
    string fullname;
    string banknumber;
    long balance;

public:
    BankCount() {}
    BankCount(string fullname, string banknumber, long balance);
    void ShowBankCount();
    int Deposit(long deposit);
    int WithDrawals(long withdrawals);
};
BankCount::BankCount(string fullname, string banknumber, long balance)
{
    this->fullname = fullname;
    this->banknumber = banknumber;
    this->balance = balance;
}
void BankCount::ShowBankCount()
{
    cout << "BankCount full name: " << fullname << endl;
    cout << "BankCount number: " << banknumber << endl;
    cout << "BankCount balance: " << balance << endl;
}
int BankCount::Deposit(long deposit)
{
    this->balance += deposit;
    return 1;
}
int BankCount::WithDrawals(long withdrawals)
{
    this->balance -= withdrawals;
    return 1;
}
void p10_1(void)
{
    BankCount MyBankCount("Jimmy", "1234567", 10000);
    cout << "Original BankCount: " << endl;
    MyBankCount.ShowBankCount();

    cout << endl;
    cout << "After Deposit 5000: " << endl;
    MyBankCount.Deposit(5000);
    MyBankCount.ShowBankCount();

    cout << endl;
    cout << "After withdrawals 5000: " << endl;
    MyBankCount.WithDrawals(5000);
    MyBankCount.ShowBankCount();
}


// practice 2
class Person {
private:
    // static const LIMIT = 25 编译报错，C++不支持默认int
    static const int LIMIT = 25;
    string lname;
    char fname[LIMIT];

public:
    Person() { lname = ""; fname[0] = '\0'; }
    Person(const string & ln, const char * fn = "Heyyou");
    void Show() const;
    void FormalShow() const;
};
Person::Person(const string & ln, const char * fn)
{
    lname = ln;
    strncpy(fname, fn, LIMIT);
}
void Person::Show() const
{
    cout << fname << ", " << lname << endl;
}
void Person::FormalShow() const
{
    cout << lname << ", " << fname << endl;
}
void p10_2(void)
{
    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");
    one.Show();
    one.FormalShow();

    cout << endl;
    two.Show();
    two.FormalShow();

    cout << endl;
    three.Show();
    three.FormalShow();
}


// practice 3
class golf {
private:
    static const int Len = 40;
    char fullname[Len];
    int handicap;

public:
    golf(const char * name, int hc);
    golf();
    void sethandicap(int hc);
    void showgolf();
};
golf::golf(const char * name, int hc)
{
    strncpy(fullname, name, Len);
    handicap = hc;
}
golf::golf()
{
    char temp[Len] = "";
    int hand = 0;
    cout << "Please enter the full name of golf player: ";
    cin.getline(temp, Len);

    cout << "Please enter the hanicap of golf player: ";
    cin >> hand;
    cin.get();

    *this = golf(temp, hand);
}
void golf::sethandicap(int hc)
{
    handicap = hc;
}
void golf::showgolf()
{
    cout << "golf full name: " << fullname << endl;
    cout << "golf handicap: " << handicap << endl;
}
void p10_3(void)
{
    golf g;
    golf g2("Jimmy", 100);

    g.showgolf();
    g.sethandicap(120);
    g.showgolf();

    g2.showgolf();
    g2.sethandicap(120);
    g2.showgolf();
}


// practice 4
using namespace SALES;
void p10_4(void)
{
    double ar[3] = { 32.1, 23.2, 65.3 };
    Sales sales1(ar, 3);
    Sales sales2;

    sales1.showSales();
    sales2.showSales();
}


// practice 5
void p10_5(void)
{
    Stack stack;
    double total = 0.0;
    customer pop;

    customer customer1 = { "jimmy", 1000 };

    if (stack.push(customer1))
    {
        cout << customer1.fullname << " push." << endl;
    }
    else
    {
        cout << "Stack full." << endl;
    }

    customer customer2 = { "hey", 200.0 };

    if (stack.push(customer2))
    {
        cout << customer2.fullname << " push." << endl;
    }
    else
    {
        cout << "Stack full." << endl;
    }

    if (stack.pop(pop))
    {
        cout << pop.fullname << " pop." << endl;
        total += pop.payment;
    }
    else
        cout << "Stack empty." << endl;


    customer customer3 = { "kitty", 3000.0 };
    if (stack.push(customer3))
        cout << customer3.fullname << " push." << endl;
    else
        cout << "Stack full." << endl;

    if (stack.pop(pop))
    {
        cout << pop.fullname << " pop." << endl;
        total += pop.payment;
    }
    else
        cout << "Stack empty." << endl;

    if (stack.pop(pop))
    {
        cout << pop.fullname << " pop." << endl;
        total += pop.payment;
    }
    else
        cout << "Stack empty." << endl;

    if (stack.pop(pop))
    {
        cout << pop.fullname << " pop." << endl;
        total += pop.payment;
    }
    else
        cout << "Stack empty." << endl;

    cout << "Total paymemt: " << total << endl;
}


// practice 6
class Move
{
private:
    double x;
    double y;

public:
    Move(double a = 0, double b = 0);
    void showmove() const;
    Move add(const Move & m) const;
    void reset(double a = 0, double b = 0);
};
Move::Move(double a, double b)
{
    x = a;
    y = b;
}
void Move::showmove() const
{
    cout << "x = " << x << ", y = " << y << "." << endl;
}
Move Move::add(const Move & m) const
{
    Move temp;
    temp.x = this->x + m.x;
    temp.y = this->y + m.y;

    return temp;
}
void Move::reset(double a, double b)
{
    x = a;
    y = b;
}
void p10_6(void)
{
    Move move1(1.1, 2.2);
    move1.showmove();

    Move move2(3.3, 4.4);
    move2.showmove();

    Move move3 = move1.add(move2);
    move3.showmove();

    move3.reset(0.1, 0.2);
    move3.showmove();
}


// practice 7
class plorg
{
private:
    enum { LEN = 20 };
    char fullname[LEN];
    int CI;

public:
    plorg(char * name = "Plorga", int CI = 50);
    void setCI(int CI);
    void showPlorg();
};
plorg::plorg(char * name, int CI)
{
    strncpy(fullname, name, LEN);
    this->CI = CI;
}
void plorg::setCI(int CI)
{
    this->CI = CI;
}
void plorg::showPlorg()
{
    cout << "plorg full name: " << fullname << endl;
    cout << "plorg CI: " << CI << endl;
}
void p10_7(void)
{
    plorg pl("Jimmy", 100);
    pl.showPlorg();

    plorg pl2;
    pl2.showPlorg();

    pl.setCI(150);
    pl.showPlorg();
}


// practice 8
// 大概这样简单的写一下吧
void p10_8(void)
{
    List list;
    if (list.isempty())
    {
        cout << "List is empty" << endl;
    }

    uItem item1 = 1;
    uItem item2 = 2;
    uItem item3 = 3;

    list.add(item1);
    list.add(item2);
    list.add(item3);

    if (list.isempty())
    {
        cout << "List is empty" << endl;
    }
    else if (list.isfull())
    {
        cout << "List is full" << endl;
    }
    else
    {
        cout << "Some items in the list" << endl;
    }

    list.visit(oringin);
    list.visit(x2);
    list.visit(half);

}


int main(int argc, char **argv)
{
    p10_8();

    while (cin.get());

    return 0;
}


// List.h
#pragma once
#include <iostream>

typedef unsigned long uItem;
using std::cout;
using std::cin;
using std::endl;

class List
{
private:
    enum { MAX = 20 };
    uItem items[MAX];
    int top;

public:
    List() { top = 0; }
    int add(uItem & item);
    bool isempty();
    bool isfull();
    void visit(void(*pf)(uItem &));
};

void oringin(uItem & item);
void x2(uItem & item);
void half(uItem & item);


// List.cpp
#include "List.h"

int List::add(uItem & item)
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

bool List::isempty()
{
    return top == 0;
}

bool List::isfull()
{
    return top == (MAX - 1);
}

void List::visit(void(*pf)(uItem &))
{
    for (int i = 0; i < top; i++)
    {
        cout << "#" << i << ": ";
        pf(items[i]);
    }
}

void oringin(uItem & item)
{
    cout << item << endl;
}

void x2(uItem & item)
{
    item = item * 2;
    cout << item << endl;
}

void half(uItem & item)
{
    item = item / 2;
    cout << item << endl;
}


// Sales.h
#pragma once
#include <iostream>

namespace SALES
{
    const int QUARTERS = 4;
    class Sales {
    private:
        double sales[QUARTERS];
        double average;
        double max;
        double min;

    public:
        Sales(double ar[], int n);
        Sales();
        void showSales();
    };
}


// Sales.cpp
#include "Sales.h"

using namespace std;
using namespace SALES;
Sales::Sales()
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
        sales[i] = input;
    }
    this->average = total / QUARTERS;
    this->max = max;
    this->min = min;
}
Sales::Sales(double ar[], int n)
{
    double total = 0.0;
    double max = ar[0];
    double min = ar[0];

    for (int i = 0; i < n; i++)
    {
        total += ar[i];
        sales[i] = ar[i];
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
        sales[i] = 0.0;
    }

    this->average = total / n;
    this->max = max;
    this->min = min;
}
void Sales::showSales()
{
    cout << "sales: ";
    for (size_t i = 0; i < QUARTERS; i++)
    {
        cout << sales[i] << " ";
    }

    cout << endl;
    cout << "average: " << average << endl;
    cout << "max: " << max << endl;
    cout << "min: " << min << endl;
}


//stack.h
#pragma once
#ifndef STACK_H_
#define STACK_H_

struct customer
{
    char fullname[35];
    double payment;
};

typedef customer Item;

class Stack
{
private:
    enum { MAX = 10};
    Item items[MAX];
    int top;

public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item & item);
    bool pop(Item & item);
};

#endif // !STACK_H_


// stack.cpp
#include "stack.h"

Stack::Stack()
{
    top = 0;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::push(const Item & item)
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item & item)
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    }
    else
        return false;
}
