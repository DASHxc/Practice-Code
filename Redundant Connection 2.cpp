Hard question... similar to redundant connection... just keep track of indegree of the node.
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int findParent(int i){
        if(i == parent[i])
            return i;
        return parent[i] = findParent(parent[i]);
    }
    bool unionMerge(int i, int j){
        int iParent = findParent(i);
        int jParent = findParent(j);
        if(iParent == jParent)
            return false;
        if(rank[iParent] > rank[jParent]){
            rank[iParent] += rank[jParent];
            parent[jParent] = iParent;
        }else{
            rank[jParent] += rank[iParent];
            parent[iParent] = jParent;
        }
        return true;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n = edges.size();
        vector<int> graph[n];
        vector<int> indegree(n+1,0);
        vector<int> ans1;
        vector<int> ans2;
        for(int i=0;i<=n;i++){
            if(i != n){
                int u = edges[i][0];
                int v = edges[i][1];
                //cout<<"*"<<i<<endl;
                if(indegree[v] > 0){
                    ans1 = {indegree[v],v};
                    ans2 = {u,v};
                }
                indegree[v] = u; 
            }
            parent.push_back(i);
            rank.push_back(1);
        }
        //cout<<ans1[0]<<" "<<ans1[1]<<endl;
        //cout<<ans2[0]<<" "<<ans2[1]<<endl;
        for(int i=0;i<n;i++){
            int parent1 = findParent(edges[i][0]);
            int parent2 = findParent(edges[i][1]);
            if(edges[i] == ans2)
                continue;
            if(parent1 == parent2){
                //cout<<"$$"<<endl;
                return ans1.size() == 0 ? edges[i] : ans1; 
            }
            unionMerge(edges[i][0],edges[i][1]);
        }
        return ans2;
    }
};