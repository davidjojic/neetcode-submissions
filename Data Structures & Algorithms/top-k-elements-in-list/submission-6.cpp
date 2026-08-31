class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int &x : nums)
            mp[x]++;
        vector<vector<int>>bucketsort(nums.size()+1);
        for(auto&[i,j]:mp){
            bucketsort[j].push_back(i);
        }
        vector<int>sol;
        sol.reserve(k);
        for(int freq = nums.size();freq>=0;freq--){
            for(int &x: bucketsort[freq]){
                sol.push_back(x);
                if(sol.size() == k)
                    return sol;
            }
        }
        return sol;
    }
};
