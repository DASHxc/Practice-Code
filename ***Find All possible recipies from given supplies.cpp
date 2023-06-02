#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
//Example of topological sorting... 
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> ans;
        int n = recipes.size();
        unordered_set<string> st;
        unordered_map<string,unordered_set<string>> graph;
        unordered_map<string,int> indegree;
        for(int i=0;i<n;i++){
            st.insert(recipes[i]);
            for(int j=0;j<ingredients[i].size();j++){
                graph[ingredients[i][j]].insert(recipes[i]);
                indegree[recipes[i]] = ingredients[i].size();
            }
        }
        queue<string> q;
        for(int i=0;i<supplies.size();i++){
            q.push(supplies[i]);
        }
        while(!q.empty()){
            string temp = q.front();
            //cout<<"** "<<temp<<endl;
            q.pop();
            if(st.find(temp) != st.end()){
                ans.push_back(temp);
            }
            for(auto it : graph[temp]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        // for(auto it : graph){
        //     cout<<"**"<<it.first<<endl;
        //     for(auto i1 : it.second){
        //         cout<<"->"<<i1<<"  ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};
