//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    Node *treeFromString(string str){
        // code here
        string cur = "";
        int i = 0, num, n = str.length();
        while (i < n && str[i] != '(' && str[i] != ')') {
            cur += str[i++];
        }
        num = stoi(cur);
        Node *root = new Node(num);
        stack<Node*> st;
        st.push(root);
        for (; i < n; i++) {
            if (str[i] == '(') {
                cur = "";
                while (str[i + 1] != '(' && str[i + 1] != ')') {
                    i++;
                    cur += str[i];
                }
                num = stoi(cur);
                Node *temp = new Node(num);
                if (!st.top()->left)
                    st.top()->left = temp;
                else
                    st.top()->right = temp;
                st.push(temp);
            }
            else if (str[i] == ')')
                st.pop();
        }
        return root;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends