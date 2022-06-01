class Solution {
public:
    int calculate(string s) {
        s += '+'; // Push the last val to the stack
        int val = 0;
        stack<int> num;
        char op = '+';
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                val = val * 10 + (s[i] - '0');
            }
            // Rule out space
            else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                if (op == '+') {
                    num.push(val);
                } 
                else if (op == '-') {
                    num.push(val * -1);
                }
                else if (op == '*') {
                    int temp = num.top();
                    num.pop();
                    num.push(temp * val);
                }
                else if (op == '/') {
                    int temp = num.top();
                    num.pop();
                    num.push(temp / val);                
                }
                op = s[i];
                val = 0;
            }
        }
        
        int ans = 0;
        while (!num.empty()) {
            ans += num.top();
            num.pop();
        }
        
        return ans;
    }
};