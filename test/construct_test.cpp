/***********************************************************************************************************************
 * Created by caffe on 2019/11/25.
 *
 **********************************************************************************************************************/
#include "../include1.0/Construct.h"
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
class tst{
public:
    tst()= default;
    tst(int i):i(i){}
    ~tst(){
        cout<<"call destructor"<<endl;
    }
    int i;
};
int main(){
    tst *obj;
    int a=5;
    mystl::construct(obj,a);
    cout<<obj->i<<endl;
    mystl::destory(obj);
    cout<<"OK!"<<endl;
    return 0;
}