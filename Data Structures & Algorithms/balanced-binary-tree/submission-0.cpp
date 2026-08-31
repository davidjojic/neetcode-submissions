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
    int balanced(TreeNode* root,bool &sol){
        if(!sol)
            return 0;
        if(root == nullptr)
            return 0;
        
        int levi = balanced(root->left,sol);
        int desni = balanced(root->right,sol);

        if(abs(levi-desni) > 1){
            sol=false;
            return 0;
        }

        return max(levi,desni)+1;
    }
    bool isBalanced(TreeNode* root) {
        bool sol = true;
        balanced(root,sol);
        return sol;
    }
};
