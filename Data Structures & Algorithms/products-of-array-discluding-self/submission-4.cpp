class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long k = 1;
        set<int>v;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] == 0)
                v.insert(i);
            else
                k*=nums[i];
        }
        vector<int>sol;
        if(v.size() > 1){
            vector<int>tl(nums.size(),0);
            return tl;
            }
        if(v.size() == 1)
            for(int i = 0;i<nums.size();i++)
            {
                if(v.find(i) != v.end())
                    sol.push_back(k);
                else
                    sol.push_back(0);
            }
        else
            for(int i = 0;i<nums.size();i++)
            {
                sol.push_back(k/nums[i]);
            }
        return sol;
    }
};
