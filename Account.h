#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
// #include "avl.h"

using namespace std;

class UserNode{
    private:
    int id;
    string username;
    string password;
    UserNode* left;
    UserNode* right;
    int height;
    public:
    UserNode()  {
        id = 0;
        username = "";
        password = "";
        left = nullptr;
        right = nullptr;
        height = 1; // Default height for a new node
    } //End of  Default constructor
    UserNode(int id, string username, string password)  {
        this->id = id;
        this->username = username;
        this->password = password;
        left = nullptr;
        right = nullptr;
        height = 1; 
    }//End of parameterized constructor
    void setLeft(UserNode* lft) { 
        left = lft; 
    }
    void setRight(UserNode* riht) { 
        right = riht;
     } 
    UserNode* getLeft() { 
        return left;
     }
    UserNode* getRight() { 
        return right;
     }
    void setHeight(int h) {
         height = h; 
        }
    int getHeight() {
         return height;
         }
    string getUsername() { 
        return username; 
    }
    string getPassword() { 
        return password;
     }
    int getId() { 
        return id; 
    }

};//End of struct UserNode
class AccountNode{
        private: 
        int pin;
        int id;
        string type;
        string status; // Active, Inactive, Blocked
        string username;
        string password;
        float balance;
        int height;
        AccountNode* left;
        AccountNode* right;
        public:
        AccountNode()   // Call the base class constructor
        {
            username = "";
            password = "";
            id = 0;
            pin = 0;
            type = "savings";
            status = "active";
            balance = 0.0;           
            left = nullptr;
            right = nullptr;
        }//End of Default Constructor
        AccountNode(int id, string username, string password, string status = "active", string type = "savings", float bal = 0.0, int pin = 0 ) {
            this->username = username;
            this->password = password;
            this->id = id;
            this->pin = pin;
            this->type = type;
            this->status = status;
            this->balance = balance;
            this->username = username;
            this->password = password;
            this->id = id;
            height = 1;
        }//End of parameterized constructor
        int getPin() { return pin; }
        string getType() { return type; }
        string getStatus() { return status; }
        float getAccountBalance
        () { return balance; }
        void setBalance(float bal) { 
            if (bal >= 0) {
                balance = bal; 
            } else {
                cout << "Balance cannot be negative." << endl;
            }
        }//End of setBalance
        void setPin(int p) { pin = p; }
        void setLeft(AccountNode* lft) { left = lft; }
        void setRight(AccountNode* riht) { right = riht; }
        string getUsername() { return username; }
        string getPassword() { return password; }
        int getId() { return id; }  
        void setHeight(int h) { 
            height = h;
        }//End of setHeight
        int getHeight() { return height; }
        AccountNode* getLeft() { return left; }
        AccountNode* getRight() { return right; }

};//End of class AccountNode

template <typename T>
class AVLTree {
private:
    T* root;

    int height(T* node) {
        return node ? node->getHeight() : 0;
    }

    int getBalance(T* node) {
        return node ? height(node->getLeft()) - height(node->getRight()) : 0;
    }

    T* rightRotate(T* y) {
        T* x = y->getLeft();
        T* T2 = x->getRight();

        x->setRight(y);
        y->setLeft(T2);

        y->setHeight(1 + max(height(y->getLeft()), height(y->getRight())));
        x->setHeight(1 + max(height(x->getLeft()), height(x->getRight())));

        return x;
    }

    T* leftRotate(T* x) {
        T* y = x->getRight();
        T* T2 = y->getLeft();

        y->setLeft(x);
        x->setRight(T2);

        x->setHeight(1 + max(height(x->getLeft()), height(x->getRight())));
        y->setHeight(1 + max(height(y->getLeft()), height(y->getRight())));

        return y;
    }

    T* insert(T* node, T* newNode) {
        if (!node) return newNode;

        if (newNode->getId() < node->getId())
            node->setLeft(insert(node->getLeft(), newNode));
        else if (newNode->getId() > node->getId())
            node->setRight(insert(node->getRight(), newNode));
        else {
            cout << "Duplicate ID not allowed." << endl;
            return node;
        }

        node->setHeight(1 + max(height(node->getLeft()), height(node->getRight())));
        int balance = getBalance(node);

        if (balance > 1 && newNode->getId() < node->getLeft()->getId())
            return rightRotate(node);
        if (balance < -1 && newNode->getId() > node->getRight()->getId())
            return leftRotate(node);
        if (balance > 1 && newNode->getId() > node->getLeft()->getId()) {
            node->setLeft(leftRotate(node->getLeft()));
            return rightRotate(node);
        }
        if (balance < -1 && newNode->getId() < node->getRight()->getId()) {
            node->setRight(rightRotate(node->getRight()));
            return leftRotate(node);
        }

        return node;
    }

    void inorder(T* node) {
        if (node) {
            inorder(node->getLeft());
            cout << "ID: " << node->getId() << ", Username: " << node->getUsername() ;
            cout << ", Password: " << node->getPassword() << endl;
            inorder(node->getRight());
        }
    }

public:
    AVLTree() { root = nullptr; }

    void insertNode(T* newNode) {
        root = insert(root, newNode);
    }

    void displayInOrder() {
        inorder(root);
    }

    T* search(int id) {
        T* current = root;
        while (current) {
            if (id == current->getId()) return current;
            else if (id < current->getId()) current = current->getLeft();
            else current = current->getRight();
        }
        return nullptr;
    }
};


AVLTree<UserNode>* addData(AVLTree<UserNode>* root, const string& filename) {
    ifstream file;
    file.open(filename);
    if(!file.is_open()){
        cout<<"Error Opening FIle:" << filename<<endl;
        return root;
    }//End of if 
    stringstream ss;
    string line,username, password,idStr;
    int id;
    while(getline(file, line))
    {
        ss.clear();
        ss.str(line);
        try{
            getline(ss, idStr, ',');
            getline(ss, username, ',');
            getline(ss, password, ',');
            id = stoi(idStr);
            // Insert the new user into the AVL tree
            root->insertNode(new UserNode(id, username, password));
        }catch(exception& e)
        {
            cout << "Error reading data from file: " << filename << endl;
            cout << "Skipping invalid line." << endl;
            continue; // Skip to the next line if there's an error
        }
    }//End of while
    file.close();
    cout << "Data from " << filename << " has been added to the tree." << endl;
    return root;
}//End of addData


AVLTree<AccountNode>* addData(AVLTree<AccountNode>* root, const string& filename) {
    ifstream file;
    file.open(filename);
    if(!file.is_open()){
        cout<<"Error Opening FIle:" << filename<<endl;
        return root;
    }//End of if 
    stringstream ss;
    string line,username, password, type, status,idStr, pinStr,balanceStr;
    int id, pin;
    float balance;
    while(getline(file, line))
    {
        ss.clear();
        ss.str(line);
        cout<<"EXECUTING WHILE LOOP IN ADD DATA"<<endl;
        try{
            getline(ss, idStr, ',');
            getline(ss, pinStr, ',');
            getline(ss, username, ',');
            getline(ss, password, ',');
            getline(ss, type, ',');
            getline(ss, balanceStr, ',');
            getline(ss, status,',');
            id = stoi(idStr);
            pin = stoi(pinStr);
            balance = stof(balanceStr);
            root->insertNode(new AccountNode(id, username, password, status, type, balance, pin));
        
        }catch(exception& e)
        {
            cout << "Error reading data from file: " << filename << endl;
            cout << "Skipping invalid line." << endl;
            cout<<"ERRO"<<e.what()<<endl;
            cout<<"Error in line: "<<line<<endl;
            continue; // Skip to the next line if there's an error
        }
    }//End of while
    file.close();
    cout << "Data from " << filename << " has been added to the tree." << endl;
    return root;
}//End of addData