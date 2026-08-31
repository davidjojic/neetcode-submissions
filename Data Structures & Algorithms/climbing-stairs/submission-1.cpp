class Solution {
public:
    int climbStairs(int n) {
        vector<int>v(n+2,0);
        v[n] = 1;
        for(int i = n-1;i>=0;i--){
            v[i]=v[i+1]+v[i+2];
        }
        return v[0];
    }
};
