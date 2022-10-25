#include <iostream>
#include <string>

using namespace std;

//************************************************************************
// Function declarations. Function definitions are in birthdays.cpp and test.cpp
//************************************************************************
void ohhi();
void startTests();

int main()
{
    
    cout << "1) Execute testing functions in test.cpp" << endl;
    cout << "2) Execute ohhi() function in main.cpp" << endl;
    cout << "Choice --> ";

    int choice;
    cin >> choice;

    // remove the return character from the cin stream buffer
    string junk;
    getline(cin, junk);

    cout << endl;

    if (choice == 1)
    {
        startTests();
    }
    else if (choice == 2)
    {
        ohhi();
    }

    return 0;
}
