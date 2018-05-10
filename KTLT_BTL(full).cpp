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
long k;
long n,m;
char *p1,*p2;
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
void Quick_Sort(long L, long R,char*p){
	int i,j;
	char pivot;
	i = L;
	j = R;
	pivot = p[L+ rand()%(R-L+1)];
	do{
		while(p[i] < pivot) i++;
		while(p[j] > pivot) j--;
		if( i<=j){
			swap(p[i],p[j]);
			i++;j--;
		}
	} while( i<=j);
	if( i < R) Quick_Sort(i,R,p);
	if( j > L) Quick_Sort(L,j,p);
}
//===================================================
bool algorithm1(){
    long i,j;
    bool mark[k] = {};// initialization array check_off
    f(i,0,k){
	   char flag=0;
       f(j,0,k){
		if((p1[i] == p2[j]) && mark[j] == false){
            mark[j] = true;
            flag =1;
            break;
          }
       }
       if( !flag)
			return false;
    }
    return true;
}
//===================================================
bool algorithm2(){
    long i;
    Quick_Sort(0,k-1,p1);
    Quick_Sort(0,k-1,p2);
    f(i,0,k){
        if(p1[i] != p2[i]) return false;
    }
    return true;
 }
//===================================================
bool algorithm3(){
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
bool algorithm4(){
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
	if(check_size(k1,k2)){
		k=k1;
		if(algorithm4()){
			printf("LA XAU DAO!!\n");
		}
		else
			printf("KHONG LA XAU DAO\n");
	}
	else
		printf("KHONG LA XAU DAO\n");
	delete p1;
	delete p2;
}

