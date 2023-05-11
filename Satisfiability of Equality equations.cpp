#include<vector>
#include<unordered_map>
#include<set>
#include<queue>
#include<string>
using namespace std;
//very bad solution beats only 5% on leetcode.
// class Solution {
// public:
//     bool equationsPossible(vector<string>& equations) {
//         int n  = equations.size();
//         vector<int> graph[26];
//         vector<int> visited(26,0);
//         unordered_map<int,set<int>> mp;
        
//         for(int i=0;i<n;i++){
//             string temp = equations[i];
//             int var1 = equations[i][0] - 'a';
//             int var2 = equations[i][3] - 'a';
//             if(var1 == var2 && equations[i][1] == '!')
//                 return false;  
//             if(equations[i][1] == '!'){
//                 mp[var1].insert(var2);
//                 mp[var2].insert(var1);
//             }else{
//                 graph[var1].push_back(var2);
//                 graph[var2].push_back(var1);
//             }
//         }

//         queue<int> q;
//         for(int i=0;i<26;i++){
//                 q.push(i);
//                 visited[i] = 1;
//                 while(!q.empty()){
//                     int temp = q.front();
//                     q.pop();
//                     for(auto it : graph[temp]){
//                         mp[temp].insert(mp[it].begin(),mp[it].end());
//                         mp[it].insert(mp[temp].begin(),mp[temp].end());
//                         if(mp[temp].find(it) != mp[temp].end())
//                                 return false;
//                         if(!visited[it]){
//                             visited[it] = 1;
//                             q.push(it);
//                         }
                        
//                     }
//                 }
        
//         }
//         return true;
//     }
// };

//best solution is to use DSU;
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int findParent(int i){
        if(i == parent[i])
            return i;
        return parent[i] = findParent(parent[i]);
    }
    void unionMerge(int i,int j){
        int pI = findParent(i);
        int pJ = findParent(j);
        if(pI == pJ)
            return;
        if(rank[pI] > rank[pJ]){
            parent[pJ] = pI;
            rank[pI]++; 
        }else{
            parent[pI] = pJ;
            rank[pJ]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        int n  = equations.size();
        vector<int> graph[26];
        vector<int> visited(26,0);
        unordered_map<int,set<int>> mp;
        for(int i=0;i<26;i++){
            parent.push_back(i);
            rank.push_back(1);
        }
        vector<pair<int,int>> notEqual;
        for(int i=0;i<n;i++){
            string temp = equations[i];
            int var1 = equations[i][0] - 'a';
            int var2 = equations[i][3] - 'a';
            if(var1 == var2 && equations[i][1] == '!')
                return false;  
            if(equations[i][1] == '!'){
                notEqual.push_back({var1,var2});
            }else{
                unionMerge(var1,var2);
            }
        }
        for(int i=0;i<notEqual.size();i++){
            int p1 = findParent(notEqual[i].first);
            int p2 = findParent(notEqual[i].second);
            if(p1 == p2)
                return false;
        }
        return true;
    }
};