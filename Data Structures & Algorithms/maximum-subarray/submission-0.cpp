class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sol = numeric_limits<int>::min();
        int tren = 0;
        for(int i : nums){
            tren+=i;
        
            sol=max(sol,tren);
            if(tren < 0)
                tren = 0;
        }
        return sol;
    }
};
