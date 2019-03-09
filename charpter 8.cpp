#include <iostream>
#include <string>
#include <cctype>
#include <cstring>


using namespace std;



// practice 1
void fun_of_p8_1(char *str, int print_times = 0)
{
    // 这里也将print_times也打印出来，方便演示
    cout << "String: " << str << " , print_times: " << print_times << endl;
    if (print_times > 1)
    {
        print_times--;
        fun_of_p8_1(str, print_times);
    }
    return;
}
void p8_1(void)
{
    char str[128];
    int print_times = 0;
    cout << "Enter the string you want to print: ";
    cin.getline(str, 128);
    cout << "Enter the times you want to print: ";
    cin >> print_times;

    // 测试传入两个参数
    cout << "Test fun which has two prematers: " << endl;
    fun_of_p8_1(str, print_times);

    // 测试传入一个参数
    cout << "Test fun which has one premater: " << endl;
    fun_of_p8_1(str);
}


// practice 2
struct CandyBar {
    char company[128];
    double weight;
    int heat;
};
void print_CandyBar(const struct CandyBar &candybar)
{
    cout << "CandyBar company: " << candybar.company << endl;
    cout << "CandyBar weight: " << candybar.weight << endl;
    cout << "CandyBar heat: " << candybar.heat << endl;
}
void fill_CandyBar(struct CandyBar &candybar, char *company, double weight, int heat)
{
    /*
    如果使用strcpy遇到如下错误：
    error C4996: 'strcpy': This function or variable may be unsafe. Consider using strcpy_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.
    1>c:\program files (x86)\windows kits\10\include\10.0.15063.0\ucrt\string.h(136): note: 参见“strcpy”的声明

    可以这样子解决：右键工程名-->属性-->C/C++-->预处理器-->预处理器定义，编辑右边输入框加入：_CRT_SECURE_NO_WARNINGS
    */
    strcpy(candybar.company, company);
    candybar.weight = weight;
    candybar.heat = heat;
}
void p8_2(void)
{
    struct CandyBar candybar = { "" };
    char company[128];
    double weight = 0.0;
    int heat = 0;

    cout << "Enter the company of candybar: ";
    cin.getline(company, 128);

    cout << "Enter the weight of candybar: ";
    cin >> weight;

    cout << "Enter the heat of candybar: ";
    cin >> heat;

    fill_CandyBar(candybar, company, weight, heat);
    print_CandyBar(candybar);

    return;
}


// practice 3
void p8_3(void)
{
    string input;

    cout << "Enter a string (q to quit): ";
    getline(cin, input);

    while (input[0] != 'q')
    {
        for (size_t i = 0; i < input.length(); i++)
        {
            input[i] = toupper(input[i]);
        }
        cout << input << endl;

        cout << "Next string (q to quit): ";
        getline(cin, input);
    }

}


// practice 4
struct stringy {
    char *str;
    int ct;
};
void set(struct stringy &in_stringy, char * in_string)
{
    int string_length = strlen(in_string);
    in_stringy.str = new char(string_length + 1);
    strcpy(in_stringy.str, in_string);
    in_stringy.ct = string_length;
}
void show(const struct stringy &in_stringy, int print_times = 1)
{
    for (int i = 0; i < print_times; i++)
    {
        cout << "member string of struct stringy: " << in_stringy.str << endl;
    }
}
void show(const char * str, int print_times = 1)
{
    for (int i = 0; i < print_times; i++)
    {
        cout << "Print char string: " << str << endl;
    }
}
int p8_4(void)
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";

    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");

    return 0;
}


// practice 5
template <typename T>
T max5(T in_array[])
{
    T max = in_array[0];
    for (size_t i = 0; i < 5; i++)
    {
        if (max < in_array[i])
        {
            max = in_array[i];
        }
    }

    return max;
}
void p8_5(void)
{
    int int_array[5] = {32, 43, 66, 23, 54};
    double double_array[5] = { 32.4, 33.3, 61.3, 646.3, 23.5 };

    int int_array_max = max5(int_array);
    double double_array_max = max5(double_array);

    cout << "max of int array: " << int_array_max << endl;
    cout << "max of double array: " << double_array_max << endl;
}


// practice 6
template <typename T>
T maxn(T in_array[], int array_size)
{
    T max = in_array[0];
    for (int i = 0; i < array_size; i++)
    {
        if (max < in_array[i])
        {
            max = in_array[i];
        }
    }

    return max;
}
// 显示具体化
template <> const char * maxn(const char *in_str[], int n)
{
    const char * str = in_str[0];

    for (int i = 0; i < n; i++)
    {
        if (strlen(str) < strlen(in_str[i]))
        {
            str = in_str[i];
        }
    }

    return str;
}
void p8_6(void)
{
    int int_array[6] = { 43, 235, 54, 232, 123, 65 };
    double double_array[4] = { 32.1, 453.2, 53.3, 67.4 };
    const char * str_array[5] = { "Hello Jimmy!", "Hello World!", "ABCDEFG,HIJKLMN", "Today is a goood day!", "C++ Primer Plus!" };

    int int_max = maxn(int_array, 6);
    double double_max = maxn(double_array, 4);
    const char * length_max_str = maxn(str_array, 5);

    cout << "max of int array: " << int_max << endl;
    cout << "max of double array: " << double_max << endl;
    cout << "max length string of string array: " << length_max_str << endl;
}


// practice 7
template <typename T>
T SumArray(T arr[], int n);

template <typename T>
T SumArray(T * arr[], int n);

struct debts {
    char name[50];
    double amount;
};

int p8_7(void)
{
    int thing[6] = { 13, 31, 103, 301, 310, 130 };
    int int_sum = 0;
    struct debts mr_E[3] =
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
    double *pd[3];
    double double_sum = 0.0;

    for (size_t i = 0; i < 3; i++)
    {
        pd[i] = &mr_E[i].amount;
    }

    int_sum = SumArray(thing, 6);
    double_sum = SumArray(pd, 3);

    cout << "Sum of int array: " << int_sum << endl;
    cout << "Sum of double* array: " << double_sum << endl;

    return 0;
}

template <typename T>
T SumArray(T arr[], int n)
{
    // 下面的sum初始化，在便宜的时候会有warning提示，有个简单的方法可以解决，那就是将sum初始化为arr的第一个元素，然后for循环从i=1开始
    T sum = 0.0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return sum;
}

template <typename T>
T SumArray(T * arr[], int n)
{
    T sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += *(arr[i]);
    }

    return sum;
}


// main
int main(int argc, char **argv)
{
    p8_7();


    while (cin.get());
}
