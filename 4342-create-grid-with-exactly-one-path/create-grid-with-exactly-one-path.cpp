class Solution {
public:
    vector<string> createGrid(int m, int n) {

        string toprow(n,'.');
        string remaining = string(n-1,'#') + '.';

        vector<string> result;
        result.push_back(toprow);

        for(int i=1; i<m; i++){
            result.push_back(remaining);
        }

        return result;
    }
};