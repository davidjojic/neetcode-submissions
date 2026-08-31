class Solution {
public:
    void obilazak(TreeNode* root, int k, int& broj, int& sol){
        if(root == nullptr || broj >= k)
            return;

        obilazak(root->left, k, broj, sol);

        broj++;

        if(broj == k){
            sol = root->val;
            return;
        }

        obilazak(root->right, k, broj, sol);
    }

    int kthSmallest(TreeNode* root, int k) {
        int broj = 0;
        int sol = 0;

        obilazak(root, k, broj, sol);

        return sol;
    }
};