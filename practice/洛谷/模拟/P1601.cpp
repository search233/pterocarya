//P1601

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int a[510]={0}, b[510]={0};
	char ch;
	int lena=0, lenb=0;
	
	while((ch=getchar())>='0' && ch<='9'){
		a[++lena] = ch-'0';
	}
	
	while((ch=getchar())>='0' && ch<='9'){
		b[++lenb] = ch-'0';	
	}
	
	if(lena==1 && lenb==1 && a[1]==0 && b[1]==0){
		cout << 0;
	}else{
		int out[510]={0}, temp=0;
		int len = max(lena,lenb);
		for(int i=0 ; i<=len ; ++i){
			int A, B;
			if(lena>-1) A=a[lena--];
			else A=0;
			if(lenb>-1) B=b[lenb--];
			else B=0;		
			out[i] = A + B + temp;
			temp = out[i] / 10;
			out[i] %= 10;
		}
		
		for(temp=500 ; !out[temp] ; --temp);
		
		for( ; temp>=0 ; --temp){
			cout << out[temp];
		}
	}
	return 0;
}
