#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
// #include "avl.h"

using namespace std;


class AccountNode{
        private:
        int id;
        int pin;
        string type;
        string status; // Active, Inactive, Blocked
        string username;
        string password;
        AccountNode* left;
        AccountNode* right;
        int height;
        float balance;
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
        AccountNode(string username, string password, int id) {
            this->username = username;
            this->password = password;
            this->id = id;
        }//End of parameterized constructor
        AccountNode(int pin ,string type,string status, float balance ) {
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
        void setLeft(Node* lft) { left = lft; }
        void setRight(Node* riht) { right = riht; }
        string getUsername() { return username; }
        getPassword() { return password; }
        int getId() { return id; }  
        Node* getLeft() { return left; }
        Node* getRight() { return right; }

};//End of class AccountNode

int getAccountHeight(AccountNode* node) {
    return node ? node->getAccountHeight() : 0;
}//End of getAccountHeight

int getAccountBalance
(AccountNode* node) {
    return node ? getAccountHeight(node->getLeft()) - getAccountHeight(node->getRight()) : 0;
}//End of getAccountBalance


AccountNode* rightRotate(AccountNode* y) {
    AccountNode* x = y->getLeft();
    AccountNode* T2 = x->getRight();

    x->setRight(y);
    y->setLeft(T2);

    y->setHeight(1 + max(getAccountHeight(y->getLeft()), getAccountHeight(y->getRight())));
    x->setHeight(1 + max(getAccountHeight(x->getLeft()), getAccountHeight(x->getRight())));

    return x;
}//End of rightRotate

AccountNode* leftRotate(AccountNode* x) {
    AccountNode* y = x->getRight();
    AccountNode* T2 = y->getLeft();

    y->setLeft(x);
    x->setRight(T2);

    x->setHeight(1 + max(getAccountHeight(x->getLeft()),  getAccountHeight(x->getRight())));
    y->setHeight(1 + max(getAccountHeight(y->getLeft()), getAccountHeight(y->getRight())));

    return y;
}//End of leftRotate

AccountNode* insertAccountInTree(AccountNode* root, int id, string username, string password, string status = "active", string type = "savings", float balance = 0.0, int pin = 0) 
{
    if (!root){ 
        root = new AccountNode();
        root->Node::Node(username, password, id);
        root->AccountNode::AccountNode(pin, type, status, balance);
        return root;
    }//End of if
    if (id < root->getId()) {
        root->setLeft(insertInTree(root->getLeft(), id, username, password));
    } else if (id > root->getId()) {
        root->setRight(insertInTree(root->getRight(), id, username, password));
    } else {
        cout << "This User Already Exists" << endl;
        return root;
    }

    // Update height
    root->setHeight(1 + max(getAccountHeight(root->getLeft()), getAccountHeight(root->getRight())));

    int balance = getAccountBalance
    (root);

    // Balance cases
    if (balance > 1 && id < root->getLeft()->getId())
        return rightRotate(root);

    if (balance < -1 && id > root->getRight()->getId())
        return leftRotate(root);

    if (balance > 1 && id > root->getLeft()->getId()) {
        root->setLeft(leftRotate(root->getLeft()));
        return rightRotate(root);
    }

    if (balance < -1 && id < root->getRight()->getId()) {
        root->setRight(rightRotate(root->getRight()));
        return leftRotate(root);
    }

    return root;
}//End of insertAccountInTree

AccountNode* searchInTree(AccountNode* root, int id) {
    while (root) {
        if (id == root->getId()) return root;
        else if (id < root->getId()) root = root->getLeft();
        else root = root->getRight();
    }
    return nullptr;
}//End of searchInTree

void display(AccountNode* root) {
    if (root) {
        display(root->getLeft());
        cout << "NAME: " << root->getUsername() << " ID: " << root->getId() << endl;
        display(root->getRight());
    }
}//End of display

