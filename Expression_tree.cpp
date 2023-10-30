// Making expression tree from post-fix expression
#include <iostream>
#include <string>
using namespace std;

// Struct for node of expression tree
struct Node
{
    char data;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(char data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};


// Function to check if the data is operator or operand
bool isOperator(char c)
{
    return (c == '^' || c == '/' || c == '*' || c == '+' || c == '-');
}


// Function to create tree out of postfix expression
Node *constructExpression(string postfix)
{
    if (postfix.length() == 0)
        return nullptr;

    // Empty stack for tree
    Node *myStack[100];
    int top = -1;

    for (char c: postfix)
    {
        // If current character is an operator
        if (isOperator(c))
        {
            // Pop two nodes and attach to operator
            Node *x = myStack[top--];
            Node *y = myStack[top--];

            Node *newNode = new Node(c, y, x);

            // Push the new node in stack
            myStack[++top] = newNode;
        }

        // If current character is variable push its node to stack
        else
        {
            Node *newNode = new Node(c, nullptr, nullptr);
            myStack[++top] = newNode;
        }
    }
    return myStack[top];
}


// Function for inorder traversal to get infix expression
void inOrder(Node *root)
{
    if (root == nullptr)
        return;

    if (isOperator(root->data))
        cout << "(";

    inOrder(root->left);
    cout << root->data;
    inOrder(root->right);

    if (isOperator(root->data))
        cout << ")";
}


int main(void)
{
    string postfix;
    cin >> postfix;

    Node *root = constructExpression(postfix);

    inOrder(root);
    cout << endl;
}
