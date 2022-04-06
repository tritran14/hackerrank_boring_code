#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define trace(...) debug(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void debug(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void debug(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " | ";
  debug(comma + 1, args...);
}
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


const int INF=1000000000+5;
const int N=2e5+5;
//~ const int N=30+5;
const int M=1000+5;
const ll oo=1ll<<60;
const int mod=998244353;		

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,r;
	cin>>n>>m>>r;
	vector<vector<int>> a(n,vector<int>(m));
	vector<vector<int>> ans(n,vector<int>(m));
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j) cin>>a[i][j];
	}
	vector<vector<int>> id(n,vector<int>(m));
	vector<int> val(n*m);
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j) id[i][j]=i*m+j,val[i*m+j]=a[i][j];
	}
	
	auto inSide=[&](int x,int y,int nn,int mm,int loop){
		return x>=loop&&x<nn&&y>=loop&&y<mm;
	};
	
	for(int loop=0;loop<min(n,m)/2;++loop){
		int dir=0;
		int x=loop,y=loop;
		vector<int> ids;
		ids.push_back(x*m+y);
		while(1){
			x+=dx[dir];
			y+=dy[dir];
			if(x==y&&x==loop) break;
			if(inSide(x,y,n-loop,m-loop,loop)) ids.push_back(x*m+y);
			else {
				x-=dx[dir];
				y-=dy[dir];
				dir=(dir+1)%4;
			}
		}
		//~ cout<<"ids : ";
		//~ for(int x:ids) cout<<x<<" ";
		//~ cout<<endl;
		vector<int> n_ids=ids;
		for(int i=0;i<(int)n_ids.size();++i) n_ids[i]=ids[(i+r)%(int)n_ids.size()];
		//~ cout<<"n_ids : ";
		//~ for(int x:n_ids) cout<<x<<" ";
		//~ cout<<endl;
		for(int i=0;i<(int)ids.size();++i){
			int nx=n_ids[i]/m;
			int ny=n_ids[i]%m;
			
			int ox=ids[i]/m;
			int oy=ids[i]%m;
			ans[nx][ny]=a[ox][oy];
		}
	}
	//~ cout<<"ans < "<<endl;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j) cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}


