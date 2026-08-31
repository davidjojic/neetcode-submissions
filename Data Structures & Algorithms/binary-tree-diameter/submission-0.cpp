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
    int nadji(TreeNode* root,int &maki){
        if(root == nullptr)
            return 0;
        int levi = nadji(root->left,maki);
        int desni = nadji(root->right,maki);
        maki=max(levi+desni,maki);
        return max(levi+1,desni+1);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maki = 0;
        nadji(root,maki);
        return maki;
    }
};
