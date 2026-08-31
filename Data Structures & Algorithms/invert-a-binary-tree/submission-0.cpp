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
    void okreni(TreeNode* root){
        if(root == nullptr)
            return;
        TreeNode* levo = root->left;
        TreeNode* desno = root->right;
        okreni(levo);
        okreni(desno);
        root->left = desno;
        root->right = levo;
    }
    TreeNode* invertTree(TreeNode* root) {
        okreni(root);
        return root;
    }
};
