#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

class Node{
    private:
    string username;
    string password;
    int id;
    Node* left;
    Node* right;
    public:
    Node()
    {
        username=" ";
        password=" ";
        id=0;
        left=NULL;
        right=NULL;
    }
   Node(string uname,string pass, int id_num)
    {
        this->username = uname;
        this->password = pass;
        this->id = id_num;
        this->left=NULL;
        this->right=NULL;
    }//End of Constructor
    void setLeft(Node* lft)
    {
        this->left=lft;
    }//End of setLeft
    void setRight(Node* riht)
    {
        this->right=riht;
    }
    string getUsername(){
        return username;
    }//End of getUsername
    string getPassword(){
        return password;
    }//End of getPassword
    int getId(){
        return id;
    }//End of getID
    Node* getLeft()
    {
        return left;
    }//End of getLeft
    Node* getRight()
    {
        return right;
    }
};//End of Node Class

Node* insertInTree(Node* root, int id, string username, string password) {
    if (root == nullptr || root->getId() == 0) {
        return new Node(username, password, id);
    }

    if (id < root->getId()) {
        root->setLeft(insertInTree(root->getLeft(), id, username, password));
    } else if (id > root->getId()) {
        root->setRight(insertInTree(root->getRight(), id, username, password));
    } else {
        cout<<"This User Already Exists"<<endl;
        return root;
    }

    return root;
}//End of insert in tree

Node* searchInTree(Node* root,int id)
{
    while(root != NULL)
    {
        if(id == root->getId())
        {
            return root;
        }
        else if(root < root->getId())
        {
            root=root->getLeft();
        }
        else 
        {
            root=root->getRight();
        }

        return NULL;
    }
}//End of search in tree
void display(Node* root)
{
    if(root != NULL)
    {
        display(root->getLeft());
        cout<<"NAME:"<<root->getUsername()<<" ID:"<<root->getId()<<endl;
        display(root->getRight());
    }
}
void addData()
{
    Node* root = new Node();
    ifstream file;
    int id;
    string num;
    string pass;
    string name;
    file.open("admin.txt");
    if(!file.is_open())
    {
        cout<<"Error opening file."<<endl;
        return;
    }
    while(!file.eof())
    {
        
        try {
            getline(file,num,',');
            getline(file,name,',');
            getline(file,pass);
            cout<<"ID:"<<num<<endl;
            id=stoi(num);
            cout<<"ID:id:"<<id<<endl;
        } catch (const std::invalid_argument& e) {
            continue; // Skip this entry if ID is not valid
        }
         root=insertInTree(root,id,name,pass);
    }//End of while loop
    display(root);
    return;
}
