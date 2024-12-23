#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Appliance
{
    string name;
    double Power_Rating;
    float HoursUsedPerDay;
};
double Daily_power_consumption(double Power_Rating, float HoursUsedPerDay);
double Total_power_Consumption(double *Daily_consumption, int Num);
int Most_power_Consumption(double *Daily_consumption, int Num);

int main()
{
    int Num_Appliances;
    cout << "\nEnter Number of Applances : ";
    cin >> Num_Appliances;
    while (cin.fail() || Num_Appliances < 0)
    {
        cout << "\nInvaild Entry!\nPlease input a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> Num_Appliances;
    }
    Appliance appliances[Num_Appliances];
    double *Daily_consumption = new double[Num_Appliances]; // dynamic array
    double Total_power_Consumpted;
    for (int i = 0; i < Num_Appliances; i++)
    {
        cin.ignore();
        cout << "\nEnter Name of " << i + 1 << " Appliance : ";
        getline(cin, appliances[i].name);
        cout << "\nEnter Power Rate in (KW) for " << appliances[i].name << " : ";
        cin >> appliances[i].Power_Rating;
        cout << "\nEnter Hours of use per day of " << appliances[i].name << " : ";
        cin >> appliances[i].HoursUsedPerDay;
        while (cin.fail() || appliances[i].Power_Rating < 0 || appliances[i].HoursUsedPerDay < 0)//70%
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n\nInvalid input\nPlease enter a positive value in (KW) for "<<appliances[i].name <<" : ";
            cin >> appliances[i].Power_Rating;
            cout << "\nEnter Hours of use per day of " << appliances[i].name << " : ";
            cin >> appliances[i].HoursUsedPerDay;
        }
    }
    cout << "\nDaily and Monthly Power consumption for Each appliance : ";
    cout << "\n==================================================================";
    for (int i = 0; i < Num_Appliances; i++)
    {
        Daily_consumption[i] = Daily_power_consumption(appliances[i].Power_Rating, appliances[i].HoursUsedPerDay);
        cout << endl
             << endl
             << "Daily Usage: " << endl
             << appliances[i].name << " Daily power Consumption is : " << Daily_consumption[i] << " KWh";
        cout << endl
             << endl
             << "Monthly Usage: " << endl
             << appliances[i].name << " monthly power Consumption is : " << Daily_consumption[i] * 30 << " KWh";
    }
    cout << "\n==================================================================";
    Total_power_Consumpted = Total_power_Consumption(Daily_consumption, Num_Appliances);
    cout << "\n\nThe Total power consumed : " << Total_power_Consumpted;
    int maximum_power_consumption = Most_power_Consumption(Daily_consumption, Num_Appliances);
    cout << "\n\nThe most power consumed Appliance is " << appliances[maximum_power_consumption].name << " with daily power consumption of : " << Daily_consumption[maximum_power_consumption] << " KWh \n";
    delete[] Daily_consumption;

    return 0;
}

double Daily_power_consumption(double Power_Rating, float HoursUsedPerDay)
{
    double Daily_power_consumpted;
    Daily_power_consumpted = Power_Rating * HoursUsedPerDay;
    return Daily_power_consumpted;
}
double Total_power_Consumption(double *Daily_consumption, int Num)
{
    double Total = 0;
    for (int i = 0; i < Num; i++)
    {
        Total += Daily_consumption[i];
    }

    return Total;
}
int Most_power_Consumption(double *Daily_consumption, int Num)
{
    int max = 0;
    for (int i = 1; i < Num; i++)
    {
        if (Daily_consumption[i] > Daily_consumption[max])
        {
            max = i;
        }
    }
    return max;
}