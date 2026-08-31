class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> dp;
        for(int i = 0;i<strs.size();i++)
        {
            vector<int>v(26);
            for(int j =0;j<strs[i].size();j++)
                v[strs[i][j] - 'a']++;
            dp[v].push_back(strs[i]);
        }
        vector<vector<string>> sol;
        for(auto nesto : dp)
            sol.push_back(nesto.second);
        return sol;
    }
};
