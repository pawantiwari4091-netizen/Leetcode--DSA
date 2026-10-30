class Solution {
public:
    typedef tuple<int, int, int> t;

    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        unordered_map<int,vector<vector<int>>> adj;

        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
        }

        vector<vector<int>> result(n, vector<int>(k+1,INT_MAX));  

        priority_queue<t, vector<t>, greater<t>> pq;

        result[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty()){
            auto [d, node, count] = pq.top();
            pq.pop();

            if(d > result[node][count]) continue;

            if(node == n-1) return d;

            for(auto &v: adj[node]){
                int adjnode = v[0];
                int wt = v[1];

                int nextcount = (labels[adjnode]==labels[node])? count+1:1;

                if(nextcount > k) continue;

                if(result[adjnode][nextcount] > d+wt){
                    result[adjnode][nextcount] = d + wt;
                    pq.push({d+wt, adjnode, nextcount});
                }
            }
        }
        return -1;
    }
};