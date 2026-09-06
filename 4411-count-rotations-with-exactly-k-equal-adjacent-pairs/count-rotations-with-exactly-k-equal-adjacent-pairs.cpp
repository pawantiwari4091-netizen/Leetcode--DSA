class Solution {
public:
    int countRotations(string s, int k) 
    {
        int n = s.length();
        int valid = 0;

        for(int start =0; start<n; ++start)
        {
            int score = 0;
            for(int j =0; j<n-1;++j)
            {
                if(s[(start+j)%n] == s[(start + j+1)%n])
                {
                    score++;
                }
            }
            if(score == k)
            {
                valid++;
            }
        }
        return valid;
    }
};