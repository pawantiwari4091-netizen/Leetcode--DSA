class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<bool> arr(1e5+1);
        for(int x:nums){
            arr[x]=true;
        }


        vector<vector<int>> result;
        int start = lower;
        while(start<=upper){
            int end = start;
            while(end<=upper && !arr[end]){
                end++;
            }
            if(end!=start) result.push_back({start,end-1});
            start = end+1;
        }
        return result;
    }
};