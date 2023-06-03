class Solution {
public:
    void DFS(int i, unordered_set<int>& st,vector<int> graph[],vector<int>& visited){
        visited[i] = 1;
        for(auto it : graph[i]){
            if(!visited[it] && st.find(it) == st.end()){
                DFS(it,st,graph,visited);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> visited(n,0);
        unordered_set<int> st;
        vector<int> graph[n];
        int ans=0;
        for(int i=0;i<restricted.size();i++)
            st.insert(restricted[i]);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(auto it : graph[temp]){
                if(!visited[it] && st.find(it) == st.end()){
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        //DFS(0,st,graph,visited);
        for(int i=0;i<n;i++){
            if(visited[i])
                ans++;
        }
        return ans;
    }
};