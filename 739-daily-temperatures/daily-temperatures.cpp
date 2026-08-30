class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);

        // nearest[t] = nearest index having temperature t
        vector<int> nearest(101, -1);

        for(int i = n - 1; i >= 0; i--) {
            int curr = temperatures[i];

            int best = INT_MAX;

            // Look for any temperature strictly greater than curr
            for(int t = curr + 1; t <= 100; t++) {
                if(nearest[t] != -1) {
                    best = min(best, nearest[t]);
                }
            }
            if(best != INT_MAX) {
                ans[i] = best - i;
            }
            // Current temperature becomes the nearest occurrence
            nearest[curr] = i;
        }

        return ans;
    }
};