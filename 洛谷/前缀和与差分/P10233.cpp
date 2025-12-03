//P10233

#include <iostream>

using namespace std;

int arr[10000010] = {0};

int func(char ch){
	int res=0;
	switch(ch){
		case'P' : res = 3; break;
		case'p' : res = 2; break;
		case'G' : res = 1; break;
	}
	return res;
}

int main()
{
	int T; cin >> T;
	char ch='0';

	for(int k=0 ; k<T; ++k){
		int cnt=0;
		getchar();
  		while((ch=getchar())!='\n') {
  	    	arr[++cnt] = func(ch);
   	    	arr[cnt] += arr[cnt-1];
  	 	}
	
	
    	int q; cin >> q;
    	for(int i=0 ; i<q ; ++i){
     	    int l, r; cin >> l >> r;
      		cout << arr[r] - arr[l-1] << '\n';
		}
	}
	
	return 0;
}
