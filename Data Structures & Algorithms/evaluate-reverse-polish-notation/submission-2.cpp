class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(auto c : tokens){
            if(c == "+"){
                int x = s.top();s.pop();
                int y = s.top();s.pop();
                s.push(x+y);
            }else if(c == "-"){
                int x = s.top();s.pop();
                int y = s.top();s.pop();
                s.push(y-x);
            }else if(c == "*"){
                int x = s.top();s.pop();
                int y = s.top();s.pop();
                s.push(x*y);
            }else if(c == "/"){
                int x = s.top();s.pop();
                int y = s.top();s.pop();
                s.push(int(y/x));
            }else
                s.push(stoi(c));
        }
        return s.top();
    }
};
