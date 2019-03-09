#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "vector.h"
#include "mytime1.h"
#include "Stonewt1.h"
#include "Stonewt2.h"
#include "complex0.h"

using namespace std;


// practice 1
// 第六版的校对做得真的有点差，随机漫步应该是程序清单11.15才对
// 对应的vector.h和vector.cpp可以用书本中原有的，也可以用practice 2中修改过的
void p11_1(void)
{
    using VECTOR::Vector;
    string filename = "randwalk.txt";
    ofstream outFile;
    outFile.open(filename.c_str(), ios_base::out);
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;

        outFile << "Target Distance: " << target << ", " << "Step Size: " << dstep << endl;
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
            step.rect_mode();
            outFile << result << endl;
        }
        outFile << "After " << steps << " steps, the subject "
            "has the following locations:\n";
        outFile << result << endl;
        result.polar_mode();
        outFile << " or\n" << result << endl;
        outFile << "Average outward distance per step = "
            << result.magval() / steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;

    return ;
}


// practice 2
void p11_2(void)
{
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;

        cout << "Target Distance: " << target << ", " << "Step Size: " << dstep << endl;
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
            step.rect_mode();
            cout << result << endl;
        }
        cout << "After " << steps << " steps, the subject "
            "has the following locations:\n";
        cout << result << endl;
        result.polar_mode();
        cout << " or\n" << result << endl;
        cout << "Average outward distance per step = "
            << result.magval() / steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;

    return;
}


// practice 3
void p11_3(void)
{
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    unsigned long max_steps = 0;
    unsigned long min_steps = 0 - 1;
    unsigned long total_steps = 0;
    double average_steps = 0.0;
    int test_times = 0;
    cout << "Enter target distance (q to quit): ";
    cin >> target;
    cout << "Enter step length: ";
    cin >> dstep;
    cout << "Enter test times: ";
    cin >> test_times;
    cin.get();
    for (int i = 0; i < test_times; i++)
    {
        cout << "Target Distance: " << target << ", " << "Step Size: " << dstep << endl;
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
            step.rect_mode();
            cout << result << endl;
        }
        cout << "After " << steps << " steps, the subject "
            "has the following locations:\n";
        cout << result << endl;
        result.polar_mode();
        cout << " or\n" << result << endl;
        cout << "Average outward distance per step = "
            << result.magval() / steps << endl;

        total_steps += steps;
        if (steps > max_steps)
        {
            max_steps = steps;
        }
        else if (steps < min_steps)
        {
            min_steps = steps;
        }
        steps = 0;
        result.reset(0.0, 0.0);
        cout << endl;
    }

    average_steps = (double)total_steps / test_times;
    cout << endl;
    cout << "Test " << test_times << " times, max steps is " << max_steps << ", min steps is " << min_steps << ", average steps is " << average_steps << endl;

    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;

    return;
}


// practice 4
void p11_4(void)
{
    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;

    cout << "Aida and Tosca:\n";
    cout << aida << "; " << tosca << endl;
    temp = aida + tosca;
    cout << "Aida + Tosca: " << temp << endl;

    temp = aida * 1.17;
    cout << "Aida * 1.17: " << temp << endl;

    cout << "10 * Tosca: " << 10 * tosca << endl;

    return;
}


// practice 5
void p11_5(void)
{
    Stonewt1 st1(120);
    Stonewt1 st2(12.3, Stonewt1::IPOUND);
    Stonewt1 st3(123.3, Stonewt1::DPOUND);

    Stonewt1 st4 = 13 + st1;
    Stonewt1 st5 = 13 * st2;
    Stonewt1 st6 = 13 - st2;

    Stonewt1 st7 = st1 + 10;
    Stonewt1 st8 = st1 - 10;
    Stonewt1 st9 = st1 * 10;

    cout << st1 << endl;
    cout << st2 << endl;
    cout << st3 << endl;
    cout << st4 << endl;
    cout << st5 << endl;
    cout << st6 << endl;
    cout << st7 << endl;
    cout << st8 << endl;
    cout << st9 << endl;
}


// practice 6
void p11_6(void)
{
    Stonewt2 st[6] = {
        Stonewt2(10.0, 0),
        Stonewt2(11.1, 0),
        Stonewt2(22.2, 0)
    };
    Stonewt2 max = st[0];
    Stonewt2 min = st[0];
    Stonewt2 ele(11, 0);
    int num = 0;

    for (int i = 0; i < 3; i++)
    {
        double pounds = 0;
        cout << "Enter the pounds: ";
        cin >> pounds;
        Stonewt2 tmp(pounds);
        st[3 + i] = tmp;
    }

    for (int i = 0; i < 6; i++)
    {
        if (max < st[i])
        {
            max = st[i];
        }
        else if (min > st[i])
        {
            min = st[i];
        }

        if (st[i] >= ele)
        {
            num++;
        }
    }

    cout << "Max element: ";
    max.show_stn();

    cout << "Min element: ";
    min.show_stn();

    cout << "There are " << num << " element large than 11 stones." << endl;

    return;
}


// practice 7
char *mystrncpy(char *s1, char *s2, int n)
{
    int s1_length = strlen(s1);
    int s2_length = strlen(s2);
    int copy_length = (s2_length >= n ? n : s2_length);

    for (size_t i = 0; i < copy_length; i++)
    {
        *++s1 = *++s2;
    }

    s1[copy_length - 1] = '\0';

    return s1;
}
void p11_7(void)
{
    char string1[256];
    char string2[256];
    int string1_length = 0;
    int string2_length = 0;

    while (1) // 一直循环输入吧，也可以添加一个退出条件
    {
        printf("Enter the first string:");
        fgets(string1, 256, stdin);

        printf("Enter the second string:");
        fgets(string2, 256, stdin);

        string1_length = strlen(string1);
        string2_length = strlen(string2);

        printf("The first original string: ");
        printf("%s", string1);
        mystrncpy(string1, string2, 256);
        printf("After mystrncpy, ths first string: ");
        printf("%s", string2);

        printf("\n");
    }

    return;
}


int main(int argc, char ** argv)
{
    p11_7();

    while (cin.get());
}

// complex0.h
#pragma once
#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include <iostream>

class complex
{
public:
    complex();
    complex(double real, double imaginary);
    complex operator+(const complex & cx) const;
    complex operator-(const complex & cx) const;
    complex operator*(const complex & cx) const;

    friend complex operator~(const complex & cx);
    friend complex operator*(int x, const complex & cx);
    friend std::istream & operator>>(std::istream & is, complex & cx);
    friend std::ostream & operator<<(std::ostream & os, const complex & cx);

private:
    double real;
    double imaginary;

};

#endif // !COMPLEX0_H_

// complex0.cpp
#include <iostream>
using namespace std;

#include "complex0.h"

complex::complex()
{
    real = imaginary = 0;
}

complex::complex(double real, double imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}

complex complex::operator+(const complex & cx) const
{
    return complex(real + cx.real, imaginary + cx.imaginary);
}

complex complex::operator-(const complex & cx) const
{
    return complex(real - cx.real, imaginary - cx.imaginary);
}

complex complex::operator*(const complex & cx) const
{
    return complex(real * cx.real - imaginary * cx.imaginary,
        real * cx.imaginary + imaginary * cx.real);
}

complex operator~(const complex & cx)
{
    return complex(cx.real, -cx.imaginary);
}

complex operator*(int x, const complex & cx)
{
    return complex(x*cx.real, x*cx.imaginary);
}

std::istream & operator>>(std::istream & is, complex & cx)
{
    cout << "real: ";
    is >> cx.real;
    if (!is)
    {
        return is;
    }
    cout << "imaginary: ";
    is >> cx.imaginary;
    cin.get();

    return is;
}

std::ostream & operator<<(std::ostream & os, const complex & cx)
{
    os << "(" << cx.real << ", " << cx.imaginary << "i)";

    return os;
}


// mytime1.h
#pragma once
#ifndef MYTIME1_H_
#define MYTIME1_H_

#include <iostream>

class Time
{
private:
    int hours;
    int minutes;

public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    friend Time operator+(const Time & t1, const Time & t2);
    friend Time operator-(const Time & t1, const Time & t2);
    friend Time operator*(double n, const Time & t);
    friend Time operator*(const Time & t, double n);
    friend std::ostream & operator<<(std::ostream & os, const Time & t);

};


#endif // MYTIME1_H_


// mytime1.cpp
#include "mytime1.h"

using namespace std;

Time::Time()
{

}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::AddMin(int m)
{
    minutes += m;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time operator+(const Time & t1, const Time & t2)
{
    Time sum;
    sum.minutes = t1.minutes + t2.minutes;
    sum.hours = t1.hours + t2.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time operator-(const Time & t1, const Time & t2)
{
    Time diff;
    int tot1, tot2;
    tot1 = t1.minutes + 60 * t1.hours;
    tot2 = t2.minutes + 60 * t2.hours;
    diff.minutes = (tot1 - tot2) % 60;
    diff.hours = (tot1 - tot2) / 60;
    return diff;
}

Time operator*(double n, const Time & t)
{
    Time result;
    long totalminutes = t.hours * n * 60 + t.minutes * n;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

Time operator*(const Time & t, double n)
{
    Time result;
    long totalminutes = t.hours * n * 60 + t.minutes * n;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

std::ostream & operator<<(std::ostream & os, const Time & t)
{
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}


// Stonewt1.h
#pragma once
#ifndef STONEWT1_H_
#define STONEWT1_H_

#include <iostream>

class Stonewt1
{
public:
    enum format { STONES, IPOUND, DPOUND };

private:
    enum {Lbs_per_stn = 14};
    format ft;
    double stone;
    int ipounds;
    double dpounds;

    // 有三种格式的数据，成员函数先对total进行操作
    // 然后调用update更新所有的成员变量
    // 免得每个成员函数里面都用if...else if的判断来更新
    double total;
    void update();

public:
    Stonewt1();
    Stonewt1(double n, format f = STONES);
    Stonewt1 operator+(double n) const;
    Stonewt1 operator-(double n) const;
    Stonewt1 operator*(double n) const;

    friend Stonewt1 operator+(double n, const Stonewt1 & st);
    friend Stonewt1 operator-(double n, const Stonewt1 & st);
    friend Stonewt1 operator*(double n, const Stonewt1 & st);
    friend std::ostream & operator<<(std::ostream & os, const Stonewt1 & st);
};

#endif // !STONEWT1_H_


// Stonewt1.cpp
#include "Stonewt1.h"
using namespace std;

void Stonewt1::update()
{
    if (ft == STONES)
    {
        stone = total;
        ipounds = (int)stone * Lbs_per_stn;
        dpounds = stone * Lbs_per_stn;
    }
    else if (ft == IPOUND)
    {
        ipounds = total;
        stone = ipounds / Lbs_per_stn;
        dpounds = ipounds;
    }
    else if (ft == DPOUND)
    {
        dpounds = total;
        stone = dpounds / Lbs_per_stn;
        ipounds = (int)dpounds;
    }
}

Stonewt1::Stonewt1()
{
    total = 0;
    ft = STONES;
    update();
}

Stonewt1::Stonewt1(double n, format f)
{
    total = n;
    ft = f;
    update();
}

Stonewt1 Stonewt1::operator+(double n) const
{
    Stonewt1 st(total + n, ft);
    return st;
}

Stonewt1 Stonewt1::operator-(double n) const
{
    Stonewt1 st(total - n, ft);
    return st;
}

Stonewt1 Stonewt1::operator*(double n) const
{
    Stonewt1 st(total * n, ft);
    return st;
}

Stonewt1 operator+(double n, const Stonewt1 & st)
{
    return (st + n);
}

Stonewt1 operator-(double n, const Stonewt1 & st)
{
    return st - n;
}

Stonewt1 operator*(double n, const Stonewt1 & st)
{
    return st * n;
}

std::ostream & operator<<(std::ostream & os, const Stonewt1 & st)
{
    if (st.ft == st.STONES)
    {
        cout << "Stone: " << st.stone ;
    }
    else if (st.ft == st.IPOUND)
    {
        cout << "pounds in int: " << st.ipounds ;
    }
    else if (st.ft == st.DPOUND)
    {
        cout << "pounds in double: " << st.dpounds;
    }

    return os;
}


// Stonewt2.h
#pragma once
#ifndef MYTIME2_H_
#define MYTIME2_H_

class Stonewt2
{
private:
    enum { Lbs_per_stn = 14 };
    int stone;
    double pds_left;
    double pounds;

public:
    Stonewt2(double lbs);
    Stonewt2(int stn, double lbs);
    Stonewt2();
    ~Stonewt2();
    void show_lbs() const;
    void show_stn() const;

    bool operator==(const Stonewt2 & st) const;
    bool operator!=(const Stonewt2 & st) const;
    bool operator<(const Stonewt2 & st) const;
    bool operator>(const Stonewt2 & st) const;
    bool operator<=(const Stonewt2 & st) const;
    bool operator>=(const Stonewt2 & st) const;
};

#endif // !MYTIME2_H_


// Stone2.cpp
#include "Stonewt2.h"
#include <iostream>

using namespace std;

Stonewt2::Stonewt2(double lbs)
{
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - (int)lbs;
    pounds = lbs;
}

Stonewt2::Stonewt2(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt2::Stonewt2()
{
    stone = pds_left = pounds = 0;
}

Stonewt2::~Stonewt2()
{

}

void Stonewt2::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}

void Stonewt2::show_lbs() const
{
    cout << pounds << " pounds\n";
}

bool Stonewt2::operator<(const Stonewt2 & st) const
{
    return pounds < st.pounds;
}

bool Stonewt2::operator>(const Stonewt2 & st) const
{
    return pounds > st.pounds;
}

bool Stonewt2::operator<=(const Stonewt2 & st) const
{
    return pounds <= st.pounds;
}

bool Stonewt2::operator>=(const Stonewt2 & st) const
{
    return pounds >= st.pounds;
}

bool Stonewt2::operator==(const Stonewt2 & st) const
{
    return pounds == st.pounds;
}

bool Stonewt2::operator!=(const Stonewt2 & st) const
{
    return pounds != st.pounds;
}


// vector.h
#ifndef VECTOR_H_
#define VECTOR_H_
#pragma once

#include <iostream>

namespace VECTOR
{
    class Vector
    {
    public:
        enum Mode {RECT, POL};

    private:
        double x;
        double y;
        Mode mode;
        void set_x(double, double);
        void set_y(double, double);

    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        double xval() const { return x; }
        double yval() const { return y; }
        double magval() const;
        double angval() const;
        void polar_mode();
        void rect_mode();

        Vector operator+(const Vector & b) const;
        Vector operator-(const Vector & b) const;
        Vector operator-() const;
        Vector operator*(double n) const;

        friend Vector operator*(double n, const Vector & a);
        friend std::ostream & operator<<(std::ostream & os, const Vector & v);
    };
}

#endif // !VECTOR_H_


// vector.cpp
#include <cmath>
#include "vector.h"

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
    const double Rad_to_deg = 45.0 / atan(1.0);

    void Vector::set_x(double mag, double ang)
    {
        x = mag * cos(ang);
    }

    void Vector::set_y(double mag, double ang)
    {
        y = mag * sin(ang);
    }

    Vector::Vector()
    {
        x = y = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
        }
        else if (form == POL)
        {
            set_x(n1, n2);
            set_y(n1, n2);
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = 0.0;
            mode = RECT;
        }
    }

    void Vector::reset(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
        }
        else if (form == POL)
        {
            set_x(n1, n2);
            set_y(n1, n2);
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = 0.0;
            mode = RECT;
        }
    }

    Vector::~Vector()
    {

    }

    void Vector::polar_mode()
    {
        mode = POL;
    }

    void Vector::rect_mode()
    {
        mode = RECT;
    }

    double Vector::magval() const
    {
        return sqrt(x * x + y * y);
    }

    double Vector::angval() const
    {
        if(x == 0.0 && y == 0.0)
        {
            return 0.0;
        }
        else
            return atan2(y, x);
    }

    Vector Vector::operator+(const Vector & b) const
    {
        return Vector(x + b.x, y + b.y);
    }

    Vector Vector::operator-(const Vector & b) const
    {
        return Vector(x - b.x, y - b.y);
    }

    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }

    Vector Vector::operator*(double n) const
    {
        return Vector(n*x, n*y);
    }

    Vector operator*(double n, const Vector & a)
    {
        return a * n;
    }

    std::ostream & operator<<(std::ostream & os, const Vector & v)
    {
        if (v.mode == Vector::RECT)
        {
            os << "(x,y) = (" << v.x << ", " << v.y << ")";
        }
        else if (v.mode == Vector::POL)
        {
            os << "(m,a) = (" << v.magval() << ", " << v.angval() * Rad_to_deg << ")";
        }
        else
            os << "Vector object mode is invalid";

        return os;
    }
}
