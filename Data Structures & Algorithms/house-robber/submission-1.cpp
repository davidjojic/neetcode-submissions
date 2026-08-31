class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>sol(n);
        sol[0] = {nums[0],0};
        if(n == 1)
            return nums[0];
        sol[1] = {nums[1],nums[0]};

        for(int i = 2;i<n;i++){
            sol[i]= {max(sol[i-2].first,sol[i-2].second) + nums[i],max(sol[i-1].first,sol[i-1].second)};
        }
        return max(sol[n-1].first,sol[n-1].second);
    }
};
