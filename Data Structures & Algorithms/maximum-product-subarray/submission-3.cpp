class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sol = nums[0];
        int mx = nums[0];
        int mn = nums[0];
        for(int i =1;i<nums.size();i++){
            int x= nums[i];
            int oldmax = mx;
            int oldmn = mn;
            mx = max({x,oldmax*x,oldmn*x});
            mn = min({x,oldmax*x,oldmn*x});
            sol=max(sol,mx);
        }
        return sol;
    }
    
};
