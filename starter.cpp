#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int t, k, l,d,p=0,q=0,r,an;
	cin>>t;
	while(t--){
		cin>>k;
		cin>>l;
		if(k>l){
			d = k-l;
			r = max(d,p);
			cout<<r;
			if(r==d) an = 1;
			if(r==p) an =2;
		}
		else {
			p= l-k;
			r = max(d,p);
			cout<<r;
			if(r==p) an =2;
			if(r==d) an = 1;
		}
	}
	cout<<r;
	cout<<"\t";
	cout<<an;
	//freopen("INPUT_FILE_NAME.txt","r",stdin);
	//freopen("OUTPUT_FILE_NAME.txt","r",stdout);
	//return 0;
}