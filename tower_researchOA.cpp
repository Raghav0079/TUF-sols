#include <bits/stdc++.h> 
using namespace std;
typedef long long int ll; 

bool check(ll c,vector<ll> a, vector<ll> b){
	ll n = a.size();
	ll m = b.size(); 
	if(m*c<n){
		return false; 
	}
	
	
	//[0....c-1](0),[c...2*c-1](1),.... 
	for(ll i=0;i<=n-1;i++){
		ll d = i/c; 
		ll j = d ; 
		if(a[i]<=b[j]){
			
		}else{
			return false; 
		}
		
	}
	
	
	return true; 
}



int main(){
	
	ll n;
	cin>>n;
	vector <ll> a(n,0); 
	for(ll i=0;i<=n-1;i++){
		cin>>a[i];
	}
	ll m;
	cin>>m; 
	vector <ll> b(m,0); 
	for(ll i=0;i<=m-1;i++){
		cin>>b[i];
	}
	
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end()); 
	ll rounds = 0; 
	if(b[0]>=a[0]){
		
		
		ll c = 1 ; 
		while(c<=n){
			
			if(check(c,a,b)==true){
				rounds = c;	
				c = n + 5 ;
			}else{
				
			}
			
			
			c++;
		}
		cout<<(2*rounds-1);
		
		
	}else{
		cout<<"-1";
	}
	
	
	
	
	
	
	return 0; 
}

