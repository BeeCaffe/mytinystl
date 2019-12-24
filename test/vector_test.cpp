/***********************************************************************************************************************
 * Created by caffe on 2019/11/25.
 *
 **********************************************************************************************************************/
#include "../include1.0.0/Vector.h"
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int main(){
    mystl::Vector<int> a(10,5);
    cout<<a.size()<<endl;
    a.push_back(6);
    a.push_back(6);
    a.push_back(6);
    a.pop_back();
    cout<<a.size()<<endl;
    for(int i=0;i<10;++i) a[i]=i;
    cout<<"1:";
    for(mystl::Vector<int>::iterator iter=a.begin();iter!=a.end();++iter) cout<<*iter<<" ";
    cout<<endl;
    a.earse(a.begin());
    a.earse(a.begin(),a.begin()+2);
    cout<<"2:";
    for(mystl::Vector<int>::iterator iter=a.begin();iter!=a.end();++iter) cout<<*iter<<" ";
    cout<<endl;
    a.resize(5);
    cout<<"3:";
    for(mystl::Vector<int>::iterator iter=a.begin();iter!=a.end();++iter) cout<<*iter<<" ";
    cout<<endl;
    a.resize(10,2);
    cout<<"4:";
    for(mystl::Vector<int>::iterator iter=a.begin();iter!=a.end();++iter) cout<<*iter<<" ";
    cout<<endl;
    a.clear();
    cout<<a.size()<<endl;
    cout<<"OK!"<<endl;
    return 0;
}