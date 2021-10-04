#include <iostream>
using namespace std;

int main()
{
    cout << fixed;
    cout.precision(8);

    for (float d = 1; d < 2; d+= .02)
    {
	    cout << d << endl;
    }

    system("pause");
}