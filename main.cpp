#include <iostream>
#include <string>
#include <vector>

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
    int Login_choice;
    vector<User> User_List;
    int n = 0;
    string first_name, last_name;
    while(n < 2)
    {
        cout << "WELCOME TO THE BANK PORTAL!!" << endl;
        cout << "\n1)SignUp \n2)LogIn" << endl;

        cout << "\n1 or 2: ";
        cin >> Login_choice;

        switch(Login_choice)
        {
            case 1:
            {   
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
            case 2:

                cout << "\nFirst and Last Name: ";
                cin >> first_name >> last_name;

                User u(first_name,last_name,0,0,0);

                for(int i = 0; i < User_List.size(); i++){
                    if(u == User_List[i]){
                        u = User_List[i];
                    }
                }
                cout << endl;
                u.printInfo();

                break;
        }

        n+=1;
    }

    return 0;
}