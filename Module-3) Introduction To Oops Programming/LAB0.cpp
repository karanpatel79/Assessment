#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <time.h>
#include <string.h>

// Class to represent ATM functionality
class ATM
{
private:
    int pin;
    double balance;
    double initialBalance;
    char name[50];
    char address[100];
    char branch[50];
    int accountNumber;

public:
    // Constructor to initialize account details
    ATM()
    {
        pin = 12345;
        balance = 20000.0;
        initialBalance = 60000.0;
        strcpy(name, "Rakesh Kharva");
        strcpy(address, "Mumbai");
        strcpy(branch, "Andheri");
        accountNumber = 5678;
    }

    // Function to display current date and time
    void displayDateTime()
    {
        // Get current time
        time_t now = time(NULL);
        // Convert to local time format
        char *datetime = ctime(&now);
        cout << "Current date : " << datetime;
    }

    // Function to display welcome screen
    void welcomeScreen()
    {
        clrscr();
        cout << "------------------------------------------" << endl;
        cout << "           WELCOME TO ATM                 " << endl;
        cout << "------------------------------------------" << endl;
        displayDateTime();
        cout << "------------------------------------------" << endl;
        cout << "Press 1 and Then Press Enter to Access Your Account Via Pin Number or" << endl;
        cout << "Press 0 and press Enter to get Help." << endl;
        cout << "------------------------------------------" << endl;
    }

    // Function to display help screen
    void helpScreen()
    {
        clrscr();
        cout << "------------------------------------------" << endl;
        cout << "          ATM ACCOUNT STATUS              " << endl;
        cout << "------------------------------------------" << endl;
        cout << "You must have the correct pin number to access this account." << endl;
        cout << "See your bank representative for assistance during bank opening hours" << endl;
        cout << "Thanks for your choice today!!" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Press any key to continue . . .";
        getch();
    }

    // Function to display exit message for wrong PIN
    void exitScreen()
    {
        clrscr();
        cout << "------------------------------------------" << endl;
        cout << "                 THANK YOU                " << endl;
        cout << "------------------------------------------" << endl;
        cout << "You had made your attempt which failed!!! No More attempts allowed!! Sorry!!!" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Press any key to continue . . .";
        getch();
    }

    // Function to verify PIN
    bool verifyPin()
    {
        clrscr();
        cout << "Enter Your Acc Pin Access Number! [only one attempt is allowed]" << endl;

        int enteredPin;
        cin >> enteredPin;

        return (enteredPin == pin);
    }

    // Function to display main menu
    void mainMenu()
    {
        clrscr();
        cout << "------------------------------------------" << endl;
        cout << "          ATM Main Menu Screen            " << endl;
        cout << "------------------------------------------" << endl;
        cout << "Enter [1] To Deposit Cash" << endl;
        cout << "Enter [2] To Withdraw Cash" << endl;
        cout << "Enter [3] To Balance Inquiry" << endl;
        cout << "Enter [0] to Exit ATM" << endl;
        cout << "------------------------------------------" << endl;
        cout << "PLEASE ENTER A SELECTION AND PRESS RETURN KEY: ";
    }

    // Function to deposit cash
    void depositCash()
    {
        clrscr();
        cout << "------------------------------------------" << endl;
        cout << "       ATM ACCOUNT DEPOSIT SYSTEM         " << endl;
        cout << "------------------------------------------" << endl;
        cout << "The Names of the Account Holders are : " << name << endl;
        cout << "The Account Holders' address is : " << address << endl;
        cout << "The Branch location is : " << branch << endl;
        cout << "Account number : " << accountNumber << endl;
        cout << "Present available balance : Rs. " << balance << endl;
        cout << "------------------------------------------" << endl;

        double amount;
        cout << "Enter the Amount to be Deposited Rs. ";
        cin >> amount;

        if (amount > 0)
        {
            balance += amount;
            cout << "Your new available Balanced Amount is Rs. " << balance << endl;
        }
        else
        {
            cout << "Invalid amount entered!" << endl;
        }

        cout << "Thank You!" << endl;
        cout << "Press any key to Return to the Main Menu";
        getch();
    }

    // Function to withdraw cash
    void withdrawCash()
    {
        clrscr();
        cout << "------------------------------------------" << endl;
        cout << "        ATM ACCOUNT WITHDRAWAL            " << endl;
        cout << "------------------------------------------" << endl;
        cout << "The Names of the Account Holders are : " << name << endl;
        cout << "The Account Holders' address is : " << address << endl;
        cout << "The Branch location is : " << branch << endl;
        cout << "Account number : " << accountNumber << endl;
        cout << "Present available balance : Rs. " << balance << endl;
        cout << "------------------------------------------" << endl;

        double amount;
        cout << "Enter the Amount to be Withdrawn Rs. ";
        cin >> amount;

        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Please collect your cash." << endl;
            cout << "Your new available Balanced Amount is Rs. " << balance << endl;
        }
        else if (amount > balance)
        {
            cout << "Insufficient Available Balance in your account." << endl;
        }
        else
        {
            cout << "Invalid amount entered!" << endl;
        }

        cout << "Thank You!" << endl;
        cout << "Press any key to Return to the Main Menu";
        getch();
    }

    // Function to check balance
    void balanceInquiry()
    {
        clrscr();
        cout << "------------------------------------------" << endl;
        cout << "        ATM ACCOUNT BALANCE INQUIRY       " << endl;
        cout << "------------------------------------------" << endl;
        cout << "The Names of the Account Holders are : " << name << endl;
        cout << "The Account Holders' address is : " << address << endl;
        cout << "The Branch location is : " << branch << endl;
        cout << "Account number : " << accountNumber << endl;
        cout << "Initial account balance : Rs. " << initialBalance << endl;
        cout << "Present available balance : Rs. " << balance << endl;
        cout << "------------------------------------------" << endl;
        cout << "Thank You!" << endl;
        cout << "Press any key to Return to the Main Menu";
        getch();
    }

    // Function to run the ATM application
    void run()
    {
        int choice;

        // Display welcome screen
        welcomeScreen();
        cin >> choice;

        if (choice == 0)
        {
            helpScreen();
            return;
        }
        else if (choice == 1)
        {
            if (verifyPin())
            {
                // PIN is correct, show main menu
                int menuChoice;
                do
                {
                    mainMenu();
                    cin >> menuChoice;

                    switch (menuChoice)
                    {
                    case 1:
                        depositCash();
                        break;
                    case 2:
                        withdrawCash();
                        break;
                    case 3:
                        balanceInquiry();
                        break;
                    case 0:
                        cout << "Thank you for using our ATM!" << endl;
                        break;
                    default:
                        cout << "Invalid choice! Please try again." << endl;
                        getch();
                    }
                } while (menuChoice != 0);
            }
            else
            {
                // PIN is incorrect
                exitScreen();
            }
        }
        else
        {
            cout << "Invalid choice!" << endl;
            getch();
        }
    }
};

// Main function
void main()
{
    clrscr();

    // Create ATM object
    ATM atmMachine;

    // Run the ATM application
    atmMachine.run();

    getch();
}