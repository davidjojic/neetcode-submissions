class Solution {
public:
    int getSum(int a, int b) {
        uint32_t mask = 1;
        uint32_t sol = 0;
        uint32_t carry = 0;
        uint32_t ua = a;
        uint32_t ub = b;
        for(int i =0;i<32;i++){
            int sum = 0;
            if(mask & ua)
                sum++;
            if(mask & ub)
                sum++;
            sum+=carry;
            carry = 0;
            if(sum%2 == 1){
                sol=sol|mask;
            }
            if(sum>1)
                carry = 1;
            mask<<=1;
        }
        return sol;
    }
};
