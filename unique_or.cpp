#include <iostream>
#include <unordered_set>
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
 
// Driver Code
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=i+1;
    }
 
    cout << distintBitwiseOR(a, n);
 
    return 0;
}