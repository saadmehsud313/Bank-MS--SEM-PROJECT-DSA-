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
    void setRight(Node* right)
    {
        this->right=right;
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

void insertInTree(Node* root,int id,string username, string password)
{
    Node* temp=root;

    if(root == NULL)
    {
        root=new Node(username,password,id);
        return;
    }
    while(root != NULL)
    {
        temp=root;
        if(id == root->getId())
        {
            cout<<"This id already exists."<<endl;
            return;
        }
        else if(id<root->getId())
        {
            root = root->getLeft();
        }
        else
        {
            root = root->getRight();
        }
    }//End of while
    id<temp->getId() ? temp->setLeft(new Node(username,password,id)) : temp->setRight(new Node(username,password,id));

    return;
}//End of insertInTree
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
    Node* root = NULL;
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
            getline(file,pass,',');
        } catch (const std::invalid_argument& e) {
            cout << "Invalid ID format in file: " << num << endl;
            continue; // Skip this entry if ID is not valid
        }
        insertInTree(root,stoi(num),name,pass);
    }
    display(root);
    return;
}
