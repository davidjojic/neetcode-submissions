class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sol = 0;
        for(int i = 0;i<prices.size();i++)
            for(int j = i+1;j<prices.size();j++)
            {
                sol = max(sol,prices[j]-prices[i]);
            }
        return sol;
    }
};
