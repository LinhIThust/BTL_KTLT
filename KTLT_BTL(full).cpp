/*
>>>>>>>>>>>>>>>>>programming techniques :subject1<<<<<<<<<<<<<<<<<<<<<<<<
							Group 28
GVHD:  ThS. Bùi Thị Mai Anh
copyright ©
1.	ĐỒNG QUANG LINH     20162385    CNTT1.01 - K61
2.	ĐỖ MINH HIẾU    	20161505   	CNTT1.01 - K61
3.	NGUYỄN TIẾN QUANG   20163312  	CNTT1.01 - K61
*/
#include<bits/stdc++.h>
#include<time.h>
#define f(i,a,b) for(long i=a;i<b;i++)
using namespace std;
long k1,k2;
long n,m;
char* p1;
char* p2;

int sizeoffile(char* fn){
	long size;
	FILE* f=fopen(fn,"r");
	if(!fseek(f, 0, SEEK_END))
		size = ftell(f);
	fclose(f);
	return size;
}
//===================================================
bool check_size(long k1,long k2){
	if(k1==k2 && k1!=0 && k2 !=0){
		return true;
	}
	return false;
}
//===================================================
int readFile(char* fn,char*p) {
	FILE* f= fopen(fn,"r");
	char ch;
	long i=0;
		while(1){
			fscanf(f,"%c",&ch);
		if(feof(f)){
			break;
		}
		if((ch >=65 && ch<=90)||
			(ch>=97 && ch<=122)){
				p[i]=toupper(ch);
				i++;
		}
	}
    fclose(f);
	return i;
}
//===================================================
//<quick_sort for algorithm2>
int Partition(char *p, long L, long R, long Index_Pivot){

    char Pivot = p[Index_Pivot];
    swap(p[Index_Pivot],p[R]);
    long Store_Index = L;
    long i;
	f(i,L,R-1){
        if(p[i] < Pivot){
            swap(p[Store_Index],p[i]);
            Store_Index++;
        }
    }
    swap(p[Store_Index],p[R]);
    return Store_Index;
}
//===============
void Quick_Sort(char *p, long L, long R){
    if(L < R){
        long Index = L;
        Index = Partition(p,L,R,Index);
        if(L < Index)
            Quick_Sort(p,L,Index-1);
        if(Index < R)
            Quick_Sort(p,Index+1,R);
    }
}
//===================================================
bool algorithm1(char *p1,char* p2, long k){
    long i,j;
    bool mark[k] = {};// initialization array check_off
    f(i,0,k){
	   char nbMark=0;
       f(j,0,k){
		if((p1[i] == p2[j]) && mark[j] == false){
            mark[j] = true;
            nbMark =1;
            break;
          }
       }
       if( !nbMark)
			return false;
    }
    return true;
}
//===================================================
bool algorithm2(char *p1,char* p2, long k){
    long i;
    Quick_Sort(p1,0,k-1);
    Quick_Sort(p2,0,k-1);
    f(i,0,k){
        if(p1[i] != p2[i]) return false;
    }
    return true;
 }
//===================================================
bool algorithm3(char *p1,char* p2, long k){
	f(i,0,k){
		char nbSwap=0;
		f(j,i,k){
			if(p1[j]==p2[i]){
				nbSwap++;
				swap(p1[i],p1[j]);
				break;
			}
		}
		if(!nbSwap) return false;
	}
	return true;
}
//===================================================
bool algorithm4(char *p1,char* p2, long k){
	long i1=0,i2=0;
	long counter[26];
	f(i,0,25) counter[i] =0;
	f(i,0,k){
		i1=p1[i]-65;//return code ASCII
		i2=p2[i]-65;
		counter[i1]++;
		counter[i2]--;
	}
		f(i,0,25) {
			if(counter[i]!=0) {
				return false;
			}
	}
	return true;
}
int main(){
	n=sizeoffile("chuoi1.txt")+3;
	m=sizeoffile("chuoi2.txt")+3;
	p1 = new char[n];
	p2 = new char[m];
	k1=readFile("chuoi1.txt",p1);
	k2=readFile("chuoi2.txt",p2);
	cout<<k1<<endl;
	if(check_size(k1,k2)){
		if(algorithm4(p1,p2,k1)){
			printf("LA XAU DAO!!\n");
		}
		else
			printf("KHONG LA XAU DAO\n");
	}
	else
		printf("KHONG LA XAU DAO\n");
}

