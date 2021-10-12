#include <iostream>
#include <iomanip>
using namespace std;

//function prototypes
double compoundInterest(double, double, int);
void displayLoan(double, double, int);

int main()
{
    //variable declaration
    double principal = 0;
    double rate = 0;
    unsigned int term = 0;

    //promting user to set variable values
    cout << "Enter the amount of the loan: ";
    cin >> principal;
    cout << "Enter the interest rate as a value between 0 and 1: ";
    cin >> rate;
    cout << "Enter the term of the loan in years: ";
    cin >> term;

    //echo intput back to user
    cout << setprecision(2) << fixed << "\nLoan Principal: " << principal;
    cout << "\nLoan Rate: " << rate;
    cout << "\nLoan Term: " << term;

    //call displayLoan function to display compound interest
    displayLoan(principal, rate, term);
    cout << "\n\n";

    system("pause");
}

//fucntion to calculate compount interest
double compoundInterest(double loan, double rate, int term)
{
    int interest = 0;

    interest = loan;

    for (int count = 0; count < term; ++count)
    {
        interest += interest * rate;
    }

    return interest - loan;
}

//function that displays loan
void displayLoan(double loan, double rate, int term)
{
    cout << "\nCompound Interest: " << compoundInterest(loan, rate, term);
}