#include<iostream>
#include<cstring>
using namespace std;
void modify(int arr[],int a,int b,int d)
{
    for(int i=a-1;i<b;i++) {
        arr[i] =arr[i] +d;
    }
}
int main()
{
    int n,q;
    int a,b,d,mx;
    cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++)
        arr[i]=0;
    for(int i=0;i<q;i++) {
        cin >> a>>b>>d;
        modify(arr,a,b,d);
        mx =arr[0];
        for(int j=1;j<n;j++) {
            if( arr[j] >mx)
                mx= arr[j];
        }

    }
    cout<<mx;
    return 0;
}