#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<pair<int,int>> q;
        vector<int> color(n,-1);
        for(int i=0;i<graph.size();i++){
            if(color[i] == -1){
                q.push({i,0});
                color[i] = 0;
                while(!q.empty()){
                    int temp = q.front().first;
                    int tempColor = q.front().second;
                    q.pop();
                    for(auto it : graph[temp]){
                        if(color[it] == tempColor)
                            return false;
                        if(color[it] == -1){
                            int tc = tempColor == 0 ? 1 : 0;
                            q.push({it,tc});
                            color[it] = tc;
                        }
                    }
                }
            }
        }
        return true;
    }
};