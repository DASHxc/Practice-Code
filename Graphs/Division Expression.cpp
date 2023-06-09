#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
    void DFS(unordered_map<string,vector<pair<string,double>>> mp, unordered_map<string,int>& visited,string src,string des,double& retAns ,double temp){
        if(visited.count(src))
            return;
        if(src == des){
            retAns = temp;
            return;
        }
        visited[src]=1;
        for(auto it : mp[src]){
                DFS(mp,visited,it.first,des,retAns,(it.second*temp));
        }
        return;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        unordered_map<string,vector<pair<string,double>>> mp;
        for(int i=0;i<equations.size();i++){
            mp[equations[i][0]].push_back({equations[i][1],values[i]});
            mp[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
        }
        for(int i=0;i<queries.size();i++){
            string src = queries[i][0];
            string des = queries[i][1];
            double temp = 1.0 ;
            double retAns = -1.0;
            unordered_map<string,int> visited;
            if(mp.find(src) != mp.end())
                DFS(mp,visited,src,des,retAns,temp);
            ans.push_back(retAns);
        }
        return ans;
    }
};