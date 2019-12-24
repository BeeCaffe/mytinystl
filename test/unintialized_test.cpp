/***********************************************************************************************************************
 * Created by caffe on 2019/11/25.
 *
 **********************************************************************************************************************/
#include "../include1.0.0/Uninitialized.h"
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int main(){
    vector<int> a(10);
    mystl::uninitialized_fill(a.begin(),a.end(),10);
    for(int num:a) cout<<num<<" ";
    cout<<endl;
    vector<int> b(10);
    mystl::uninitialized_copy(a.begin(),a.end(),b.begin());
    for(int num:b) cout<<num<<" ";
    cout<<endl;

    vector<int> c(10);
    mystl::uninitalized_fill_n(c.begin(),c.end(),3,10);
    for(int num:c) cout<<num<<" ";
    cout<<endl;
    cout<<"OK!"<<endl;

    return 0;
}