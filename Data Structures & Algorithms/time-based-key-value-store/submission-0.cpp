class TimeMap {
    unordered_map<string,vector<pair<int,string>>>mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto itr = mp.find(key);
        if(itr == mp.end())
            return "";
        vector<pair<int,string>>&v = mp[key];
        int l =0;
        int r = v.size();
        while(r>l){
            int middle = l + (r-l)/2;
            if(v[middle].first > timestamp){
                r = middle;
            }else{
                l=middle+1;
            }
        }
        if(l == 0)
            return "";
        else
            return v[l-1].second;
    }
};
