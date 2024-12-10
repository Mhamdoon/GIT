#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;
bool isloggedin(string username,string password)
{ 
    string un,pss;
    cout << "==================================" << endl;
    cout << "               LOGIN          " << endl;
    cout << "==================================" << endl;
        cout<<"Enter Username:";
        cin>>username;
        cout<<"Enter Password:";
        cin>>password;
    cout << "==================================" << endl;
    cout<<endl;
    ifstream read(username + ".txt");
    getline(read,un);//un used to extract the username into a string
    getline(read,pss);
    if(un==username && pss==password)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    srand(time(0));  
    int choice;
    bool loggedin;
    string username,password;
    cout<<setw(70)<<"|---------------------------------------------|"<<endl;
    cout<<setw(70)<<"|         WELCOME TO BMI CALCULATOR APP       |"<<endl; 
    cout<<setw(70)<<"|---------------------------------------------|"<<endl<<endl;
    cout<<"|--------------------------------------|"<<endl;
    cout<<"|                                      |"<<endl;
    cout<<"|            DO YOU WISH TO:           |"<<endl;
    cout<<"|                                      |"<<endl;
    cout<<"|--------------------------------------|"<<endl;
    cout<<"|    1.Login                2.Regsiter |"<<endl;
    cout<<"|--------------------------------------|"<<endl;
    cout<<"         Enter your Option(1/2): ";
    cin>>choice;
    if(choice==2)
    {
    cout << "==================================" << endl;
    cout << "           REGISTRATION           " << endl;
    cout << "==================================" << endl;
        cout<<"Enter Username:";
        cin>>username;
        cout<<"Enter Password:";
        cin>>password;
        ofstream file;
        file.open(username + ".txt");
        file<<username<<endl<<password;
        file.close();
    cout << "==================================" << endl;
    cout << "     WELCOME, " << username << "!" << endl;
    cout << "==================================" << endl;
        main();
    }
    else if(choice==1)
    {
     loggedin=isloggedin(username,password);
     if(loggedin==1)
     {
        cout<<"Successfully Logged in!"<<endl;
    cout << "====================================" << endl;
    cout << "    WELCOME TO BMI CALCULATOR APP   " << endl;
    cout << "====================================" << endl;
