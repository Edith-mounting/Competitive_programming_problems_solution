tmkc=int(input())
while(tmkc>0):
    n=int(input())
    v=list(map(int,input().split()))
    x=[]
    i=0
    while(i<n):
        p=1
        while(j<n && v[i]!=v[j]):
            int t=(i-j)//(v[j]-v[i])
            if(t*(v[j]-v[i])==(i-j)):
                if(t>0):
                    p++
            j+=1
        x.append(p)
        i+=1
    x.sort()
    print(x[0]," ",x[-1])
    tmkc-=1