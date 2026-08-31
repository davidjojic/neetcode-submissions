class Solution {
public:
    struct VectorHash{
        size_t operator()(const vector<int>&v) const{
            size_t h = 0;
            for(const int &x : v){
                h = h*31 + hash<int>{}(x);
            }
            return h;
        }
    };
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<vector<int>, vector<string>,VectorHash> mp;
        mp.reserve(strs.size());
        for(const auto &s : strs){
            vector<int>v(26,0);
            for(char c: s){
                v[c-'a']++;
            }
            mp[v].push_back(s);
        }
        vector<vector<string>> sol;
        for(auto &[i,j] : mp){
            sol.push_back(j);
        }
        return sol;
    }
};
