#include <bits/stdc++.h>

using namespace std;


class a{
    public:
        ~a(){
            cout << "destroy";
        }
};
int main()
{
    vector<a*> *v1 = new vector<a*>;
    vector<a> *v2 = new vector<a>;

}
