class Solution {
public:

    string encode(vector<string>& strs) {
        string sol = "";
        for(string &s: strs){
            sol+= to_string(s.size());
            sol+="#";
            sol+=s;
        }
        return sol; 
    }
    vector<string> decode(string s) {
        vector<string>sol;
        string tren = "";
        int broj = 0;
        bool read = false;
        for(char c:s){
            if(!read){
                if(c == '#'){
                    read = true;
                    if(broj == 0){
                        sol.push_back("");
                        read = false;
                    }
                }else{
                    broj = broj*10 + (c-'0');
                }
                
            }else{
                tren+=c;
                broj--;
                if(broj == 0){
                    read = false;
                    sol.push_back(tren);
                    tren = "";
                }
            }
        }
        return sol;
    }
};
