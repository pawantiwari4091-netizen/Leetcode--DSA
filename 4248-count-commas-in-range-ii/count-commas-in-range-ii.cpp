class Solution {
public:
    typedef long long ll;
    long long countCommas(long long n) {
        ll result = 0;
        ll lower = 1000;
        int commas = 1;

        while(lower<=n){
            ll upper = lower*1000 - 1;
            if(upper > n) upper = n;
            
            ll countnumbers = upper -lower +1;
            result = result + countnumbers*commas;

            lower*=1000;
            commas++; 
        }

        return result;

    }
};