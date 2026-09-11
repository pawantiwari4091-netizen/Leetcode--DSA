class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count = 0;

        int d[10] = {0};

        for(int i=0; i<digits.size(); i++){
            d[digits[i]]++;
        }

        for(int i=1; i<=9; i++){
            if(d[i]==0) continue;
            d[i]--;
            for(int j=0; j<=9; j++){
                if(d[j]==0) continue;
                d[j]--;
                for(int k=0; k<=9; k++){
                    if(d[k]==0) continue;
                    if(k%2==0) count++;
                }
                d[j]++;
            }
            d[i]++;
        }

        return count;
    }
};