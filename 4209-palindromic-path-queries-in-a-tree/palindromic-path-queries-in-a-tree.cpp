class Solution {
public:
    int n;
    vector<int> tin, tout, eulertour;
    int time;
    vector<int> segmenttree;

    unordered_map<int, vector<int>> adj;

    vector<vector<int>> ancestorTable;
    vector<int> depth;
    int cols;

    void dfs(int node, int par, int d, string &s){
        depth[node] = d;
        ancestorTable[node][0] = par;

        tin[node] = time;
        eulertour[time] = (1<< (s[node]-'a'));
        time++;

        for(int c: adj[node]){
            if(c==par){
                continue;
            }
            dfs(c, node, d+1, s);
        }

        tout[node] = time;
        eulertour[time] = (1<< (s[node]- 'a'));
        time++;
    }

    // Segment Tree : Build (For XOR)
    void buildsegmenttree(int i, int l, int r, vector<int>& nums) {
        if(l == r) {
            segmenttree[i] = nums[l];
            return;
        }

        int mid = l + (r-l)/2;
        buildsegmenttree(2*i+1, l, mid, nums);
        buildsegmenttree(2*i+2, mid+1, r, nums);
        segmenttree[i] = segmenttree[2*i+1] ^ segmenttree[2*i+2];
    }


    //Segment Tree : Point update (Xor)
    void updateSegTree(int index, int val, int i, int l, int r) {
        if(l == r) {
            segmenttree[i] = val;
            return;
        }

        int mid = l + (r-l)/2;
        if(index <= mid) {
            updateSegTree(index, val, 2*i+1, l, mid);
        } else {
            updateSegTree(index, val, 2*i+2, mid+1, r);
        }

        segmenttree[i] = segmenttree[2*i+1] ^ segmenttree[2*i+2];
    }


    //Segment Tree : Search Query (Xor)
    int querySegmentTree(int start, int end, int i, int l, int r) {
        if(l > end || r < start) {
            return 0;
        }

        if(l >= start && r <= end) {
            return segmenttree[i];
        }

        int mid = l + (r-l)/2;
        return querySegmentTree(start, end, 2*i+1, l, mid) ^querySegmentTree(start, end, 2*i+2, mid+1, r);
    }

    void buildancestortable(){
        for(int j=1; j<cols; j++){
            for(int node=0; node<n; node++){
                if(ancestorTable[node][j-1]!=-1){
                    ancestorTable[node][j] = ancestorTable[ancestorTable[node][j-1]][j-1];
                }
            }
        }
    }

    int getlca(int u, int v){
        if(depth[u] < depth[v]) swap(u,v);

        int diff = depth[u] - depth[v];
        for(int j=0; j<cols; j++){
            if(diff & (1<<j)){
                u = ancestorTable[u][j];
            }
        }

        if(u==v){
            return u;
        }

        for(int j = cols-1; j>=0; j--){
            if(ancestorTable[u][j]!=ancestorTable[v][j]){
                u = ancestorTable[u][j];
                v = ancestorTable[v][j];
            }
        }

        return ancestorTable[u][0];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;

        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        eulertour.assign(2*n, 0); //Sees each node at inTime and outTime

        //root = 0
        time = 0;
        cols = log2(n) + 1;
        ancestorTable.assign(n, vector<int>(cols, -1));
        
        dfs(0, -1, 0, s);


        //Build Segment Tree for the array - eulerTour -> size = 2*n
        int N = 2*n; //size of eulerTour array
        segmenttree.resize(4*N, 0);
        buildsegmenttree(0, 0, N-1, eulertour);
        
        buildancestortable();


        vector<bool> result;

        for(auto &q: queries){
            stringstream ss(q);
            string type;
            ss >> type;

            if(type=="update"){
                int node; 
                char c;

                ss >> node >> c;

                int charValue = (1 << (c - 'a'));
                s[node] = c;
                updateSegTree(tin[node], charValue, 0, 0, 2*n-1);
                updateSegTree(tout[node], charValue, 0, 0, 2*n-1);

            }
            else{
                int u , v;
                ss >> u >> v;

                int lcanode =  getlca(u, v);
                char ch = s[lcanode];
                int charval = 1 << (ch-'a');

                int msk = querySegmentTree(0, tin[u], 0, 0, 2*n-1) ^querySegmentTree(0, tin[v], 0, 0, 2*n-1)^charval;

                result.push_back((msk & (msk-1))==0);
            }
        }

        return result;
    }
};