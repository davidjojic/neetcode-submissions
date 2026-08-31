class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> dp;
        int sol = 0, k = 0;
        if(s.size() == 1)
            return 1;
        for(int i = 0;i<s.size();i++)
        {
            if(dp.find(s[i]) !=dp.end())
                k = max(k,dp[s[i]] + 1);
            dp[s[i]] = i;
            sol = max(sol,i-k+1);
        }

        return sol;
    }
};
