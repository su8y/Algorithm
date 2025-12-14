class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int answer = 0; 

        for(int i=0;i<n;i++) {
            cout << answer << endl;
            int l = RTI(s[i]);
            if(i < n-1){
                int r = RTI(s[i+1]);
                if(l < r) {
                    answer +=  arr[r] - arr[l];
                    i++;
                    continue;
                } 
            }

            answer += arr[l];
        }

        return answer;
    }
private:
    int arr[8] = {1, 5, 10, 50, 100, 500, 1000};
    int RTI(char ch){
        if(ch=='I') return 0;
        else if(ch=='V') return 1;
        else if(ch=='X') return 2;
        else if(ch=='L') return 3;
        else if(ch=='C') return 4;
        else if(ch=='D') return 5;
        else return 6; // M
    }
};
