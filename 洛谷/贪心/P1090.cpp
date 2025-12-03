//P1090

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int n, s=0; cin >> n;
    priority_queue<int, vector<int>, greater<int> > q;

    for(int i=0 ; i<n ; ++i){
        int t; cin >> t;
        q.push(t);
    }

    while(q.size()>=2){
            int a=q.top(); q.pop();
            int b=q.top(); q.pop();
            s+=a+b;
            q.push(a+b);
        }

    cout << s;

    return 0;
}