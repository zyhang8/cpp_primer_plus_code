#include <iostream>

using std::cout;
using std::cin;
using std::endl;


//practice 1
const int Foot2Inch = 12;
void p3_1(void)
{
    int inch_input = 0;
    int inch_output = 0;
    int foot = 0;

    cout << "Please input you height in inch:___\b\b\b";
    cin >> inch_input;
    foot = inch_input / Foot2Inch;
    inch_output = inch_input % Foot2Inch;

    cout << "Your height in inch was: " << inch_input << "; Your height in foot and inch was: " << foot << " foot " << inch_output << " inch!" << endl;

    return;
}


// practice 2
const double Inch2Meter = 0.254;
const double Kilo2Pound = 2.2;
void p3_2(void)
{
    double height_foot = 0.0;
    double height_inch = 0.0;
    double height_meter = 0.0;
    double weight_pound = 0.0;
    double weight_kilo = 0.0;
    double BMI = 0.0;

    cout << "Enter your height in foot and inch" << endl;
    cout << "First enter the foot: ";
    cin >> height_foot;
    cout << "Second enter the inch: ";
    cin >> height_inch;

    cout << "Enter you weight in pound: ";
    cin >> weight_pound;

    height_meter = (height_foot * Foot2Inch + height_inch) * Inch2Meter;
    weight_kilo = weight_pound / Kilo2Pound;

    BMI = weight_kilo / (height_meter * height_meter);

    cout << "Your BIM is " << BMI << endl;
}


// practice 3
void p3_3(void)
{
    int degrees = 0;
    int minutes = 0;
    int seconds = 0;
    double total = 0.0;

    cout << "Enter a latitude in degrees, minute and seconds:" << endl;
    cout << "First, enter the degrees: ";
    cin >> degrees;
    cout << "Next, enter the minucts of arc: ";
    cin >> minutes;
    cout << "Finally, enter the seconds of arc: ";
    cin >> seconds;

    total = degrees + minutes / 60.0 + seconds / 3600.0;
    cout << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = " << total << " degrees." << endl;
}


// practice 4
void p3_4(void)
{
    long long total_seconds = 0;
    int days = 0;
    int hours = 0;
    int minutes = 0;
    int seconds = 0;

    cout << "Enter the number of seconds: ";
    cin >> total_seconds;

    days = total_seconds / (24 * 60 * 60);
    hours = ((total_seconds % (24 * 60 * 60)) / (60 * 60));
    minutes = ((total_seconds % (60 * 60)) / 60);
    seconds = (total_seconds % 60);

    cout << total_seconds << " seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds" << endl;
}


// practice 5
void p3_5(void)
{
    long long world_population = 0;
    long long US_population = 0;
    double rate = 0.0;

    cout << "Enter the world's population :";
    cin >> world_population;

    cout << "Enter the population of the US: ";
    cin >> US_population;

    rate = double(US_population) / (world_population);
    cout << "The population of the US is " << rate * 100 << "% of the world population." << endl;
}


// practice 6
void p3_6(void)
{
    double mile = 0.0;
    double gallon = 0.0;
    double mile_per_gallon = 0.0;

    cout << "Enter the distance in mile you drive: ";
    cin >> mile;
    cout << "Enter the comsumption of oil: ";
    cin >> gallon;

    mile_per_gallon = mile / gallon;
    cout << "Average fuel comsuption: " << mile_per_gallon << " mile/gallon" << endl;
}


// practice 7
void p3_7(void)
{
    double fuel_comsuption_eu = 0.0;
    double fuel_comsuption_us = 0.0;

    cout << "Enter the fuel comsuption in Europ standard: ";
    cin >> fuel_comsuption_eu;

    fuel_comsuption_us = fuel_comsuption_eu / 19 * 12.41;
    cout << "the fuel comsuption in US standard is " << fuel_comsuption_us << "/100KM" << endl;
}


int main(int argc, char **argv)
{
    p3_7();

    while (getchar());

    return 0;
}
