#include <iostream>
#include <bits/stdc++.h>

using namespace std;

double dist(double x1,double y1,double x2,double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
void conquer(vector<pair<double,double>>&a) {

    for (int i=0;i<a.size();i++) {
        for (int j=i+1;j<a.size();j++) {
            cout<<dist(a[i].first,a[i].second,a[j].first,a[j].second)<<endl;
        }
    }

}
void divide(vector<pair<double,double>>a,int k) {
    int xk=0;
    if (a.size()<k) {
        vector<pair<double,double>>start(a.begin(),a.end());
        conquer(start);
    }else {
        int s=0,e=k;
        for (int s=0;s<a.size();s+=k) {
            int e=min(s+k,(int)a.size());
            vector<pair<double,double>>st(a.begin()+s,a.begin()+e);
            conquer(st);

        }
    }

}


int main()
{
    int parametar1=100,parametar2=100;

    int n;
    cin>>n;

    vector<pair<double,double>>a;

    for (int i=0;i<n;i++) {
        int x,y;
        cin>>x>>y;
        a.push_back({x,y});
    }

    sort(a.begin(),a.end());

    // for (auto i:a) {
    //     cout<<i.first<<" "<<i.second<<endl;
    // }

    divide(a,3);


}
