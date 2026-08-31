class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>a1(27,0);
        vector<int>a2(27,0);
        if(s2.size() < s1.size())
            return false;
        for(char c: s1)
            a1[c-'a']++;
        for(int i = 0;i<s1.size();i++)
            a2[s2[i]-'a']++;

        if(a1 == a2)
            return true;
        for(int i = s1.size();i< s2.size();i++)
        {
            a2[s2[i-s1.size()]-'a']--;
                a2[s2[i]-'a']++;
            if(a1 == a2)
                return true;
        }
        return false;
    }
};
