#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<pii> v;
#define N 100
#define M 100
int a[N][M];
void four(int i,int j){
    v.pb({i+1,j+1});
    v.pb({i+1,j+2});
    v.pb({i+2,j+2});
    v.pb({i+1,j+2});
    v.pb({i+2,j+2});
    v.pb({i+2,j+1});
    v.pb({i+1,j+1});
    v.pb({i+2,j+1});
    v.pb({i+2,j+2});
    v.pb({i+1,j+1});
    v.pb({i+1,j+2});
    v.pb({i+2,j+1});
}
void three(int i,int j){
    if(a[i][j]==0){
        v.pb({i+2,j+1});
        v.pb({i+1,j+2});
        v.pb({i+2,j+2});
    }
    else if(a[i+1][j]==0){
        v.pb({i+1,j+2});
        v.pb({i+1,j+1});
        v.pb({i+2,j+2});
    }
    else if(a[i][j+1]==0){
        //cout<<"YES"<<" ";
        v.pb({i+2,j+1});
        v.pb({i+1,j+1});
        v.pb({i+2,j+2});
    }
    else{
        v.pb({i+2,j+1});
        v.pb({i+1,j+2});
        v.pb({i+1,j+1});
    }
}
void two(int i,int j){
    if(a[i][j]==1){
        v.pb({i+2,j+1});
        v.pb({i+1,j+2});
        v.pb({i+2,j+2});
        a[i+1][j]=1-a[i+1][j];
        a[i][j+1]=1-a[i][j+1];
        a[i+1][j+1]=1-a[i+1][j+1];
    }
    else if(a[i+1][j]==1){
        v.pb({i+1,j+1});
        v.pb({i+1,j+2});
        v.pb({i+2,j+2});
        a[i][j]=1-a[i][j];
        a[i][j+1]=1-a[i][j+1];
        a[i+1][j+1]=1-a[i+1][j+1];
    }
    else if(a[i][j+1]==1){
        v.pb({i+1,j+1});
        v.pb({i+2,j+2});
        v.pb({i+2,j+1});
        a[i][j]=1-a[i][j];
        a[i+1][j+1]=1-a[i+1][j+1];
        a[i+1][j]=1-a[i+1][j];
    }
    else{
        v.pb({i+1,j+1});
        v.pb({i+1,j+2});
        v.pb({i+2,j+1});
        a[i][j]=1-a[i][j];
        a[i][j+1]=1-a[i][j+1];
        a[i+1][j]=1-a[i+1][j];
    }
    three(i,j);
}
void one(int i,int j){
    if(a[i][j]==1){
        v.pb({i+1,j+1});
        v.pb({i+1,j+2});
        v.pb({i+2,j+1});
        a[i][j]=1-a[i][j];
        a[i][j+1]=1-a[i][j+1];
        a[i+1][j]=1-a[i+1][j];
    }
    else if(a[i+1][j]==1){
        v.pb({i+1,j+1});
        v.pb({i+1,j+2});
        v.pb({i+2,j+1});
        a[i][j]=1-a[i][j];
        a[i][j+1]=1-a[i][j+1];
        a[i+1][j]=1-a[i+1][j];
    }
    else if(a[i][j+1]==1){
        v.pb({i+1,j+1});
        v.pb({i+1,j+2});
        v.pb({i+2,j+1});
        a[i][j]=1-a[i][j];
        a[i][j+1]=1-a[i][j+1];
        a[i+1][j]=1-a[i+1][j];
    }
    else{
        v.pb({i+2,j+2});
        v.pb({i+1,j+2});
        v.pb({i+2,j+1});
        a[i+1][j+1]=1-a[i+1][j+1];
        a[i][j+1]=1-a[i][j+1];
        a[i+1][j]=1-a[i+1][j];
    }
    two(i,j);
}
int32_t main() 
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        v.clear();
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                a[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            for(int j=0;j<m;j++){
                a[i][j]=s[j]-'0';
            }
        }
        for(int i=0;i<(n/2)*2;i+=2){
            for(int j=0;j<(m/2)*2;j+=2){
                int sum=a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1];
                //cout<<sum<<" ";
                if(sum==4){
                    four(i,j);
                }
                else if(sum==3){
                    three(i,j);
                }
                else if(sum==2){
                    two(i,j);
                }
                else if(sum==1){
                    one(i,j);
                }
                a[i][j]=0;
                a[i+1][j]=0;
                a[i][j+1]=0;
                a[i+1][j+1]=0;
            }
            if(m%2==1){
                int j=m-2;
                int sum=a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1];
                if(sum==4){
                    four(i,j);
                }
                else if(sum==3){
                    three(i,j);
                }
                else if(sum==2){
                    two(i,j);
                }
                else if(sum==1){
                    one(i,j);
                }
                a[i][j]=0;
                a[i+1][j]=0;
                a[i][j+1]=0;
                a[i+1][j+1]=0;
            }
        }
        int i=n-2;
        for(int j=0;j<(m/2)*2;j+=2){
            int sum=a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1];
                if(sum==4){
                    four(i,j);
                }
                else if(sum==3){
                    three(i,j);
                }
                else if(sum==2){
                    two(i,j);
                }
                else if(sum==1){
                    one(i,j);
                }
                a[i][j]=0;
                a[i+1][j]=0;
                a[i][j+1]=0;
                a[i+1][j+1]=0;
        }
        if(m%2==1){
            int j=m-2;
            int sum=a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1];
                if(sum==4){
                    four(i,j);
                }
                else if(sum==3){
                    three(i,j);
                }
                else if(sum==2){
                    two(i,j);
                }
                else if(sum==1){
                    one(i,j);
                }
                a[i][j]=0;
                a[i+1][j]=0;
                a[i][j+1]=0;
                a[i+1][j+1]=0;
        }
        cout<<v.size()/3<<"\n";
        for(int i=0;i<v.size();i+=3){
            cout<<v[i].ff<<" "<<v[i].ss<<" "<<v[i+1].ff<<" "<<v[i+1].ss<<" "<<v[i+2].ff<<" "<<v[i+2].ss<<" ";
            cout<<"\n";
        }
    }
}