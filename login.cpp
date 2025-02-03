#include <iostream>
#include <fstream>
using namespace std;

class db{
    string username,email,pass;
    fstream file;
    public:
        void signup(){
            cout<<"Enter your User name : ";
            cin>>username;
            cout<<"Enter Email : ";
            cin>>email;
            cout<<"Enter password : ";
            cin>>pass;

            file.open("database.txt",ios::out | ios::app);
            file<<username<<"*"<<email<<"*"<<pass<<endl;
            file.close();
        }
        
        void login(){
            cout<<"----------Login----------"<<endl;
            string searchUser , searchPass;
            cout<<"Enter username : ";
            cin>>searchUser;
            cout<<"Enter password : ";
            cin>>searchPass;
            
            file.open("database.txt",ios::in);
            bool found = false;
            
            while(getline(file,username,'*') && getline(file,email,'*') && getline(file,pass,'\n')){
                if(username == searchUser && pass == searchPass){
                    cout<<"\n Account Login Successful!!"<<endl;
                    cout<<"Username : "<<username<<endl;
                    cout<<"Email : "<<email<<endl;
                    found = true;
                    break; // Exit the loop once found
                }
            }

            if(!found){
                cout<<"Username or Password is incorrect"<<endl;
            }
            file.close();
        }

        void forgot(){
            cout<<"Enter your Username : ";
            string user,e;
            cin>>user;
            cout<<"Enter Email id : ";
            cin>>e;

            file.open("database.txt",ios::in);
            bool found = false;
            
            while(getline(file,username,'*') && getline(file,email,'*') && getline(file,pass,'\n')){
                if(username == user && email == e){
                    cout<<"Account Found"<<endl;
                    cout<<"Password : "<<pass<<endl;
                    found = true;
                    break; // Exit the loop once found
                }
            }
            if(!found){
                cout<<"User does not exist or Email does not match"<<endl;
            }
            file.close();
        }
};

int main(){
    db o;
    cout<<"1.Login \n 2.Sign Up \n 3.Forgot Password \n 4.Exit"<<endl;
    char ch;
    cout<<"Enter your Choice : ";
    cin>>ch;
    switch (ch)
    {
    case '1':
        o.login();
        break;
    case '2':
        o.signup();
        break;
    case '3':
        o.forgot();
        break;
    default:
        cout<<"Invalid Selection"<<endl;
        break;
    }

    return 0;
}
