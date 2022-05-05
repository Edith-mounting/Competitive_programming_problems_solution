#include <iostream>
#include <stack>
using namespace std;
int main(){
    int n,k;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    cin>>k;
    
    int max_upto[n]; 
  
    stack<int> s; 
    s.push(0); 
    for (int i = 1; i < n; i++) { 
        while (!s.empty() && a[s.top()] < a[i]) { 
            max_upto[s.top()] = i - 1; 
            s.pop(); 
        } 
        s.push(i); 
    } 
    while (!s.empty()) { 
        max_upto[s.top()] = n - 1; 
        s.pop(); 
    } 
    int j = 0; 
    for (int i = 0; i <= n - k; i++) { 
        while (j < i || max_upto[j] < i + k - 1) 
            j++; 
        cout << a[j] << " "; 
    } 
    cout << endl; 

}