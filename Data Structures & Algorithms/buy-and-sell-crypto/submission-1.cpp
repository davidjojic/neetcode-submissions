class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int smal = prices[0];
        int sol =0;
        for(int i : prices){
            sol=max(sol,i-smal);
            smal = min(smal,i);
        }
        return sol;
    }
};
