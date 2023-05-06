class Solution {
public:
    void DFS(vector<vector<int>>& graph,int n, vector<int>& visited,int row){
        if(visited[row])
            return;
        visited[row] = 1;
        for(int i=0;i<n;i++){
            if(visited[i] == 0 && i != row && graph[row][i] == 1)
                DFS(graph,n,visited,i);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0;
        int n = isConnected.size();
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                DFS(isConnected,n,visited,i);
                cnt++;
            }
        }
        return cnt;
    }
};