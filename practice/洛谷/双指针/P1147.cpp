//P1147

#include <iostream>

using namespace std;

int main(){
    int m; cin >> m;

    int tag1, tag2; tag1 = tag2 = 0;
    int sum=0, t=m/2;

    while(tag2<=t){
        if(sum < m)    sum += ++tag2;
        if(sum > m)    sum -= tag1++;
        if(sum == m){
            cout << tag1 << ' ' << tag2 << '\n';
            sum -= tag1++;
        }
    }

    return 0;
}