#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int rank;
    int id;
    char name[11];
    int math;
    int english;
    int chinese;
    int total;
}student;

int compare(const void *a, const void *b){
    student *sa = (student *)a;
    student *sb = (student *)b;
    if(sa->total != sb->total){
        return sb->total - sa->total;
    }else{
        return sb->id - sa->id;
    }
}   
    void rankfun(student *s, int n){
        int rank=2;
        s[0].rank=1;
        for(int i=1 ; i<n ; ++i){
            if(s[i].total == s[i-1].total){
                s[i].rank=s[i-1].rank;
            }else{
                s[i].rank=rank;
            }
            ++rank;
        }
    }
    
    void print(student *s, int n){
        for(int i=n-1 ; i>=0 ; --i){
            printf("%4d%10d%10s%5d%5d%5d\n", s[i].rank, s[i].id, s[i].name, s[i].math, s[i].english, s[i].chinese);
        }
    }
    
    int main(){
        int n;scanf("%d", &n);
        
        if(n >= 10){
            printf("Please input 1-9.\n");
            return 0;
        }
        
        student s[10];
        
        for(int i=0 ; i<n ; ++i){
              scanf("%d %s %d %d %d", &s[i].id, s[i].name, &s[i].math, &s[i].english, &s[i].chinese);
              s[i].total = s[i].math + s[i].english + s[i].chinese;
        }
        
        qsort(s, n, sizeof(student), compare);
        
        rankfun(s,n);
        print(s,n);
        
        return 0;
    }
