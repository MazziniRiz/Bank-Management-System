#ifndef PAGES_H
#define PAGES_H

#include <iostream>
#include <vector>
#include "User.h"

using namespace std;

User SignUp(int& A, int& M_N, string& F_N, string& L_N, float& C_N, float& S_N, vector<User>& U_D)
{
    cout << "Enter first and last name: ";
    cin >> F_N >> L_N;

    cout << "Enter age: ";
    cin >> A;

    cout << "Enter phone number: ";
    cin >> M_N;

    User o(A, M_N, F_N, L_N, 0, 0);

    U_D.push_back(o);

    return o;
}

User Login(int& A, int& M_N, string& F_N, string& L_N, float& C_N, float& S_N, vector<User>& U_D)
{
    bool flag2 = true;
    do{
        cout << "Enter first and last name: ";
        cin >> F_N >> L_N;

        for (auto x : U_D)
        {
            if ((x.getFirstName() == F_N) && (x.getLastName() == L_N))
            {
                return x;
            }
            else
            {
                cout << "Not Found. Try Entering Again.";
            }
        }
    }while(flag2);
}

void AuthChoice(int& A, int& M_N, string& F_N, string& L_N, float& C_N, float& S_N, vector<User>& U_D)
{
    int option;
    cout << "WELCOME TO BNK BANK E-PORTAL\n" << endl;
    

    while ((option != 1) || (option != 2) || (option != 3))
    {
        cout << "1) SignUp \n2) Login \n3) Exit\nEnter Option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            SignUp(A, M_N, F_N, L_N, C_N, S_N, U_D);
            break;
        case 2:
            Login(A, M_N, F_N, L_N, C_N, S_N, U_D);
            break;
        case 3:
            /*for(auto x : user_database){
                x.printInfo();
                cout << endl;
            }*/
            exit(0);
        default:
            cout << "Not correct option. Enter 1 or 2 or 3." << endl;
            break;
        }
    }
}

#endif