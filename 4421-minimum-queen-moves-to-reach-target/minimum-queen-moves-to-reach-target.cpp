class Solution {
public:
    int minQueenMoves(vector<int>& s, vector<int>& t) {

        int x1 = s[0],y1=s[1];
        int x2 = t[0],y2=t[1];

        if(s==t) return 0; // same points
        if(x1==x2 or y1==y2) return 1; // same row or col
        if(x1 + y1 == x2 + y2) return 1; //  '\' diag
        if(x1-y1==x2-y2) return 1; // '/' diag
        return 2; // all other cases
    }
};