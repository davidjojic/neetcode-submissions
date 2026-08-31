class Solution {
public:
    bool isValid(string s) {
        stack<char> q;
        for(int i = 0; i < s.size(); i++) {
            // If it's an opening bracket, push to the stack
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                q.push(s[i]);
            
            // If it's a closing bracket
            else if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
                // Check if the stack is empty (no opening bracket to match)
                if(q.empty()) 
                    return false;
                
                // Check if the current closing bracket matches the top of the stack
                if(s[i] == ')' && q.top() == '(') 
                    q.pop();
                else if(s[i] == '}' && q.top() == '{') 
                    q.pop();
                else if(s[i] == ']' && q.top() == '[') 
                    q.pop();
                else 
                    return false;  // If no match, return false
            }
        }
        
        // If the stack is empty, all brackets were matched correctly
        return q.empty();
    }
};
