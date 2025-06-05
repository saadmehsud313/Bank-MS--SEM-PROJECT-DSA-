#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

bool validateCredentials(string username, string password,string pos)
{
    cout<<"Position:"<<pos<<endl;
    string usn="Saad",pass="1234";

    if(pos== "admin")
    {
        cout<<"Admin Selected"<<endl;

    }
    else if(pos == "staff")
    {
        cout<<"Staff Selected"<<endl;
    }
    else if(pos == "atm")
    {
        cout<<"ATM Selected"<<endl;
    }
    else{
        cout<<"Position Not  Recognized"<<endl;
    }
    return true;
}

int main()
{
    char ch='*';
    int choice=1,choice1=1,cnt=3;
    string username, password;
    cout<<"**********************************wELCOME TO BANK MANAGEMENT SYSTEM**********************************"<<endl;
    cout<<setfill(ch)<<setw(120)<<"*"<<endl;
    while(choice!=0)
    {
        cout<<"    Please Select Your Role     "<<endl;
        cout<<"    1.For Admin      "<<endl;
        cout<<"    2. For Staff     "<<endl;
        cout<<"    3. For ATM Services     "<<endl;
        cout<<"     0.For Exit        "<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                do{
                cout<<"Remaining Attempts: "<<cnt<<endl;
                cout<<"Please Insert Your Credentials:"<<endl;
                cout<<"Username: ";
                cin>>username;
                cout<<"Password: ";
                cin>>password;
                cnt--;
                cnt == 0 ? cout<<"You have exhausted all attempts. Exiting..."<<endl : cout<<endl; 
            } while(!validateCredentials(username, password,"admin") && cnt != 0);
                while(choice1!=0)
                {
                    cout<<"Welcome "<<username<<",you are logged in as Admin."<<endl;
                    cout<<"Please select an operation you want to perform :"<<endl;
                    cout<<"Press 1 to Create new account."<<endl;
                    cout<<"Press 2 to Delete existing account."<<endl;
                    cout<<"Press 3 to search for an account."<<endl;
                    cout<<"Press 4 to View all accounts."<<endl;
                    cout<<"Press 5 to Update account details."<<endl;
                    cout<<"Press 6 to view logs of deleted accounts."<<endl;
                    cout<<"Press 0 to Logout."<<endl;
                    cout<<"Enter your choice: ";
                    cin>>choice1;
                    switch(choice1)
                    {
                        case 1:
                            cout<<"Creating new account..."<<endl;
                            // Add account creation functionality here
                            break;
                        case 2:
                            cout<<"Deleting existing account..."<<endl;
                            // Add account deletion functionality here
                            break;
                        case 3:
                            cout<<"Searching for an account..."<<endl;
                            // Add account search functionality here
                            break;
                        case 4:
                            cout<<"Viewing all accounts..."<<endl;
                            // Add view all accounts functionality here
                            break;
                        case 5:
                            cout<<"Updating account details..."<<endl;
                            // Add update account details functionality here
                            break;
                        case 6:
                            cout<<"Viewing logs of deleted accounts..."<<endl;
                            // Add view logs funtionality here 
                            break;
                        case 0:
                            cout<<"Logging out..."<<endl;
                            choice1 = 0; // Exit the admin menu
                            break;
                        default:
                            cout<<"Invalid choice. Please try again."<<endl;
                    }
                }
                
                break;
            case 2:
                cout<<"You selected Staff."<<endl;
                do{
                cout<<"Remaining Attempts: "<<cnt<<endl;
                cout<<"Please Insert Your Credentials:"<<endl;
                cout<<"Username: ";
                cin>>username;
                cout<<"Password: ";
                cin>>password;
                cnt--;
                cnt == 0 ? cout<<"You have exhausted all attempts. Exiting..."<<endl : cout<<endl ;
                } while(!validateCredentials(username, password,"staff") && cnt != 0);
                // Add staff functionality here
                while(choice1!=0)
                {
                    cout<<"Welcome "<<username<<",you are logged in as Admin."<<endl;
                    cout<<"Please select an operation you want to perform :"<<endl;
                    cout<<"Press 1 to Check Account."<<endl;
                    cout<<"Press 2 to Withdraw cash."<<endl;
                    cout<<"Press 3 to deposit cash."<<endl;
                    cout<<"Press 4 to view logs of selected account."<<endl;
                    cout<<"Press 0 to Logout."<<endl;
                    cout<<"Enter your choice: ";
                    cin>>choice1;
                    switch(choice1)
                    {
                        case 1:
                            cout<<"Checking account..."<<endl;
                            // Add check account functionality here
                            break;
                        case 2:
                            cout<<"Withdrawing cash..."<<endl;
                            // Add withdraw cash functionality here
                            break;
                        case 3:
                            cout<<"Depositing cash..."<<endl;
                            // Add deposit cash functionality here
                            break;
                        case 4:
                            cout<<"Viewing logs of selected account..."<<endl;
                            // Add view logs functionality here
                            break;
                        case 0:
                            cout<<"Logging out..."<<endl;
                            choice1 = 0; // Exit the staff menu
                            break;
                        default:
                            cout<<"Invalid choice. Please try again."<<endl;
                    }
                }
                break;
            case 3:
                cout<<"You selected ATM Services."<<endl;
                // Add ATM services functionality here
                break;
            case 0:
                cout<<"Exiting the program."<<endl;
                break;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
        cout << endl; // Add a new line for better readability
    }
    return 0;
}
