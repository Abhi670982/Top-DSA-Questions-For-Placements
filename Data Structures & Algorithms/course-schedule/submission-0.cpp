class Solution {
public:
    bool dfs(int node,
             vector<vector<int>>& graph,
             vector<bool>& visited,
             vector<bool>& pathVisited) {

        visited[node] = true;
        pathVisited[node] = true;

        for (int neigh : graph[node]) {

            if (!visited[neigh]) {

                if (dfs(neigh, graph, visited, pathVisited))
                    return true;

            }
            else if (pathVisited[neigh]) {

                return true;
            }
        }

        pathVisited[node] = false;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);

        for (auto &edge : prerequisites) {

            int course = edge[0];
            int prerequisite = edge[1];

            graph[prerequisite].push_back(course);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> pathVisited(numCourses, false);

        for (int i = 0; i < numCourses; i++) {

            if (!visited[i]) {

                if (dfs(i, graph, visited, pathVisited))
                    return false;
            }
        }

        return true;
    }
};