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
};
