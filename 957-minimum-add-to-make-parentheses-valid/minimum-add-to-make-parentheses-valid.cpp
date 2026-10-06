class Solution {
public:
    int minAddToMakeValid(string s) {
        int openbracket = 0;
        int needclosebracket = 0;

        for(char ch:s){
            if(ch=='('){
                openbracket++;
            }
            else{
                openbracket>0? openbracket-- : needclosebracket++;
            }
        }

        return openbracket+needclosebracket;
    }
};