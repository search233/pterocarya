//P1563

#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct R{
	string name;
	int head;
};

int main()
{
	int n, m;	cin >> n >> m;
	vector<R> row(n);
	for(int i=0 ; i<n ; ++i){
		cin >> row[i].head >> row[i].name;
	}
	
	int a, s, pos=0;
	for(int i=0 ; i<m ; ++i){
		cin >> a >> s;
		s %= n;
		
		if((a==0 && row[pos].head) || (a && row[pos].head==0)){ 		//逆时针 (增)
			pos += s;
			if(pos>=n)	pos -= n; 
		}else{
			pos -= s;
			if(pos<0)	pos += n;
		} 
	}
	
	cout << row[pos].name;
	
	return 0; 
}

/*
head=0 :朝内;  
head=1 :朝外; 

ai=0 向左;
ai=1 向右; 
*/
