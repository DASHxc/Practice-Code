#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    int maxE = 1e5;
    vector<int> DFS(vector<vector<int>>& graph, int b, int parent){
        
        if(b == 0){
            return {0};
        }
        
        for(auto it : graph[b]){
            if(it != parent){
                vector<int> temp = DFS(graph,it,b);
                if(temp.size() != 0){
                    temp.push_back(b);
                    return temp;
                }
            }
        }
        return {};
    }
    int run(vector<vector<int>>& graph, vector<int>& bPath, vector<int>& amnt, int alice,int parent,vector<int>& gateVisited,int time){
        if(graph[alice].size() == 1 && graph[alice][0] == parent){
            if(gateVisited[alice])
                return 0;
            return amnt[alice];
        }
        int bobPosition = min(time,(int)bPath.size()-1);
        int bob = bPath[bobPosition];
        int cost = 0;
        if(!gateVisited[alice])
            cost = amnt[alice];
        if(alice == bob)
            cost = cost/2;
        int ans = INT_MIN;
        gateVisited[alice] = 1;
        gateVisited[bob] = 1;

        for(auto it : graph[alice]){
            if(it != parent){
                int tempCost = run(graph,bPath,amnt,it,alice,gateVisited,time+1);
                ans = max(ans, tempCost + cost);
            }
        }
        gateVisited[bob] = 0;
        gateVisited[alice] = 0;
        return ans;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        vector<vector<int>> graph(maxE);
        for(auto it : edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<int> bobPath = DFS(graph,bob,-1);
        reverse(bobPath.begin(),bobPath.end());
        vector<int> gateVisited(maxE,0);
        int ans = run(graph,bobPath,amount,0,-1,gateVisited,0);
        // for(int i=0;i<bobPath.size();i++)
        //     cout<<bobPath[i]<<" ";
        return ans;
    }
};