#ifndef PAGES_H
#define PAGES_H

#include <iostream>
#include <vector>
#include "User.h"

using namespace std;

// Home Page Functions

void CurrentAccount(User& user){
    cout << endl;
    cout << "\nWelcome to your Current Accounts!" << endl;
    cout << "\nCurrent amount: AED" << user.getCurrentNum() << endl;
}

void SavingAccount(User& user){
    cout << endl;
    cout << "\nWelcome to your Savings Accounts!" << endl;
    cout << "\nSaving Amount: AED" << user.getSavingNum() << endl;
}

void Deposit(User& user){
    int option;
    float amount;

    cout << endl;
    cout << "\nDeposit some funds into your account!" << endl;
    

    while ((option != 1) && (option != 2))
    {
        cout << "\n1) Current Account \n2) Savings Account \nWhich Account would you like to deposit in: ";
        cin >> option;

        switch(option)
        {
            case 1:
                cout << "\nHow much would you like to deposit into your Current Account?: ";
                cin >> amount;
                user.depositCurrentNum(amount);
                break;
            case 2:
                cout << "\nHow much would you like to deposit into your Savings Account?: ";
                cin >> amount;
                user.depositSavingNum(amount);
                break;
            default:
                cout << "\nIncorrect option. Enter 1 or 2." << endl;
                break;
        }
    }
}

void TransferAmount(User& user, User& user2)
{
    int option;
    float amount;

    cout << endl;
    cout << "\nHow much would you like to transfer: ";
    cin >> amount;

    user.transferFrom(amount);
    user2.transferTo(amount);

    cout << "\n ...Funds transferred to " << user2.getFirstName() << " " << user2.getLastName() << endl;
}

void Transfer(vector<User>& U_D, User& user)
{
    string F_N, L_N;
    cout << "Who would you like to transfer to?: ";
    cin >> F_N >> L_N;

    for(int i = 0; i < U_D.size(); i++){
        if((U_D[i].getFirstName() == F_N) && (U_D[i].getLastName() == L_N)){
            TransferAmount(user, U_D[i]);
            i = U_D.size();
        }
    }
}


void HomePage(vector<User>& U_D, User& user)
{
    bool flag3 = true;
    int option;
    cout << "\nWelcome, " << user.getFirstName() << "!" << endl;
    cout << "\nWhat would you like to do today?" << endl;
    while(flag3){
        while ((option != 1) && (option != 2) && (option != 3) && (option != 4) && (option != 5))
        {
            cout << "\n1) Current Account \n2) Savings Account \n3) Deposit funds \n4) Transfer Funds \n5) Logout \nEnter your choice: ";
            cin >> option;

            switch(option)
            {
                case 1:
                    CurrentAccount(user);
                    break;
                case 2:
                    SavingAccount(user);
                    break;
                case 3:
                    Deposit(user);
                    break;
                case 4:
                    Transfer(U_D, user);
                    break;
                case 5:
                    exit(0);
                    break;
                default:
                    cout << "Incorrect Input. Enter 1, 2, 3, 4, or 5." << endl;
                    break;
            }
        }
    }
}

// Authentication Page Functions

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

    HomePage(U_D, user);
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

    HomePage(U_D, user);
}

void AuthChoice(int& A, int& M_N, string& F_N, string& L_N, float& C_N, float& S_N, vector<User>& U_D, User& user)
{
    int option;
    cout << "WELCOME TO BNK BANK E-PORTAL\n" << endl;
    

    while ((option != 1) && (option != 2) && (option != 3))
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