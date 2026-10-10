class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        return rek(text1,text2,dp,0,0);
    }
private:
    int rek(string &text1,string &text2,vector<vector<int>>&dp ,int i,int j){
        if(i == text1.size() || j == text2.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(text1[i] == text2[j]){
            dp[i][j] = 1 + rek(text1,text2,dp,i+1,j+1);
            dp[i][j] = max(dp[i][j],max(rek(text1,text2,dp,i+1,j),rek(text1,text2,dp,i,j+1)));
        }else{
            dp[i][j] = max(dp[i][j],max(rek(text1,text2,dp,i+1,j),rek(text1,text2,dp,i,j+1)));
        }
        return dp[i][j];
    }
};

