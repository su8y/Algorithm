#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
const int HIT = 1;
const int MISS = 5;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if(cacheSize == 0) {
        return MISS * cities.size();
    }
    for(auto &s: cities) {
        for_each(s.begin(), s.end(), [](auto &c) {c = tolower(c);});
    }
    map<string, int> m;
    
    for(auto& s: cities) {
        if(m.count(s) /* cache hit */ ) {
            answer += HIT;
        } else  {
            answer += MISS;
            if(m.size() >= cacheSize) /* delete */ {
                int mn = 0;
                string key;
                for(auto& [k,v]: m) {
                    if(v > mn) {
                        mn = v;
                        key = k;
                    }
                }
                m.erase(key);
            }
        }
        for(auto& [k,v]: m) {
            v++;
        }
        
        m[s] = 1;
        
    }
    
    return answer;
}