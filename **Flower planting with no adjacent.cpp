#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> ans;
        vector<int> color(n+1,-1);
        vector<int> visited(n+1,0);
        vector<int> graph[n+1];
        for(int i=0;i<paths.size();i++){
            graph[paths[i][0]].push_back(paths[i][1]);
            graph[paths[i][1]].push_back(paths[i][0]);
        }
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(visited[i] == 0){
                q.push(i);
                while(!q.empty()){
                    int temp = q.front();
                    q.pop();
                    vector<int> tempColorSet(5,-1);
                    for(auto it : graph[temp]){
                        if(!visited[it]){
                            visited[it] = 1;
                            q.push(it);
                        }
                        int tempC = color[it];
                        if(tempC != -1)
                            tempColorSet[tempC] = 1;
                    }
                    int fillC;
                    for(int i=1;i<=4;i++){
                        if(tempColorSet[i] == -1){
                            fillC = i;
                            break;
                        }
                    }
                    color[temp] = fillC;
                }
            }
        }
        for(int i=1;i<=n;i++){
            ans.push_back(color[i]);
        }
        return ans;
    }
};