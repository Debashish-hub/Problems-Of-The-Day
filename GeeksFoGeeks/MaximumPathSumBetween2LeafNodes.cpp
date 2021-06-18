// Maximum Path Sum between 2 Leaf Nodes 

// Given a binary tree in which each node element contains a number. Find the maximum possible 
// sum from one leaf node to another leaf node.

// NOTE: Here Leaf node is a node which is connected to exactly one different node.

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:

     int maxPathSumUtil(Node *root, int &res) {
        if (root == NULL)
            return 0;
        if (!root->left && !root->right)
            return root->data;

        int ls = maxPathSumUtil(root->left, res);
        int rs = maxPathSumUtil(root->right, res);

        if (root->left && root->right) {
            res = max(res, ls + rs + root->data);
            return max(ls, rs) + root->data;
        }
        return (!root->left) ? rs + root->data : ls + root->data;
    }
public:
    int maxPathSum(Node *root) {
        int res = INT_MIN;
        int h = maxPathSumUtil(root, res);
        if (root->left == NULL || root->right == NULL)
        {
            res = max(res, h);
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.maxPathSum(root) << "\n";
    }
    return 0;
}  // } Driver Code Ends