#include <iostream>
using namespace std;

class Employee{
public:
    string Name;
    string Company;
    int Age;
    void intro(){
        cout<<"Name - "<<Name<<"\n";
        cout<<"Company - "<<Company<<"\n";
        cout<<"Age - "<<Age<<"\n";
    }
};

int main(){
    Employee employee1;
    employee1.Name = "Raj";
    employee1.Company = "koi bhi chalegi";
    employee1.Age = 18;
    employee1.intro();

}