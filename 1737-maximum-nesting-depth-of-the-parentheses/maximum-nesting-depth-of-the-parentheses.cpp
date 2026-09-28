class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int openbracket = 0;

        for (char c : s) {
            if (c == '(') {
                openbracket++;
            } else if (c == ')') {
                openbracket--;
            }
            
            ans = max(ans, openbracket);
        }
        
        return ans;
    }
};