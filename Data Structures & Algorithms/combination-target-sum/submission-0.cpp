class Solution {
public:
    void res(vector<vector<int>>&sol, vector<int>&nums,int trensum, int stigao,vector<int>&tren){
        if(trensum< 0)
            return;
        if(trensum == 0){
            sol.push_back(tren);
            return;
        }
        for(int i = stigao;i<nums.size();i++){
            if(nums[i] > trensum)
                break;
            tren.push_back(nums[i]);
            res(sol,nums,trensum-nums[i],i,tren);
            tren.pop_back();

        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> sol;
        sort(nums.begin(),nums.end());
        vector<int>tren;
        res(sol,nums,target,0,tren);
        return sol;
    }
};
