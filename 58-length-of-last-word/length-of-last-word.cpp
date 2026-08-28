class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int i = s.size() - 1;

        while(i >= 0){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
                ans++;
            }
            else{
                if(ans > 0) break; // stop once word ends
            }
            i--; // ❗ missing
        }
        return ans;
    }
};