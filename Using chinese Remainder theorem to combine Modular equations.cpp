#include<bits/stdc++.h>
using namespace std;
vector<int>extended_euclidean(int a,int b)
{
    if(a==0)
    {
        vector<int>temp;
        temp.push_back(b);
        temp.push_back(0);
        temp.push_back(1);
        return temp;
    }
    else
    {
        vector<int>temp(3);
        temp=extended_euclidean(b%a,a);
        int g=temp[0];
        int x=temp[1];
        int y=temp[2];
        temp[0]=g;
        temp[1]=x-((b/a)*y);
        temp[2]=y;
        return temp;
    }
    vector<int>temp;
    return temp;
}
int modinv(int a,int m)
{
    vector<int>temp(3);
    temp=extended_euclidean(a,m);
    int g=temp[0];
    int x=temp[1];
    int y=temp[2];
    int ans=x-(floor(x/(float)m)*m);
    return ans;
}
int crt(vector<int>&m,vector<int>&x)
{
    while(1)
    {
        int var1=(modinv(m[1],m[0]));
        int var2=(modinv(m[0],m[1]));
        int temp1=(modinv(m[1],m[0]))*x[0]*m[1]+(modinv(m[0],m[1]))*x[1]*m[1];
        int temp2=m[0]*m[1];
        x.erase(x.begin());
        x.erase(x.begin());
        x.insert(x.begin(),temp1%temp2);

        m.erase(m.begin());
        m.erase(m.begin());
        m.insert(m.begin(),temp2);

        if(x.size()==1)
        {
            break;
        }

    }
    return x[0];
}
int main()
{
      vector<int> m = {4, 7, 9, 11};
    vector<int> x = {3, 4, 1, 0};
    cout << crt(m, x) << endl;
    return 0;
}
