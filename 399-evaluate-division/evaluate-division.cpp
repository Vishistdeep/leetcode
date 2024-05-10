class Solution {
private:
    double bfs(map<int,vector<pair<int,double>>>&g,int src,int dest){
        queue<pair<int,double>> q;
        set<int> vis;
        q.push({src,1});
        vis.insert(src);
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int node = top.first;
            double x = top.second;
            if(node == dest) return x;
            for(auto&[child,val]: g[node]){
                if(!vis.count(child)){
                    vis.insert(child);
                    q.push({child,val*x});
                }
            }
        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& eqns, vector<double>& values, vector<vector<string>>& queries) {
        int st = 0, n = size(eqns), sz = size(queries);
        unordered_map<string,int> mappy;
        map<int,vector<pair<int,double>>> graph;
        vector<double> ans(sz,-1);
        for(int i=0; i<n; ++i){
            auto eqn = eqns[i];
            int e,f;
            if(mappy.count(eqn[0])) e = mappy[eqn[0]];
            else{
                mappy[eqn[0]] = st;
                e = st++;
            }
            if(mappy.count(eqn[1])) f = mappy[eqn[1]];
            else{
                mappy[eqn[1]] = st;
                f = st++;
            }
            graph[e].push_back({f,values[i]});
            if(values[i]) graph[f].push_back({e,1/values[i]});
        }
        for(int i=0; i<sz; ++i){
            auto qry = queries[i];
            double x = -1;
            if(qry[0] == qry[1]){
                if(mappy.count(qry[0]) && mappy.count(qry[1])) ans[i] = 1;
                else ans[i] = -1;
            }
            else if(mappy.count(qry[0]) && mappy.count(qry[1])){
                x = bfs(graph,mappy[qry[0]],mappy[qry[1]]);
                if(x != -1) ans[i] = x;
                else{
                    x = bfs(graph,mappy[qry[1]],mappy[qry[0]]);
                    if(x != -1) ans[i] = x;
                }
            }
        }
        return ans;
    }
};