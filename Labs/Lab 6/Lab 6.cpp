#include <iostream>
#include <cctype>
using namespace std;

string getName();
int countAlpha(string s);

int main()
{
    string name;
    /*name = "bob";
    cout << name << endl;
    name = "kate";
    cout << name << endl;

    cout << endl; */

    name = getName();
    cout << name << "\n" << "You name has " << countAlpha(name) << " letters in it" << endl;

    system("pause");
}

string getName()
{
    string first;
    string last;
    
    cout << "Enter your first name: ";
    cin >> first;

    cout << "Enter your last name: ";
    cin >> last;

    return first + " " + last;
}

int countAlpha(string s)
{
    auto characters = 0;

    for (auto count = 0; count < s.length(); ++count)
    {
        if (isalpha(s[count]))
        {
            ++characters;
        }
    }

    return characters;
}