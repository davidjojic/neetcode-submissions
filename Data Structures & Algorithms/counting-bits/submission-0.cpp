class Solution {
public:
int hammingWeight(uint32_t n) {
        int count = 0 ;
        uint32_t indeks = (1<<31);
        while(indeks){
            if(n & indeks)
                count++;
            indeks>>=1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int>v(n+1);
        for(int i =0;i<=n;i++){
            v[i] = hammingWeight(uint32_t (i));
        }
        return v;
    }
};
