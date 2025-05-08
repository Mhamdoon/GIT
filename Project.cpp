#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<windows.h> // for Sleep(ms)
using namespace std;

// Base class for transactions (rental and sale)(abstract class)
class transaction
{
protected:
    int creditcardno;
    string name;
    string transactionID;
    string vehicleID;
    double amount;

public:
//constructor for base class
    transaction(string name, string transactionID, string vehicleID, double amount) {
        this->name = name;
        this->transactionID = transactionID;
        this->vehicleID = vehicleID;
    this->amount = amount;
    }
//pure virtual fucntions
    virtual void process() = 0;
    virtual void receipt() = 0;
};

// Rental transaction inheritied from transaction base class
class carrent : public transaction
{
private:
    int days;
    string returndate;

public:
carrent(string name, string transactionID, string vehicleID, double amount, int days, string returndate) : transaction(name, transactionID, vehicleID, amount)
{
this->days = days;
this->returndate = returndate;
}
//overrides the pure virtual function in base
    void process() override {
        cout << "\n[Processing Your Rental...]\n";
        Sleep(1000); // 1 second delay for effect
        cout << "\nYour Car Rental Cost is: $" << amount << endl;
        cout << "Enter Your Credit Card No: ";
        cin >> creditcardno;
        cout << "\nCongrats! You have rented the car! Receipt is generating...\n";
        Sleep(1500);
    }
//overrides the pure virtual function in base
    void receipt() override {
        cout << "\n------------------ RENTAL RECEIPT ------------------\n";
        cout << "Transaction ID  : " << transactionID << endl;
        cout << "Vehicle ID      : " << vehicleID << endl;
        cout << "Rental Days     : " << days << endl;
        cout << "Total Amount    : $" << amount << endl;
        cout << "Return Date     : " << returndate << endl;
        cout << "----------------------------------------------------\n";
        
    }
};

// Sale transaction
class carsale : public transaction
{
private:
//encapsulated private member
    bool warranty;

public:
//constructor for derived class
    carsale(string name, string transactionID, string vehicleID, double amount, bool warranty)
    : transaction(name, transactionID, vehicleID, amount) 
    {
        this->warranty = warranty;
    }
//overrides the pure virtual function in base
    void process() override {
        cout << "\n[Processing Your Purchase...]\n";
        Sleep(1000);
        cout << "\nYour Car Purchase Amount is: $" << amount << endl;
        cout << "Enter Your Credit Card No: ";
        cin >> creditcardno;
        cout << "\nCongrats! You have bought the car! Receipt is generating...\n";
        Sleep(1500);
    }
//overrides the pure virtual function in base
    void receipt() override {
        cout << "\n------------------ SALE RECEIPT ------------------\n";
        cout << "Transaction ID  : " << transactionID << endl;
        cout << "Vehicle ID      : " << vehicleID << endl;
        cout << "Sale Amount     : $" << amount << endl;
        cout << "Warranty        : " << (warranty ? "Included" : "No Warranty") << endl;
        cout << "--------------------------------------------------\n";

    }
};
// Abstract base class for Vehicles
class vehicle
{
protected:
    string type, id, make, model;
    int year;
    double price;
    bool found = false;

public:
//pure virtual functions
    virtual void searchcar() = 0;
    virtual void displayvehicles() = 0;
};

// Standard Car(inherits from vehicle base class)
class car : public vehicle
{
public:
    int choice()
    {
        int carchoice;
        cout << "\nSelect Car Type:\n";
        cout << "1. Standard\n";
        cout << "2. SUV\n";
        cout << "3. Electric Car\n";
        cout << "4. Luxury Car\n";
        cout << "Enter your choice: ";
        cin >> carchoice;
        return carchoice;
    }
//functions that override the base abstract class
    void displayvehicles()override
    {
        ifstream file("cars.txt");
        if (!file.is_open()) {
            cout << "Error opening car file!\n";
            return;
        }

        cout << "\n---- Available Cars ----\n";
        while (file >> type >> id >> make >> model >> year >> price) {
            cout << "Type: " << type << ", ID: " << id << ", Make: " << make
                 << ", Model: " << model << ", Year: " << year
                 << ", Price/day: $" << price << endl;
        }
        file.close();
    }
    //for converting all inputs intto lower case
    string lowercaseconversion(string str) {
        for (char& c : str)
            c = tolower(c);
        return str;
    }
//functions that override the base abstract class
    void searchcar()override
    {
        bool found = false;
        string MAKE;
        string MODEL;
        ifstream file("carsstock.txt");
        if (!file.is_open()) {
            cout << "Error opening car file!\n";
            return;
        }

        cout << "Enter Make OF Car:";
        cin >>MAKE;
        cout<<"Enter Model Of Car:";
        cin>>MODEL;
        MAKE = lowercaseconversion(MAKE);
        MODEL = lowercaseconversion(MODEL);
        while (file >> type >> id >> make >> model >> year >> price) {
            if (lowercaseconversion(make) == MAKE && lowercaseconversion(model) ==MODEL) {
                cout << "\nCar Found!\n";
                cout << "Type: " << type << ", ID: " << id << ", Make: " << make
                     << ", Model: " << model << ", Year: " << year
                     << ", Price/day: $" << price << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Car Is Not In STOCK!!.\n";
        }
        file.close();
    }
};

// SUV class that inherits from already derived class car
class suv : public car
{
public:
//methods that override the previous mnethods from derived
    void displayvehicles()
    {
        ifstream file("suv.txt");
        if (!file.is_open()) {
            cout << "Error opening SUV file!\n";
            return;
        }

        cout << "\n---- Available SUVs ----\n";
        while (file >> type >> id >> make >> model >> year >> price) {
            cout << "Type: " << type << ", ID: " << id << ", Make: " << make
                 << ", Model: " << model << ", Year: " << year
                 << ", Price/day: $" << price << endl;
        }
        file.close();
    }

   //for converting all inputs intto lower case
   string lowercaseconversion(string str) {
    for (char& c : str)
        c = tolower(c);
    return str;
}
//functions that override the base abstract class
void searchcar()override
{
    bool found = false;
    string MAKE;
    string MODEL;
    ifstream file("suvstock.txt");
    if (!file.is_open()) {
        cout << "Error opening car file!\n";
        return;
    }

    cout << "Enter Make OF Car:";
    cin >>MAKE;
    cout<<"Enter Model Of Car:";
    cin>>MODEL;
    MAKE = lowercaseconversion(MAKE);
    MODEL = lowercaseconversion(MODEL);
    while (file >> type >> id >> make >> model >> year >> price) {
        if (lowercaseconversion(make) == MAKE && lowercaseconversion(model) ==MODEL) {
            cout << "\nCar Found!\n";
            cout << "Type: " << type << ", ID: " << id << ", Make: " << make
                 << ", Model: " << model << ", Year: " << year
                 << ", Price/day: $" << price << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Car Is Not In STOCK!!.\n";
    }
    file.close();
}
};

// Electric Car that inherits from already derived class car
class electriccar : public car
{
public:
    void displayvehicles()
    {
        //methods that override the previous methods from derived
        ifstream file("electric.txt");
        if (!file.is_open()) {
            cout << "Error opening electric car file!\n";
            return;
        }

        cout << "\n---- Available Electric Cars ----\n";
        while (file >> type >> id >> make >> model >> year >> price) {
            cout << "Type: " << type << ", ID: " << id << ", Make: " << make
                 << ", Model: " << model << ", Year: " << year
                 << ", Price/day: $" << price << endl;
        }
        file.close();
    }

   //for converting all inputs intto lower case
   string lowercaseconversion(string str) {
    for (char& c : str)
        c = tolower(c);
    return str;
}
//functions that override the base abstract class
void searchcar()override
{
    bool found = false;
    string MAKE;
    string MODEL;
    ifstream file("electricstock.txt");
    if (!file.is_open()) {
        cout << "Error opening car file!\n";
        return;
    }

    cout << "Enter Make OF Car:";
    cin >>MAKE;
    cout<<"Enter Model Of Car:";
    cin>>MODEL;
    MAKE = lowercaseconversion(MAKE);
    MODEL = lowercaseconversion(MODEL);
    while (file >> type >> id >> make >> model >> year >> price) {
        if (lowercaseconversion(make) == MAKE && lowercaseconversion(model) ==MODEL) {
            cout << "\nCar Found!\n";
            cout << "Type: " << type << ", ID: " << id << ", Make: " << make
                 << ", Model: " << model << ", Year: " << year
                 << ", Price/day: $" << price << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Car Is Not In STOCK!!.\n";
    }
    file.close();
}
};

// Luxury Car that inherits from already derived class car
class luxurycar : public car
{
public:
    void displayvehicles()
    {
         //methods that override the previous methods from derived
        ifstream file("luxury.txt");
        if (!file.is_open()) {
            cout << "Error opening luxury car file!\n";
            return;
        }

        cout << "\n---- Available Luxury Cars ----\n";
        while (file >> type >> id >> make >> model >> year >> price) {
            cout << "Type: " << type << ", ID: " << id << ", Make: " << make
                 << ", Model: " << model << ", Year: " << year
                 << ", Price/day: $" << price << endl;
        }
        file.close();
    }

   //for converting all inputs intto lower case
   string lowercaseconversion(string str) {
    for (char& c : str)
        c = tolower(c);
    return str;
}
//functions that override the base abstract class
void searchcar()override
{
    bool found = false;
    string MAKE;
    string MODEL;
    ifstream file("luxurystock.txt");
    if (!file.is_open()) {
        cout << "Error opening car file!\n";
        return;
    }

    cout << "Enter Make OF Car:";
    cin >>MAKE;
    cout<<"Enter Model Of Car:";
    cin>>MODEL;
    MAKE = lowercaseconversion(MAKE);
    MODEL = lowercaseconversion(MODEL);
    while (file >> type >> id >> make >> model >> year >> price) {
        if (lowercaseconversion(make) == MAKE && lowercaseconversion(model) ==MODEL) {
            cout << "\nCar Found!\n";
            cout << "Type: " << type << ", ID: " << id << ", Make: " << make
                 << ", Model: " << model << ", Year: " << year
                 << ", Price/day: $" << price << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Car Is Not In STOCK!!.\n";
    }
    file.close();
}
};
// Abstract base class for user login
class userlogin
{
protected:
    string username;
    string password;

public:
    userlogin() {
        //default contructor so that no garbage value is provided
        username = "";
        password = "";
    }
    string getUsername() {
        return username;
    }
    //constructor to initialize username and password
    userlogin(string username, string password) {
        this->username = username;
        this->password = password;
    }

    static int displaymenu() {
        //menu to ask the user
        int choice;
        cout << "\n\n---------------------------------------------------------\n";
        cout << "             WELCOME TO CAR RENTAL & BUYING SYSTEM        \n";
        cout << "---------------------------------------------------------\n";
        cout << "1. Login as Customer\n";
        cout << "2. Register as Customer\n";
        cout << "3. Login as Admin\n";
        cout << "4. Exit\n";
        cout << "---------------------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        return choice;
    }

    virtual bool authenticate() = 0; // pure virtual function
};

// Admin login inherited from userlogin
class adminlogin : public userlogin
{
private:
//predefined admin data members in private
    string adminusername = "admin";
    string adminpassword = "admin123";

public:
//derived constructors
    adminlogin():userlogin() {

    }

    adminlogin(string username, string password) : userlogin(username, password) 
    {

    }

    bool authenticate() override {
        return (username == adminusername && password == adminpassword);
    }

    void adminWelcomePanel() {
        cout << "\n\n---------------------------------------------------------\n";
        cout << "                  ADMINISTRATOR PANEL                    \n";
        cout << "---------------------------------------------------------\n";
        cout << "1. Add New Vehicle\n";
        cout << "2. Remove Existing Vehicle\n";
        cout << "3. Logout\n";
        cout << "---------------------------------------------------------\n";
    }
//function to add vehicles
    void addvehicle()
    {
        string type, id, make, model;
        int year;
        double price;
        string filename;
        int choice;
        //asking user if he wants to update the stock file or standard display files
        cout<<"Would you like to add Car as a New stock or Reupdate Stocks:(1 or 2:)";
        cin>>choice;
        if(choice==1)
        {
        cout << "\n==== Add New Vehicle ====\n";
        //for file name depending on type
        cout << "Enter vehicle type (car/suv/electric/luxury): ";
        cin >> type;
        if (type == "car") filename = "cars.txt";
        else if (type == "suv") filename = "suv.txt";
        else if (type == "electric") filename = "electric.txt";
        else if (type == "luxury") filename = "luxury.txt";
        else {
            cout << "Invalid vehicle type!\n";
            return;
        }
        //asks user which model and name he wants to input the car as in the file
        cout << "Enter vehicle ID (e.g., C001): ";
        cin >> id;
        cout << "Enter make:(First Word Capital) ";
        cin >> make;
        cout << "Enter model:(First Word Capital) ";
        cin >> model;
        cout << "Enter year: ";
        cin >> year;
        cout << "Enter daily price ($): ";
        cin >> price;
//algorithm to write in file to add cars
        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file << type << " " << id << " " << make << " "
                 << model << " " << year << " " << price << endl;
            cout << "Vehicle added successfully!\n";
        } else {
            cout << "Error opening file!\n";
        }
        file.close();
    }
    else if(choice==2)
    {
        // same process but for stock files in each car
        cout << "\n==== Add New Vehicle ====\n";
        cout << "Enter vehicle type (car/suv/electric/luxury): ";
        cin >> type;
        if (type == "car") filename = "carsstock.txt";
        else if (type == "suv") filename = "suvstock.txt";
        else if (type == "electric") filename = "electricstock.txt";
        else if (type == "luxury") filename = "luxurystock.txt";
        else {
            cout << "Invalid vehicle type!\n";
            return;
        }
        cout << "Enter vehicle ID (e.g., C001): ";
        cin >> id;
        cout << "Enter make:(First Word Capital) ";
        cin >> make;
        cout << "Enter model:(First Word Capital) ";
        cin >> model;
        cout << "Enter year: ";
        cin >> year;
        cout << "Enter daily price ($): ";
        cin >> price;

        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file << type << " " << id << " " << make << " "
                 << model << " " << year << " " << price << endl;
            cout << "Vehicle added successfully!\n";
        } else {
            cout << "Error opening file!\n";
        }
        file.close();
    }
    }
    
//method to remove vehicles
void removevehicle() {
    string type, filename, id;
    const int MAX = 100;
    string data[MAX];
    int count = 0;

    cout << "\n==== Remove Vehicle ====\n";
    cout << "Enter vehicle type (cars/suv/electric/luxury): ";
    cin >> type;
    filename = type + "stock.txt";

    cout << "Enter vehicle ID to remove: ";
    cin >> id;

    ifstream file(filename);
    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    // Load all lines except the one to be removed
    string line;
    bool found = false;
    while (getline(file, line)) {
        if (line.find(id) == string::npos) {
            data[count++] = line;
        } else {
            found = true;
        }
    }
    file.close();

    if (!found) {
        cout << "Vehicle ID not found.\n";
        return;
    }

    // Overwrite original file with filtered lines
    ofstream out(filename);
    for (int i = 0; i < count; i++) {
        out << data[i] << '\n';
    }
    out.close();

    cout << "Vehicle removed successfully!\n";
}
};

// Customer login derived from userlogin
class customerlogin : public userlogin
{
    //constructors derived from base abstract class
public:
    customerlogin() : userlogin() {

    }

    customerlogin(string username, string password) : userlogin(username, password) {

    }
//derived method to override abstract class method
    bool authenticate() override {
        string storedUsername, storedPassword;

        cout << "\n==== Customer Login ====\n";
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
//reads the file based on username is username is wrong file doesnt exist so returns false as it is
        ifstream read(username + ".txt");
        if (!read.is_open()) {
            cout << "User not found!\n";
            return false;
        }

        getline(read, storedUsername);
        getline(read, storedPassword);
        read.close();
//returns true if user inputted correct username and pass
        return (storedUsername == username && storedPassword == password);
    }
//method to register the user
    bool registerUser() {
        cout << "\n==== Customer Registration ====\n";
        cout << "Enter New Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
//opens the username file based on the username inputted
        ofstream file(username + ".txt");
        if (!file.is_open()) {
            cout << "Error creating user file!\n";
            return false;
        }
//writes the username and pass in the file
        file << username << endl << password;
        file.close();

        cout << "Registration successful! Welcome, " << username << "!\n";
        return true;
    }
};
// Function to show loading effect
void loadingEffect(string text) {
    cout << text;
    for (int i = 0; i < 3; i++) {
        cout << ".";
        Sleep(500);
    }
    cout << endl;
}

// Transaction Operations for Customer
void transactionOperations(string username)
{
    bool transacting=true;
    int operationChoice1;
    do {
        //based on rent or buying a vehicle
        cout << "\n==== TRANSACTION OPERATIONS ====\n";
        cout << "1. Rent a Vehicle\n";
        cout << "2. Buy a Vehicle\n";
        cout << "3. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> operationChoice1;

        if (operationChoice1 == 3) break;

        if (operationChoice1 == 1) {
            char cont;
            string vehicleID;
            int days;
            string returnDate;
            double price;

            cout << "\n==== RENT VEHICLE ====\n";
            cout << "Enter Vehicle Make and Model: ";
            cin.ignore(); 
            getline(cin, vehicleID); 
            cout << "Enter rental days: ";
            cin >> days;
            cout << "Enter return date (DD-MM-YYYY): ";
            cin >> returnDate;
            cout << "Enter price: $";
            cin >> price;
            double dayprice=price/150;
            time_t now = time(0);
            string transactionID = to_string(now);

            carrent rental(username, transactionID, vehicleID, dayprice*days, days, returnDate);
            //carrent constructor and declares the parameters 
            loadingEffect("Processing Rental");
            rental.process();
            rental.receipt();
             cout << "\nDo you want to perform another transaction? (Y/N): ";
             cin >> cont;
             if (cont == 'N' || cont == 'n') {
               transacting = false;
                }
        }
        //same but for buying transaction
        else if (operationChoice1 == 2) {
            string vehicleID;
            double price;
            char warrantyOption;
            char cont;
            cout << "\n==== BUY VEHICLE ====\n";
            cout << "Enter Vehicle Make and Model: ";
            cin.ignore(); // Prevents leftover newline from previous cin
            getline(cin, vehicleID); // Allows spaces
            cout << "Enter total price: $";
            cin >> price;
            cout << "Include warranty (Y/N)? ";
            cin >> warrantyOption;

            time_t now = time(0);
            string transactionID = to_string(now);

            carsale sale(username, transactionID, vehicleID, price, (warrantyOption == 'Y' || warrantyOption == 'y'));
            loadingEffect("Processing Purchase");
            sale.process();
            sale.receipt();
            cout << "\nDo you want to perform another transaction? (Y/N): ";
            cin >> cont;
            if (cont == 'N' || cont == 'n') {
                transacting = false;
            }
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }
    } while (transacting==true);
}

// Main function
int main()
{
    int choice;
    do {
        choice = userlogin::displaymenu();

        if (choice == 1) {
            customerlogin customer;
            if (customer.authenticate()) {
                loadingEffect("Logging you in");
                cout << "\nWelcome back, valued customer!\n";

                int customerOption;
                do {
                //displays menu and asks user to choose
                    cout << "\n==== CUSTOMER MENU ====\n";
                    cout << "1. Display Vehicles\n";
                    cout << "2. Search Vehicle\n";
                    cout << "3. Rent/Buy Vehicle\n";
                    cout << "4. Logout\n";
                    cout << "Enter your choice: ";
                    cin >> customerOption;

                    if (customerOption == 1) {
                        car baseCar;
                        // asks user to enter his choice on what he wants
                        int type = baseCar.choice();
                        switch (type) {
                            //depending on type uses the overridden function of each calss
                            case 1: baseCar.displayvehicles(); break;
                            case 2: suv().displayvehicles(); break;
                            case 3: electriccar().displayvehicles(); break;
                            case 4: luxurycar().displayvehicles(); break;
                            default: cout << "Invalid vehicle type!\n";
                        }
                    }
                    else if (customerOption == 2) {
                        car baseCar;
                               // asks user to enter his choice on what he wants
                        int type = baseCar.choice();
                        switch (type) {
                            //depending on type uses the overridden function of each calss
                            case 1: baseCar.searchcar(); break;
                            case 2: suv().searchcar(); break;
                            case 3: electriccar().searchcar(); break;
                            case 4: luxurycar().searchcar(); break;
                            default: cout << "Invalid vehicle type!\n";
                        }
                    }
                    else if (customerOption == 3) {
                        //goes to transaction operations file which is actually abstraction process 
                        transactionOperations(customer.getUsername());
                    }
                    else if (customerOption != 4) {
                        cout << "Invalid choice!\n";
                    }
                } while (customerOption != 4);
            }
            else {
                cout << "Customer login failed!\n";
            }
        }
        else if (choice == 2) {
            //for registering the user
            customerlogin customer;
            customer.registerUser();
        }
        else if (choice == 3) {
            //for admin login 
            string name, pa;
            cout << "\n==== Admin Login ====\n";
            cout << "Enter Admin Username: ";
            cin >> name;
            cout << "Enter Admin Password: ";
            cin >> pa;

            adminlogin admin(name, pa);
            if (admin.authenticate()) {
                loadingEffect("Logging in as Admin");
            //authenticating as admin
                int adminOption;
                do {
                    admin.adminWelcomePanel();
                    cout << "Enter your choice: ";
                    cin >> adminOption;
//depending on choice adds or removes vehicles
                    if (adminOption == 1) {
                        admin.addvehicle();
                    }
                    else if (adminOption == 2) {
                        admin.removevehicle();
                    }
                    else if (adminOption != 3) {
                        cout << "Invalid choice! Try again.\n";
                    }
                } while (adminOption != 3);
            }
            else {
                cout << "Admin login failed!\n";
            }
        }
        else if (choice != 4) {
            cout << "Invalid menu choice!\n";
        }
    } while (choice != 4);

    cout << "\nThank you for using the Car Rental & Buying System. Goodbye!\n";
    return 0;
}
