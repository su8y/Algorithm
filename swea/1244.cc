/* 최대 상금: https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15Khn6AN0CFAYD&categoryId=AV15Khn6AN0CFAYD&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1 */
#include <deque>
#include <iostream>
#include <string>
#include <set>
using namespace std;

int M;
string maxAnswer;
set<pair<string, int>> visited;
void dfs(string &s, int deps) {
    if(deps >= M) {
        maxAnswer = max(maxAnswer, s);
        return;
    }
    for (int left = 0; left < s.size(); left++) {
        for (int right = left + 1; right < s.size(); right++) {
            swap(s[left], s[right]);
            if(visited.count({s, deps + 1}) == 0) {
                visited.insert({s, deps + 1});
                dfs(s, deps + 1);
            }
            swap(s[left], s[right]);
        }
    }
}
int main(int argc, char **argv) {
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        string s;
        maxAnswer = "0";
        visited.clear();
        cin >> s >> M;
        visited.insert({s, 0});
        dfs(s, 0);

        cout << "#" << test_case << " " << stoi(maxAnswer) << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}