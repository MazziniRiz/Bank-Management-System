#include <iostream>
#include <vector>
#include "Pages.h"
#include "User.h"

using namespace std;


int main(){
    int Age, Mobile_Num;
    string first_name, last_name;
    float Current_Num, Saving_Num;

    bool flag = true;
    vector<User> user_database;

    while(flag){
        AuthChoice(Age, Mobile_Num, first_name, last_name, Current_Num, Saving_Num, user_database);
        flag = false;
    }


    return 0;
}