class Solution {
public:

    bool dfs(int node,
             vector<vector<int>>& graph,
             vector<bool>& visited,
             vector<bool>& pathVisited,
             vector<int>& ans){

        visited[node] = true;
        pathVisited[node] = true;

        for(int neigh : graph[node]){

            if(!visited[neigh]){

                if(dfs(neigh,graph,visited,pathVisited,ans))
                    return true;

            }
            else if(pathVisited[neigh]){

                return true;
            }
        }

        pathVisited[node] = false;

        ans.push_back(node);

        return false;
    }

    vector<int> findOrder(int numCourses,
                          vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);

        for(auto &edge : prerequisites){

            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(numCourses,false);
        vector<bool> pathVisited(numCourses,false);

        vector<int> ans;

        for(int i=0;i<numCourses;i++){

            if(!visited[i]){

                if(dfs(i,graph,visited,pathVisited,ans))
                    return {};
            }
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};