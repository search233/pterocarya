//P1252

#include <iostream>

using namespace std;

struct node{
    int pos;
    int time[10];
    int jude[10];
}list[5];

int main(){

    int sum = 0, left=20;
    for(int i=0 ; i<5 ; ++i){
        list[i].pos = 1; 
        for(int j=0 ; j<10 ; ++j)   cin >> list[i].time[j];
        // sum += list[i].time[0];
    }

    for(int i=0 ; i<5 ; ++i){
        for(int j=9 ; j>0 ; --j){
            list[i].jude[j] = list[i].time[j] - list[i].time[j-1];
        }
    }

    while(left){

        int min = list[0].jude[list[0].pos], p=0, t;
        for(int i=1 ; i<5 ; ++i){
            t = list[i].jude[list[i].pos];
            if(t < min && list[i].pos < 10){
                min = t;
                p = i;
            }
        }
        --left;
        ++list[p].pos;
    }
    
    // sum = 0;
    for(int i=0 ; i<5 ; ++i){
        sum += list[i].time[list[i].pos-1];

    }
    cout << sum << endl;
    for(int i=0 ; i<5 ; ++i){
        if(!i) cout << list[i].pos;
        else   cout << ' ' << list[i].pos;
    }
    return 0;
}


