#ifndef PAGES_H
#define PAGES_H

#include <iostream>
#include <vector>
#include "main.cpp"
#include "User.h"

using namespace std;

extern vector<User> user_database;
void SignUp(int& A, int& M_N, string& F_N, string& L_N, float& C_N, float& S_N)
{
    cout << "Enter first and last name: ";
    cin >> F_N >> L_N;

    cout << "Enter age: ";
    cin >> A;

    cout << "Enter phone number: ";
    cin >> M_N;
}

void Login(int& A, int& M_N, string& F_N, string& L_N, float& C_N, float& S_N)
{
    cout << "Enter first and last name: ";
    cin >> F_N >> L_N;

    for (auto x : user_database)
    {
        if ((x.getFirstName() == F_N) && (x.getLastName() == L_N))
        {
            cout << "Found...";
        }
        else
        {
            cout << "Not Found...";
        }
    }
}

void AuthChoice(int& A, int& M_N, string& F_N, string& L_N, float& C_N, float& S_N)
{
    int option;
    cout << "WELCOME TO BNK BANK E-PORTAL\n" << endl;
    cout << "1) SignUp \n2) Login \n3) Exit";

    while ((option != 1) || (option != 2) || (option != 3))
    {
        cin >> option;

        switch (option)
        {
        case 1:
            SignUp(A, M_N, F_N, L_N, C_N, S_N);
            break;
        case 2:
            Login(A, M_N, F_N, L_N, C_N, S_N);
            break;
        case 3:
            break;
        default:
            cout << "Not correct option. Enter 1 or 2 or 3.";
            break;
        }
    }
}

#endif