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
    bool proveri(TreeNode* root, int minv,int maxv){
        if(root == nullptr)
            return true;
        if(root->val <= minv || root->val >= maxv)
            return false;
        return proveri(root->left,minv,root->val) && proveri(root->right,root->val,maxv);
    }
    bool isValidBST(TreeNode* root) {
        return proveri(root,numeric_limits<int>::min(),numeric_limits<int>::max());
    }
};
