#include <iostream>
#include <iomanip>
#include <string>
#include "avl.h"
using namespace std;

bool validateCredentials(Node* root,int id, string password)
{
    Node* temp=NULL;
    temp=searchInTree(root,id);
    if(temp == NULL)//Checks if the user exists or not 
    {
        cout<<"ID:"<< id <<" does not exist in the record."<<endl;
        return false;
    }//End of if
    else
    {
        if(temp->getPassword() == password )
        {
            cout<<"Welcome "<<temp->getUsername()<< " To Bank Management."<<endl;
            return true;
        }//end of nested id 
        else
        {
            cout<<"Wrong Password"<<endl;
            return false;
        }//End of nested else
    }//End of else
}//End of validate credentials function

int main()
{
    Node* adminRoot=new Node();
    Node* staffRoot=new Node();
    Node* accountRoot=new Node();
    int choice=1,choice1=1,cnt=3,id=0;
    string username, password;
    adminRoot = addData(adminRoot,"admin.txt");
    staffRoot = addData(staffRoot,"staff.txt");
    cout<<setfill('*')<<setw(100)<<"*"<<endl;
    cout<<"**********************************WELCOME TO BANK MANAGEMENT SYSTEM*********************************"<<endl;
    cout<<setfill('*')<<setw(100)<<"*"<<endl;
    while(choice!=0)
    {
        
        cout<<"    Please Select Your Role     "<<endl;
        cout<<"    1.For Admin      "<<endl;
        cout<<"    2. For Staff     "<<endl;
        cout<<"    3. For ATM Services     "<<endl;
        cout<<"    0.For Exit        "<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                do{
                cout<<"Remaining Attempts: "<<cnt<<endl;
                cout<<"Please Insert Your Credentials:"<<endl;
                cout<<"ID: ";
                cin>>id;
                cout<<"Password: ";
                cin.ignore();
                cin.clear();
                cin>>password;
                cnt--;
                cnt == 0 ? cout<<"You have exhausted all attempts. Exiting..."<<endl : cout<<endl; 
            } while(!validateCredentials(adminRoot,id, password) && cnt != 0);
                while(choice1!=0 && cnt != 0)
                {
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
                            cout<<"Enter The Name Of the Account (NAME USED IN CNIC):";
                            cin>>username;
                            cout<<"Generating ID.......";
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
                cout<<"ID: ";
                cin>>id;
                cout<<"Password: ";
                cin.clear();
                cin.ignore();
                getline(cin,password);
                cnt--;
                cnt == 0 ? cout<<"You have exhausted all attempts. Exiting..."<<endl : cout<<endl ;
                } while(!validateCredentials( staffRoot , id , password ) && cnt != 0);
                // Add staff functionality here
                while(choice1!=0 && cnt!=0)
                {
                    cout<<"Welcome "<<username<<",you are logged in as Staff."<<endl;
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
                while(choice1 != 0)
                {
                cout<<"Press 1 to withdraw cash."<<endl;
                cout<<"Press 2 to exit."<<endl;
                cout<<"Enter your choice: ";
                cin>>choice1;
                switch(choice1)
                {
                    case 1:
                        cout<<"Withdrawing cash from ATM..."<<endl;
                        // Add ATM withdraw functionality here
                        break;
                    case 2:
                        cout<<"Exiting ATM services."<<endl;
                        choice1 = 0; // Exit the ATM menu
                        break;
                    default:
                        cout<<"Invalid choice. Please try again."<<endl;
                }//End of while loop
                break;
            case 0:
                cout<<"Exiting the program."<<endl;
                break;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
        cout << endl; // Add a new line for better readability
    }//End of switch case
    cnt=3;
}//End of while loop
    return 0;
}//End of main function
