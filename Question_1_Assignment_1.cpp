#include <iostream>
#include<limits>
using namespace std;
// functions declarations
void Add_Expenses(string *Categories, double *Expenses, int range);
double Total_Expenses(double *Expenses, int range);
int highest_expense(double *Expenses, int range);
int main()
{
    int size;
    double Total;
    cout << "\nEnter the number of categories : ";
    cin >> size;
    while(cin.fail() || size < 0)
    {
        cout << "\nInvalid input!Please enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> size;
    }
        cin.ignore();

        string *Categories = new string[size];
        double *Expenses = new double[size];

        cout << "\nEnter Categories name : ";
        for (int i = 0; i < size; i++)
        {
            cout << "\nEnter Category " << i + 1 << " : ";
            getline(cin, Categories[i]);
        }
        Add_Expenses(Categories, Expenses, size);
        Total = Total_Expenses(Expenses, size);
        int HighestExpense = highest_expense(Expenses, size);

        // display summary
        cout << "\n============================================\n"
             << "\nSummary of Categories and Expenses:\n";
        for (int k = 0; k < size; k++)
        {
            cout << Categories[k] << " = $" << Expenses[k] << endl;
        }
        cout << "\n============================================\n";
        cout << "\nTotal : $" << Total;
        cout << "\n"
             << Categories[HighestExpense] << " is the Category with highest expense : $" << Expenses[HighestExpense];

        delete[] Categories;
        delete[] Expenses;
    

    return 0;

}
void Add_Expenses(string *Categories, double *Expenses, int range)
{
    cout << "\nEnter Expenses for each Category: ";
    for (int i = 0; i < range; i++)
    {
        cout << "\nEnter expense for " << Categories[i] << " : ";
        cin >> Expenses[i];
        while (true)
        {
            if (cin.fail() || Expenses[i] < 0)
            {
                cout << "\ninvalid input! please Enter positive value for "<<Categories[i]<<" : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> Expenses[i];
            }
            else
            {
                break;
            }
        }
    }
}

double Total_Expenses(double *Add_Expenses, int range)
{
    double Total = 0;
    for (int i = 0; i < range; i++)
    {
        Total += Add_Expenses[i];
    }
    return Total;
}

int highest_expense(double *Expenses, int range)
{
    int max = 0;
    for (int i = 0; i < range; i++)
    {
        if (Expenses[i] > Expenses[max])
        {
            max = i;
        }
    }
    return max;
}