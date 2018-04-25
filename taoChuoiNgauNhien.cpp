#include<bits/stdc++.h>
using namespace std;
void creatData(char* fn,long n){
	FILE*f = fopen(fn,"w");
	char ch;
	for(int i =0;i<n;i++){
		ch = 65 +rand()%26;
		fprintf(f,"%c",ch);
	}
}
int main(){
	creatData("chuoi1.txt",600000);
	creatData("chuoi2.txt",600000);
}