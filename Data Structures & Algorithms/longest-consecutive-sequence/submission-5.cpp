class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        sort(nums.begin(),nums.end());
        int maks = 0;
        for(int i : nums){
            mp[i]=mp[i-1]+1;
            maks = max(maks, mp[i]);
        }        
        return maks;
    }
};