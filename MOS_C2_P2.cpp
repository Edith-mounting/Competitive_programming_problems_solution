#include <iostream>
#include <iomanip>
using namespace std;
int32_t main(){
    int n;
    cout<<"Enter the number of components ";
    cin>>n;
    cout<<"\n";
    double p[n],l[n],a[n],E[n];
    double P=0;
    cout<<"Enter the values in this format:load(kN),length(mm),area of cross-section(mm^2)";
    cout<<"modulus of elasticity(GPa) respec. (with spacing)"<<"\n";
    for(int i=0;i<n;i++){
        cout<<"Enter values for "<<i+1<<" components: ";
        double x;
        cin>>x;
        x=x*1000;
        P+=x;
        p[i]=P;
        cin>>l[i];
        l[i]=l[i]/1000;
        cin>>a[i];
        a[i]=a[i]/(1000000);
        cin>>E[i];
        E[i]=E[i]*(1000000000);
    }
    double deltaB=0;
    double sigma[n],delta[n];
    for(int i=0;i<n;i++){
        sigma[i]=(p[i]/a[i]);
        delta[i]=(p[i]*l[i])/a[i]*E[i];
        deltaB+=delta[i];
    }
    double unitdeltaB=0;
    double unitsigma[n],unitdelta[n];
    for(int i=0;i<n;i++){
        unitsigma[i]=(1/a[i]);//Mpa
        unitdelta[i]=(l[i]/(a[i]*E[i]));//mm
        unitdeltaB+=unitdelta[i];
    }
    double reactionB=0;
    reactionB=(-1)*(deltaB)/(unitdeltaB);//N
    reactionB=reactionB;//kN
    double reactionA=P+reactionB;
    cout<<"       RA="<<reactionA/1000<<"\n";
    cout<<"       RB="<<reactionB/1000<<"\n";
    cout<<"-------------------------------------------------------------------"<<"\n";
    cout<<"Element       "<<"Stress(MPa)        "<<"Deformation(mm)"<<"\n";
    for(int i=0;i<n;i++){
        cout<<i+1<<"             ";
        cout<<(sigma[i]+(reactionB/a[i]))/1000000;
        cout<<"               ";
        cout<<(delta[i]+(reactionB*l[i]/a[i]*E[i]))*1000<<"\n";
        cout<<"-------------------------------------------------------------------"<<"\n";
    }
}