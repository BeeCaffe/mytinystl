/***********************************************************************************************************************
 * Created by caffe on 2019/11/25.
 *
 **********************************************************************************************************************/
#include "../include1.0/Construct.h"
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int main(){
    int a=5;
    mystl::destory<int>(&a);
    cout<<"OK!"<<endl;
    return 0;
}