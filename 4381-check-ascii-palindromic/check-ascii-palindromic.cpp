#include <bitset>

class Solution {
public:
    bool palindrome(string &str){
        int l =0;
        int r =str.size()-1;

        while(l<r){
            if(str[l]!=str[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    
    bool isPalindromic(string s) {

        string binary;
        for(char ch:s){
            binary+=bitset<8>(ch).to_string();
        }
        if(palindrome(binary)){
            return true;
        }
        return false;
    }
};