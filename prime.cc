#include<iostream>
using namespace std;
int prime(int n)
{
    int c=0;
    for(int i=2; i<n;i++)
    {
        if(n%i==0)
        c++;
    }
    if(c==0)
    cout<<"prime"<<endl;
    else cout<<"not prime"<<endl;    
}

int main()
{
    prime(6);
    prime(5);
    prime(8);
}
