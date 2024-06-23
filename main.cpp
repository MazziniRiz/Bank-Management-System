#include <iostream>
#include <vector>
#include "Pages.h"
#include "User.h"
#include "DoublyLinkedList.h"

using namespace std;


int main(){
    int Age, Mobile_Num;
    string first_name, last_name;
    float Current_Num, Saving_Num;
    User current_user;
    DoublyLinkedList pages_database;
    vector<User> user_database;

    user_database.push_back(current_user);

    Pages LoginPage(current_user, user_database, 2);
    Pages AuthenticationPage(current_user, user_database, 1);
    Pages SignUpPage(current_user, user_database, 3);
    Pages HomePage(current_user, user_database, 4);

    pages_database.insertList(LoginPage);
    pages_database.insertList(AuthenticationPage);
    pages_database.setHead(HomePage);
    pages_database.setTail(SignUpPage);

    bool flag = true;

    pages_database.SearchList(AuthenticationPage, LoginPage, SignUpPage, HomePage, pages_database);


    return 0;
}