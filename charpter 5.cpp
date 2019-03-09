#include <iostream>
#include <string>
#include <array>

using std::cin;
using std::cout;
using std::endl;
using std::array;
using std::string;
using std::getline;


// practice 1
void p5_1(void)
{
    int number1 = 0;
    int number2 = 0;
    int sum = 0;

    cout << "Enter the first number: ";
    cin >> number1;

    cout << "Enter the second number: ";
    cin >> number2;

    for (int i = number1; i <= number2; i++)
    {
        sum += i;
    }

    cout << "The sum of number " << number1 << " to " << number2 << ", sum = " << sum << endl;
}


// practice 2
const int ArSize = 100;
void p5_2(void)
{
    array<long double, ArSize+1> factorials;
    factorials[0] = factorials[1] = 1.0;
    for (int i = 2; i <= ArSize; i++)
    {
        factorials[i] = i * factorials[i - 1];
    }
    for (int i = 0; i <= ArSize; i++)
    {
        cout << i << "! = " << factorials[i] << endl;
    }

    return;
}


// practice 3
void p5_3(void)
{
    int sum = 0;
    int num = 0;

    while (1)
    {
        cout << "Enter a number( 0 to exit): ";
        cin >> num;
        if (num == 0)
        {
            break;
        }
        sum += num;
        cout << "Until now, the sum of the number you inputed is " << sum << endl;
    }

    cout << "Done." << endl;

    return;
}


// practice 4
void p5_4(void)
{
    double Daphne_account = 100;
    double Cleo_account = 100;
    int years = 0;

    while (Daphne_account >= Cleo_account)
    {
        years++;
        Cleo_account = Cleo_account + Cleo_account * 0.05;
        Daphne_account += 10;
    }

    cout << "After " << years << " years. " << "Cleo account which is " << Cleo_account << " will more than Daphne account which is " << Daphne_account << "." << endl;
}


// practie 5
void p5_5(void)
{
    string month[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "Septempber", "October", "November", "December" };
    int sell[12];
    int total_sales = 0;

    cout << "Enter the sales of book <C++ for Fools> each month: " << endl;
    for (int i = 0; i < 12; i++)
    {
        cout << month[i] << ": ";
        cin >> sell[i];
        total_sales += sell[i];
    }

    cout << "The total sales is " << total_sales << endl;
    for (int i = 0; i < 12; i++)
    {
        cout << month[i] << ": " << sell[i] << endl;
    }

    return;
}


// practice 6
void p5_6(void)
{
    string month[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "Septempber", "October", "November", "December" };
    unsigned int sales[3][12] = { 0 };
    unsigned int total_sales[3] = { 0 };

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter " << i + 1 << " year(s) sales of book <C++ for Fools> each month: " << endl;
        for (int j = 0; j < 12; j++)
        {
            cout << month[j] << ": ";
            cin >> sales[i][j];
            total_sales[i] += sales[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << " year(s) total sales is " << total_sales[i] << endl;
    }

    cout << "Three years total sales is " << total_sales[0] + total_sales[1] + total_sales[2] << endl;
}


//practice7
struct car
{
    string company;
    int pro_year;
};
void p5_7(void)
{
    unsigned int size = 0;
    cout << "How many cars do you wish to catalog? ";
    cin >> size;
    cin.get();

    struct car *pcar = new struct car[size];
    for (unsigned int i = 0; i < size; i++)
    {
        cout << "Car #" << i + 1 << ":" << endl;
        cout << "Please enter the make: ";
        getline(cin, pcar[i].company);

        cout << "Please enter the year make: ";
        cin >> pcar[i].pro_year;
        cin.get();
    }

    cout << "Here is your collection:" << endl;
    for (unsigned int i = 0; i < size; i++)
    {
        cout << pcar[i].pro_year << " " << pcar[i].company << endl;
    }
}


// practice 8
void p5_8(void)
{
    unsigned int n_word = 0;
    char input[128];

    cout << "Enter words (to stop, type the word done):" << endl;
    while (cin >> input)
    {
        if (strcmp(input, "done"))
        {
            n_word++;
        }
        else
            break;
    }

    cout << "You entered a total of " << n_word << " words." << endl;
}


// practice 9
void p5_9(void)
{
    unsigned int n_word = 0;
    string input;

    cout << "Enter words (to stop, type the word done):" << endl;
    while (cin >> input)
    {
        if (input != "done")
        {
            n_word++;
        }
        else
            break;
    }

    cout << "You entered a total of " << n_word << " words." << endl;
}


// practice 10
void p5_10(void)
{
    unsigned int row = 0;

    cout << "Enter number of rows: ";
    cin >> row;

    for (unsigned int i = 1; i <= row; i++)
    {
        for (unsigned int j = i; j < row; j++)
        {
            cout << ".";
        }
        for (unsigned int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}


int main(int argc, char **argv)
{
    p5_10();

    while (getchar());

    return 0;
}
