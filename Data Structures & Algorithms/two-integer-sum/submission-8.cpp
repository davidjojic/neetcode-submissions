class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp; // vrednost indeks
        for(int i = 0;i<nums.size();i++){
            int need = target - nums[i];
            if(mp.find(need) != mp.end()){
                return {mp[need],i};
            }
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = i;
            }
        }
        return {-1,-1};
    }

};
