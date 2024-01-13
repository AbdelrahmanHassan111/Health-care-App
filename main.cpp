/*The program is designed to ask the user about his/her current weight
and some body dimensions to calculate the average body fat
percentage. To help the user know his health status and whether his
health is changing to the better or getting worse. Also helping the user
to know the sugar levels of his body and blood pressure to be alerted of 
his health.*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define name_file  "data_siup_loin/"
void sign_up();
void log_in();
void log_out();
void menu() ;
void body_fat();
void muscle_percentage();
void water_percentage();

//main function
int main()
{
    system("color 0");
    system("cls");
    //log in && sign up code
    char n ;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                  WELCOME TO                                           |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                           HEALTH CARE APPLECATION                                     |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
    cout << "\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
    system("pause");
    system("cls");
    cout << "\n\t\t\t\t\t\t\tpress 1 to SignUp";
    cout << "\n\t\t\t\t\t\t\tpress 2 to LogIn\n";
    cin >> n;
    if (n == '1')
        sign_up();
    else if (n == '2')
        log_in();
    else
    {
        cout << "\t\t\t\t\t\t\tYou didn't choose 1 or 2....\n";
        cout << "\t\t\t\t\t\t\t\tTry again...\n";
        system("pause");
        //redirect to main function
        main();
    }
    //delete the screen contents
    system("cls");
    //--------------------------------------------

    //menu function
    menu();
    //--------------------------------------------

    return 0;
}
//sign up function
void sign_up()
{
    cout << "\n\t\t\t\t------------------------------signup-------------------------------\n\n";
    string mail, username, password, age , weight , gander;
    cout << "\t\t\t\t\t\t\tEnter your username: ";
    cin >> username;
    cout << "\t\t\t\t\t\t\tEnter your age: ";
    cin >> mail;
    cout << "\t\t\t\t\t\t\tEnter your gander: ";
    cin >> gander;
    cout << "\t\t\t\t\t\t\tEnter your mail: ";
    cin >> mail;
    cout << "\t\t\t\t\t\t\tEnter your password: ";
    cin >> password;
    // open file data

    ofstream ofile;
    ofstream obfile;
    string userfile = name_file + username + ".txt";
    ofile.open(userfile);
    ofile << username << endl << mail << endl << age << endl << gander << endl << password;
    ofile.close();
    obfile.close();
    cout << "\n\t\t\t\t\t\t   You are successfully registered:)\n";
    cout << "\t\t\t\t\t\t   ";
    system("pause");
    system("cls");
    //redirect to log in function
    log_in();
}
// log in function

void log_in()
{
    cout << "\n\t\t\t\t------------------------------login--------------------------------\n\n";
    string getpassword, getusername, password , username , getmail , getage , getgander;

    cout << "\t\t\t\t\t\t\tEnter your username: ";
    cin >> username;
    cout << "\t\t\t\t\t\t\tEnter your password: ";
    cin >> password;
    //verify from files

    ifstream getdatafile;
    string userfile = name_file + username + ".txt";
    getdatafile.open(userfile);
    if (getdatafile.is_open())
    {
        getline(getdatafile, getusername);
        getline(getdatafile, getmail);
        getline(getdatafile, getage);
         getline(getdatafile, getgander);
        getline(getdatafile, getpassword);
        if (username == getusername && password == getpassword) {
            cout << "\n\t\t\t\t\t\t   You are successfully logged in:)\n";
            cout << "\t\t\t\t\t\t   ";
             system("pause");
            getdatafile.close();
            system("cls") ;
            // redirect to menu function

            menu();
        }
        else {
            cout << "\n\t\t\t\t\t\t    Wrong username or password!\n";
            cout << "\t\t\t\t\t\t\t Please try Again.\n";
            log_in();
        }
        cout << endl;

    }
    else
    {
        cout << "\n\t\t\t\t\t\t\t Username not found.\n";
        cout << "\t\t\t\t\t\t\t   please sign up.\n";
        sign_up();
    }
}
void menu()
{
    char N ;
    cout << "\n\t\t\t\t---------------------------main menu-------------------------------\n";
    cout << "\t\t\t\t\t[1]measuring The Change of Body fat percentage\n";
    cout << "\t\t\t\t\t[2]Water Percentage\n";
    cout << "\t\t\t\t\t[3]Muscle percentage\n";
    cout << "\t\t\t\t\t[4]Log Out\n";
    cin >> N ;
    if (N == '1')
        {
        body_fat() ;
        }
    else if (N == '2')
    {
        water_percentage();
    }
        else if (N == '3')
        {
        muscle_percentage();
        }
        else if (N == '4')
        {
        log_out();
        }
    else
    {
        cout << "\t\t\t\t\t\t\tYou didn't choose 1 or 2....\n";
        cout << "\t\t\t\t\t\t\t\tTry again...\n";
        system("pause");
        main();
    }
    //delete the screen contents
    system("cls");
    //--------------------------------------------

    //menu function
    menu();
    //-------------------------------------    return 0;

}
void body_fat()
{
char G ;
double waist , hips , neck ,height , b_f_percentage , abdomen ;

cout << "\n\t\t\t\t\t\t\tChoose Your Gander\n";
    cout << "\n\t\t\t\t\t\t\[1] Male\n";
    cout << "\n\t\t\t\t\t\t\[2] Female\n";
    cin >> G;
     if (G == '1')
     {


        cout << "\n\t\t\t\t\t\t\tEnter your waist size \n";
        cin >> waist ;
        cout << "\n\t\t\t\t\t\t\tEnter your hips size \n";
        cin >> hips ;
        cout << "\n\t\t\t\t\t\t\tEnter your neck size \n";
        cin >> neck ;
        cout << "\n\t\t\t\t\t\t\tEnter your Height \n";
        cin >> height ;
        b_f_percentage = 163.205 * (waist + hips - neck) - 97.684 * (height) - 78.387 ;
        cout << "\n\t\t\t\t\t\t\tYour Body Fat Percentage is:" << b_f_percentage << endl ;
         system("pause");
     }
    else if (G == '2')
    {


        cout << "\n\t\t\t\t\t\t\tEnter your Abdomen size \n";
        cin >> abdomen ;
        cout << "\n\t\t\t\t\t\t\tEnter your neck size \n";
        cin >> neck ;
        cout << "\n\t\t\t\t\t\t\tEnter your Height \n";
        cin >> height ;
        b_f_percentage = 86.010 * (abdomen - neck) - 70.041 * (height) + 36.76 ;
        cout << "\n\t\t\t\t\t\t\tYour Body Fat Percentage is:" << b_f_percentage << endl ;
         system("pause");
    }
    else
    {
        cout << "\t\t\t\t\t\t\tYou didn't choose 1 or 2....\n";
        cout << "\t\t\t\t\t\t\t\tTry again...\n";
        system("pause");
        system("cls") ;
        body_fat() ;
    }
    //delete the screen contents
    system("cls");
}
void water_percentage()
{
char W ;
 double Age , Weight ,Height , w_p ;

cout << "\n\t\t\t\t\t\t\tChoose Your Gander\n";
    cout << "\n\t\t\t\t\t\t\[1] Male\n";
    cout << "\n\t\t\t\t\t\t\[2] Female\n";
    cin >> W;
     if (W == '1')
     {
        cout << "\n\t\t\t\t\t\t\tEnter your age \n";
        cin >> Age ;
        cout << "\n\t\t\t\t\t\t\tEnter your weight \n";
        cin >> Weight ;
        cout << "\n\t\t\t\t\t\t\tEnter your Height \n";
        cin >> Height ;
        w_p =2.447 - (0.09145 * Age) + (0.1074 * Height) + (0.3362 * Weight) ;
        cout << "\n\t\t\t\t\t\t\tYour Body water Percentage is:" << w_p << endl ;
         system("pause");
     }
    else if (W == '2')
    {
       cout << "\n\t\t\t\t\t\t\tEnter your age \n";
        cin >> Age ;
        cout << "\n\t\t\t\t\t\t\tEnter your weight \n";
        cin >> Weight ;
        cout << "\n\t\t\t\t\t\t\tEnter your Height \n";
        cin >> Height ;
        w_p = 2.097 + (0.1069 * Height) + (0.2466 * Weight) ;
        cout << "\n\t\t\t\t\t\t\tYour Body Water Percentage is:" << w_p << endl ;
         system("pause");
    }
    else
    {
        cout << "\t\t\t\t\t\t\tYou didn't choose 1 or 2....\n";
        cout << "\t\t\t\t\t\t\t\tTry again...\n";
        system("pause");
        system("cls") ;
        water_percentage() ;
    }
    //delete the screen contents
    system("cls");
}
void muscle_percentage()
{
    char X ;
double B_F_P , m_p ;

cout << "\n\t\t\t\t\t\t\tChoose Your Gander\n";
    cout << "\n\t\t\t\t\t\t\[1] Male\n";
    cout << "\n\t\t\t\t\t\t\[2] Female\n";
    cin >> X;
     if (X == '1')
     {
        cout << "\n\t\t\t\t\t\t\tEnter your Body Fat Percentage \n";
        cin >> B_F_P ;
        m_p = (100 - B_F_P) ;
        cout << "\n\t\t\t\t\t\t\t your muscle Percentage is:" << m_p << endl ;
         system("pause");
     }
    else if (X == '2')
    {
       cout << "\n\t\t\t\t\t\t\tEnter your Body Fat Percentage \n";
        cin >> B_F_P ;
         m_p = 100 - B_F_P ;
        cout << "\n\t\t\t\t\t\t\t your Muscle Percentage is:" << m_p << endl ;
         system("pause");


    }
    else
    {
        cout << "\t\t\t\t\t\t\tYou didn't choose 1 or 2....\n";
        cout << "\t\t\t\t\t\t\t\tTry again...\n";
        system("pause");
        system("cls") ;
        muscle_percentage() ;
    }
    //delete the screen contents
    system("cls");
}


    void log_out()
    {
        main();
    }
