#include <string>
#include <vector>
#include <iterator>   //insert

using namespace std;

string solution(string s) {
    string answer = "";
    vector<char> v(s.begin(), s.end());
    
    if((v.size()%2) == 0){
        answer.insert(0,1,v.at((v.size()/2)-1));
        answer.insert(1,1,v.at((v.size()/2)));
    }
    else{
        answer = v.at(v.size()/2);
    }
    
    return answer;
}
