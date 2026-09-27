class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> storelength;
        string ans;

        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                storelength.push(ans.size());
            }
            else if(s[i]==')'){
                int len = storelength.top();
                storelength.pop();
                reverse(ans.begin() + len, ans.end());
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};