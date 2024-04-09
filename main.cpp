#include <iostream>
#include <string>

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

        void printInfo(){
            cout << "Name: " << f_name << " " << l_name << endl;
            cout << "Age: " << age << endl;
            cout << "Mobile Number: +" << mobile_num << endl;
            cout << "Current Balance in Bank Account: " << balance_current << endl;
        }
};

int main(){
    int Login_choice;

    cout << "WELCOME TO THE BANK PORTAL!!" << endl;
    cout << "1)LogIn \n2)SignUp" << endl;

    cout << "1 or 2: ";
    cin >> Login_choice;

    switch(Login_choice)
    {
        case 1:
            string first_name;
            string last_name;
            cout << "\nFirst and Last name: ";
            cin >> first_name >> last_name;

            int Age;
            cout << "\nEnter your age: ";
            cin >> Age;

            int phone_num;
            cout << "\nEnter Phone Number: ";
            cin >> phone_num;

            User o(first_name, last_name, Age, phone_num, 3000);
            cout << "\nDepositing intial 3000AED into account.......Successful" << endl;
            break;
    }

    return 0;
}