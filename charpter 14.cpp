#include <iostream>
#include <array>
#include <string>
#include <ctime>
#include "Pairs.h"
#include "QueueTp.h"
#include "Worker.h"
#include "Person.h"
#include "emp.h"

// practice 1的时候include Wine.h
// 还要将Wine.cpp中的 #if 0 改成 #if 1
// 还要将Wine1.cpp中的 #if 1 改成 #if 0
//#include "Wine.h"

// practice 2的时候include Wine1.h
#include "Wine1.h"

using namespace std;

// practice 1 && practice 2
void p14_1(void)
{
    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab, 50);
    cout << "Enter number of years: ";
    int yrs;
    cin >> yrs;

    Wine holding(lab, yrs);
    holding.GetBottles();
    holding.Show();

    const int YRS = 3;
    int y[YRS] = { 1993, 1995, 1998 };
    int b[YRS] = { 48, 60, 72 };

    Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();

    cout << "Total bottles for " << more.Label()
        << ": " << more.sum() << endl;

    cout << "Bye\n";
    return;
}


// practice 3
void p14_3(void)
{
    QueueTp<Worker> * Qworker = new QueueTp<Worker>(20);

    // 放在大括号里面是想看看Queue里面的item是否受原数据生命周期的影响的
    // 看来是不会受到影响
    {
        Worker w1("jimmy", 0);
        Worker w2("jimmy2", 1);
        if (Qworker->isempty())
        {
            cout << "Qworker is empty!\n";
        }
        Qworker->enqueue(w1);
        Qworker->enqueue(w2);
        cout << "Qworker count: " << Qworker->queuecount() << endl;

        Worker w3("hello", 2);
        Qworker->enqueue(w3);
        Qworker->enqueue(w2);
        cout << "Qworker count: " << Qworker->queuecount() << endl;
    }

    Worker temp;
    Qworker->dequeue(temp);
    cout << "Dequeue: " << endl;
    temp.Show();

    Qworker->dequeue(temp);
    cout << "Dequeue: " << endl;
    temp.Show();

    cout << "Qworker count: " << Qworker->queuecount() << endl;
}


// practice 4
// 勉勉强强用吧，感觉写得我自己都有点晕了
void p14_4(void)
{
    const int SIZE = 5;
    srand(time(0));

    Person * person[SIZE];
    int ct = 0;
    for ( ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the choice:\n"
            << "g: Gunslinger  t: BadDude  "
            << "a: PokerPlayer  q: quit\n";
        cin >> choice;

        while (strchr("pgatq", choice) == NULL)
        {
            cout << "Please enter a p, g, a, t, q: ";
            cin >> choice;
        }
        while (cin.get() != '\n')
        {
            continue;
        }

        if (choice == 'q')
        {
            break;
        }

        string fname;
        string lname;
        int nicks = 0;

        cout << "Enter first name: " << endl;
        getline(cin, fname);
        cout << "Enter last name: " << endl;
        getline(cin, lname);

        switch (choice)
        {
        case 'g':
            cout << "Enter nicks: " << endl;
            cin >> nicks;
            person[ct] = new Gunslinger(fname, lname, nicks);
            break;

        case 'a':
            person[ct] = new PokerPlayer(fname, lname);
            break;

        case 't':
            cout << "Enter nicks: " << endl;
            cin >> nicks;
            person[ct] = new BadDude(fname, lname, nicks);
            break;

        default:
            break;
        }
    }

    cout << "\nHere is your input:\n";
    int i = 0;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        person[i]->Show();
    }

    for (i = 0; i < ct; i++)
    {
        delete person[i];
    }

    cout << "Bye!\n";
    return;
}


// practice 5
void p14_5(void)
{
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl;
    em.ShowAll();
    manager ma("Amorphias", "Spindragon", "Nuancer", 5);
    cout << ma << endl;
    ma.ShowAll();

    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    cout << fi << endl;
    fi.ShowAll();
    highfink hf(ma, "Curly Kew");
    hf.ShowAll();
    cout << "Press a key for next phase:\n";
    cin.get();
    highfink hf2;
    hf2.SetAll();

    cout << "Using an abstr_emp * pointer:\n";
    abstr_emp * tri[4] = { &em, &fi, &hf, &hf2 };
    for (int i = 0; i < 4; i++)
    {
        tri[i]->ShowAll();
    }

    return;
}



int main(int argc, char **argv)
{
    p14_5();

    while (cin.get());

    return 0;
}

// emp.h
#pragma once
#include <iostream>
#include <string>

class abstr_emp
{
public:
    abstr_emp();
    abstr_emp(const std::string & fn, const std::string & ln,
        const std::string & j);
    virtual void ShowAll() const;
    virtual void SetAll();
    friend std::ostream &
        operator<<(std::ostream & os, const abstr_emp & e);
    virtual ~abstr_emp() = 0;

private:
    std::string fname;
    std::string lname;
    std::string job;
};

class employee : public abstr_emp
{
public:
    employee();
    employee(const std::string & fn, const std::string & ln,
        const std::string & j);
    virtual void ShowAll() const;
    virtual void SetAll();
};

class manager: virtual public abstr_emp
{
private:
    int inchargeof;

protected:
    int InChargeOf() const { return inchargeof; }
    int & InChargeOf() { return inchargeof; }

public:
    manager();
    manager(const std::string & fn, const std::string & ln,
        const std::string & j, int ico = 0);
    manager(const abstr_emp & e, int ico);
    manager(const manager & m);
    virtual void ShowAll() const;
    virtual void SetAll();
};

class fink : virtual public abstr_emp
{
private:
    std::string reportsto;
protected:
    const std::string ReportsTo() const { return reportsto; }
    std::string & ReportsTo() { return reportsto; }
public:
    fink();
    fink(const std::string & fn, const std::string & ln,
        const std::string & j, const std::string & rpo);
    fink(const abstr_emp & e, const std::string & rep);
    fink(const fink & e);
    virtual void ShowAll() const;
    virtual void SetAll();
};

class highfink : public manager, public fink
{
public:
    highfink();
    highfink(const std::string & fn, const std::string & ln,
        const std::string & j, const std::string & rpo,
        int ico);
    highfink(const abstr_emp & e, const std::string & rpo, int ico);
    highfink(const fink & f, int ico);
    highfink(const manager & m, const std::string & rpo);
    highfink(const highfink & h);
    virtual void ShowAll() const;
    virtual void SetAll();
};


// emp.cpp
#include "emp.h"

using namespace std;

abstr_emp::abstr_emp() : fname("None"), lname("None"), job("None")
{

}

abstr_emp::abstr_emp(const string & fn, const string & ln,
    const string & j)
{
    lname = ln;
    fname = fn;
    job = j;
}

void abstr_emp::ShowAll() const
{
    cout << "abstr_emp: " << endl;
    cout << "First Name: " << fname << endl;
    cout << "Last Name: " << lname << endl;
    cout << "job: " << job << endl;
}

void abstr_emp::SetAll()
{
    cout << "Enter First name: ";
    getline(cin, fname);
    cout << "Enter Last name: ";
    getline(cin, lname);
    cout << "Enter job: ";
    getline(cin, job);
}

std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{
    cout << e.fname << ", " << e.lname ;
    return os;
}

abstr_emp::~abstr_emp()
{

}

employee::employee() : abstr_emp()
{

}

employee::employee(const string & fn, const string & ln,
    const string & j) : abstr_emp(fn, ln, j)
{

}

void employee::ShowAll() const
{
    cout << "employee: " << endl;
    abstr_emp::ShowAll();
}

void employee::SetAll()
{
    abstr_emp::SetAll();
}

manager::manager() : abstr_emp(), inchargeof(-1)
{

}

manager::manager(const string & fn, const string & ln,
    const string & j, int ico) : abstr_emp(fn, ln, j), inchargeof(ico)
{

}

manager::manager(const abstr_emp & e, int ico) :
    abstr_emp(e), inchargeof(ico)
{

}

manager::manager(const manager & m) : abstr_emp(m)
{
    inchargeof = m.inchargeof;
}

void manager::ShowAll() const
{
    cout << "manager: " << endl;
    abstr_emp::ShowAll();
    cout << "inchargeof: " << inchargeof << endl;
}

void manager::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter inchargeof: ";
    cin >> inchargeof;
    while (cin.get() != '\n')
    {
        continue;
    }
}

fink::fink() : abstr_emp(), reportsto("None")
{

}

fink::fink(const string & fn, const string & ln,
    const string & j, const string & rpo) : abstr_emp(fn, ln, j), reportsto(rpo)
{

}

fink::fink(const abstr_emp & e, const string & rpo) : abstr_emp(e), reportsto(rpo)
{

}

fink::fink(const fink & e) : abstr_emp(e)
{
    reportsto = e.reportsto;
}

void fink::ShowAll() const
{
    cout << "fink: " << endl;
    abstr_emp::ShowAll();
    cout << "reportsTo: " << reportsto << endl;
}

void fink::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter reportsTo: ";
    getline(cin, reportsto);
}

highfink::highfink() : abstr_emp(), manager(), fink()
{

}

highfink::highfink(const string & fn, const string & ln,
    const string & j, const string & rpo, int ico) :
    abstr_emp(fn, ln, j), manager(fn, ln, j, ico),
    fink(fn, ln, j, rpo)
{

}

highfink::highfink(const abstr_emp & e, const string & rpo, int ico) :
    abstr_emp(e), manager(e, ico), fink(e, rpo)
{

}

highfink::highfink(const fink & f, int ico) :
    abstr_emp(f), manager(f, ico), fink(f)
{

}

highfink::highfink(const manager & m, const string & rpo) :
    abstr_emp(m), manager(m), fink(m, rpo)
{

}

highfink::highfink(const highfink & h) :
    abstr_emp(h), manager(h), fink(h)
{

}

void highfink::ShowAll() const
{
    cout << "highfink: " << endl;
    abstr_emp::ShowAll();
    cout << "inchargeof: " << manager::InChargeOf() << endl;
    cout << "reportsTo: " << fink::ReportsTo() << endl;
}

void highfink::SetAll()
{
    manager::SetAll();
    cout << "Enter reportsTo: ";
    getline(cin, fink::ReportsTo());
}


// Pairs.h
#pragma once
#include <iostream>
#include <string>

template<class T1, class T2>
class Pair {
private:
    T1 a;
    T2 b;

public:
    T1 & first();
    T2 & second();
    T1 first() const { return a; }
    T2 second() const { return b; }
    Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) {}
    Pair() {}
};

template<class T1, class T2>
T1 & Pair<T1, T2>::first()
{
    return a;
}

template<class T1, class T2>
T2 & Pair<T1, T2>::second()
{
    return b;
}


// Person.h
#pragma once
#include <string>

class Person
{
private:
    std::string firstName;
    std::string lastName;

public:
    Person() : firstName("None"), lastName("None") {}
    Person(const std::string fname, const std::string lname) :
        firstName(fname), lastName(lname) {}
    Person(const Person & p);
    virtual ~Person() = 0;
    virtual void Show() const = 0;
};

class Gunslinger : public virtual Person
{
private:
    int nicks;

public:
    Gunslinger(int d = 0) : Person(), nicks(d) {}
    Gunslinger(const std::string fname, const std::string lname, int d) :
        Person(fname, lname), nicks(d) {}
    Gunslinger(const Person & p, int d) : Person(p), nicks(d) {}
    Gunslinger(const Gunslinger & g);
    ~Gunslinger();
    void Show() const;
    double Draw() const;
};

class PokerPlayer : public virtual Person
{
public:
    int Draw() const;
    void Show() const;
    PokerPlayer() : Person() {}
    PokerPlayer(const Person & p) : Person(p) {}
    PokerPlayer(const std::string fname, const std::string lname) :
        Person(fname, lname) {}
    PokerPlayer(const PokerPlayer & p) : Person(p) {}
    ~PokerPlayer();
};

class BadDude : public Gunslinger, public PokerPlayer
{
public:
    BadDude() {}
    BadDude(const std::string fname, const std::string lname, int d) :
        Person(fname, lname), Gunslinger(fname, lname, d), PokerPlayer(fname, lname) {}
    BadDude(const Person & p, int d) :
        Person(p), Gunslinger(p, d), PokerPlayer(p) {}
    BadDude(const Gunslinger & g) :
        Person(g), Gunslinger(g), PokerPlayer(g) {}
    BadDude(const PokerPlayer & p, int d) :
        Person(p), Gunslinger(p, d), PokerPlayer(p) {}
    ~BadDude();

    void Show() const;
    double Gdraw();
    int Cdraw();
};


// Person.cpp
#include "Person.h"
#include <iostream>
#include <ctime>
#include <cmath>

using std::cout;
using std::endl;

Person::Person(const Person & p)
{
    firstName = p.firstName;
    lastName = p.lastName;
}

Person::~Person()
{
}

void Person::Show() const
{
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
}

Gunslinger::Gunslinger(const Gunslinger & g) : Person(g)
{
    nicks = g.nicks;
}

double Gunslinger::Draw() const
{
    return (double)(rand() % 10) / 10;
}

void Gunslinger::Show() const
{
    Person::Show();
    cout << "Nicks: " << nicks << endl;
    cout << "Pull the gun time: " << Draw() << endl;
}

Gunslinger::~Gunslinger()
{

}

int PokerPlayer::Draw() const
{
    return (rand() % 52);
}

void PokerPlayer::Show() const
{
    Person::Show();
}

PokerPlayer::~PokerPlayer()
{

}


void BadDude::Show() const
{
    Gunslinger::Show();
    cout << "Next Card: " << PokerPlayer::Draw() << endl;
}

double BadDude::Gdraw()
{
    return Gunslinger::Draw();
}

int BadDude::Cdraw()
{
    return PokerPlayer::Draw();
}

BadDude::~BadDude()
{

}


// QueueTp.h
#pragma once

// 这个模板类的内容是按照程序清单12.10来写的
// 还要注意模板类定义和实现都要放在头文件中，不然编译会报错
template <class T>
class QueueTp
{
private:
    struct Node { T item; struct Node * next; };
    enum { Q_SIZE = 10 };
    Node * front;
    Node * rear;
    int items;
    const int qsize;
    QueueTp(const QueueTp & q) : qsize(0) {}
    QueueTp & operator=(const QueueTp & q) { return *this; }

public:
    QueueTp(int qs = Q_SIZE);
    ~QueueTp();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const T & item);
    bool dequeue(T & item);
};

template <class T>
QueueTp<T>::QueueTp(int qs) : qsize(qs)
{
    front = rear = NULL;
    items = 0;
}

template <class T>
QueueTp<T>::~QueueTp()
{
    Node * temp;
    while (front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}

template <class T>
bool QueueTp<T>::isempty() const
{
    return items == 0;
}

template <class T>
bool QueueTp<T>::isfull() const
{
    return items == qsize;
}

template <class T>
int QueueTp<T>::queuecount() const
{
    return items;
}

template <class T>
bool QueueTp<T>::enqueue(const T & item)
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

template <class T>
bool QueueTp<T>::dequeue(T & item)
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


// Wine.h
#pragma once
#include <iostream>
#include <array>
#include <string>
#include <valarray>
#include "Pairs.h"

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine
{
private:
    int year;
    std::string label;
    PairArray pArray;

public:
    Wine(const char * l, int y, const int yr[], const int bot[]);
    Wine(const char * l, int y);
    ~Wine();
    void GetBottles();
    void Show();
    std::string & Label();
    int sum();
};

// Wine.cpp
#include "Wine.h"

#if 0

Wine::Wine(const char * l, int y, const int yr[], const int bot[])
{
    pArray = PairArray(ArrayInt(y), ArrayInt(y));
    label = l;
    year = y;
    for (int  i = 0; i < y; i++)
    {
        pArray.first()[i] = yr[i];
        pArray.second()[i] = bot[i];
    }
}

Wine::Wine(const char * l, int y)
{
    pArray = PairArray(ArrayInt(y), ArrayInt(y));
    label = l;
    year = y;
    for (int i = 0; i < y; i++)
    {
        pArray.first()[i] = 0;
        pArray.second()[i] = 0;
    }
}


Wine::~Wine()
{
}

void Wine::GetBottles()
{
    std::cout << "Enter " << label << " data for " << year << " year(s):" << std::endl;
    for (int i = 0; i < year; i++)
    {
        std::cout << "Enter year: ";
        std::cin >> pArray.first()[i];
        std::cout << "Enter bootles for that year: ";
        std::cin >> pArray.second()[i];
    }
}

void Wine::Show()
{
    std::cout << "Wine: " << label << std::endl;
    std::cout << "  Year    Bottles" << std::endl;
    for (int i = 0; i < year; i++)
    {
        std::cout << "  " << pArray.first()[i] << " " << pArray.second()[i] << std::endl;
    }
}

std::string & Wine::Label()
{
    return label;
}

int Wine::sum()
{
    int sum = 0;
    for (int i = 0; i < year; i++)
    {
        sum += pArray.second()[i];
    }

    return sum;
}

#endif


// Wine1.h
#pragma once
#include <iostream>
#include <string>
#include <valarray>
#include "Pairs.h"

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine : public PairArray, public std::string
{
private:
    int year;

public:
    Wine(const char * l, int y, const int yr[], const int bot[]);
    Wine(const char * l, int y);
    ~Wine();
    void GetBottles();
    void Show();
    std::string & Label();
    int sum();
};


// Wine1.cpp
#include "Wine1.h"

#if 1

Wine::Wine(const char * l, int y, const int yr[], const int bot[]) :
    std::string(l), PairArray(ArrayInt(y), ArrayInt(y))
{
    year = y;
    for (int i = 0; i < year; i++)
    {
        PairArray::first()[i] = yr[i];
        PairArray::second()[i] = bot[i];
    }
}

Wine::Wine(const char * l, int y) :
    std::string(l), PairArray(ArrayInt(y), ArrayInt(y))
{
    year = y;
    for (int i = 0; i < year; i++)
    {
        PairArray::first()[i] = 0;
        PairArray::second()[i] = 0;
    }
}

Wine::~Wine()
{

}

void Wine::GetBottles()
{
    std::cout << "Enter " << (const std::string)*this << " data for " << year
        << " year(s): " << std::endl;
    for (int i = 0; i < year; i++)
    {
        std::cout << "Enter year: ";
        std::cin >> PairArray::first()[i];
        std::cout << "Enter bootles for that year: ";
        std::cin >> PairArray::second()[i];
    }
}

void Wine::Show()
{
    std::cout << "Wine: " << (const std::string)*this << std::endl;
    std::cout << "  Year    Bootles" << std::endl;
    for (int i = 0; i < year; i++)
    {
        std::cout << "  " << PairArray::first()[i] << " "
            << PairArray::second()[i] << std::endl;
    }
}

std::string & Wine::Label()
{
    return (std::string &)*this;
}

int Wine::sum()
{
    int sum = 0;
    for (int i = 0; i < year; i++)
    {
        sum += PairArray::second()[i];
    }

    return sum;
}

#endif


// Worker.h
#pragma once
#include <string>


class Worker
{
private:
    std::string fullname;
    long id;

public:
    Worker() : fullname("no one"), id(0L) {}
    Worker(const std::string & s, long n)
        : fullname(s), id(n) {}
    virtual ~Worker();
    virtual void Set();
    virtual void Show() const;
};

// Worker.cpp
#include "Worker.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;


void Worker::Set()
{
    cout << "Enter worker's name: ";
    std::getline(cin, fullname);
    cout << "Enter worker's ID: ";
    cin >> id;
    while (cin.get() != '\n')
    {
        continue;
    }
}

void Worker::Show() const
{
    cout << "Name: " << fullname << "\n";
    cout << "Employee ID: " << id << "\n";
}


Worker::~Worker()
{
}
