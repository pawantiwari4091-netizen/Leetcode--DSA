class Solution {
public:
    int n;
    unordered_set<string> st;

    void solve(string &s, string &c, int idx, int &maxlen, int check) {

        // More closing brackets than opening brackets
        if (check < 0)
            return;

        // Reached end of string
        if (idx == n) {

            // Valid parentheses string
            if (check == 0) {

                if (c.length() > maxlen) {
                    st.clear();
                    maxlen = c.length();
                }

                if (c.length() == maxlen) {
                    st.insert(c);
                }
            }

            return;
        }

        // Normal character
        if (s[idx] != '(' && s[idx] != ')') {

            c.push_back(s[idx]);

            solve(s, c, idx + 1, maxlen, check);

            c.pop_back();

            return;
        }

        // CASE 1: Keep the parenthesis
        c.push_back(s[idx]);

        if (s[idx] == '(')
            solve(s, c, idx + 1, maxlen, check + 1);
        else
            solve(s, c, idx + 1, maxlen, check - 1);

        c.pop_back();

        // CASE 2: Remove the parenthesis
        solve(s, c, idx + 1, maxlen, check);
    }

    vector<string> removeInvalidParentheses(string s) {

        string curr = "";
        int maxlen = 0;

        n = s.length();
        st.clear();

        solve(s, curr, 0, maxlen, 0);

        return vector<string>(st.begin(), st.end());
    }
};