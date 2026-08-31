class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> mp;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i: hand){
            pq.push(i);
            mp[i]++; 
        }
        while(!pq.empty()){
            int tren = pq.top();
            pq.pop();
            if(mp.find(tren) == mp.end())
                continue;
            for(int i = 0;i<groupSize;i++){
                if(mp.find(tren) != mp.end()){
                    int br  = mp[tren];
                    if(br <= 0)
                        return false;
                    if(br >1){
                        mp[tren] = br-1;
                    }else{
                        mp.erase(tren);
                    }

                }else{
                    return false;}
                tren++;
            }
        }
        return true;
    }
};
