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
    void pretraga(TreeNode*root, int maxElement,int &sol){
        if(root == nullptr)
            return;
        if(root->val >= maxElement){
            sol++;
        }
        pretraga(root->left,max(maxElement,root->val),sol);
        pretraga(root->right,max(maxElement,root->val),sol);

    }
    int goodNodes(TreeNode* root) {
        int sol = 0;
        pretraga(root,-101,sol);
        return sol;
    }
};
