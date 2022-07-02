#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void login();
void registration();
void forgot();


int main()
{
    int c;
    cout << "___________ welcome to the login page ___________________"<<endl;
    cout << "________________________   MENU   ________________________";
    cout << "                                                                 \n\n";
    cout << "|Press 1 to Login |" << endl;
    cout << "|Press 2 to Register |" << endl;
    cout << "|Press 3 to to Recover Password |" << endl;
    cout << "|Press 4 to Exit |" << endl;
    cout << "\n\Select one of the Items: ";
    cin >> c;
    cout<<endl;

    switch (c)
    {
    case 1:
        login();
        break;

    case 2:
        registration();
        break;

    case 3:
        forgot();
        break;

    case 4:
        cout<<"Thank you " <<endl;
        break;

    default:
        system("cls");
        cout << "Please select from the options given above " << endl;
        main();

    }
    system("pause>0");
}

void login()
{
    int count;
    string userId, password, id, pass;
    system("cls");
    cout << "Please enter username and password:" << endl;
    cout << "USERNAME: ";
    cin >> userId;
    cout << "PASSWORD: ";
    cin >> password;

    ifstream input("records.txt");

    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();
    if (count == 1)
    {
        cout << userId << "\n You are Welcome\n";
        main();
    }
    else {
        cout << "\Error, Please check your username and password ";
        main();
    }
}

void registration()
{
    string ruserId, rpassword, rid, rpass;
    system("cls");
    cout << "Enter Username : ";
    cin >> ruserId;
    cout << "Enter Password : ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << ruserId << ' ' << rpassword << endl;
    system("cls");
    cout << "Registration is successful";
    main();
}

void forgot()
{
    int option;
    system("cls");
    cout << "Forgot password?" << endl;
    cout << "Select 1 to search for account" << endl;
    cout << "Select 2 to go back to the main menu" << endl;
    cout << "Enter your choice:" ;
    cin >> option;

    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserId, sId, spass;
        cout << "Enter the username you remembered:";
        cin >> suserId;

        ifstream f2("records.txt");
        while (f2>>sId>>spass)
        {
            if (sId == suserId)
            {
                count = 1;
            }
        }
        f2.close();
        if (count == 1)
        {
            cout << "Your account is found" << endl;
            cout << "Your password is :" << spass;
            main();
        }
        else {
            cout << "Account isn't found";
            main();
        }
        break;
    }
    case 2:
    {
        main();
    }
    default:
        cout << "Wrong selection, Please try again" <<endl;
        forgot();
    }
}