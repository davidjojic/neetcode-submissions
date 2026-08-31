class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>sol(nums.size());
        vector<int>levi(nums.size()+1,1);
        vector<int>desni(nums.size()+1,1);
        for(int i =0;i<nums.size();i++){
            levi[i+1]=levi[i]*nums[i];
        }
        for(int i = nums.size();i>=1;i--){
            desni[i-1]=desni[i]*nums[i-1];
        }

        for(int i = 0;i<nums.size();i++){
            sol[i]=levi[i]*desni[i+1];
        }
        return sol;
    }
};
