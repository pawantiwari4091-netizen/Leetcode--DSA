class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        // Store all indices for each integer
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int count = 0;

        // Check every distinct integer
        for (auto &c : mp) {
            // c.first  = integer
            // c.second = vector of its indices

            if (c.second.size() == 3) {
                int i1 = c.second[0];
                int i2 = c.second[1];
                int i3 = c.second[2];

                if (i2 - i1 == i3 - i2) {
                    count++;
                }
            }
        }

        return count;
    }
};