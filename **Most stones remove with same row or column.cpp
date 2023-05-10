//good question similar to counting number of islands.
//this solution works in 522ms need to find better method
//faster if we use find-union methods.
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    void DFS(int i,vector<int> graph[], vector<int>& visited){
        visited[i] = 1;
        for(auto it : graph[i]){
            if(!visited[it])
                DFS(it,graph,visited);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int ans = 0;
        int n = stones.size();
        vector<int> graph[n];
        for(int i =0;i<n;i++){
            for(int j=1;j<n;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        vector<int> visited(n,0);
        int cont = 0;
        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                DFS(i,graph,visited);
                cont++;
            }
        }
        return n - cont;
    }
};