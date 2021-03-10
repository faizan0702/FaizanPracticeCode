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
vector<int> disjoint_set;

int find_Absolute_Parent(int v){
	if(disjoint_set[v] == -1)
		return v;
	find_Absolute_Parent(disjoint_set[v]);
}

void union_of_set(int from , int to){
	disjoint_set[to] = from;
}

bool isCycle(vector<pair<int,int>> edge_list){
	for(auto &edge : edge_list){
		int to = find_Absolute_Parent(edge.first);
		int from = find_Absolute_Parent(edge.second);
		
		if(to == from)
			return true;
		union_of_set(from , to);

	}
	return false;
}
int main(){
	//#ifndef ONLINE_JUDGE
  	//	freopen("input.txt", "r", stdin);
  	//	freopen("output.txt", "w", stdout);
	//#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int vertex , edge;
	cin >> vertex>>edge;
	disjoint_set.resize(vertex+1,-1);
    vector<pair<int,int>> edge_list;
	for(int i =0;i<edge;i++){
		int to , from ;
		cin >> from >> to;
		edge_list.push_back(make_pair(from,to));
	}

	if(isCycle(edge_list))
		cout<< " cycle is present";
	else
		cout <<"cycle is not present";

	return 0;
}
