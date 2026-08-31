class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sol = 0,k=1;
        if(nums.size() == 0)
            return 0;
        for(int i = 1;i<nums.size();i++)
            if(nums[i]== nums[i-1] +1)
                k++;
            else if(nums[i] != nums[i-1])
            {
                sol = max(sol,k);
                k = 1;
            }
        sol = max(sol,k);
        return sol;
    }
};
