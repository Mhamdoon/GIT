-------------------------------

#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;

void displayTable(int bodylevel) {
    srand(time(0));

    string activityLevels[] = {"Less", "Moderate", "High", "Very High"};
    int maintenanceCalories[4];

    cout << "=========================================" << endl;
    cout << "     Activity Level vs Maintenance Calories" << endl;
    cout << "=========================================" << endl;

    if (bodylevel == 0) {
        maintenanceCalories[0] = 1800 + rand() % 201;
        maintenanceCalories[1] = 2100 + rand() % 101;
        maintenanceCalories[2] = 2250 + rand() % 151;
        maintenanceCalories[3] = 2450 + rand() % 251;
    } else if (bodylevel == 2) {
        maintenanceCalories[0] = 2000 + rand() % 201;
        maintenanceCalories[1] = 2250 + rand() % 201;
        maintenanceCalories[2] = 2500 + rand() % 151;
        maintenanceCalories[3] = 2660 + rand() % 141;
    } else if (bodylevel == 3) {
        maintenanceCalories[0] = 2300 + rand() % 101;
        maintenanceCalories[1] = 2450 + rand() % 201;
        maintenanceCalories[2] = 2650 + rand() % 251;
        maintenanceCalories[3] = 2950 + rand() % 451;
    } else {
        cout << "Invalid body level!" << endl;
        return;
    }

    cout << left << setw(20) << "Activity Level" << setw(20) << "Maintenance Calories" << endl;
    cout << "-----------------------------------------" << endl;

    for (int i = 0; i < 4; i++) {
        cout << left << setw(20) << activityLevels[i] << setw(20) << maintenanceCalories[i] << "cal" << endl;
    }

    cout << "=========================================" << endl;
}
int bmicomparison(double measuredbmi)
{
    int level;
if(measuredbmi>0&&measuredbmi<18)
{
    level=0;
}
else if(measuredbmi>18&&measuredbmi<25)
{
    level=1;
}
else if(measuredbmi>25&&measuredbmi<35)
{
    level=2;
}
else if(measuredbmi>35)
{
    level=3;
}
return level;
}
double bmi(double convertedheight,double convertedweight)
{
    int bmi;
    double heightinmeters=convertedheight/100;
    return convertedweight/(heightinmeters*heightinmeters);
}
double conversionheight(double height,double option1)
{
if (option1==1)
{
    return height;
}
else if(option1==2)
{
    return height* 30.48;
}
}
double conversionweight(double weight, double option2)
{
if (option2==1)
{
    return 0.453592*weight;//returning in kg
}
else if(option2==2)
{
    return weight;
}
}
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
    double height,weight;
    int age,option1,option2,calories;
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
    cout << "Choose Height Unit (1 for CM, 2 for FOOT): ";//choose option then calorie counting and table
        cin>>option1;
    cout<<"Enter Your Height:";
        cin>>height;
    cout << "Choose Weight Unit (1 for POUNDS, 2 for KG): ";
        cin>>option2;
    cout<<"Enter Your Weight:";
        cin>>weight;
    cout<<"Enter Your Age:";
        cin>>age;
    double convertedheight=conversionheight(height,option1);
    double convertedweight=conversionweight(weight,option2);
         double measuredbmi=bmi(convertedheight,convertedweight);
        cout<<endl;
    cout << "==================================" << endl;
        cout << "Your BMI is: " << measuredbmi <<"\n"<< endl;
    cout << "==================================" << endl;
        int bodylevel=bmicomparison(measuredbmi);
        if(bodylevel==0)
        {

    cout << "You are Underweight (NORMAL BMI is 25)." << endl;
    cout << "To gain weight, you need to consume at least 500 calories more than usual." << endl;
    cout << "Would you like to proceed with a calorie plan? (y/n): ";
        cin>>plan;
        if(plan=='Y'||plan=='y')
        {
        displayTable(bodylevel);
        cout<<"Enter Your Maintenance Calories from The Table:"<<endl;
        cin>>maintenance;




            
        }
        else if(bodylevel==1)
        {
    cout << "Your BMI is Normal (NORMAL BMI is 25)." << endl;
    cout << "You do not need a calorie plan." << endl;
        }
        else if(bodylevel==2)
        {

       cout << "You are Overweight (NORMAL BMI is 25)." << endl;
    cout << "To lose weight, you need to consume at least 500 calories less than usual." << endl;
    cout << "Would you like to proceed with a calorie plan? (y/n): ";
        cin>>plan;
        if(plan=='Y'||plan=='y')
        {
        displayTable(bodylevel);
    cout << "Enter Your Maintenance Calories from the Table: ";
        cin>>maintenance;

            
        }
        else if(bodylevel==3)
        {


    cout << "You are Obese (NORMAL BMI is 25)." << endl;
    cout << "Would you like to proceed with a calorie plan? (y/n): ";
        cin>>plan;
        if(plan=='Y'||plan=='y')
        {
        displayTable(bodylevel);
    cout<<"Enter Your Maintenance Calories from The Table:"<<endl;
        cin>>maintenance;

            
        }
 else if(loggedin==0)
     {
    cout<<"YOU INPUTTED INVALID USERNAME AND PASSWORD!! GOING BACK TO MAIN MENU"<<endl;
    cout<<"\n";
        main();
     }
    }
}
