#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007LL
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define For(i,a,b) for(int i=(a);i<(b);i++)
#define forr(i,n) for(int i=(n);i>=0;i--)
#define clr(a,b) memset(a,b,sizeof(a))

#define pb push_back
#define fi first
#define se second
#define mkp make_pair

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int LIS(vector<int>& arr ,vector<int>& dp , int i){
	int n = arr.size();
	dp[0] =1;
	for(int i =0;i<n;i++){
		for(int j =i-1;j>=0;j--){
				if(arr[i] > arr[j])
					dp[i] = max(dp[i] , dp[j]+1);
		}
	}
	return dp[n-1];
}

int main(){
	int n ; 
	cin >>n;
	vector<int> arr(n) , dp(n,1);
	
	for(int i = 0 ; i < n ;i++){
		cin >> arr[i];
	}

	cout << LIS(arr , dp , 0);

	return 0;
}
