//example of using
#include "func.h"
#include <iostream>

using namespace std;

func<void(*)(string)> f; //def type "[yout type](*)([your arguments])" or this not work!!!

void exit_(string str) {
    quick_exit(1);
}
void read(string str) {
    cout << "enter thing: ";
    cin >> str;
}
void print(string str){//func exampl
    cout << str << endl;
}
void mode(string str) {
    if (str == "administrator"||str=="admin") {
        f.func_name_list = {
            {"print",print},
            {"mode",mode},
            {"read",read},
            {"exit",exit_}
        };
        cout << "administrator mode activated"<<endl;
    }
    if (str == "user") {
        f.func_name_list = {
            {"print",print},
            {"mode",mode},
            {"exit",exit_}
        };
        cout << "administrator mode deactivated" << endl;
    }
}
int main()
{
    //add func to list witch name
    f.func_name_list = {
        {"print",print},
        {"mode",mode},
        {"exit",exit_}
    };
    void (*fun)(string); //func here
    string arg;
    string f_name;
    while (true)
    {
        cout << "enter command: ";
        cin >> f_name;
        if (f_name == "exit") exit_("Y");
        cin >> arg;
        fun = f.func_name_list[f_name];
        fun(arg);
    }
}

 