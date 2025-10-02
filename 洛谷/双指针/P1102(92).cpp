//P1102

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, c; cin >> n >> c;

    vector<int> a;

    for(int i=0 ; i<n ; ++i){
        int t; cin >> t;
        a.push_back(t);
    }

    sort(a.begin(), a.end());

    int cnt, tag, temp;
    cnt = tag = temp = 0;

    for(int i=0 ; i<n ; ++i){
        int num = a[i] + c;
        if(num > a[n-1]) break;
        tag = temp;
        while(tag<n && a[tag] < num) ++tag;
        temp = tag; 

        while(tag<n && a[tag]==num){
            ++cnt;
            ++tag;
        }
    }

    cout << cnt;

    return 0;
}