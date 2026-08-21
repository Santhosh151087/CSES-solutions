/*
 * Problem Name: Range_Update_Queries
 * Language: C++
 * Category: Range_Queries
 * Date: 2026-08-21
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 4e18	
vector<ll> seg;
ll find(ll Node , ll nl , ll nr , ll ind){
	if(ind<nl || ind>nr)
	return 0;
	if(nl == nr)
	return seg[Node];
	ll mid = (nl+nr)/2;
	ll left = find(Node*2 , nl , mid ,ind);
	ll right = find(Node*2+1 , mid+1 , nr , ind);
	return seg[Node] + left + right;
}
void update(ll Node , ll nl , ll nr , ll ql , ll qr , ll inc){
	if(ql > nr ||nl>qr)
	return ;
	if(ql>=nl && qr<=nr){
		seg[Node]+= inc;
		return;
	}
	int mid = (nl+nr)/2;
	update(Node*2 , nl , mid , ql , qr , inc);
	update(Node*2+1 , mid+1 , nr , ql , qr , inc);
}
void print(vector<ll> arr){
	for(int n:arr)cout<<n<<" ";
	cout<<endl;
}
int main(){
	ll N , Q;
	cin>>N>>Q;
	ll newN = 1;
	while(newN < N) newN = newN << 1;
	
	 seg.resize(newN + newN , 0);
	 
	for(int i=newN ;i<newN+N ;i++){
		cin>>seg[i];
	}
	N = newN;
	// print(seg);
	while(Q -- >0){
		ll q;
		cin>>q;
		if(q==2){
			int ind ;
			cin>>ind;
			cout<<find(1 , 1 , N , ind)<<endl;
		}
		else{
			int start , stop , inc;
			cin>>start>>stop>>inc;
			update(1 , 1 , N , stop , stop , inc);
		}
	}
	
	
}