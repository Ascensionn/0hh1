#include <iostream>
#include <string>

using namespace std;

void ohhi();
void startTests();

int main()
{

    cout << "-------------------------------" << endl
         << "EECS 183 Project 3 Menu Options" << endl
         << "-------------------------------" << endl;
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
