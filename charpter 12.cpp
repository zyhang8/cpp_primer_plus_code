#pragma once
#ifndef CHAPTER12_H_
#define CHAPTER12_H_

class Cow {
    char name[20];
    char * hobby;
    double weight;

public:
    Cow();
    Cow(const char * nm, const char * ho, double wt);
    Cow(const Cow & c);
    ~Cow();
    Cow & operator=(const Cow & c);
    void ShowCow() const;
};

#endif // !CHAPTER12_H_


// Chapter12.cpp
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cstdlib>

#include "Chapter12.h"
#include "string2.h"
#include "Stock.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;


// practice 1
Cow::Cow()
{

}
Cow::Cow(const char * nm, const char * ho, double wt)
{
    strncpy(name, nm, 20);
    int ho_length = strlen(ho);
    hobby = new char[ho_length + 1];
    strncpy(hobby, ho, ho_length);
    hobby[ho_length] = '\0';
    weight = wt;
}
Cow::Cow(const Cow & c)
{
    strncpy(name, c.name, 20);
    int ho_length = strlen(c.hobby);
    hobby = new char[ho_length + 1];
    strncpy(hobby, c.hobby, ho_length);
    hobby[ho_length] = '\0';
    weight = c.weight;
}
Cow::~Cow()
{
    delete[] hobby;
    hobby = nullptr;
}
Cow & Cow::operator=(const Cow & c)
{
    strncpy(name, c.name, 20);
    int ho_length = strlen(c.hobby);
    hobby = new char[ho_length + 1];
    strncpy(hobby, c.hobby, ho_length);
    hobby[ho_length] = '\0';
    weight = c.weight;

    return *this;
}
void Cow::ShowCow() const
{
    cout << "Cow name: " << name << endl;
    cout << "Cow hobby: " << hobby << endl;
    cout << "Cow weight: " << weight << endl;
}
void p12_1(void)
{
    Cow cow1("hehehe", "eat", 123.4);
    Cow cow2("heihei", "drink", 321.2);
    Cow cow3(cow2);
    Cow cow4 = cow1;

    cow1.ShowCow();
    cow2.ShowCow();
    cow3.ShowCow();
    cow4.ShowCow();
}


// practice 2
void p12_2(void)
{
    String2 s1("and i am a C++ student.");
    String2 s2 = "Please enter your name: ";
    String2 s3;
    cout << s2;
    cin >> s3;
    s2 = "My name is " + s3;
    cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.Stringup();
    cout << "The sting\n" << s2 << "\ncontains " << s2.has('A')
        << " 'A' characters in it.\n";
    s1 = "red";
    String2 rgb[3] = { String2(s1), String2("green"), String2("blue") };
    cout << "Enter the name of a primary color for mixing light: ";
    String2 ans;
    bool success = false;
    while (cin >> ans)
    {
        ans.Stringlow();
        for (int i = 0; i < 3; i++)
        {
            if (ans == rgb[i])
            {
                cout << "That's right!\n";
                success = true;
                break;
            }
        }
        if (success)
        {
            break;
        }
        else
        {
            cout << "Try again!\n";
        }
    }

    cout << "Bye!\n";
    return ;
}


// practice 3
const int STKS = 4;
void p12_3(void)
{
    Stock stocks[STKS] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
    };

    std::cout << "Stock holdings:\n";
    int st;
    for (st = 0; st < STKS; st++)
    {
        std::cout << stocks[st];
    }

    const Stock * top = &stocks[0];
    for (st = 0; st < STKS; st++)
    {
        top = &top->topval(stocks[st]);
    }

    std::cout << "\nMost valuable holding:\n";
    cout << *top;
    return;
}


// practice 4
void p12_4(void)
{
    Stack st1(10);
    srand(time(0));
    for (size_t i = 0; i < 10; i++)
    {
        if (!st1.push(rand() % 100))
        {
            cout << "Push error!" << endl;;
        }

    }
    if (!st1.push(0))
    {
        cout << "Push 0 error!" << endl;
    }
    Stack st2(st1);
    Stack st3 = st1;
    // 故意导致pop error
    for (size_t i = 0; i < 11; i++)
    {
        Item item;
        cout << "#" << i+1 << ": " << endl;
        if (!st1.pop(item))
        {
            cout << "st1 pop error!" << endl;
        }
        else
            cout << "st1: " << item << endl;

        if (!st2.pop(item))
        {
            cout << "st2 pop error!" << endl;
        }
        else
            cout << "st2: " << item << endl;

        if (!st3.pop(item))
        {
            cout << "st3 pop error!" << endl;
        }
        else
            cout << "st3: " << item << endl;

        cout << endl;
    }
}


// practice 5
const int MIN_PER_HR = 60;
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}
void p12_5(void)
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

    std::srand(std::time(0));

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximun size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);

    // 直接将测试时间设置为100好了
    cout << "Simulation hours: 100" << endl;
    int hours = 100;

    long cyclelimit = MIN_PER_HR * hours;

    cItem temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0;
    long line_wait = 0;
    double avg_wait_time = 0.0;

    // 每小时使用人数初始值为15，之后进行+1枚举测试
    double perhour = 15;
    double min_per_cust;

    do {
        min_per_cust = MIN_PER_HR / perhour;
        turnaways = 0;
        customers = 0;
        served = 0;
        sum_line = 0;
        wait_time = 0;
        line_wait = 0;
        avg_wait_time = 0;

        // 需要清空队列
        while (!line.isempty())
        {
            line.dequeue(temp);
        }

        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust))
            {
                if (line.isfull())
                {
                    turnaways++;
                }
                else
                {
                    customers++;
                    temp.set(cycle);
                    line.enqueue(temp);
                }
            }
            if (wait_time <= 0 && !line.isempty())
            {
                line.dequeue(temp);
                wait_time = temp.ptime();
                line_wait += (cycle - temp.when());
                served++;
            }
            if (wait_time > 0)
            {
                wait_time--;
            }
            sum_line += line.queuecount();
        }

        if (customers > 0)
        {
            cout << "customers accepted: " << customers << endl;
            cout << "  customers served: " << served << endl;
            cout << "         turnaways: " << turnaways << endl;
            cout << "average queue size: ";
            cout.precision(2);
            cout.setf(ios_base::fixed, ios_base::floatfield);
            cout << (double)sum_line / cyclelimit << endl;
            avg_wait_time = (double)line_wait / served;
            cout << " average wait time: "
                << avg_wait_time << " minutes\n" << endl;
        }
        else
            cout << "No customers!\n" << endl;;
        // 平均等待时间不一定刚好是1，设置在一个区间内
    } while ((perhour++) && (avg_wait_time < 0.9) || (avg_wait_time > 1.1));

    cout << "When perhour = " << perhour << " , the average wait time"
        " will be about 1 minute\n" << endl;

    cout << "Done!\n";

    return;
}


// practice 6
void p12_6(void)
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

    std::srand(std::time(0));

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximun size of queue: ";
    int qs;
    cin >> qs;
    Queue line1(qs);
    Queue line2(qs);

    // 直接将测试时间设置为100好了
    cout << "Simulation hours: 100" << endl;
    int hours = 100;

    long cyclelimit = MIN_PER_HR * hours;

    cItem temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time1 = 0;
    int wait_time2 = 0;
    int line1_size = 0;
    int line2_size = 0;
    long line_wait = 0;
    double avg_wait_time = 0.0;

    // 每小时使用人数初始值为15，之后进行+1枚举测试
    double perhour = 15;
    double min_per_cust;

    do {
        min_per_cust = MIN_PER_HR / perhour;
        turnaways = 0;
        customers = 0;
        served = 0;
        sum_line = 0;
        wait_time1 = 0;
        wait_time2 = 0;
        line1_size = 0;
        line2_size = 0;
        line_wait = 0;
        avg_wait_time = 0;

        // 需要清空队列
        while (!line1.isempty())
        {
            line1.dequeue(temp);
        }

        while (!line2.isempty())
        {
            line2.dequeue(temp);
        }

        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust))
            {
                if (line1.isfull() && line2.isfull())
                {
                    turnaways++;
                }
                else if (line1_size > line2_size)
                {
                    customers++;
                    temp.set(cycle);
                    line2.enqueue(temp);
                    line2_size++;
                }
                else
                {
                    customers++;
                    temp.set(cycle);
                    line1.enqueue(temp);
                    line1_size++;
                }
            }
            if (wait_time1 <= 0 && !line1.isempty())
            {
                line1.dequeue(temp);
                line1_size--;
                wait_time1 = temp.ptime();
                line_wait += (cycle - temp.when());
                served++;
            }
            if (wait_time2 <=0 && !line2.isempty())
            {
                line2.dequeue(temp);
                line2_size--;
                wait_time2 = temp.ptime();
                line_wait += (cycle - temp.when());
                served++;
            }
            if (wait_time1 > 0)
            {
                wait_time1--;
            }
            if (wait_time2 > 0)
            {
                wait_time2--;
            }
            sum_line += line1.queuecount();
            sum_line += line2.queuecount();
        }

        if (customers > 0)
        {
            cout << "customers accepted: " << customers << endl;
            cout << "  customers served: " << served << endl;
            cout << "         turnaways: " << turnaways << endl;
            cout << "average queue size: ";
            cout.precision(2);
            cout.setf(ios_base::fixed, ios_base::floatfield);
            cout << (double)sum_line / cyclelimit << endl;
            avg_wait_time = (double)line_wait / served;
            cout << " average wait time: "
                << avg_wait_time << " minutes\n" << endl;;
        }
        else
            cout << "No customers!\n" << endl;
        // 平均等待时间不一定刚好是1，设置在一个区间内
    } while ((perhour++) && (avg_wait_time < 0.9) || (avg_wait_time > 1.1));

    cout << "When perhour = " << perhour << " , the average wait time"
        " will be about 1 minute\n" << endl;

    cout << "Done!\n";

    return;
}


int main(int argc, char **argv)
{
    p12_6();

    while (cin.get());
}


// Queue.h
#pragma once

class Customer
{
private:
    long arrive;
    int processtime;

public:
    Customer() { arrive = processtime = 0; }
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};

typedef Customer cItem;

class Queue
{
private:
    struct Node { cItem item; struct Node * next; };
    enum {Q_SIZE = 10};
    Node * front;
    Node * rear;
    int items;
    const int qsize;
    Queue(const Queue & q) : qsize(0) {}
    Queue & operator=(const Queue & q) { return *this; }

public:
    Queue(int qs = Q_SIZE);
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const cItem & item);
    bool dequeue(cItem & item);
};


// Queue.cpp
#include "Queue.h"
#include <cstdlib>


Queue::Queue(int qs) : qsize(qs)
{
    front = rear = NULL;
    items = 0;
}

Queue::~Queue()
{
    Node * temp;
    while (front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}

bool Queue::isempty() const
{
    return items == 0;
}

bool Queue::isfull() const
{
    return items == qsize;
}

int Queue::queuecount() const
{
    return items;
}

bool Queue::enqueue(const cItem & item)
{
    if (isfull())
    {
        return false;
    }

    Node * add = new Node;
    add->item = item;
    add->next = NULL;
    items++;
    if (front == NULL)
    {
        front = add;
    }
    else
        rear->next = add;

    rear = add;
    return true;
}

bool Queue::dequeue(cItem & item)
{
    if (front == NULL)
    {
        return false;
    }

    item = front->item;
    items--;
    Node * temp = front;
    front = front->next;
    delete temp;

    if (items == 0)
    {
        rear = NULL;
    }
    return true;
}

void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when;
}


// Stack.h
#pragma once
typedef unsigned long Item;


class Stack
{
private:
    enum {MAX = 10};
    Item * pitems;
    int size;
    int top;

public:
    Stack(int n = MAX);
    Stack(const Stack & st);
    ~Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item & item);
    bool pop(Item & item);
    Stack & operator=(const Stack & st);
};


// Stack.cpp
#include "Stack.h"
#include <iostream>


Stack::Stack(int n)
{
    pitems = new Item[n];
    size = n;
    top = 0;
}

Stack::Stack(const Stack & st)
{
    size = st.size;
    pitems = new Item[size];
    top = st.top;
    for (int i = 0; i < top; i++)
    {
        pitems[i] = st.pitems[i];
    }
}

Stack::~Stack()
{
    delete[] pitems;
    pitems = nullptr;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == size;
}

bool Stack::push(const Item & item)
{
    if (isfull())
    {
        return false;
    }

    pitems[top++] = item;
    return true;
}

bool Stack::pop(Item & item)
{
    if (isempty())
    {
        return false;
    }

    item = pitems[--top];
    return true;
}

Stack & Stack::operator=(const Stack & st)
{
    size = st.size;
    pitems = new Item[size];
    top = st.top;
    for (int i = 0; i < top; i++)
    {
        pitems[i] = st.pitems[i];
    }

    return *this;
}


// Stock.h
#pragma once
#include <iostream>
class Stock
{
private:
    char * company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }

public:
    Stock();
    Stock(const char * co, long n = 0, double pr = 0.0);
    ~Stock();
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show() const;
    friend std::ostream & operator<<(std::ostream & os, const Stock & st);
    const Stock & topval(const Stock & s) const;
};


// Stock.cpp
#include "Stock.h"
#include <cstring>


Stock::Stock()
{
    int len = std::strlen("no name");
    company = new char[len + 1];
    std::strcpy(company, "no name");
    company[len] = '\0';

    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char * co, long n, double pr)
{
    int len = std::strlen(co);
    company = new char[len + 1];
    std::strcpy(company, co);

    if (n < 0)
    {
        std::cout << "Number of shares can't be negative; "
            << company << " shares set to n.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

Stock::~Stock()
{
    delete[] company;
    company = nullptr;
}

void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. "
            << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        cout << "Number of shares sold can't be negative. "
            << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        cout << "You can't sell more than you have! "
            << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show() const
{
    using std::cout;
    using std::ios_base;
    ios_base::fmtflags orig =
        cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);

    cout << "Company: " << company
        << " Shares: " << shares << '\n';
    cout << "Share Price: $" << share_val;
    cout.precision(2);
    cout << " Total Worth: $" << total_val << '\n';

    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

std::ostream & operator<<(std::ostream & os, const Stock & st)
{
    using std::ios_base;
    ios_base::fmtflags orig =
        os.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = os.precision(3);

    os << "Company: " << st.company
        << " Shares: " << st.shares << '\n';
    os << " Share Price: $" << st.share_val;
    os.precision(2);
    os << " Total Worth: $" << st.total_val << '\n';

    os.setf(orig, ios_base::floatfield);
    os.precision(prec);

    return os;
}

const Stock & Stock::topval(const Stock & s) const
{
    if (s.total_val > total_val)
    {
        return s;
    }
    else
        return *this;
}


// string2.h
#pragma once
#ifndef STRING2_H_
#define STRING2_H_

#include <iostream>
using std::ostream;
using std::istream;

class String2
{
private:
    char * str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;

public:
    String2(const char * s);
    String2();
    String2(const String2 &);
    ~String2();
    int length() const { return len; }

    String2 & operator=(const String2 &);
    String2 & operator=(const char *);
    char & operator[](int i);
    const char & operator[](int i) const;

    friend bool operator<(const String2 &st, const String2 &st2);
    friend bool operator>(const String2 &st, const String2 &st2);
    friend bool operator==(const String2 &st, const String2 &st2);
    friend ostream & operator<<(ostream & os, const String2 &st);
    friend istream & operator>>(istream & is, String2 &st);

    static int HowMany();

    String2 operator+(const String2 &) const;
    String2 operator+(const char *) const;
    friend String2 operator+(const char *, const String2 &);
    void Stringlow();
    void Stringup();
    int has(char);
};

#endif // !STRING2_H_


// string2.cpp
#include <cstring>
#include "string2.h"

using std::cin;
using std::cout;

int String2::num_strings = 0;

int String2::HowMany()
{
    return num_strings;
}

String2::String2(const char * s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
}

String2::String2()
{
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String2::String2(const String2 & st)
{
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
}

String2::~String2()
{
    --num_strings;
    delete[] str;
}

String2 & String2::operator=(const String2 & st)
{
    if (this == &st)
    {
        return *this;
    }
    delete[] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

String2 & String2::operator=(const char * s)
{
    delete[] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

char & String2::operator[](int i)
{
    return str[i];
}

const char & String2::operator[](int i) const
{
    return str[i];
}

bool operator<(const String2 & st, const String2 & st2)
{
    return(std::strcmp(st.str, st2.str) < 0);
}

bool operator>(const String2 & st, const String2 & st2)
{
    return(std::strcmp(st.str, st2.str) > 0);
}

bool operator==(const String2 & st, const String2 & st2)
{
    return(std::strcmp(st.str, st2.str) == 0);
}

ostream & operator<<(ostream & os, const String2 & st)
{
    os << st.str;
    return os;
}

istream & operator>>(istream & is, String2 & st)
{
    char temp[String2::CINLIM];
    is.get(temp, String2::CINLIM);
    if (is)
    {
        st = temp;
    }
    while (is && is.get() != '\n')
    {
        continue;
    }
    return is;
}

String2 String2::operator+(const String2 & st) const
{
    int total_len = len + st.len;
    char *temp = new char[total_len + 1];
    std::strcpy(temp, str);
    std::strcpy(temp + len, st.str);
    temp[total_len] = '\0';
    return String2(temp);
}

String2 String2::operator+(const char * s) const
{
    int total_len = len + strlen(s);
    char *temp = new char[total_len + 1];
    std::strcpy(temp, str);
    std::strcpy(temp + len, s);
    temp[total_len] = '\0';
    return String2(temp);
}

String2 operator+(const char * s, const String2 & st)
{
    return String2(s) + st;
}

void String2::Stringlow()
{
    for (int i = 0; i < len + 1; i++)
    {
        str[i] = tolower(str[i]);
    }
}

void String2::Stringup()
{
    for (int i = 0; i < len + 1; i++)
    {
        str[i] = toupper(str[i]);
    }
}

int String2::has(char c)
{
    int same = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == c)
        {
            same++;
        }
    }

    return same;
}
