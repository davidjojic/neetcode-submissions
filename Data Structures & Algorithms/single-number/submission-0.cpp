class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int broj = nums[0];
        for(int i =1;i<nums.size();i++)
            broj ^=nums[i];
        return broj;
    }
};
