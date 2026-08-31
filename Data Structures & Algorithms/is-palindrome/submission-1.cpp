class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0,j = s.size() - 1;
        string sk = "";
        for(char c : s)
        {
            if(isalnum(c))
                sk +=tolower(c);
        }
        j = sk.size() - 1;
        cout<<sk<<endl;
        while(j > i)
        {
            if(sk[i] != sk[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
