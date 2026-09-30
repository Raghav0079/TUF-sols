#include <bits/stdc++.h> 
using namespace std;
typedef long long int ll; 

int main() {
	string s;
	cin>>s;
	ll n = s.size();
	s = '1' + s; //converting string to 1-based indexing 
	ll x,y;cin>>x>>y; 
	vector <ll> dp(n+1,1e18);
	dp[0] = -1*y; 
	for(ll i=1;i<=n;i++){
		ll cost = 1e18;
		unordered_map <ll,ll> k; 
		for(ll j=i;j>=1;j--){
			//[j....i]
			k[s[j]]++;
			ll g = 0; 
			for(char c='a';c<='z';c++){
				ll m = k[c];
				g = g + (m*(m-1))/2 ;
			}
			ll p = g*x; 
			cost = min(cost,y + dp[j-1] + p);
		}
		dp[i] = cost; 
		//cout<<dp[i]<<"\n";
	}
	cout<<dp[n]; 
	
	return 0;
}