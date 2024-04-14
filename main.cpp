#include <iostream>
#include <string>
#include <vector>
#include "HomePage.cpp"
#include "CurrentAccount.cpp"

using namespace std;

class User{
    private:
        string f_name;
        string l_name;
        int age;
        int mobile_num;
        int balance_current;
    public:
        User(){
            f_name = "John";
            l_name = "Doe";
            age=0;
            mobile_num=000000000000;
            balance_current=3000;
        };
        User(string f, string l, int a, int m_n, int b_c){
            f_name = f;
            l_name = l; 
            age = a; 
            mobile_num = m_n; 
            balance_current = b_c;
        }

        int get_balance_current(){return balance_current;}

        void printInfo(){
            cout << "Name: " << f_name << " " << l_name << endl;
            cout << "Age: " << age << endl;
            cout << "Mobile Number: +971 " << mobile_num << endl;
            cout << "Current Balance in Bank Account: " << balance_current << endl;
        }

        User(const User& m){
            f_name = m.f_name;
            l_name = m.l_name;
            age = m.age;
            mobile_num = m.mobile_num;
            balance_current = m.balance_current;
        }

        bool operator==(const User& u){
            if((f_name == u.f_name) && (l_name == u.l_name)){
                return true;
            }

            return false;
        }

        User& operator=(const User& m){
            if((f_name == m.f_name) && (l_name == m.l_name)){
                age = m.age;
                mobile_num = m.mobile_num;
                balance_current = m.balance_current;
                return *this;
            }

            f_name = m.f_name;
            l_name = m.l_name;
            age = m.age;
            mobile_num = m.mobile_num;
            balance_current = m.balance_current;

            return *this;
        }
};

int main(){
    int option, HomePage_choice;
    vector<User> User_List;
    bool flag = true;
    string first_name, last_name;

    while(flag)
    {
        cout << "WELCOME TO THE BANK PORTAL!!" << endl;
        cout << "\n1)SignUp \n2)LogIn \n3)Exit" << endl;

        cout << endl;
        cout << "Select an Option: ";
        cin >> option;

        switch(option)
        {
            case 1:
            {   
                cout << "First and Last name: ";
                cin >> first_name >> last_name;
                cout << endl;

                int Age;
                cout << "Enter your age: ";
                cin >> Age;
                cout << endl;

                int phone_num;
                cout << "Enter Phone Number: ";
                cin >> phone_num;
                cout << endl;

                User o(first_name, last_name, Age, phone_num, 0);
                User_List.push_back(o);
                cout << endl;

                cout << "Depositing initial 3000AED into account.......Successful" << endl;

                homepage_menu(HomePage_choice, first_name);

                switch(HomePage_choice)
                {
                    case 1: 
                        CurrentAccount_script(o.get_balance_current());
                }

                break;
            }
            case 2:
            {
                cout << "\nFirst and Last Name: ";
                cin >> first_name >> last_name;

                User u(first_name,last_name,0,0,0);

                for(auto x:User_List){
                    if(u == x){
                        u = x;
                    }
                }
                
                

                break;
            }
            case 3:
            {
                flag = false;
                break;
            }
        }
        
    }

    cout << "Exited Program" << endl;
    cout << "Content of User List: " << endl;
    cout << endl;
    for(auto x: User_List){
        x.printInfo();
        cout << endl;
    }
    return 0;
}