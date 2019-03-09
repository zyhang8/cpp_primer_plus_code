#include <iostream>


// practice 1
void p2_1(void)
{
    std::cout << "Jimmy Chen" << std::endl;
    std::cout << "China, Guangdong Province, Huizhou" << std::endl;

    return;
}


// practice 2
void p2_2(void)
{
    int ilong = 0;
    int iyards = 0;
    std::cout << "Input the distance in long:";
    std::cin >> ilong;
    iyards = 220 * ilong;
    std::cout << "the distance in yards is " << iyards << std::endl;

    return;
}


// practice 3
void string1(void)
{
    std::cout << "Three blind mice" << std::endl;

    return;
}

void string2(void)
{
    std::cout << "See how they run" << std::endl;

    return;
}

void p2_3(void)
{
    string1();
    string1();
    string2();
    string2();

    return;
}


// practice 4
void p2_4(void)
{
    int years = 0;
    int months = 0;
    std::cout << "Enter your age:";
    std::cin >> years;

    months = years * 12;
    std::cout << years << " years contain " << months << " monthes!" << std::endl;

    return;
}


// practice 5
double Celsius2Fahrenheit(double Celsius)
{
    return (1.8 * Celsius + 32.0);
}
void p2_5(void)
{
    double Celsius = 0.0;
    double Fahrenheit = 0.0;
    std::cout << "Please enter a Celsius value :";
    std::cin >> Celsius;
    Fahrenheit = Celsius2Fahrenheit(Celsius);

    std::cout << Celsius << " degrees Celsius is " << Fahrenheit << " defrees Fahrenheit." << std::endl;

    return;
}


// practice 6
double LightYears2Astronomical(double LightYears)
{
    return (LightYears * 63240);
}
void p2_6(void)
{
    double lightYears = 0;
    double astronomical = 0;

    std::cout << "Enter the number of light years: ";
    std::cin >> lightYears;

    astronomical = LightYears2Astronomical(lightYears);

    std::cout << lightYears << " light years = " << astronomical << " astronomical units." << std::endl;

    return;
}


// practice 7
void disTime(int hours, int minutes)
{
    std::cout << "Time: " << hours << ":" << minutes << std::endl;

    return;
}
void p2_7(void)
{
    int hours = 0;
    int minutes = 0;
    std::cout << "Enter the number of hours: ";
    std::cin >> hours;
    std::cout << "Enter the number of minutes: ";
    std::cin >> minutes;
    disTime(hours, minutes);

    return;

}


int main(int argc, char **argv)
{
    p2_7();

    getchar();
}
