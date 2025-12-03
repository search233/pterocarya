//C6061

#include<stdio.h>

int score(int x);


int main()
{
	int a[3][3];
	int m, n;
	
	for(int i=0 ; i<3 ; i++){
		for(int j=0 ; j<3 ; j++){
			scanf("%d", &a[i][j]);
			if(a[i][j]==0){
				m=i; n=j;
			}
		}
	}
	
	int k;
	for(k=1 ; k<=9 ;){
			
		for(int i=0 ; i<3 ; i++){
			for(int j=0 ; j<3 ; j++){
				if (a[i][j]==k){
					goto next;
				}
				if(i==2 && j==2){
					a[m][n] = k;
					goto out;
				}
			}
		}
		next:
			k++;
	}
	out:
		k=0;
		
	int b[3][2];
	

	for(int i=0 ; i<3 ; i++){
		for(int j=0 ; j<2 ; j++){
			scanf("%d", &b[i][j]);
		}
	}
	
	
	int line, s=0;
	scanf("%d", &line);
	
	if(line<=3){
		
		for(int j=0 ; j<3 ; j++){
			s += a[line-1][j];
		} 
	}
	
	if(line<=6 && line>=4){
		
		for(int i=0 ; i<3 ; i++){
			s += a[i][line-4];
		}
	}
	
	
	if(line==7){
		
		for(int i=0,j=0; i<3 ; i++,j++){
			s += a[i][j];
		}
	}
	
	if(line==8){
		
		for(int i=0,j=2; i<3 ; i++,j--){
			s += a[i][j];
		}
	}	
	
	printf("%d\n", a[ b[0][0]-1 ][ b[0][1]-1 ]);
	printf("%d\n", a[ b[1][0]-1 ][ b[1][1]-1 ]);
	printf("%d\n", a[ b[2][0]-1 ][ b[2][1]-1 ]);
	
	printf("%d", score(s));
	
	return 0;	
}

int score(int x)
{
	int ret;
	
	switch (x) 
	{
		case 6:ret = 10000;	break;
		case 7:ret = 36;	break;
		case 8:ret = 720;	break;
		case 9:ret = 360;	break;
		case 10:ret = 80;	break;
		case 11:ret = 252;	break;
		case 12:ret = 108;	break;
		case 13:ret = 72;	break;
		case 14:ret = 54;	break;
		case 15:ret = 180;	break;
		case 16:ret = 72;	break;
		case 17:ret = 180;	break;
		case 18:ret = 119;	break;
		case 19:ret = 36;	break;
		case 20:ret = 306;	break;
		case 21:ret = 1080;	break;
		case 22:ret = 144;	break;
		case 23:ret = 1800;	break;
		case 24:ret = 3600;	break;		
	}
	return ret;
}
