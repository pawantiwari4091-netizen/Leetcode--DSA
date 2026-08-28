class Solution {
public:
    string res = "";
    int half = 0;
    char mid ='$';

    bool solve(vector<int> &cnt, string tar, string curr, int i, bool greater) {
        // if(!ans.empty()) return true;
        if(i==half){
            string left = curr;
            string right = curr;
            reverse(right.begin(), right.end());
            if(mid!='$'){
                left = left + mid;
            }
            left = left + right;

            if(left > tar){
                res = left;
                return true;
            }
            return false;
        }

        for(char ch='a'; ch<='z'; ch++){
            if(cnt[ch-'a']==0){
                continue;
            }

            if(!greater && ch < tar[i]){
                continue;
            }

            curr.push_back(ch);
            cnt[ch-'a']--;

            bool isgreater = greater || ch > tar[i];

            if(solve(cnt, tar, curr, i+1, isgreater)){
                return true;
            }

            curr.pop_back();
            cnt[ch-'a']++;
        }
        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        vector<int> count(26, 0);

        for (char ch : s) {
            count[ch - 'a']++;
        }

        int oddCount = 0;

        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 != 0) {
                oddCount++;
                mid = 'a' + i;
            }
            count[i] /= 2;
        }

        if (oddCount > 1) {
            return "";
        }

        int n = s.size();
        half = n / 2;

        string currPath;
        solve(count, target, currPath, 0, false);
        return res;
    }
};