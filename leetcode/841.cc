// 841: https://leetcode.com/problems/keys-and-rooms/?envType=study-plan-v2&envId=graph-theory
class Solution {
public:
    // 메모리를 사용하지만 SOF 안전
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int> st;
        vector<bool> visited(rooms.size(), false);
        visited[0] = true;
        st.push(0);
        int count = 0;

        while(!st.empty()) {
            int curRoom = st.top(); st.pop();
            count++;
            for(auto nextRoom: rooms[curRoom]) {
                if(visited[nextRoom]) continue;

                st.push(nextRoom);
                visited[nextRoom] = true;

            }
        }
        return count == rooms.size();
    }
    // 메모리 효율적 시간 복잡도 매우 빠름 
// private: 
//     vector<bool> visited;

//     void recursiveVisit(int currentRoom, vector<vector<int>> &rooms) {
//         if (visited[currentRoom]) return;
//         visited[currentRoom] = true;

//         for(auto nextRoom: rooms[currentRoom]) {
//             recursiveVisit(nextRoom, rooms);
//         }
//     }
// public:
//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
//         visited = vector(rooms.size(), false);
//         recursiveVisit(0, rooms);

//         for(auto x : visited) {
//             if (x == false) return false;
//         }
//         return true;
//     }
};
