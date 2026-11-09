class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> availableserver;
        
        for(int i=0; i<k; i++){
            availableserver.insert(i);
        }

        vector<int> countrequest(k, 0);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > busyserver;

        for(int i=0; i<arrival.size(); i++){
            int time = arrival[i];

            while(!busyserver.empty() && busyserver.top().first<=time){
                int server = busyserver.top().second;

                busyserver.pop();

                availableserver.insert(server);
            }

            int target = i%k;

            auto it = availableserver.lower_bound(target);

            if(it == availableserver.end()){
                it = availableserver.begin();
            }

            if(availableserver.empty()){
                continue;
            }

            int targetserver = *it;

            availableserver.erase(it);

            busyserver.push({time + load[i], targetserver});

            countrequest[targetserver]++;
        }

        int max = *max_element(begin(countrequest), end(countrequest));

        vector<int> result;

        for(int i=0; i<k; i++){
            if(countrequest[i]==max){
                result.push_back(i);
            }
        }

        return result;
    }
};