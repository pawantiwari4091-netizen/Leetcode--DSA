class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int m = 1e9 + 7;
        vector<int> cnt(32,0);

        for(int n:nums){
            for(int i=0; i<32; i++){
                if(n & (1<<i)){
                    cnt[i]++;
                }
            }
        }

        long long result = 0;

        while(k--){
            long long curr = 0;

            for(int i=0; i<32; i++){
                if(cnt[i]>0){
                    curr = curr | (1<<i);
                    cnt[i]--;
                }
            }

            result = (result + curr*curr) % m;
        }
        return (int)result;
    }
};