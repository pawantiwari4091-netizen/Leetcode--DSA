class Solution {
public:
    int fact(int n){
        if(n==0 || n==1) return 1;
        return n * fact(n-1);
    }
    string getPermutation(int n, int k) {
        vector <int> v;
        for(int i=1; i<=n; i++){
            v.push_back(i);
        }
        string ans="";
        k=k-1;
        while(v.size()!=1){
            int l=v.size();
            int j=k/(fact(l-1));
            ans+=to_string(v[j]);
            v.erase( v.begin()+j );
            k=k%(fact(l-1));
        }
        ans+=to_string(v[0]);
        return ans;
    }
};