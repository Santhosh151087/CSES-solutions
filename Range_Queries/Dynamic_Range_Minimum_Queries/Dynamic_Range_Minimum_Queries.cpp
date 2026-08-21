/*
 * Problem Name: Dynamic_Range_Minimum_Queries
 * Language: C++
 * Category: Range_Queries
 * Date: 2026-08-21
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 4e18	
ll find(vector<ll>& seg  , ll Node , ll nl , ll nr ,ll ql ,ll qr){
	if(nl>qr ||nr <ql )
	return INF;
	if(ql<=nl && qr>=nr)
	return seg[Node];
	ll mid = (nl+nr)/2;
	return min(find(seg , Node*2 , nl , mid , ql , qr) , find(seg , Node*2+1 , mid+1 , nr , ql ,qr));
}
void update(vector<ll>& seg , ll Node , ll nl , ll nr , ll ind , ll val ){
	if(ind<nl || ind>nr)
	return;
	if(nl == nr){
	seg[Node] = val;
	return;
	}
	int mid = nl +(nr -nl)/2;
	update(seg , Node*2 , nl , mid , ind , val);
	update(seg , Node*2 +1 , mid+1 , nr , ind , val);
	seg[Node] =  min(seg[Node*2] , seg[Node*2+1]);
	return;
}
 
int main(){
	ll N , Q;
	cin>>N>>Q;
	ll newN = 1;
	while(newN < N) newN = newN << 1;
	vector<ll> seg(newN+newN , INF);
	for(ll i=newN;i<newN+N;i++){
		cin>>seg[i];
	}
	for(ll i=newN-1;i>=1;i--){
		seg[i] = min(seg[i*2] , seg[i*2+1]);
		
	}
	N = newN;
	while(Q-->0){
		ll q ;
		cin>>q;
		if(q==1){
			ll ind , val;
			cin>>ind>>val;
			update(seg , 1 ,1 , N,ind,val );
		}
		else{
			ll start , end;
			cin>>start>>end;
			cout<<find(seg ,1 , 1 ,N ,start , end  )<<endl;
		}
	}
}