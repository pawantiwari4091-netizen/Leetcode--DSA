class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        long long comb1 = (long)cost1*need1 + (long)cost2*need2;

        long long comb2 = (long)costBoth*max(need1, need2);

        long long comb3 = LLONG_MAX;

        if(need1>need2){
            comb3 = (long)need2*costBoth + (long)(need1-need2)*cost1;
        }
        else{
            comb3 = (long)need1*costBoth + (long)(need2-need1)*cost2;
        }

        return min({comb1, comb2, comb3});
        
    }
};