#include <iostream>
#include <string>
#include <cctype>


using namespace std;



// practice 1
void p7_1(void)
{
    double x, y;
    double avg = 0;

    cout << "Enter two numbers: ";
    cin >> x >> y;
    while (x != 0 && y != 0)
    {
        avg = 2.0 * x * y / (x + y);
        cout << "The average of " << x << " and " << y << " is " << avg << endl;

        cout << "Enter the next two numbers: ";
        cin >> x >> y;
    }
}


// practice 2
void GetInput(double *grade, unsigned int *number)
{
    cout << "You can enter up to 10 grades( -1 to quit): " << endl;
    while (cin >> grade[(*number)++])
    {
        if (grade[*number - 1] == -1)
        {
            break;
        }
    }
    (*number)--;
}
void PrintArray(const double *grage, const unsigned int number)
{
    cout << "The grade is: " << endl;

    for (unsigned int i = 0; i < number; i++)
    {
        cout << grage[i] << " ";
    }

    cout << endl;
}
void CalAvg(const double *grade, const unsigned int number)
{
    double total = 0.0;
    cout << "The average is :";
    for (unsigned int i = 0; i < number; i++)
    {
        total += grade[i];
    }
    cout << total / number << endl;
}
void p7_2(void)
{
    double grade[10];
    unsigned int enter = 0;

    GetInput(grade, &enter);
    PrintArray(grade, enter);
    CalAvg(grade, enter);

    return;
}


// practice 3
struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};
void PrintBox(struct box mbox)
{
    cout << "Box maker: " << mbox.maker << endl;
    cout << "Box height: " << mbox.height << endl;
    cout << "Box width: " << mbox.width << endl;
    cout << "Box length: " << mbox.length << endl;
    cout << "Box volume: " << mbox.volume << endl;
}
void CalBoxVolume(struct box *pbox)
{
    pbox->volume = pbox->height * pbox->width * pbox->length;
}
void p7_3(void)
{
    struct box mbox = { "Jimmy Chen", 0.25, 4.0, 1.0, 0.0 };
    PrintBox(mbox);
    CalBoxVolume(&mbox);
    PrintBox(mbox);
}


// practice 4
long double probability(unsigned number, unsigned picks)
{
    long double result = 1.0;
    long double n = 0;
    unsigned p;
    for (n = number, p = picks; p > 0; n--, p--)
    {
        result = result * n / p;
    }

    return result;
}
void p7_4(void)
{
    unsigned field1 = 47;
    unsigned field2 = 27;

    cout << "You have on chance in ";
    cout << probability(47, 5) * probability(27, 1);
    cout << " of winning.\n" << endl;
}


// practice 5
long long factorial(unsigned int number)
{
    if (number == 0 || number == 1)
    {
        return 1;
    }
    else
    {
        return number * factorial(number - 1);
    }
}
void p7_5(void)
{
    long long result = 0;
    unsigned int input = 0;

    cout << "Please enter the number: ";
    cin >> input;

    while (1)
    {
        result = factorial(input);
        cout << "The result of " << input << "! is " << result << "." << endl;

        cout << "Please enter the next number: ";
        cin >> input;
    }
}


// practice 6
unsigned int Fill_array(double double_array[], unsigned int length)
{
    unsigned int n_input = 0;
    cout << "Enter double numbers (non-digital to quit): " << endl;
    for (size_t i = 0; i < length; i++)
    {
        if (cin >> double_array[i])
        {
            n_input++;
        }
        else
        {
            break;
        }
    }

    return n_input;
}
void Show_array(double double_array[], unsigned int length)
{
    cout << "The double array is :" << endl;
    for (size_t i = 0; i < length; i++)
    {
        cout << double_array[i] << " ";
        if ((i + 1) % 5 == 0)
        {
            cout << endl;
        }
    }
    if (length % 5 != 0)
    {
        cout << endl;
    }
}
void Reverse_array(double double_array[], unsigned int length)
{
    cout << "Revert the array" << endl;
    for (size_t i = 0; i < length / 2; i++)
    {
        double tmp = double_array[i];
        double_array[i] = double_array[length - 1 - i];
        double_array[length - 1 - i] = tmp;
    }
}
void p7_6(void)
{
    double double_array[10];
    unsigned int n_input;
    n_input = Fill_array(double_array, 10);
    Show_array(double_array, n_input);
    Reverse_array(double_array, n_input);
    Show_array(double_array, n_input);
}


// practice 7
int fill_array(double *ar_begin, double *ar_end)
{
    double temp = 0.0;
    int i = 0;
    double *ar_tmp = nullptr;
    for (ar_tmp = ar_begin; ar_tmp < ar_end; ar_tmp++)
    {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if (!cin)
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; input preocess terminated.\n";
            break;
        }
        else if (temp < 0)
        {
            break;
        }

        *ar_tmp = temp;
        i++;
    }

    return i;
}
void show_array(const double *ar_begin, const double *ar_end)
{
    const double *ar_tmp = nullptr;
    unsigned int i = 0;
    for (ar_tmp = ar_begin; ar_tmp < ar_end; ar_tmp++)
    {
        cout << "Property #" << (i + 1) << ": $";
        cout << *ar_tmp << endl;
        i++;
    }
}
void revalue(double *ar_begin, double *ar_end, double r)
{
    for (double * ar = ar_begin; ar < ar_end; ar++)
    {
        *ar *= r;
    }
}
void p7_7(void)
{
    double properties[10];

    int size = fill_array(properties, properties + 10);
    show_array(properties, properties + size);
    if (size > 0)
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; Please enter a number: ";
        }
        revalue(properties, properties + size, factor);
        show_array(properties, properties + size);
    }

    cout << "Done.\n";

    return;
}


// practice 8
const int Seasons = 4;
const char *Snames[Seasons] = { "Spring", "Summer", "Fall", "Winter" };
struct cost
{
    double expenses[Seasons];
};
void fill(double *pa)
{
    for (int i = 0; i < Seasons; i++)
    {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> pa[i];
    }
}
void show(double *pa)
{
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        cout << Snames[i] << ": $" << pa[i] << endl;
        total += pa[i];
    }
    cout << "Total Expenses: $" << total << endl;
}
void fill(struct cost *pCost)
{
    for (int i = 0; i < Seasons; i++)
    {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> pCost->expenses[i];
    }
}
void show(struct cost *pCost)
{
    double total = 0.0;
    cout << "\nEXPENSE\n";
    for (int i = 0; i < Seasons; i++)
    {
        cout << Snames[i] << ": $" << pCost->expenses[i] << endl;
        total += pCost->expenses[i];
    }
    cout << "Total Expense: $" << total << endl;
}
void p7_8(void)
{
    // situation a
    cout << "Situation a: " << endl;
    double pa[Seasons] = { 0 };
    fill(pa);
    show(pa);

    // situation b
    cout << endl << endl;
    cout << "Situation b: " << endl;
    struct cost *pCost = new struct cost;
    fill(pCost);
    show(pCost);
    delete pCost;
}


// practice 9
const int SLEN = 30;
struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};
int getinfo(student pa[], int n)
{
    int enter = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the infomation of student #" << i+1 << endl;
        cout << "Enter full name (blank line to quit): ";
        cin.getline(pa[i].fullname, SLEN);
        cout << "Enter hobby: ";
        cin.getline(pa[i].hobby, SLEN);
        cout << "Enter ooplevel: ";
        cin >> pa[i].ooplevel;
        while (cin.get() != '\n')
            continue;
        enter++;
    }
    return enter;
}
void display1(student st)
{
    cout << "Using display1(student st): " << endl;
    cout << "Full name: " << st.fullname << endl;
    cout << "Hobby: " << st.hobby << endl;
    cout << "Ooplevel: " << st.ooplevel << endl;
}
void display2(const student *st)
{
    cout << "Using display2(const student *st)" << endl;
    cout << "Full name: " << st->fullname << endl;
    cout << "Hobby: " << st->hobby << endl;
    cout << "Ooplevel: " << st->ooplevel << endl;
}
void display3(const student pa[], int n)
{
    cout << "Using display3(const student pa[], int n)" << endl;;
    for (int i = 0; i < n; i++)
    {
        cout << "Infomation of student #" << i + 1 << ": " << endl;
        cout << "Full name: " << pa[i].fullname << endl;
        cout << "Hobby: " << pa[i].hobby << endl;
        cout << "Ooplevel: " << pa[i].ooplevel << endl;
    }
}
void p7_9(void)
{
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n')
        continue;

    student *ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i = 0; i < entered; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);

    delete[] ptr_stu;
    cout << "Done.\n";
    return;
}


// practice 10
double add(double x, double y)
{
    return x + y;
}
double mul(double x, double y)
{
    return x * y;
}
double calculate(double x, double y, double(*fun)(double, double))
{
    return fun(x, y);
}
void p7_10(void)
{
    double x = 0.0;
    double y = 0.0;

    cout << "Enter two double number: ";
    while (cin >> x >> y)
    {
        cout << "Call add, the result of " << x << " and " << y << " is " << calculate(x, y, add) << endl;
        cout << "Call mul, the result of " << x << " abd " << y << " is " << calculate(x, y, mul) << endl;

        cout << "Enter next two double number: ";
    }
}


int main(int argc, char **argv)
{
    p7_10();

    while (getchar());

    return 0;
}
