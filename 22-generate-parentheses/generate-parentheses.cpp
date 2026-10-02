class Solution {
public:
    vector<string> result;

    // bool isValid(string str) {
    //     int count = 0;

    //     for(char ch:str) {
    //         if(ch == '(')
    //             count++;
    //         else
    //             count--;
    //         if(count < 0)
    //             return false;
    //     }
    //     return count==0;
    // }

    void solve(string &curr, int open, int close, int n){
        if(curr.length()==2*n){
            result.push_back(curr);
        }

        if(open < n){
            curr.push_back('(');
            solve(curr, open+1, close, n);
            curr.pop_back();
        }

        if(close<open){
            curr.push_back(')');
            solve(curr, open, close+1, n);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(curr, 0, 0, n);
        return result; 
    }
};