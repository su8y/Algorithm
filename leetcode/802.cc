// 802. Find Eventual Safe States
// https://leetcode.com/problems/find-eventual-safe-states/?envType=study-plan-v2&envId=graph-theory

class Solution {
public:
    // O(NE)
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> outgoing(graph.size(), 0);
        vector<vector<int>> edge(graph.size(), vector<int>());
        queue<int> q;
        for (int i = 0; i < graph.size(); i++) {
            outgoing[i] = graph[i].size();
            if (graph[i].size() == 0)
                q.push(i); // terminal node
            for (auto x : graph[i]) {
                edge[x].push_back(i); // reverse graph ingoing
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto x : edge[cur]) {
                if (--outgoing[x] == 0) q.push(x);
            }
        }
        vector<int> answer;

        for (int i = 0; i < outgoing.size(); i++) {
            if (outgoing[i] == 0)
                answer.push_back(i);
        }
        return answer;
    }
    // O(N^3)
    // vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    //     vector<int> outgoing(graph.size(), 0); 
    //     queue<int> q;
    //     for(int i=0;i<graph.size();i++){
    //         outgoing[i] = graph[i].size();
    //         if (outgoing[i] == 0) q.push(i); // terminal node
    //     }

    //     while (!q.empty()) {
    //         int cur = q.front(); q.pop();
    //         for(int i=0;i<graph.size();i++){
    //             for(int j=0;j<graph[i].size();j++){
    //                 if (graph[i][j] == cur) {
    //                     if( --outgoing[i] == 0 ) q.push(i);
    //                 }
    //             }
    //         }
    //     }
    //     vector<int> answer;

    //     for(int i=0;i<outgoing.size();i++){
    //         if (outgoing[i] == 0) answer.push_back(i);
    //     }
    //     return answer;
    // }
};
