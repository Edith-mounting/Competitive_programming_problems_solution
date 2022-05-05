#include <iostream>
#include <unordered_set>
#include <cmath>
using namespace std;
 
// function to calculate count of
// distinct bitwise OR of all
// subarrays.
int distintBitwiseOR(int arr[], int n)
{
    unordered_set<int> ans, prev;
 
    for (int i = 0; i < n; i++) {
        unordered_set<int> ne;
 
        for (auto x : prev)ne.insert(arr[i] | x);
        
        ne.insert(arr[i]);
 
        for (auto x : ne)ans.insert(x);
 
        prev = ne;
    }
 
    return ans.size();
}
int powd(int x,int y){
    if(y==0){
        return 1;
    }
    else if(y%2==0){
        int t=powd(x,y/2);
        return (t*t);
    }
    else{
        int t=powd(x,y/2);
        return (t*t*x);
    }
}
// Driver Code
int main()
{
    int w;
    cin>>w;
    while(w--){
        int n,a;
        cin>>n>>a;
        int k=sqrt(n);
        cout<<k*a<<"\n";
    }
    

}