#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
// #include "avl.h"

using namespace std;
using namespace std::chrono;
struct Transaction{
    int id;
    string type;//Deposit or withdraw
    float ammount;
    string date;
    Transaction* next;
};
class Account{
        private:
        int id;
        int pin;
        string name;
        string status;//Active ,Inactive or Blocked
        string type;//Savings Current or Default
        string password;
        float balance;
        Transaction* transactionHead;
        public:
        Account()
        {
            id = 0;
            pin = 0;
            name = "";
            password="";
            status = "active";
            type = "savings";
            balance = 0.0;
            transactionHead = nullptr;
        }//End of Default Constructor
        Account(int id, int pin, string name, string status, string type, float balance,string password)
        {
            this->id = id;
            this->pin = pin;
            this->name = name;
            this->password = password;
            this->status = status;
            this->type = type;
            this->balance = balance;
            this->transactionHead = nullptr;
        }//End of Parameterized Constructor

        void addTransaction(string type,float amount){
            if(type == "withdraw" && amount> balance){
                cout<<"Ghareeb Ul Ghurba"<<endl;
                return;
            }//End of if 
            else {
                this->balance -= amount;
            }//End of else
            if(type == "deposit"){
                this->balance += amount;
            }
            else {
                cout<<"Invalid Transaction Type"<<endl;
                return;
            }
            if(transactionHead == nullptr){
                transactionHead = new Transaction();
                transactionHead->id = this->id;
                transactionHead->type = type;
                transactionHead->ammount = amount;
                auto now= system_clock::now();
                auto in_time_t=system_clock::to_time_t(now);
                transactionHead->date = ctime(&in_time_t);
                transactionHead->next = nullptr;
            }
            else
            {
             Transaction* temp = transactionHead;
             while(temp->next != NULL){
                temp = temp->next;
             }
             temp->next = new Transaction();
            temp = temp->next;
            temp->id =this->id;
            temp->type = type;
            temp->ammount = amount;
            auto now= system_clock::now();
            auto in_time_t=system_clock::to_time_t(now);
            temp->date = ctime(&in_time_t);
            temp->next = nullptr;
            
            }//End of else
           
        }//End of addTransaction
        
};//End of Account Class