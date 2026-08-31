class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> brojevi;
        unordered_map<int,int> predjeni;
       for(int &i : nums){
            brojevi.insert(i);
       }
       int sol = 0;
       for(int &num: nums){
          if(predjeni.find(num+1) != predjeni.end()){
            sol = max(sol,1+predjeni[num+1]);
            continue;
          }  
            int tren = num;
            int vel = 1;
            while(brojevi.find(tren+1) != brojevi.end()){
                vel++;
                predjeni[tren+1] = 1;
                tren++;
            }
            predjeni[num] = vel;
            sol=max(sol,vel);
       }
       return sol;
    }
};