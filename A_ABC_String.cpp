#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <stack>
using namespace std;
 
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define vb              vector<bool>
#define int             long long
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
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
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
int powd(int x,int y){
    if(y==0){
        return 1;
    }
    else if(y%2==0){
        int t=powd(x,y/2)%mod;
        return (t*t)%mod;
    }
    else{
        int t=powd(x,y/2)%mod;
        return (((t*t)%mod)*x)%mod;
    }
}
bool areBracketsBalanced(string expr) 
{   
    stack<char> s; 
    char x; 
  
    // Traversing the Expression 
    for (int i = 0; i < expr.length(); i++)  
    { 
        if (expr[i] == '(' || expr[i] == '['
            || expr[i] == '{')  
        { 
            // Push the element in the stack 
            s.push(expr[i]); 
            continue; 
        } 
  
        // IF current current character is not opening 
        // bracket, then it must be closing. So stack 
        // cannot be empty at this point. 
        if (s.empty()) 
            return false; 
  
        switch (expr[i]) { 
        case ')': 
              
            // Store the top element in a 
            x = s.top(); 
            s.pop(); 
            if (x == '{' || x == '[') 
                return false; 
            break; 
  
        case '}': 
  
            // Store the top element in b 
            x = s.top(); 
            s.pop(); 
            if (x == '(' || x == '[') 
                return false; 
            break; 
  
        case ']': 
  
            // Store the top element in c 
            x = s.top(); 
            s.pop(); 
            if (x == '(' || x == '{') 
                return false; 
            break; 
        } 
    } 
  
    // Check Empty Stack 
    return (s.empty()); 
} 
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        string s;
        cin>>s;
        int n=s.length();
        string x[8];
        for(int i=0;i<8;i++){
            x[i]="";
        }
        //a=(
            int i=0;
            for(int j=0;j<n;j++){
                if(s[j]=='A'){
                    x[i]+='(';
                }
                else if(s[j]=='B'){
                    x[i]+='(';
                }
                else{
                    x[i]+='(';
                }
            }
            i++;
            for(int j=0;j<n;j++){
                if(s[j]=='A'){
                    x[i]+='(';
                }
                else if(s[j]=='B'){
                    x[i]+='(';
                }
                else{
                    x[i]+=')';
                }
            }
            i++;

            for(int j=0;j<n;j++){
                if(s[j]=='A'){
                    x[i]+='(';
                }
                else if(s[j]=='B'){
                    x[i]+=')';
                }
                else{
                    x[i]+='(';
                }
            }
            i++;
            for(int j=0;j<n;j++){
                if(s[j]=='A'){
                    x[i]+='(';
                }
                else if(s[j]=='B'){
                    x[i]+=')';
                }
                else{
                    x[i]+=')';
                }
            }
            i++;
            for(int j=0;j<n;j++){
                if(s[j]=='A'){
                    x[i]+=')';
                }
                else if(s[j]=='B'){
                    x[i]+='(';
                }
                else{
                    x[i]+='(';
                }
            }
            i++;
            for(int j=0;j<n;j++){
                if(s[j]=='A'){
                    x[i]+=')';
                }
                else if(s[j]=='B'){
                    x[i]+='(';
                }
                else{
                    x[i]+=')';
                }
            }
            i++;
            for(int j=0;j<n;j++){
                if(s[j]=='A'){
                    x[i]+=')';
                }
                else if(s[j]=='B'){
                    x[i]+=')';
                }
                else{
                    x[i]+='(';
                }
            }
            i++;
            for(int j=0;j<n;j++){
                if(s[j]=='A'){
                    x[i]+=')';
                }
                else if(s[j]=='B'){
                    x[i]+=')';
                }
                else{
                    x[i]+=')';
                }
            }
            bool b=false;
            /*for(int i=0;i<8;i++){
                cout<<x[i]<<" ";
            }*/
            for(int k=0;k<8;k++){
                if(areBracketsBalanced(x[k])){
                    b=true;
                    break;
                }
            }
            if(b){
                cout<<"YES";
            }
            else{
                cout<<"NO";
            }
            cout<<"\n";
    }
}