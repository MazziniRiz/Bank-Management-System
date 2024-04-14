#include <iostream>

using namespace std;

void homepage_menu(int& option, string f_name){
    cout << endl;
    cout << "WELCOME " << f_name << "! Select what you would like to do: ";
    cout << "\n1) Manage Current Account \n2) Manage Savings Account \n3) Deposit funds \n4) Transfer funds into alt account \n5) Logout" << endl;

    cout << "Enter your option: ";
    cin >> option;

}