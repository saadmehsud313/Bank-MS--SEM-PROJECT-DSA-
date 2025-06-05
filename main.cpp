#include <iostream>
#include <iomanip>

using namespace std;

bool validdateCredentials(string usename, string password,string pos)
{
    string usn="Saad",pass="1234";

    if(usename==usn && password==pass)
    {
        cout<<"Login Successful"<<endl;
        return true;
    }
    else
    {
        cout<<"Invalid Credentials"<<endl;
        return false;
    }
}

int main()
{
    int choice=1,choice1=1,cnt=3;
    string username, password;
    cout<<"**********************************wELCOME TO BANK MANAGEMENT SYSTEM**********************************"<<endl;
    cout<<"********************************************************************************************************** \n\n\n"<<endl;
    while(choice!=0)
    {
        cout<<setfill('*')<<setw(60)<<"    Please Select Your Role     "<<setfill('*')<<setw(50)<<'*'<<endl;
        cout<<setfill(' ')<<setw(50)<<"1.For Admin      "<<endl;
        cout<<setfill(' ')<<setw(50)<<"2. For Staff     "<<endl;
        cout<<setfill(' ')<<setw(57)<<"3. For ATM Services     "<<endl;
        cout<<setfill(' ')<<setw(51)<<"  0.For Exit        "<<endl;
        cout<<setfill(' ')<<setw(52)<<"Enter your choice: ";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                do{
                cout<<setfill(' ')<<setw(50)<<"Remaining Attempts: "<<cnt<<endl;
                cout<<setfill(' ')<<setw(50)<<"Please Insert Your Credentials:"<<endl;
                cout<<setfill(' ')<<setw(50)<<"Username: ";
                cin>>username;
                cout<<setfill(' ')<<setw(50)<<"Password: ";
                cin>>password;
                cnt--;
                } while(!validdateCredentials(username, password,"admin") && cnt != 0);
                
                break;
            case 2:
                cout<<"You selected Staff."<<endl;
                // Add staff functionality here
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
