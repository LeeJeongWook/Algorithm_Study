#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int cnt = 0;
    vector<int> v(n,1);
    
    for(int i=0; i<reserve.size(); i++){
        v[reserve[i]-1] += 1;
    }
    
    for(int i=0; i<lost.size(); i++){
        v[lost[i]-1] -= 1;
    }
    
    for(int i=0; i<n-1; i++){
        if(v[i] == 0){
            if(v[i-1] == 2){
                v[i] += 1;
                v[i-1] -= 1;
            }
            else if(v[i+1] == 2){
                v[i] += 1;
                v[i+1] -= 1;
            }
        }
    }
    
    for(int x : v){
        if(x == 0){
            cnt++;
        }
    }
    answer = n - cnt;
    
    return answer;
}
