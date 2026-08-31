class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maki = -1;
        for(int &i : piles)
            maki = max(maki,i);
        
        int l = 1, r= maki;
        while(l<r){
            int middle= l + (r-l)/2;
            int count = 0;
            for(int &i:piles){
                count+=i/middle;
                if(i%middle != 0)
                    count++;
                if(count > h)
                    break;
            }
            if(count>h){
                l=middle + 1;
            }else{
                r = middle;
            }
        }
        return l;
    }
};
