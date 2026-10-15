class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = 0;
        for(int i=0; i<nums.size(); i++){
            if(i>mx){
                return false;
            }

            int farther = i + nums[i];
            mx = max(mx, farther);
        }
        return true;
    }
};