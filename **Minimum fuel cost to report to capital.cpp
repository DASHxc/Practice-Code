#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    long long DFS(long long &ans, vector<int>graph[],int node, int parent,int seats){
        long long passenger = 0;
        for(auto it : graph[node]){
            if(it != parent){
                long long temp = DFS(ans,graph,it,node,seats);
                passenger += temp;
                ans += ceil(double(temp)/double(seats));
            }
        }
        return passenger + 1;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        long long ans = 0;
        int n = roads.size() + 1;
        vector<int> graph[n];
        for(int i=0;i<roads.size();i++){
            graph[roads[i][0]].push_back(roads[i][1]);
            graph[roads[i][1]].push_back(roads[i][0]);
        }
        vector<int> visited(n,0);
        long long t = DFS(ans,graph,0,-1,seats);
        return ans;
    }
};