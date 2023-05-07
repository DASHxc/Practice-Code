#include<vector>
#include<unordered_map>
#include<string>
#include<queue>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,INT_MAX);
        int N = flights.size();
        vector<pair<int,int>> graph[n];
        for(int i=0;i<N;i++){
            graph[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        dist[src] = 0;
        queue<vector<int>> q;
        q.push({src,0,0});
        while(!q.empty()){
            auto temp = q.front();
            int tempCity = temp[0];
            int tempDist = temp[1];
            int tempPass = temp[2];
            q.pop();
            for(auto it : graph[tempCity]){
                int t = tempPass;
                if(it.first != dst)
                    t++;
                if(tempDist + it.second < dist[it.first] && t <= k){
                    dist[it.first] = tempDist + it.second;
                    q.push({it.first,tempDist+it.second, t});
                }
                
            }
        }
        if(dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
    }
};