/* 1206: https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV134DPqAA8CFAYh&categoryId=AV134DPqAA8CFAYh&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1 */
#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	for(test_case = 1; test_case <= 10; ++test_case)
	{
        /////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 입력 처리
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
        vector<int> arr;
        int N, answer=0; cin >> N;
        
        for(int i=0,tmp;i<N;i++) cin >>tmp, arr.push_back(tmp);
        
        /////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 조망권을 못받는 세대 업데이트 -2 ~ i ~ +2 만큼 max 값 갱신
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
        vector<int> test(N,0);
        
        for (int i=0;i<N;i++) {
            for(int effect=i-2;effect<=i+2;effect++) {
                if (effect == i) continue;
                if (effect < 0 || effect >= N) continue;
                test[effect] = max(test[effect], arr[i]);
            }
        }
        
        /////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 조망권 계산
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
        for (int i=0;i<N;i++) {
            if(arr[i] > test[i]) {
                answer += arr[i] - test[i]; // 최대 높이 - 조망권 최대 높이( 5 -- 7 ) 7 - 5
            }
        }
        
		cout << "#" << test_case << " " << answer << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}