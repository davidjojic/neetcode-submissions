class Solution {
public:
    void res(vector<vector<int>>& sol, vector<int>& nums,
             int trensum, int stigao, vector<int>& tren){

        if(trensum == 0){
            sol.push_back(tren);
            return;
        }

        for(int i = stigao; i < nums.size(); i++){

            if(i > stigao && nums[i] == nums[i-1])
                continue;

            if(nums[i] > trensum)
                break;

            tren.push_back(nums[i]);

            res(sol, nums, trensum - nums[i], i + 1, tren);

            tren.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> sol;
        vector<int> tren;

        res(sol, candidates, target, 0, tren);

        return sol;
    }
};