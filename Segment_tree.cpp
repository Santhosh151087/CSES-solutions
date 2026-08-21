	#include<bits/stdc++.h>
	using namespace std;
	#define ll long long int
	#define INF 2e9
	int find(vector<int>& seg , int node , int nl , int nr , int ql , int qr){
		// no overlap
		if(nr < ql || nl>qr)
		return INF;
		// Node range completely inside query range 
		if(nl>=ql && nr<=qr)
		return seg[node];
		// partially overlap
			
		int mid = (nl+nr)/2;
		int leftval = find(seg , node*2 ,nl , mid,ql , qr );
		int rightval = find(seg , node*2+1 , mid+1 , nr , ql , qr);
		return min(leftval , rightval);
		}
	int main(){
		
		int N , Q;
		cin>>N>>Q;
		int newN = 1;
		while(newN < N)newN = newN<<1;
	
		vector<int> seg(newN + newN , INT_MAX);
		for(int i=newN; i<newN+N;i++){
			cin>>seg[i];
		}
		for(int i= newN -1;i>=1;i--){
			seg[i] = min(seg[i*2], seg[i*2+1]);
		}
		N = newN;
		while(Q-- > 0){
			int start , end;
			cin>>start>>end;
			cout<< find(seg , 1 ,1 , N , start , end)<<endl;
		}
	}
		
	
