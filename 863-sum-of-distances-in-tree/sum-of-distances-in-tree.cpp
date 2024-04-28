class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
          vector<vector<int>> tree(n);
        for(auto x : edges){
            tree[x[0]].push_back(x[1]);
            tree[x[1]].push_back(x[0]);
        }
        vector<int> sz(n), distance(n);
        function<void(int, int)> dfs1=[&](int u, int p){
            sz[u]=1;
            for(int v : tree[u]){
                if(v==p)continue;
                dfs1(v, u);
                sz[u]+=sz[v];
                distance[u]+=distance[v]+sz[v];
            }
        };
        dfs1(0, 0);
        vector<int> solution(n);
        function<void(int, int)> dfs2=[&](int u, int p){
            for(int v : tree[u]){
                if(v==p)continue;
                solution[v]=solution[u]+sz[0]-2*sz[v];
                dfs2(v, u);
            }
        };
        solution[0]=distance[0];
        dfs2(0, 0);
        return solution;
        
    }
};