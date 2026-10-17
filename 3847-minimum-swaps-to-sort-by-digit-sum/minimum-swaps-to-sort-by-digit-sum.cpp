class Solution {
public:
    int digitsum(int n){
        int sum = 0;
        while(n>0){
            sum = sum + (n%10);
            n/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> valtoidx;
        for(int i=0; i<n; i++){
            valtoidx[nums[i]] = i;
        }


        vector<int> aftersorted(nums);
        auto lambda = [&](int n1, int n2){
            int n1sum = digitsum(n1);
            int n2sum = digitsum(n2);

            if(n1sum!=n2sum){
                return n1sum < n2sum;
            }
            return n1 < n2;
        };

        sort(begin(aftersorted), end(aftersorted), lambda);

        int swapcount = 0;

        for(int i=0; i<n; i++){
            int expect = aftersorted[i];
            int curr = nums[i];
            
            if(expect==curr) continue;

            int idx = valtoidx[expect];

            nums[i] = expect;
            nums[idx] = curr;

            valtoidx[curr] = idx;
            valtoidx[expect] = i;

            swapcount++;
        }
        return swapcount;
    }
};