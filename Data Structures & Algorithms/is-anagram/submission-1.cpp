class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<long long>v1(27,0),v2(27,0);
        if(s.size() != t.size())
            return false;
        for(char c : s){
            v1[c-'a']++;
        }
        for(char c : t){
            v2[c-'a']++;
        }
        for(int i = 0;i<27;i++){
            if(v1[i] != v2[i])
                return false;
        }
        return true;
    }
};
