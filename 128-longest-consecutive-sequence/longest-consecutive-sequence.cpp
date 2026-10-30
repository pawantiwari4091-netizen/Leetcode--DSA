class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int longestseq = 0;
        for(int x:s){

            if(s.find(x-1)==s.end()){

                int currnum = x;
                int currseq = 1;
                while(s.find(currnum+1)!=s.end()){
                    currnum++;
                    currseq++;
                }
                longestseq = max(longestseq, currseq);
            }
        }
        return longestseq;
    }
};