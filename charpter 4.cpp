#include <iostream>
#include <string>
#include <array>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;


// practice 1
void p4_1(void)
{
    char first_name[128];
    char last_name[128];
    char letter;
    int age;

    cout << "What is your first name? ";
    cin.getline(first_name, 128);

    cout << "What is your last name? ";
    cin.getline(last_name, 128);

    cout << "What letter grade do you deserve? ";
    cin >> letter;

    cout << "What is your age? ";
    cin >> age;

    cout << "Name: " << last_name << ", " << first_name << endl;
    cout << "Grade: " << char(letter + 1) << endl;
    cout << "Age: " << age << endl;

}


// practice 2
void p4_2(void)
{
    const int ArSize = 20; // 这句可以去掉
    string name;
    string dessert;

    cout << "Enter your name:\n";
    getline(cin, name);

    cout << "Enter your favourite dessert:\n";
    getline(cin, dessert);

    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";

    return;
}


// practice 3
void p4_3(void)
{
    char first_name[256];
    char last_name[256];

    cout << "Enter your fitst name:";
    cin.getline(first_name, 256);
//  cin.get(first_name, 256);   // cin.get的参数和cin.getline相同，但是getline会读取换行符并保存到第一个参数中，但是cin.get会将换行符留在输入队列中，所以会导致下一个读取的内容是换行符

    cout << "Enter your last name:";
    cin.getline(last_name, 256);

    cout << "Here's your infomation is a single string: " << last_name << ", " << first_name << endl;

    return;
}


// pracitce 4
void p4_4(void)
{
    string first_name;
    string last_name;

    cout << "Enter your first name: ";
//  cin.getline()  // cin.getline不适用于string类
    getline(cin, first_name);

    cout << "Enter your last name: ";
    getline(cin, last_name);

    cout << "Here's your infomation is a single string: " << last_name << ", " << first_name << endl;
}


// practice 5
typedef struct CandyBar {
    string name;
    double weight;
    int calories;
} ST_CandyBar;
void p4_5(void)
{
    ST_CandyBar candybar = { "Mocha Munch", 2.3, 350 };
    cout << "the infomation of CandyBar, Name: " << candybar.name << ", Weight: " << candybar.weight << ", " << " Calories: " << candybar.calories << "." << endl;

    return;
}


// practice 6
void p4_6(void)
{
    ST_CandyBar candybar[3] = {
        {"Mocha Munch", 2.3, 350},
        {"Banana", 3.5, 400},
        {"HAHAHAHA", 3.0, 370}
    };

    for (int i = 0; i < 3; i++)
    {
        cout << "the infomation of CandyBar, Name: " << candybar[i].name << ", Weight: " << candybar[i].weight << ", " << " Calories: " << candybar[i].calories << "." << endl;
    }
}


// practice 7
typedef struct PIZZA_INFO {
    string name;
    double size;
    double weight;
} ST_PIZZA_INFO;
void p4_7(void)
{
    ST_PIZZA_INFO pizz_info;

    cout << "Enter the pizza company name: ";
    getline(cin, pizz_info.name);

    cout << "Enter the pizza size: ";
    cin >> pizz_info.size;

    cout << "Enter the pizza weight: ";
    cin >> pizz_info.weight;

    cout << "The company name of pizza is " << pizz_info.name << ", the size of the pizza is " << pizz_info.size << ", the weight of the pizza is " << pizz_info.weight << endl;

    return;
}


// practice 8
void p4_8(void)
{
    ST_PIZZA_INFO *pizza_info = new ST_PIZZA_INFO;

    cout << "Enter the pizza size: ";
    cin >> pizza_info->size;
    cin.get();

    cout << "Enter the pizza company name: ";
    getline(cin, pizza_info->name);

    cout << "Enter the pizza weight: ";
    cin >> pizza_info->weight;

    cout << "The company name of pizza is " << pizza_info->name << ", the size of the pizza is " << pizza_info->size << ", the weight of the pizza is " << pizza_info->weight << endl;

    delete pizza_info;

    return;
}


// practice 9
void p4_9(void)
{
    ST_CandyBar *pcandybar = new ST_CandyBar[3]{
        { "Mocha Munch", 2.3, 350 },
        { "Banana", 3.5, 400 },
        { "HAHAHAHA", 3.0, 370 }
    };

    for (int i = 0; i < 3; i++)
    {
        cout << "the infomation of CandyBar, Name: " << pcandybar[i].name << ", Weight: " << pcandybar[i].weight << ", " << " Calories: " << pcandybar[i].calories << "." << endl;
    }

    delete[] pcandybar;
}


// practice 10
void p4_10(void)
{
    std::array<double, 3> time;
    double avg_time = 0.0;

    printf("Enter three results time of runing 40 meters: ");
    cin >> time[0];
    cin >> time[1];
    cin >> time[2];

    avg_time = (time[0] + time[1] + time[2]) / 3;
    cout << "Result: " << time[0] << ", " << time[1] << ", " << time[2] << endl;
    cout << "Average result: " << avg_time;

}


int main(int argc, char **argv)
{
    p4_10();

    while (cin.get());

    return 0;
}
