class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        int n = nums.size();
        vector<int> vec = nums;
        sort(begin(vec), end(vec));

        int group = 0;
        unordered_map<int,int> numToGroup;
        numToGroup[vec[0]] = group;
        unordered_map<int, list<int>> groupToList;
        groupToList[group].push_back(vec[0]);

        for(int i=1; i<n; i++){
            if(abs(vec[i]-vec[i-1])>limit){
                group++;
            }
            numToGroup[vec[i]] = group;
            groupToList[group].push_back(vec[i]);
        }

        vector<int> ans(n);

        for(int i=0; i<n; i++){
            int num = nums[i];
            int groupNum = numToGroup[num];
            ans[i] = *groupToList[groupNum].begin();
            groupToList[groupNum].pop_front();
        }

        return ans;
    }
};