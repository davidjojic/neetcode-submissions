class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>sol(nums.size());
        int proz = 1;
        int broj_nula = 0;
        for(int &i : nums){
            if(i == 0)
                broj_nula++;
            else{
                proz *= i;
            }    
        }
        for(int i =0;i<nums.size();i++){
            if(nums[i] != 0){
                if(broj_nula == 0)
                    sol[i] = proz/nums[i];
                else
                    sol[i] = 0;
            }
            else{
                if(broj_nula > 1)
                    sol[i] = 0;
                else{
                    sol[i] = proz;
                }
            }
        }
        return sol;
    }
};
