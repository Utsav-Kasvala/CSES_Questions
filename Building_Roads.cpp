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

// JAY SHRI KRISHNA

class DisjointSet{
    public:
    vector<int> rank,size,par;
 
    DisjointSet(int n){
      rank.resize(n+1,0);
      par.resize(n+1);
      size.resize(n+1,1);
      for(int i=0;i<=n;i++){par[i]=i;}
    }
    int findupar(int v){
      if(par[v]==v)return v;
      
      return par[v]=findupar(par[v]);
    }
    
    void unionbyrank(int u,int v){
         int upu=findupar(u);
         int upv=findupar(v);
         if(upu==upv)return;
         
         if(rank[upu]>rank[upv]){
          par[upv]=upu;
         }
         else if(rank[upu]<rank[upv]){
          par[upu]=upv;
         }
         else{
          rank[upu]++;
          par[upv]=upu;
         }
    }
    void unionbysize(int u,int v){
         int upu=findupar(u);
         int upv=findupar(v);
         if(upu==upv)return;
         if(size[upu]>size[upv]){
          par[upv]=upu;
          size[upu]+=size[upv];
         }
         else{
          par[upu]=upv;
          size[upv]+=size[upu];
         }
    }
};

void solve()
{           
  int n,m;
  cin>>n>>m;
  DisjointSet ds(n+1);
  
  for(int i=0;i<m;i++){
  	int x,y;
  	cin>>x>>y;
  	ds.unionbysize(x,y);
  }
  
  map<int,int> mp;
  for(int i=1;i<=n;i++){
  	mp[ds.findupar(i)]++;
  }
  int last=0;
  cout<<mp.size()-1<<"\n";
  for(auto &val:mp){
  	 if(last==0){
  	 	last=val.fi;
  	 }
  	 else{
  	 	cout<<last<<" "<<val.fi<<"\n";
  	 }
  }
  
  
}


int main()
{
    hibro
       solve();     
    
    
    return 0;
}