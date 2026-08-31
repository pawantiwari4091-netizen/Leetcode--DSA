class Solution {
public:
    int solve(vector<int> &coins, int rem, vector<int> &t){
        if(rem<0) return -1;
        if(rem==0) return 0;

        if(t[rem]!=-2) return t[rem];

        int min_count = INT_MAX;

        for(int n:coins){
            int res = solve(coins, rem - n, t);
            if(res>=0 && res < min_count){
                min_count = 1 + res;
            }
        }
        
        t[rem] = min_count==INT_MAX? -1:min_count;
        return t[rem];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> t(amount+1, -2);
        return solve(coins, amount, t);
    }
};