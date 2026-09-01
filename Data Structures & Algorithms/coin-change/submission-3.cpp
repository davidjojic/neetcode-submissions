class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int indeks = coins.size()-1;
        vector<int>v(amount+1,-1);
        
        v[0] = 0;
        for(int i =1;i<=amount;i++){
            int mi = -1;
            for(int coin:coins){
                if(i-coin >= 0){
                    if(v[i-coin] == -1)
                        continue;
                    if(mi == -1 || mi > v[i-coin]+1){
                        mi = v[i-coin]+1;
                    }
                }
            }
            v[i] = mi;
        }

        return v[amount];
    }
};
