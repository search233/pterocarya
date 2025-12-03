//P1786

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct L{
	string name;
	string duty;
	int cbt;
	int level;
	int rank;
};

bool cmp1(L a, L b){
	if(a.cbt!=b.cbt)  
	return a.cbt > b.cbt;
	else	 return a.rank<b.rank;
}

bool cmp2(L a, L b){
	if(a.duty==b.duty) {
		if(a.level==b.level)
			return a.rank < b.rank;
		else
			return a.level > b.level;
	}
} 


int main()
{
	int n; cin >> n;
	vector<L> list(n);
	int pos=0;
	
	for(int i=0 ; i<n ; ++i){
		list[i].rank = i;
		cin >> list[i].name >> list[i].duty >> list[i].cbt >> list[i].level;
	}
	
	do{ ++pos;}while(list[pos].duty=="Bangzhu" || list[pos].duty=="FuBangZhu");
	
	sort(list.begin()+pos, list.end(), cmp1);
	
	for(int i=pos, j=1; i<n ; ++i, ++j){
		if(j==1 || j==2) 		list[i].duty="HuFa";
		else if(j>=3 && j<=6) 	list[i].duty="ZhangLao";
		else if(j>=7 && j<=13)	list[i].duty="TangZhu";
		else if(j>=14 && j<=37)	list[i].duty="JingYing";
		else					list[i].duty="BangZhong"; 
	}
	
	sort(list.begin(), list.end(), cmp2);
	
	for(int i=0 ; i<n ; ++i) cout << list[i].name << ' ' << list[i].duty  << ' ' << list[i].level << '\n';
	
	return 0; 
}

// 2 4 7 25
