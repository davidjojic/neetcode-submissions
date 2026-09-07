class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t track = 1;
        uint32_t sol = 0;
        for(int i = 0;i<31;i++){
            if(track & n){
                sol =sol | 1;
            }
            sol<<=1;
            track<<=1;
        }
        if(track & n){
            sol|=1;
        }
        return sol;
    }
};
