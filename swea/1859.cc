/* 1859: https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LrsUaDxcDFAXc&categoryId=AV5LrsUaDxcDFAXc&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1# 
미래의 가격을 알고 있다면 미래에서 부터 시작하여 최대 값을 갱신하여 판매한다. 
엣지 테스트 케이스
0 0 0 0 = 0
3 2 1 = 0
1 4 2 3 = 4
*/
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        vector<int> arr;
        cin >> N;
        for (int i=0, tmp;i<N;i++) cin >> tmp, arr.push_back(tmp);
		long long answer = 0;
        int mx = 0;
        for (int i=N-1;i>=0;i--) {
            if (arr[i] > mx) {
                mx = arr[i];
            } else {
                answer += mx - arr[i];
            }
        }
        cout << "#" << (test_case) << " " << answer << endl;
	}
	return 0;
}