#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User{
    private:
        int age;
        int mobile_num;
        string f_name;
        string l_name;
        float current_num;
        float saving_num;
        float total_num;

    public:
        User(): age{}, mobile_num{}, f_name{"None"}, l_name{"None"}, current_num{}, saving_num{}, total_num{} {}
        User(const int& A, const int& M_N, const string& F_N, const string& L_N, const float& C_N, const float& S_N): age{A}, mobile_num{M_N}, f_name{F_N}, l_name{L_N}, current_num{C_N}, saving_num{S_N}, total_num{C_N + S_N} {}

        User(const User& m): age{m.age}, mobile_num{m.mobile_num}, f_name{m.f_name}, l_name{m.l_name}, current_num{m.current_num}, saving_num{m.saving_num}, total_num{m.current_num + m.saving_num}{}
        User(User&& m): age{std::move(m.age)}, mobile_num{std::move(m.mobile_num)}, f_name{std::move(m.f_name)}, l_name{std::move(m.l_name)}, current_num{std::move(m.current_num)}, saving_num{std::move(m.saving_num)}, total_num{std::move(m.current_num + m.saving_num)} {}

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
                current_num = m.current_num;
                saving_num = m.saving_num;
                total_num = saving_num + current_num;
                return *this;
            }

            f_name = m.f_name;
            l_name = m.l_name;
            age = m.age;
            mobile_num = m.mobile_num;
            current_num = m.current_num;
            saving_num = m.saving_num;
            total_num = saving_num + current_num;

            return *this;
        }

        void printInfo(){
            cout << "Name: " << f_name << " " << l_name << endl;
            cout << "Age: " << age << endl;
            cout << "Mobile Number: +971 " << mobile_num << endl;
            cout << "Total Account Balance: AED" << total_num << endl;
            cout << "Current Account Balance: AED" << current_num << " || Saving Account Balance: AED" << saving_num << endl;
            cout << endl;
        }

        string getFirstName(){return f_name;}
        string getLastName(){return l_name;}
        float getCurrentNum(){return current_num;}
        float getSavingNum(){return saving_num;}

        void depositCurrentNum(const float& num){current_num = num; total_num += num;}
        void depositSavingNum(const float& num){saving_num = num; total_num += num;}
        void transferTo(const float& num){total_num += num; current_num += num;}
        void transferFrom(const float& num){total_num -= num; current_num -= num;}

};

#endif