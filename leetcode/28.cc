/** https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
c++의 std::find는 해당 문자열이 발생한 위치를 반환한다. 없으면 -1
만약 두번재의 문자를 찾고 싶다면 .find(<찾을문자>, <첫번째 문자 위치 + 1>)을 해주면 된다.
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
}
