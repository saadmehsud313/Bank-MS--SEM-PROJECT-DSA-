#include <iostream>
#include <iomanip>
#include <string>
#include "linked_list.h"
#include "Account.h"
using namespace std;
template <typename T>
int genearteID(AVLTree<T>* root)
{
    if(root == nullptr)
    {
        cout<<"Tree is empty. Generating ID as 1."<<endl;
        return 1; // If tree is empty, start with ID 1
    }
    T* node = root->search(1001);
    while(node->getRight() !=NULL)
    {
        node = node->getRight();
    }
    cout<<"ID:"<< node->getId()  <<endl;
    return node->getId() + 1;;
}//Geneaates id for new user
template <typename C>
bool validateCredentials(AVLTree<C>* root,int id, string password)
{
   C* user = root->search(id);
   if(user == nullptr)
   {
       cout<<"User not found."<<endl;
       return false;
   }
    if(user->getPassword() == password)
    {
         cout<<"Credentials Validated Successfully."<<endl;
         return true;
    }
    else
    {
         cout<<"Invalid Credentials. Please try again."<<endl;
         return false;
    }
}//End of validate credentials function

int main()
{
    AVLTree<UserNode>* adminRoot = new AVLTree<UserNode>();
    AVLTree<UserNode>* staffRoot=new AVLTree<UserNode>();
    AVLTree<AccountNode>* accountRoot=new AVLTree<AccountNode>();
    int choice=1,choice1=1,cnt=3,id=0, pin=0, status=1; // status: 1 for active, 0 for inactive
    string username, password;
    int accountType=0;  
    string typ;
    adminRoot = addData(adminRoot,"admin.txt");
    adminRoot->displayInOrder();
    cout<<setfill('*')<<setw(100)<<"*"<<endl;
    staffRoot = addData(staffRoot,"staff.txt");
    adminRoot->displayInOrder();
    cout<<setfill('*')<<setw(100)<<"*"<<endl;
    accountRoot = addData(accountRoot,"accounts.txt");
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
                            id = genearteID(accountRoot);
                            cout<<"ID fo account is: "<<id<<endl;
                            cout<<"Enter Password for the account: ";
                            cin.ignore();
                            getline(cin, password);
                            cout<<"Enter PIN for the account: ";
                            cin>>pin;
                            cout<<"Select Account Type:"<<endl;
                            cout<<"1. Savings"<<endl;   
                            cout<<"2. Current"<<endl;
                            cout<<"3. Default"<<endl;
                            cin>>accountType;
                            switch(accountType)
                            {
                                case 1:
                                    typ = "Savings";
                                    break;
                                case 2:
                                    typ = "Current";
                                    break;
                                case 3:
                                    typ = "Default";
                                    break;
                                default:
                                    cout<<"Invalid account typ selected. Defaulting to Savings."<<endl;
                                    typ = "Savings";
                            }
                            accountRoot->insertNode(new AccountNode(id, username, password, "active", typ, 0.0, pin));
                            cout<<"Account created successfully with ID: "<<id<<endl;   
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
                } while(!validateCredentials(staffRoot , id , password ) && cnt != 0);
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
                    }//End of switch case
                    }//End of while loop
                break;
            case 0:
                cout<<"Exiting the program."<<endl;
                break;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
            
        cout << endl; // Add a new line for better readability
    }//End of switch case
    cnt=3;
}//End of while loop
    return 0;
}//End of main function
