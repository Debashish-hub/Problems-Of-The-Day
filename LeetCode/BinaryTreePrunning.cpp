// Binary Tree Pruning

// Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.
// A subtree of a node node is node plus every node that is a descendant of node.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root){
            return NULL;
        }
        TreeNode* left = pruneTree(root->left);
        TreeNode* right = pruneTree(root->right);
        root->left = left;
        root->right= right;
        if(root->left == NULL && root->right==NULL && root->val==0){
            root=NULL;
            return NULL;
        }
        return root;
    }
};