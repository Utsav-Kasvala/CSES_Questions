   
   #include<bits/stdc++.h>  
   using namespace std;

//-----------------------------------------------------------------------------------------
   #define hi_bro         ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   #define test           int T; cin>>T; for(int t=1;t<=T;t++)
   #define int             long long
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

vector<pair<int,int>> moves={{0,1},{1,0},{0,-1},{-1,0}};


vector<vector<int>> djk(int i,int j,vector<vector<char>> &arr){
    int n=arr.size(),m=arr[0].size();
    vector<vector<int>> dist(n,vector<int>(m,1e18));
    string mv="RDUL";
    
    dist[i][j]=0;
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    pq.push({0,i,j});
    
    while(pq.size()>0){
        vector<int> curr=pq.top();
        pq.pop();
        int ci=curr[1],cj=curr[2],cw=curr[0];
        for(int k=0;k<4;k++){
            int x=ci+moves[k].fi;
            int y=cj+moves[k].se;
            if(x<n && x>=0 && y>=0 && y<m && arr[x][y]!='#'){
                if(cw+1 < dist[x][y]){
                    dist[x][y]=cw+1;
                    pq.push({cw+1,x,y});
                }
            }
        }
    }
    
    return dist;
    
}



void solve()
{           
  int n,m;
  cin>>n>>m;
  vector<vector<char>> arr(n,vector<char>(m));
  int si=-1,sj=-1,ei=-1,ej=-1;
  for(int i=0;i<n;i++){
  	for(int j=0;j<m;j++){
  		cin>>arr[i][j];
  		if(arr[i][j]=='A'){
  			si=i,sj=j;
  		}
        if(arr[i][j]=='B'){
            ei=i,ej=j;
        }
  	}
  } 
  
    
  vector<vector<int>> dist1=djk(si,sj,arr);
  vector<vector<int>> dist2=djk(ei,ej,arr);
  
  
  string ans,mv="RDLU";
  
  int d=dist1[ei][ej];
  if(d==1e18){
    no;
    return;
  }
  
  vector<vector<int>> vis(n,vector<int>(m,0));
  while(!(si==ei && sj==ej)){
     vis[si][sj]=1;
        for(int k=0;k<4;k++){
            int x=si+moves[k].fi;
            int y=sj+moves[k].se;
            if(x<n && x>=0 && y>=0 && y<m && arr[x][y]!='#' && vis[x][y]==0 &&(dist1[si][sj]+1+dist2[x][y]==d)){
                ans.pb(mv[k]);
                si=x,sj=y;
            }
        }
  }
  yes;
  cout<<d<<"\n";
  
  cout<<ans<<"\n";
  
  
  
  
  
    
}

signed main()
{
    hi_bro;
    
        solve();
    
    return 0;
}










