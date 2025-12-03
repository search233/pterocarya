//P1303

#include<iostream>

using namespace std;

int main()
{
	int a[2000]={0}, b[2000]={0};
	int lena=0, lenb=0;
	char ch;
	
	//用a，b记录两数，从1到len; 
	while((ch=getchar())<'0' || ch>='9');
	a[++lena] = ch - '0';
	while((ch=getchar())>='0' && ch<='9') a[++lena] = ch - '0';
	
	while((ch=getchar())<'0' || ch>='9');
	b[++lenb] = ch - '0';
	while((ch=getchar())>='0' && ch<='9') b[++lenb] = ch - '0';
	
	
	if((lena==1 && a[1]==0) || (b[1]==0 && lenb==1)){
		cout << 0 << endl;
	}else{
		 
		int t1=0, t2=0, temp=0;
		int out[4001]={0}, pos=0;
		
		for(int i=lenb ; i>0 ; --i){
			 
			//POS记录起始位置，temp记录每一位上加得的数字
			//t1记录进位情况，每次都将temp加入到out中，用t2进位 
			for(int j=lena,k=0 ; j>=0 ; --j,++k){			 
				temp = b[i] * a[j] + t1;
				t1 = temp / 10;
				temp %= 10;
				
				out[k+pos] += temp + t2;
				t2 = out[k+pos] / 10;
				out[k+pos] %= 10;
	 		}
			++pos; 
		}
		for(pos=4000 ; !out[pos] ; --pos);
		for( ; pos>=0 ; --pos) cout << out[pos];		
	}
		
	return 0;
}
