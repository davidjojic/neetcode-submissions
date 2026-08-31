class Solution {
public:
    int characterReplacement(string s, int k) {
        int sol = 0;
        for(int i = 0;i<26;i++){
            cout<<i<<endl;
            char c = 'A' + i;
            int l = 0;
            int r = 0;
            int drug = 0;
            while(r<s.size()){
                
                if(s[r] != c){
                    drug++;
                }
                r++;
                while(drug> k ){
                    if(s[l] != c){
                        drug--;
                    }
                     l++;
                }
                sol = max(sol,r-l);
            }
        }
        return sol;
    }
};