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

            if (c.second.size() >= 3) {
                int diff = INT_MIN;
                bool special = true;
                int sz = c.second.size();
                for(int i=0; i<sz-1; i++){
                    int gh =  c.second[i+1] - c.second[i];
                    if(diff==INT_MIN){
                        diff = gh;
                    }
                    else{
                        if(gh != diff){
                            special = false;
                            break;
                        }
                    }
                }
                if(special) count++;
            }
        }

        return count;
    }
};