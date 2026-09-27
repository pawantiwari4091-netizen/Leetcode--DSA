class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int> openbracket;
        vector<int> door(n);

        for(int i=0; i<n; i++){
            if(s[i]=='('){
                openbracket.push(i);
            }
            else if(s[i]==')'){
                int j = openbracket.top();
                openbracket.pop();
                door[i]=j;
                door[j]=i;
            }
        }

        string result;
        int flag = 1;
        for(int i=0; i<n; i+=flag){
            if(s[i]=='(' || s[i]==')'){
                i=door[i];
                flag = -flag;
            }
            else{
                result+=s[i];
            }
        }
        return result;
    }
};