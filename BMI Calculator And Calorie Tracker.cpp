#include<iostream> //used for input/output objects
#include<fstream> //used for file handling
#include<string> //used for string characters
#include <iomanip> //used to set character width and spaces
#include<ctime> //used to import rand function
using namespace std;
void plantrue(int maintenance, int calories,int bodylevel)
{
    cout << "|----------------------------------------------|" << endl; //prints the assessment if plan is followed
    cout << "|         CALORIE PLAN ASSESSMENT              |" << endl;
    cout << "|----------------------------------------------|" << endl;
    cout << "| Maintenance Calories:     " << setw(10) << maintenance << " cal    |" << endl;
    cout << "| Calories Consumed Today:  " << setw(10) << calories << " cal     |" << endl;
    cout << "| Calorie Deficit:          " << setw(10) << maintenance - calories << " cal     |" << endl;
    cout << "|----------------------------------------------|" << endl;
    cout << "|  ✓ CONGRATULATIONS! You Followed The Plan!   |" << endl;
    cout << "|----------------------------------------------|" << endl;
}
void planfalse(int maintenance, int calories,int bodylevel)
{        //if plan is not followed the following assesmment is done
    cout << "|----------------------------------------------|" << endl;
    cout << "|         CALORIE PLAN ASSESSMENT              |" << endl;
    cout << "|----------------------------------------------|" << endl;
    cout << "| Maintenance Calories:     " << setw(10) << maintenance << " cal    |" << endl;
    cout << "| Calories Consumed Today:  " << setw(10) << calories << " cal    |" << endl;
    cout << "| Calorie Deficit:          " << setw(10) << maintenance - calories << " cal    |" << endl;
    cout << "|----------------------------------------------|" << endl;
    cout << "|  × WORK HARDER! Deficit Less Than Required   |" << endl;
    cout << "|----------------------------------------------|" << endl;
}
int caloriedeficit(int maintenance, int calories)
{
return maintenance-calories; //gets the calorie deficit
}
void displayTable(int bodylevel) {
    srand(time(0));
 //displays the required table for maintenance calories
    string activityLevels[] = {"Less", "Moderate", "High", "Very High"};
    int maintenanceCalories[4];

    cout << "=========================================" << endl;
    cout << "   Activity Level vs Maintenance Calories" << endl;
    cout << "=========================================" << endl;

    if (bodylevel == 0) {
        maintenanceCalories[0] = 1800 + rand() % 201;
        maintenanceCalories[1] = 2100 + rand() % 101;
        maintenanceCalories[2] = 2250 + rand() % 151;
        maintenanceCalories[3] = 2450 + rand() % 251;
    } else if (bodylevel == 2) {
        maintenanceCalories[0] = 2000 + rand() % 201; //assigns different calories based on different bodylevels and activity levels
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

    for (int i = 0; i < 4; i++) { //inititates a loop to print a table using the declared arrays
        cout << left << setw(20) << activityLevels[i] << setw(20) << maintenanceCalories[i] << "cal" << endl;
    }

    cout << "=========================================" << endl;
}
int bmicomparison(double measuredbmi)
{
    int level; //compares bmi to get the bodylevel
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
double conversionheight(double height,double option1)
{
if (option1==1)
{
    return height; //returns height in cm if its in foot it converts
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
double bmi(double convertedheight,double convertedweight)
{
    int bmi;
    double heightinmeters=convertedheight/100;
    return convertedweight/(heightinmeters*heightinmeters); //calculates the bmi
}
int calorietracker() {
    int choice, itemChoice;  //prints a calorie tracker table for today
    int totalCalories = 0;
    string items[10] = {"Pizza", "Bread", "Biryani", "Chicken Curry", "Haleem", "Dessert", "Burger", "Pasta", "Cold Drink", "Sandwich"};
    int calories[10] = {500, 100, 600, 600, 700, 400, 800, 700, 150, 550};

    cout << "========================================" << endl;
    cout << "         TRACK YOUR CALORIES            " << endl;
    cout << "========================================" << endl;

    while (true) {
        cout << "\n============= FOOD MENU =============" << endl;
        for (int i = 0; i < 10; i++) {
            cout << "ITEM " << i + 1 << " - " << items[i] 
                 << " - CALORIES: " << calories[i] << " cal" << endl;
        }

        cout << "\nChoose an option:" << endl;
        cout << "1. Add calories (enter the food item number)" << endl;
        cout << "2. View total calories and exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the item number you have eaten (1-10): ";
            cin >> itemChoice;

            if (itemChoice >= 1 && itemChoice <= 10) {
                totalCalories += calories[itemChoice - 1];
                cout << "You chose " << items[itemChoice - 1] 
                     << ". Calories added: " << calories[itemChoice - 1] << " cal." << endl;
            } else {
                cout << "Invalid item number. Please choose a number between 1 and 10." << endl;
            }
        } else if (choice == 2) {
            cout << "========================================" << endl;
            cout << "    Total Calories Consumed: " << totalCalories << " cal" << endl;
            cout << "========================================" << endl;
            break;
        } else {
            cout << "Invalid choice. Please choose 1 or 2." << endl;
        }
    }

    return totalCalories;
}
bool isitloggedin(string username,string password)
{ 
    string username1,pass; //checks to see if its logged in
    cout << "==================================" << endl;
    cout << "               LOGIN          " << endl;
    cout << "==================================" << endl;
        cout<<"Enter Username:";
        cin>>username;
        cout<<"Enter Password:";
        cin>>password;
    cout << "==================================" << endl;
    cout<<endl;
    ifstream read(username + ".txt"); //checks the file if username is wrong then such a file doesnt exist and it assigns garbage values to un and pss
    getline(read,username1);//un used to extract the username into a string
    getline(read,pass);
    if(username1==username && pass==password)
    {
        return 1;//true
    }
    else
    {
        return 0;//false
    }
}
int main()
{
    srand(time(0));   //setting time to change in the program with each execution
    double height,weight;  //declaring all the required varibles
    int age,option1,option2,calories;
    int maintenance;
    char plan;
    int choice;
    bool isloggedin;
    string username,password;
    cout<<setw(70)<<"|---------------------------------------------|"<<endl; //welcomes the user to the program
    cout<<setw(70)<<"|         WELCOME TO BMI CALCULATOR APP       |"<<endl; 
    cout<<setw(70)<<"|---------------------------------------------|"<<endl<<endl;
    cout<<"|--------------------------------------|"<<endl;
    cout<<"|                                      |"<<endl;
    cout<<"|            DO YOU WISH TO:           |"<<endl;
    cout<<"|                                      |"<<endl;
    cout<<"|--------------------------------------|"<<endl;
    cout<<"|    1.Login                2.Regsiter |"<<endl;//option to login or register
    cout<<"|--------------------------------------|"<<endl;
    cout<<"         Enter your Option(1/2): ";
    cin>>choice;
    if(choice==2)
    {
    cout << "==================================" << endl;
    cout << "           REGISTRATION           " << endl; //registration process
    cout << "==================================" << endl;
        cout<<"Enter Username:";
        cin>>username;
        cout<<"Enter Password:";
        cin>>password;
        ofstream file;
        file.open(username + ".txt"); //opens file with username.txt variable name
        file<<username<<endl<<password;
        file.close();
    cout << "==================================" << endl;
    cout << "     WELCOME, " << username << "!" << endl;
    cout << "==================================" << endl;
        main();
    }
    else if(choice==1)
    {
     isloggedin=isitloggedin(username,password);//declared a bool variable which is equal to a function used to check if its loggedin
     if(isloggedin==1)
     {
        cout<<"Successfully Logged in!"<<endl;
    cout << "====================================" << endl;
    cout << "    WELCOME TO BMI CALCULATOR APP   " << endl;
    cout << "====================================" << endl;

    cout << "Choose Height Unit (1 for CM, 2 for FOOT): ";//choose option then calorie counting and table
        cin>>option1;
        if(option1>2||option1<1)
        {
            cout<<"ERROR! INPUT 1 OR 2!!"<<endl; //error handling
            main();
        }
    cout<<"Enter Your Height:";
        cin>>height;
    cout << "Choose Weight Unit (1 for POUNDS, 2 for KG): ";
        cin>>option2;               //enter weight
        if(option2>2||option2<1)
        {
            cout<<"ERROR! INPUT 1 OR 2!!"<<endl; //errorhandlimg
            main();
        }
    cout<<"Enter Your Weight:";
        cin>>weight;
    cout<<"Enter Your Age:";
        cin>>age;
        double convertedheight=conversionheight(height,option1);  //converts height using cinverted height function
        double convertedweight=conversionweight(weight,option2); //converts weight using converted weight function
        double measuredbmi=bmi(convertedheight,convertedweight);  //measures bmi using bmi function
        cout<<endl;
    cout << "==================================" << endl;
        cout << "Your BMI is: " << measuredbmi <<"\n"<< endl;
    cout << "==================================" << endl;
        int bodylevel=bmicomparison(measuredbmi); //compares the said bmi and measures 3 bodylevels
        if(bodylevel==0) //bodylevel 0 is underweight
        {
    cout << "You are Underweight (NORMAL BMI is 25)." << endl;
    cout << "To gain weight, you need to consume at least 500 calories more than usual." << endl;
    cout << "Would you like to proceed with a calorie plan? (y/n): "; //statements
        cin>>plan;
        if(plan=='Y'||plan=='y') //choice to see if user wants a calorie plam
        {
        displayTable(bodylevel); //displays a table based on body level
        cout<<"Enter Your Maintenance Calories from The Table:"<<endl;
        cin>>maintenance; //maintenance calories input
        cout<<"Proceeding To Calculate Your Calories Today:"<<endl;
        calories=calorietracker(); //made a calorie varible that takes the value of calorie tracker menu
        int deficit=caloriedeficit(maintenance,calories); //makes a calorie deficit function thats equal to the deficit variable
        if(deficit<=-500)
        {
    plantrue(maintenance,calories,bodylevel); //if plan is true 
        }
        else
        {
    planfalse(maintenance,calories,bodylevel); //if plan is false
        }
        }
        else if(plan=='N'||plan=='n')
        {
            system("exit");
        }
        else
        {
            cout<<"Error!! Input The Correct Choice!";
            system("exit");
        }
        }
        else if(bodylevel==1)
        {
    cout << "Your BMI is Normal (NORMAL BMI is 25)." << endl; //when weight is normal
    cout << "You do not need a calorie plan." << endl;
        }
        else if(bodylevel==2) // if bodylevel is 2
        {
    cout << "You are Overweight (NORMAL BMI is 25)." << endl;
    cout << "To lose weight, you need to consume at least 500 calories less than usual." << endl;
    cout << "Would you like to proceed with a calorie plan? (y/n): ";
        cin>>plan;
        if(plan=='Y'||plan=='y')
        {
        displayTable(bodylevel); //displays table based on body level
    cout << "Enter Your Maintenance Calories from the Table: ";
        cin>>maintenance;
    cout<<"Proceeding To Calculate Your Calories Today:"<<endl;
        calories=calorietracker(); //measures calories today
        int deficit=caloriedeficit(maintenance,calories);
        if(deficit>=500)
        {
        plantrue(maintenance,calories,bodylevel); //if deficit is required print the true plan
        }
        else
        {
        planfalse(maintenance,calories,bodylevel);//if its not the base case then print the false plan
        }
        }
        else if(plan=='N'||plan=='n')
        {
            system("exit");
        }
        else
        {
            cout<<"Error!! Input The Correct Choice!";
            system("exit");
        }
        }
        else if(bodylevel==3)
        {
    cout << "You are Obese (NORMAL BMI is 25)." << endl; //if user is obese
    cout << "Would you like to proceed with a calorie plan? (y/n): ";
        cin>>plan;
        if(plan=='Y'||plan=='y')//enter the plan
        {
        displayTable(bodylevel); //displays the maintencance calorie table
    cout<<"Enter Your Maintenance Calories from The Table:"<<endl;
        cin>>maintenance;
    cout<<"Proceeding To Calculate Your Calories Today:"<<endl;
        calories=calorietracker(); //calorie variable is equal to calorie tracker function
        int deficit=caloriedeficit(maintenance,calories);
        if(deficit>=500)
        {
        plantrue(maintenance,calories,bodylevel);
        }
        else
        {
        planfalse(maintenance,calories,bodylevel);
        }
        }
        else if(plan=='N'||plan=='n')
        {
            system("exit");
        }
        else
        {
            cout<<"Error!! Input The Correct Choice!";
            system("exit");
        }
        }
        
        
     }
     else if(isloggedin==0)
     {
    cout<<"YOU INPUTTED INVALID USERNAME AND PASSWORD!! GOING BACK TO MAIN MENU"<<endl;
    cout<<"\n";
        main();
     }
    
}
else{
    cout<<"ERROR !! Enter 1 or 2:"<<endl;
     main();
}
}
