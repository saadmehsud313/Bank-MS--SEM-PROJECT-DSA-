#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

class Node {
private:
    string username;
    string password;
    int id;
    int height;
    Node* left;
    Node* right;

public:
    Node() : username(""), password(""), id(0), height(1), left(nullptr), right(nullptr) {}

    Node(string uname, string pass, int id_num)
        : username(uname), password(pass), id(id_num), height(1), left(nullptr), right(nullptr) {}

    void setLeft(Node* lft) { left = lft; }
    void setRight(Node* riht) { right = riht; }

    string getUsername() { return username; }
    string getPassword() { return password; }
    int getId() { return id; }

    Node* getLeft() { return left; }
    Node* getRight() { return right; }

    void setHeight(int h) { height = h; }
    int getHeight() { return height; }
};

int getHeight(Node* node) {
    return node ? node->getHeight() : 0;
}

int getBalance(Node* node) {
    return node ? getHeight(node->getLeft()) - getHeight(node->getRight()) : 0;
}

Node* rightRotate(Node* y) {
    Node* x = y->getLeft();
    Node* T2 = x->getRight();

    x->setRight(y);
    y->setLeft(T2);

    y->setHeight(1 + max(getHeight(y->getLeft()), getHeight(y->getRight())));
    x->setHeight(1 + max(getHeight(x->getLeft()), getHeight(x->getRight())));

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->getRight();
    Node* T2 = y->getLeft();

    y->setLeft(x);
    x->setRight(T2);

    x->setHeight(1 + max(getHeight(x->getLeft()), getHeight(x->getRight())));
    y->setHeight(1 + max(getHeight(y->getLeft()), getHeight(y->getRight())));

    return y;
}

Node* insertInTree(Node* root, int id, string username, string password) {
    if (!root) return new Node(username, password, id);

    if (id < root->getId()) {
        root->setLeft(insertInTree(root->getLeft(), id, username, password));
    } else if (id > root->getId()) {
        root->setRight(insertInTree(root->getRight(), id, username, password));
    } else {
        cout << "This User Already Exists" << endl;
        return root;
    }

    // Update height
    root->setHeight(1 + max(getHeight(root->getLeft()), getHeight(root->getRight())));

    int balance = getBalance(root);

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
}

Node* searchInTree(Node* root, int id) {
    while (root) {
        if (id == root->getId()) return root;
        else if (id < root->getId()) root = root->getLeft();
        else root = root->getRight();
    }
    return nullptr;
}

void display(Node* root) {
    if (root) {
        display(root->getLeft());
        cout << "NAME: " << root->getUsername() << " ID: " << root->getId() << endl;
        display(root->getRight());
    }
}

Node* addData(Node* temp, string fileName) {
    Node* root = temp;
    ifstream file;
    int id;
    string num, pass, name;

    file.open(fileName);
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return nullptr;
    }

    while (getline(file, num, ',') && getline(file, name, ',') && getline(file, pass)) {
        try {
            id = stoi(num);
        } catch (const invalid_argument& e) {
            continue; // skip if ID is invalid
        }
        root = insertInTree(root, id, name, pass);
    }

    file.close();
    return root;
}
