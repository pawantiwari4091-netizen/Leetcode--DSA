class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for(int i = 0; i < knowledge.size(); i++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }

        int i = 0;
        string result = "";

        while(i < s.size()){
            if(s[i] == '('){
                string temp = "";
                i++;

                while(s[i] != ')'){
                    temp.push_back(s[i++]);
                }

                if(mp.find(temp) != mp.end()){
                    result += mp[temp];
                }
                else{
                    result.push_back('?');
                }

                i++;
            }
            else{
                result.push_back(s[i++]);
            }
        }

        return result;
    }
};