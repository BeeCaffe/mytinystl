/***********************************************************************************************************************
 * Created by caffe on 2019/11/20.
 *
 **********************************************************************************************************************/
#include "../include1.0/Alloc.h"
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;
int main(){
    //test 1
    mystl::simply_alloc<int>::allocate(5);
    vector<int,mystl::simply_alloc<int>> vec;
    for(int i=0;i<100000;++i)
        vec.push_back(i);
    for(int i=0;i<100000;++i)
        cout<<vec[i]<<endl;
    vec.pop_back();
    printf("OK!\n");
    //test 2
//    for(int i=1;i<128;++i)
//        cout<<mystl::default_alloc::get_roundup(i)<<"   ";
//    cout<<endl;
//    for(int i=1;i<128;++i)
//        cout<<mystl::default_alloc::get_index(i)<<"   ";
//    cout<<endl;
    return 0;
}