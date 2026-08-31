class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        map<char, int> s1;
        map<char, int> t1;
        set<char> c;
        set<char> d;
        for(int i = 0;i<s.size();i++)
        {
            s1[s[i]]++;
            c.insert(s[i]);
            t1[t[i]]++;
            d.insert(t[i]);
        }
        if(c.size() != d.size())
            return false;
        for(char car : c)
        {
            if(d.find(car) == d.end())
                return false;
            else if(s1[car] != t1[car])
                return false;
        }
        return true;
    }
};
