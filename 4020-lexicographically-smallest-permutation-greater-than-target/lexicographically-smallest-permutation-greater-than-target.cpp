class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();

        // 步驟 1：統計 s 的手牌（每個字母出現的次數）
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        // 用來記錄我們在每一格填了什麼字元
        string res = string(n, ' ');

        // 步驟 2：嘗試「完美跟牌」
        int i = 0;
        while (i < n) {
            char t_char = target[i];
            // 如果手牌裡還有跟 target 一模一樣的字母，就先跟牌
            if (cnt[t_char - 'a'] > 0) {
                res[i] = t_char;
                cnt[t_char - 'a']--;
                i++;
            } else {
                // 手牌不夠跟了，在此處斷掉
                break;
            }
        }

        // 步驟 3：從斷掉的位置（或最後一格）往左退，尋找突破口
        // 如果一路跟牌到了最後 (i == n)，因為要求「嚴格大於」，我們也必須退回一格開始找突破口
        int limit = (i == n) ? n - 1 : i;
        for (int curr = limit; curr >= 0; curr--) {
            // 如果這個位置之前有跟牌，我們要先把它回收，放回手牌中
            if (res[curr] != ' ') {
                cnt[res[curr] - 'a']++;
                res[curr] = ' '; // 清空當前位置
            }
            // 尋找比 target[curr] 大的、且我們手牌裡有的最小字母
            char target_char = target[curr];
            int choice = -1;
            for (int c = (target_char - 'a') + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    choice = c;
                    break; // 找到的第一個就是最小的
                }
            }
            // 如果找到了突破口！
            if (choice != -1) {
                // 1. 在突破口填入這個較大的字母
                res[curr] = (char)('a' + choice);
                cnt[choice]--;

                // 2. 突破口之後的所有格子，用剩餘手牌「由小到大」填滿
                int write_idx = curr + 1;
                for (int c = 0; c < 26; c++) {
                    while (cnt[c] > 0) {

                        res[write_idx++] = (char)('a' + c);
                        cnt[c]--;
                    }
                }
                return res; // 成功找到答案，直接返回！
            }
            // 如果沒找到，迴圈會繼續往左退一格（curr--），並在下一輪開頭回收字元
        }

        // 如果一路退到 curr = -1 都沒找到突破口，說明無解
        return "";
    }
};