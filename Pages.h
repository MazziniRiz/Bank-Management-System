#ifndef PAGES_H
#define PAGES_H

#include <iostream>
#include <vector>
#include "User.h"

using namespace std;

void SignUp(int& A, int& M_N, string& F_N, string& L_N, float& C_N, float& S_N, vector<User>& U_D, User& user)
{
    cout << "Enter first and last name: ";
    cin >> F_N >> L_N;

    cout << "Enter age: ";
    cin >> A;

    cout << "Enter phone number: ";
    cin >> M_N;

    User o(A, M_N, F_N, L_N, 0, 0);
    user = o;
    U_D.push_back(o);
}

void Login(int& A, int& M_N, string& F_N, string& L_N, float& C_N, float& S_N, vector<User>& U_D, User& user)
{
    bool flag2 = true;
    do{
        cout << "Enter first and last name: ";
        cin >> F_N >> L_N;

        for (int i = 0; i < U_D.size(); i++)
        {
            if ((U_D[i].getFirstName() == F_N) && (U_D[i].getLastName() == L_N))
            {
                user = U_D[i];
                i = U_D.size();
                flag2 = false;
            }
            else
            {
                cout << "Not Found. Try Entering Again." << endl;
            }
        }
    }while(flag2);
}

void AuthChoice(int& A, int& M_N, string& F_N, string& L_N, float& C_N, float& S_N, vector<User>& U_D, User& user)
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
            SignUp(A, M_N, F_N, L_N, C_N, S_N, U_D, user);
            break;
        case 2:
            Login(A, M_N, F_N, L_N, C_N, S_N, U_D, user);
            break;
        case 3:
            for(auto x : U_D){
                x.printInfo();
                cout << endl;
            }
            exit(0);
        default:
            cout << "Not correct option. Enter 1 or 2 or 3." << endl;
            break;
        }
    }
}

#endif