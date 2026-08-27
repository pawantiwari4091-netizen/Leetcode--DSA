class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();


        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }


        string res = string(n, ' ');


        int i = 0;
        while (i < n) {
            char t_char = target[i];

            if (cnt[t_char - 'a'] > 0) {
                res[i] = t_char;
                cnt[t_char - 'a']--;
                i++;
            } else {
                break;
            }
        }

        int limit = (i == n) ? n - 1 : i;
        for (int curr = limit; curr >= 0; curr--) {
            if (res[curr] != ' ') {
                cnt[res[curr] - 'a']++;
                res[curr] = ' '; 
            }

            char target_char = target[curr];
            int choice = -1;
            for (int c = (target_char - 'a') + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    choice = c;
                    break; 
                }
            }

            if (choice != -1) {
                
                res[curr] = (char)('a' + choice);
                cnt[choice]--;

                int write_idx = curr + 1;
                for (int c = 0; c < 26; c++) {
                    while (cnt[c] > 0) {

                        res[write_idx++] = (char)('a' + c);
                        cnt[c]--;
                    }
                }
                return res; 
            }

        }
        return "";
    }
};