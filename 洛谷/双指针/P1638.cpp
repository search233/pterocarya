//P1638

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int a, b;
    int n, m; cin >> n >> m;

    vector<int> arr(n);
    vector<int> judge(m+10);

    for(int i=0 ; i<n ; ++i)  cin >> arr[i];
    fill(judge.begin(), judge.end(), 0);

    int tag1, tag2, flag;
    flag = tag1 = tag2 = 0;
    int min=n+1;
    judge[arr[0]] = 1;
    while(tag2<n-1){

        ++tag2;
        ++judge[arr[tag2]];

        while(judge[arr[tag1]]>1){
            --judge[arr[tag1++]];
        }

        for(int i=1 ; i<=m ; ++i){
            if(!judge[i]) break;
            if(i==m) flag=1;
        }

        if(flag){
            if(tag2-tag1+1 < min){
                a=tag1; b=tag2;
                min=tag2-tag1+1;
            }
        }
    }

    cout << a+1 << ' ' << b+1;

    return 0;
}
