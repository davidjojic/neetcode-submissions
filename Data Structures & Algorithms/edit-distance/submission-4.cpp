class Solution {
public:
    int dp[1000][1000];
bool test[1000][1000] = {false};
int rekurzija(string x,string y ,int i,int j)
{
    if(test[i][j])
    {
        return dp[i][j];
    }else if(i == x.size())
    {
        dp[i][j] = y.size() - j;
        test[i][j] = true;
        return y.size() - j;
    }else if(j == y.size())
    {
        dp[i][j] = x.size() - i;
        test[i][j] = true;
        return x.size() - i;
    }else
    {
        if(x[i] == y[j])
        {
            dp[i][j] = rekurzija(x,y,i + 1,j + 1);
            test[i][j] = true;
            return dp[i][j];
        }else
        {
            dp[i][j] = min(rekurzija(x,y,i + 1,j)  +1 , min(rekurzija(x,y,i,j + 1) + 1, rekurzija(x,y,i +1 , j + 1) + 1));
            test[i][j] = true;
            return dp[i][j];
        }
    }
}
    int minDistance(string word1, string word2) {
        return rekurzija(word1,word2,0,0);     
    }
};
