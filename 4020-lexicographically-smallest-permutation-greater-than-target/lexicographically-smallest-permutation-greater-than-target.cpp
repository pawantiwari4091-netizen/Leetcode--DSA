class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = target.length();

        vector<int> v(26, 0);

        for (char ch : s) {
            v[ch - 'a']++;
        }

        string ans;

        for (int i = 0; i < n; i++) {

            int curr = target[i] - 'a';

            // Case 1: We can put the same character
            if (v[curr] > 0) {
                ans.push_back(target[i]);
                v[curr]--;
            }
            else {
                // We cannot continue matching target.
                // Try to find a greater character at current position.
                int greater = -1;

                for (int j = curr + 1; j < 26; j++) {
                    if (v[j] > 0) {
                        greater = j;
                        break;
                    }
                }

                if (greater != -1) {
                    // Put the greater character
                    ans.push_back(greater + 'a');
                    v[greater]--;

                    // Put remaining characters in sorted order
                    for (int j = 0; j < 26; j++) {
                        while (v[j] > 0) {
                            ans.push_back(j + 'a');
                            v[j]--;
                        }
                    }

                    return ans;
                }

                // No greater character here.
                // Need to backtrack.
                for (int k = i - 1; k >= 0; k--) {

                    // Return the character used at position k
                    v[ans[k] - 'a']++;

                    int prev = target[k] - 'a';

                    // Try to find a character greater than target[k]
                    greater = -1;

                    for (int j = prev + 1; j < 26; j++) {
                        if (v[j] > 0) {
                            greater = j;
                            break;
                        }
                    }

                    if (greater != -1) {
                        string result = ans.substr(0, k);

                        result.push_back(greater + 'a');
                        v[greater]--;

                        // Fill remaining characters in sorted order
                        for (int j = 0; j < 26; j++) {
                            while (v[j] > 0) {
                                result.push_back(j + 'a');
                                v[j]--;
                            }
                        }

                        return result;
                    }
                }

                // No greater permutation exists
                return "";
            }
        }

        // s can form exactly target, but we need GREATER.
        // Backtrack from the last position.
        for (int k = n - 1; k >= 0; k--) {

            v[ans[k] - 'a']++;

            int curr = target[k] - 'a';

            for (int j = curr + 1; j < 26; j++) {

                if (v[j] > 0) {

                    string result = ans.substr(0, k);

                    result.push_back(j + 'a');
                    v[j]--;

                    // Fill remaining characters
                    for (int x = 0; x < 26; x++) {
                        while (v[x] > 0) {
                            result.push_back(x + 'a');
                            v[x]--;
                        }
                    }

                    return result;
                }
            }
        }

        return "";
    }
};