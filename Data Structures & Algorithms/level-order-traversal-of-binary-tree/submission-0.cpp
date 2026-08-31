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
    void pretraga(TreeNode* root, int dubina,vector<vector<int>>&sol){
        if(root == nullptr)
            return;
        
        if(dubina > sol.size())
            sol.push_back({});
        sol[dubina-1].push_back(root->val);
        pretraga(root->left,(dubina+1),sol);
        pretraga(root->right,(dubina+1),sol);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>sol;
        pretraga(root,1,sol);
        return sol;
    }
};
