#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

#include "Cd.h"
#include "Cd1.h"
#include "dma.h"
#include "Port.h"


// practice 1
void Bravo(const Cd & disk);
void p13_1(void)
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
        "Alfred Brendel", "Philips", 2, 57.17);
    Cd *pcd = &c1;

    cout << "Using object directly:\n";
    c1.Report();
    c2.Report();

    cout << "Using type cd * pointer to objects:\n";
    pcd->Report();
    pcd = &c2;
    pcd->Report();

    cout << "Calling a function whit a cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);

    cout << "Testing assignment: ";
    Classic copy;
    copy = c2;
    copy.Report();

    return;
}
void Bravo(const Cd & disk)
{
    disk.Report();
}


// practice 2
void Bravo(const Cd1 & disk)
{
    disk.Report();
}
void p13_2(void)
{
    Cd1 c1("Beatles", "Capitol", 14, 35.5);
    Classic1 c2 = Classic1("Piano Sonata in B flat, Fantasia in C",
        "Alfred Brendel", "Philips", 2, 57.17);
    Cd1 *pcd = &c1;

    cout << "Using object directly:\n";
    c1.Report();
    c2.Report();

    cout << "Using type cd * pointer to objects:\n";
    pcd->Report();
    pcd = &c2;
    pcd->Report();

    cout << "Calling a function whit a cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);

    cout << "Testing assignment: ";
    Classic1 copy;
    copy = c2;
    copy.Report();

    return;
}


// practice 3
const int CLIMENTS = 5;
void p13_3(void)
{
    baseDMA * dma[CLIMENTS];
    string label;
    int rating;
    char choice;
    string color;
    string style;

    for (int i = 0; i < CLIMENTS; i++)
    {
        cout << "Enter lable: ";
        getline(cin, label);
        cout << "Enter rating: ";
        cin >> rating;
        cout << "Enter 1 for baseDMA or 2"
            " for lacksDMA or 3 for hasDMA: ";
        while (cin >> choice && (choice != '1' && choice != '2' && choice != '3'))
        {
            cout << "Enter 1 or 2 or 3: ";
        }
        while (cin.get() != '\n');
        if (choice == '1')
        {
            dma[i] = new baseDMA(label.c_str(), rating);
        }
        else if (choice == '2')
        {
            cout << "Enter color: ";
            getline(cin, color);
            dma[i] = new lacksDMA(color.c_str(), label.c_str(), rating);
        }
        else
        {
            cout << "Enter style: ";
            getline(cin, style);
            dma[i] = new hasDMA(style.c_str(), label.c_str(), rating);
        }

    }
    cout << endl;
    for (int i = 0; i < CLIMENTS; i++)
    {
        dma[i]->View();
        cout << endl;
    }

    for (int i = 0; i < CLIMENTS; i++)
    {
        delete dma[i];
    }

    cout << "Done.\n";
    return;

}


// practice 4
void p13_4(void)
{
    Port port1("Gallo", "tawny", 20);
    VintagePort vp("None", 20, "The Noble", 1997);

    port1.Show();
    vp.Show();

    VintagePort vp2 = vp;
    Port port2 = port1;

    cout << vp2 << endl;
    cout << port2 << endl;
}


int main(int argc, char ** argv)
{
    p13_4();

    while (cin.get());
}


// Cd.h
#pragma once
#ifndef CD_H_
#define CD_H_

#include <iostream>

class Cd
{
private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;

public:
    Cd(char * s1, char * s2, int n, double x);
    Cd(const Cd & d);
    Cd();
    virtual ~Cd();
    virtual void Report() const;
    virtual Cd & operator=(const Cd & d);
};

class Classic : public Cd
{
private:
    char mainfile[20];

public:
    Classic(char * s1, char * s2, char * s3, int n, double x);
    Classic(const Cd & d, char * s3);
    Classic(const Classic & d);
    Classic();
    virtual ~Classic();
    virtual void Report() const;
    virtual Classic & operator=(const Classic & d);
};

#endif // !CD_H_

// Cd.cpp
#include "Cd.h"

#include <cstring>

Cd::Cd(char * s1, char * s2, int n, double x)
{
    std::strcpy(performers, s1);
    std::strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d)
{
    std::strcpy(performers, d.performers);
    std::strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd()
{
    std::strcpy(performers, "null");
    std::strcpy(label, "null");
    selections = 0;
    playtime = 0;
}


Cd::~Cd()
{
}

void Cd::Report() const
{
    std::cout << "Performers: " << performers << std::endl;
    std::cout << "Label: " << label << std::endl;
    std::cout << "Selections: " << selections << std::endl;
    std::cout << "Playtime: " << playtime << std::endl;
}

Cd & Cd::operator=(const Cd & d)
{
    std::strcpy(performers, d.performers);
    std::strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;

    return *this;
}



// Classic
Classic::Classic(char * s1, char * s2, char * s3, int n, double x) :
    Cd(s1, s2, n, x)
{
    std::strcpy(mainfile, s3);
}

Classic::Classic(const Cd & d, char * s3) : Cd(d)
{
    std::strcpy(mainfile, s3);
}

Classic::Classic(const Classic & d) : Cd(d)
{
    std::strcpy(mainfile, d.mainfile);
}

Classic::Classic() : Cd()
{
    std::strcpy(mainfile, "null");
}

Classic::~Classic()
{

}

void Classic::Report() const
{
    Cd::Report();
    std::cout << "Mainfile: " << mainfile << std::endl;
}

Classic & Classic::operator=(const Classic & d)
{
    Cd::operator=(d);
    std::strcpy(mainfile, d.mainfile);
    return *this;
}


// Cd1.h
#pragma once
#ifndef CD1_H_
#define CD1_H_

#include <iostream>

class Cd1
{
private:
    char * performers;
    char * label;
    int selections;
    double playtime;

public:
    Cd1(char * s1, char * s2, int n, double x);
    Cd1(const Cd1 & d);
    Cd1();
    virtual ~Cd1();
    virtual void Report() const;
    virtual Cd1 & operator=(const Cd1 & d);
};

class Classic1 : public Cd1
{
private:
    char * mainfile;

public:
    Classic1(char * s1, char * s2, char * s3, int n, double x);
    Classic1(const Cd1 & d, char * s3);
    Classic1(const Classic1 & d);
    Classic1();
    virtual ~Classic1();
    virtual void Report() const;
    virtual Classic1 & operator=(const Classic1 & d);
};

#endif // !CD1_H_

// Cd1.cpp
#include "Cd1.h"

#include <cstring>

Cd1::Cd1(char * s1, char * s2, int n, double x)
{
    int performers_length = std::strlen(s1);
    performers = new char[performers_length + 1];

    int label_length = std::strlen(s2);
    label = new char[label_length + 1];

    std::strcpy(performers, s1);
    std::strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd1::Cd1(const Cd1 & d)
{
    int performers_length = std::strlen(d.performers);
    performers = new char[performers_length + 1];

    int label_length = std::strlen(d.label);
    label = new char[label_length + 1];

    std::strcpy(performers, d.performers);
    std::strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd1::Cd1()
{
    int null_length = std::strlen("null");
    performers = new char[null_length + 1];
    label = new char[null_length + 1];

    std::strcpy(performers, "null");
    std::strcpy(label, "null");
    selections = 0;
    playtime = 0;
}


Cd1::~Cd1()
{
    delete[] performers;
    delete[] label;
    performers = nullptr;
    label = nullptr;
}

void Cd1::Report() const
{
    std::cout << "Performers: " << performers << std::endl;
    std::cout << "Label: " << label << std::endl;
    std::cout << "Selections: " << selections << std::endl;
    std::cout << "Playtime: " << playtime << std::endl;
}

Cd1 & Cd1::operator=(const Cd1 & d)
{
    delete[] performers;
    delete[] label;
    performers = nullptr;
    label = nullptr;

    int performers_length = std::strlen(d.performers);
    performers = new char[performers_length + 1];

    int label_length = std::strlen(d.label);
    label = new char[label_length + 1];

    std::strcpy(performers, d.performers);
    std::strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;

    return *this;
}



// Classic1
Classic1::Classic1(char * s1, char * s2, char * s3, int n, double x) :
    Cd1(s1, s2, n, x)
{
    int mainfile_length = std::strlen(s3);
    mainfile = new char[mainfile_length + 1];

    std::strcpy(mainfile, s3);
}

Classic1::Classic1(const Cd1 & d, char * s3) : Cd1(d)
{
    int mainfile_length = std::strlen(s3);
    mainfile = new char[mainfile_length + 1];

    std::strcpy(mainfile, s3);
}

Classic1::Classic1(const Classic1 & d) : Cd1(d)
{
    int mainfile_length = std::strlen(d.mainfile);
    mainfile = new char[mainfile_length + 1];

    std::strcpy(mainfile, d.mainfile);
}

Classic1::Classic1() : Cd1()
{
    int null_length = std::strlen("null");
    mainfile = new char[null_length + 1];

    std::strcpy(mainfile, "null");
}

Classic1::~Classic1()
{
    delete[] mainfile;
    mainfile = nullptr;
}

void Classic1::Report() const
{
    Cd1::Report();
    std::cout << "Mainfile: " << mainfile << std::endl;
}

Classic1 & Classic1::operator=(const Classic1 & d)
{
    Cd1::operator=(d);
    delete[] mainfile;
    mainfile = nullptr;

    int mainfile_length = std::strlen(d.mainfile);
    mainfile = new char[mainfile_length + 1];

    std::strcpy(mainfile, d.mainfile);
    return *this;
}


// dma.h
#pragma once
#ifndef DMA_H_
#define DMA_H_

#include <iostream>

class DMA
{
public:
    DMA();
    ~DMA();
    virtual void View() = 0;
};


class baseDMA : public DMA
{
private:
    char * label;
    int rating;

public:
    baseDMA(const char * l = "null", int r = 0);
    baseDMA(const baseDMA & rs);
    virtual ~baseDMA();
    baseDMA & operator=(const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const baseDMA & rs);

    virtual void View();
};


class lacksDMA : public baseDMA
{
private:
    enum { COL_LEN = 40 };
    char color[COL_LEN];

public:
    lacksDMA(const char * c = "black", const char * l = "null", int r = 0);
    lacksDMA(const char * c, const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const lacksDMA & rs);

    virtual void View();
};

class hasDMA : public baseDMA
{
private:
    char * style;

public:
    hasDMA(const char * s = "none", const char * l = "null", int r = 0);
    hasDMA(const char * s, const baseDMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const hasDMA & rs);

    virtual void View();
};

#endif // !DMA_H_

// dma.cpp
#include "dma.h"

#include <cstring>


DMA::DMA()
{

}


DMA::~DMA()
{
}

baseDMA::baseDMA(const char * l, int r)
{
    int label_length = std::strlen(l);
    label = new char[label_length + 1];

    std::strcpy(label, l);
    rating = r;
}

baseDMA::baseDMA(const baseDMA & rs)
{
    int label_length = std::strlen(rs.label);
    label = new char[label_length + 1];

    std::strcpy(label, rs.label);
    rating = rs.rating;
}

baseDMA::~baseDMA()
{
    delete[] label;
    label = nullptr;
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    delete[] label;

    int label_length = std::strlen(rs.label);
    label = new char[label_length + 1];

    std::strcpy(label, rs.label);
    rating = rs.rating;

    return *this;
}

std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
    os << "Label: " << rs.label << std::endl;
    os << "Rating: " << rs.rating;

    return os;
}

void baseDMA::View()
{
    std::cout << "Label: " << label << std::endl;
    std::cout << "Rating: " << rating << std::endl;
}

lacksDMA::lacksDMA(const char * c, const char * l, int t) :
    baseDMA(l, t)
{
    std::strcpy(color, c);
}

lacksDMA::lacksDMA(const char * c, const baseDMA & rs) :
    baseDMA(rs)
{
    std::strcpy(color, c);
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & rs)
{
    operator<<(os, (baseDMA)rs) << std::endl;
    os << "Color: " << rs.color;

    return os;
}

void lacksDMA::View()
{
    baseDMA::View();
    std::cout << "Color: " << color << std::endl;
}

hasDMA::hasDMA(const char * s, const char * l, int r) :
    baseDMA(l, r)
{
    int style_length = std::strlen(s);
    style = new char[style_length + 1];

    std::strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const baseDMA & rs) :
    baseDMA(rs)
{
    int style_length = std::strlen(s);
    style = new char[style_length + 1];

    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs) :
    baseDMA(hs)
{
    int style_length = std::strlen(hs.style);
    style = new char[style_length + 1];

    std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete[] style;
    style = nullptr;
}

hasDMA & hasDMA::operator=(const hasDMA & rs)
{
    baseDMA::operator=(rs);
    delete[] style;

    int style_length = std::strlen(rs.style);
    style = new char[style_length + 1];

    std::strcpy(style, rs.style);

    return *this;
}

std::ostream & operator<<(std::ostream & os, const hasDMA & rs)
{
    operator<<(os, baseDMA(rs)) << std::endl;
    os << "Style: " << rs.style;

    return os;
}

void hasDMA::View()
{
    baseDMA::View();
    std::cout << "Style: " << style << std::endl;
}


// port.h
#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Port
{
private:
    char * brand;
    char style[20];
    int bottles;

public:
    Port(const char * br = "none", const char * st = "none", int b = 0);
    Port(const Port & p);
    virtual ~Port() { delete[] brand; }
    Port & operator=(const Port & p);
    Port & operator+=(int b);
    Port & operator-=(int b);
    int BottleCount() const { return bottles; }
    virtual void Show() const;
    friend ostream & operator<<(ostream & os, const Port & p);
};

class VintagePort : public Port
{
private:
    char * nickname;
    int year;

public:
    VintagePort();
    VintagePort(const char * br, int b, const char * nn, int y);
    VintagePort(const VintagePort & vp);
    ~VintagePort() { delete[] nickname; }
    VintagePort & operator=(const VintagePort & vp);
    void Show() const;
    friend ostream & operator<<(ostream & os, const VintagePort & vp);
};

// port.cpp
#include "Port.h"



Port::Port(const char * br, const char * st, int b)
{
    int brand_length = std::strlen(br);
    brand = new char[brand_length + 1];
    std::strcpy(brand, br);
    std::strcpy(style, st);
    bottles = b;
}

Port::Port(const Port & p)
{
    int brand_length = std::strlen(p.brand);
    brand = new char[brand_length + 1];
    std::strcpy(brand, p.brand);
    std::strcpy(style, p.style);
    bottles = p.bottles;
}

Port & Port::operator=(const Port & p)
{
    delete[] brand;

    int brand_length = std::strlen(p.brand);
    brand = new char[brand_length + 1];
    std::strcpy(brand, p.brand);
    std::strcpy(style, p.style);
    bottles = p.bottles;

    return *this;
}

Port & Port::operator+=(int b)
{
    bottles += b;

    return *this;
}

Port & Port::operator-=(int b)
{
    bottles -= b;
    return *this;
}

void Port::Show() const
{
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Style: " << style << std::endl;
    std::cout << "Bottles: " << bottles << std::endl;
}

ostream & operator<<(ostream & os, const Port & s)
{
    os << s.brand << ", " << s.style << ", " << s.bottles;

    return os;
}

VintagePort::VintagePort() : Port()
{
    int null_length = std::strlen("null");
    nickname = new char[null_length + 1];
    std::strcpy(nickname, "null");
    year = 0;
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y) :
    Port(br, "Vintage", b)
{
    int nn_length = std::strlen(nn);
    nickname = new char[nn_length + 1];
    std::strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort & vp) : Port(vp)
{
    int nn_length = std::strlen(vp.nickname);
    nickname = new char[nn_length + 1];
    std::strcpy(nickname, vp.nickname);
    year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    delete nickname;
    Port::operator=(vp);

    int nn_length = std::strlen(vp.nickname);
    nickname = new char[nn_length + 1];
    std::strcpy(nickname, vp.nickname);
    year = vp.year;

    return *this;
}

void VintagePort::Show() const
{
    Port::Show();
    cout << "Nickname: " << nickname << endl;
    cout << "Year: " << year << endl;
}

ostream & operator<<(ostream & os, const VintagePort & vp)
{
    os << Port(vp);
    os << ", " << vp.nickname << ", " << vp.year;

    return os;
}
