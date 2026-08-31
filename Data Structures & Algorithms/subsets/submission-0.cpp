class Solution {
public:
    void ubaci(vector<vector<int>>&sol,int stigli,vector<int>&nums, vector<int>&tren){
        sol.push_back(tren);

        for(int i = stigli;i<nums.size();i++){
            tren.push_back(nums[i]);
            ubaci(sol,i+1,nums,tren);
            tren.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>sol;
        vector<int>tren;
        ubaci(sol,0,nums,tren);
        return sol;
    }
};
