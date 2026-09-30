#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

typedef tree<
    pair<ll,ll>,
    null_type,
    less<pair<ll,ll>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

int main(){
	
	ll n;ordered_set st;
	cin>>n;vector <ll> a(n+1,0); 
	for(ll i=1;i<=n;i++){
		ll y;cin>>y; a[i] = y;
		st.insert({y,i});
	}
	
	ll sum = 0;ll used[n+1]={0};  
	while(!(st.empty())){
		auto it = st.begin();
		ll number = it->first;
		ll index = it->second;
		sum = sum + number; 
		ll v;
		if(index-1>=1 && used[index-1]==0){
			v = a[index-1];
			st.erase({v, index-1});
			used[index-1] = 1;
		}
		
		if(index+1<=n && used[index+1]==0){
			v = a[index+1];
			st.erase({v,index+1}); 
			used[index+1] = 1; 
		}
		st.erase({number,index}); 
		used[index] = 1; 
	}
	cout<<sum;
	
	return 0; 
}