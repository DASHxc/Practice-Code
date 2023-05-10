#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int N = dislikes.size();
        vector<int> graph[n+1];
        for(int i=0;i<N;i++){
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int> color(n+1,-1);
        queue<pair<int,int>> q;
        for(int i = 1;i<=n;i++){
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
                            int t = tempColor == 0 ? 1 : 0;
                            color[it] = t;
                            q.push({it,t});
                        }
                    }
                }
            }
            
        }
        return true;
    }
};