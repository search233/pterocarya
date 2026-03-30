//C6073

#include <iostream>
#include <queue>

using namespace std;

void judge(int a, int b, int *cnta, int *cntb);

int main(){
	int n, na, nb;
	cin >> n >> na >> nb;
	
	int t;
	queue<int> qa, qb;
	for(int i=0 ; i<na ; ++i){
		cin >> t;
		qa.push(t);
	}
	
	for(int i=0 ; i<nb ; ++i){
		cin >> t;
		qb.push(t);
	}
	
	int cnta, cntb;
	int a, b;
	cnta = cntb = 0;
	for(int i=0 ; i<n ; ++i){
		a = qa.front(); qa.pop();
		b = qb.front(); qb.pop();
		judge(a, b, &cnta, &cntb);
		qa.push(a);
		qb.push(b);
	}
	
	if(cnta > cntb) cout << 'A';
	else if(cnta < cntb) cout << 'B';
	else cout << "draw";
	
	return 0;
}

void judge(int a, int b, int *cnta, int *cntb){
	switch (a) {
		case 0:
			if(b==2) ++*cnta;
			else if(b==5) ++*cntb;
			break;
		case 2:
			if(b==5) ++*cnta;
			else if(b==0) ++*cntb;
			break;
		case 5:
			if(b==0) ++*cnta;
			else if(b==2) ++*cntb;
			break;
	}
}
