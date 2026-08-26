class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int i = 0, j = 0;
        int n1 = 0;

        string ans = "";
        int ansSize = INT_MAX;

        while (j < n) {

            if (s[j] == '1') {
                n1++;
            }

            // Too many 1s -> move left pointer
            while (n1 > k) {
                if (s[i] == '1') {
                    n1--;
                }
                i++;
            }

            // Exactly k ones
            if (n1 == k) {

                // Remove unnecessary leading zeroes
                while (s[i] == '0') {
                    i++;
                }

                int len = j - i + 1;
                string temp = s.substr(i, len);

                if (len < ansSize || 
                   (len == ansSize && temp < ans)) {
                    ans = temp;
                    ansSize = len;
                }
            }

            j++;
        }

        return ans;
    }
};