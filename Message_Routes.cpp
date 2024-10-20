   
   #include<bits/stdc++.h>  
   using namespace std;

//-----------------------------------------------------------------------------------------
   #define hi_bro         ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   #define test           int T; cin>>T; for(int t=1;t<=T;t++)
   #define ll             long long
   #define ld             long double
   #define yes            cout<<"YES"<<endl
   #define no             cout<<"NO"<<endl
   #define f(i,x,n)       for(int i = x; i < n; i++)
   #define fo(i,x,n)      for(int i=x;i>=n;i--)
   #define pb             push_back
   #define pp             pop_back()
   #define fi             first
   #define se             second
   #define all(v)         (v).begin(), (v).end()
   #define array_le_le    ll a[n]; f(i,0,n){cin>>a[i];}
//-----------------------------------------------------------------------------------------


const int mod=1e9+7;


void solve()
{           
   
   int n,m;
   cin>>n>>m;
   
   vector<int> g[n+1];
   
   for(int i=0;i<m;i++){
   	int x,y;
   	cin>>x>>y;
   	g[x].pb(y);
   	g[y].pb(x);
   	
   }
   
   set<pair<int,int>> st;
   vector<int> dist(n+1,1e9),par(n+1,0);
   dist[1]=0;
   st.insert({0,1});
   while(st.size()>0){
   	auto curr=*st.begin();
   	st.erase(st.begin());
   	int w=curr.fi,node=curr.second;
   	  for(auto &val:g[node]){
   	  	 if(w+1<dist[val]){
   	  	 	dist[val]=w+1;
   	  	 	par[val]=node;
   	  	 	st.insert({w+1,val});
   	  	 }
   	  }
   }
   
   int curr=n;
   if(dist[n]==1e9){
      cout<<"IMPOSSIBLE";
      return;
   }
   cout<<dist[n]+1<<"\n";
   vector<int> v;
   while(curr!=1){
   	v.pb(curr);
   	curr=par[curr];
   }
   v.pb(curr);
   reverse(all(v));
   for(auto &val:v)cout<<val<<" ";
    
}

int main()
{
    hi_bro;
    
        solve();
    
    return 0;
}










