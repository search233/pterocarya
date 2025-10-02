//241125

#include <iostream>

using namespace std;

int main(){
	int list[20][6] = {{0}};
	
	cout << "输入参加人数"; 
	int n;	cin >> n;
	
	int pos=5, maxn, flag=0;
	for(int j=0 ; list[j][0]!=n ; ++j){
		
		int num=n;
		for(int i=pos ; i>0 ; --i){
			list[j][i] = num / i;
			if(i==pos) maxn = list[j][i];
			num -= list[j][i] * i;
			if(!num)	break;
		}
		list[j][0] = num;
		
		if(list[j][pos] + list[j][0]==n && maxn!=1)	--maxn;
		else if(list[j][0]==n-1)	--pos;
	}
	
}

//约瑟夫环(不确定)250102
