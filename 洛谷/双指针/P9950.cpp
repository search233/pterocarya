//P9950

#include <iostream>
#include <string>
using namespace std;

int main(){
    int n; cin >> n;

    int cnt = -1;
    char ch, a[n];
    while(cnt<n-1){
        ch = getchar();
        if(ch=='G' || ch=='H'){
            a[++cnt] = ch;
        }
    }

    int list[n];
    cnt = -1;
    while(cnt<n-1){
        ch = getchar();
        if(ch=='G' || ch=='H'){
            ++cnt;
            if(ch==a[cnt]) list[cnt] = 0;
            else    list[cnt] = 1;
        }
    }

    for(int i=n-1 ; i>0 ; --i){
        if(list[i])
        list[i] = list[i] - list[i-1];
    }

    cnt = 0;
    for(int i=0 ; i<n-1 ; ++i){
        if(list[i]) ++cnt;
    }

    cout << cnt;

    return 0;
}