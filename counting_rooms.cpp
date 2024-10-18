 #include<bits/stdc++.h>  
   using namespace std;
 
//-----------------------------------------------------------------------------------------
   #define hibro       ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   #define test           int T; cin>>T; for(int t=1;t<=T;t++)
   #define ll             long long
   #define ld             long double
   #define yes            cout<<"YES"<<endl
   #define no             cout<<"NO"<<endl
   #define f(i,x,n)       for(ll i = x; i < n; i++)
   #define fo(i,x,n)      for(int i=x;i>=n;i--)
   #define pb             push_back
   #define pp             pop_back()
   #define fi             first
   #define se             second
   #define all(v)         (v).begin(), (v).end()
   #define array_le_le    ll a[n]; f(i,0,n){cin>>a[i];}
//-----------------------------------------------------------------------------------------
vector<vector<int>> vis(1001,vector<int>(1001,0));
char grid[1001][1001];
int n,m;
 
vector<pair<int,int>> moves={{1,0},{0,1},{-1,0},{0,-1}};
bool isvalid(int i,int j){
    if(i>=0 && j>=0 && i<n && j<m)return true;
    return false;
}
 
void dfs(int i,int j){
    vis[i][j]=1;
    
    for(int k=0;k<4;k++){
        int x=i+moves[k].fi;
        int y=j+moves[k].se;
        
        if(isvalid(x,y) && grid[x][y]=='.' && vis[x][y]==0)dfs(x,y);
    }
}
 
 
void solve()
{           
   cin>>n>>m;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>grid[i][j];
    }
   }
   int ct=0;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(vis[i][j]==0 && grid[i][j]=='.'){
            dfs(i,j);
            ct++;
        }
    }
   }
   
   cout<<ct<<"\n";
   
   
    
}
 
int main()
{
    hibro
    solve();     
    
    return 0;
}
