//
// Created by caffe on 2019/12/23.
//
/***********************************************************************************************************************
 * Created by caffe on 2019/12/2.
 *
 **********************************************************************************************************************/
#include "../include1.0.0/Deque.h"
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int main(){
    mystl::deque_iter<int> iter;
    //operator ++ test
    printf("operator++ test iter location is : %d\n",iter.node);
    iter++;
    printf("operator++ test iter location is : %d\n",iter.node);
    for(int i = 1;i<iter.buf_sz;++i) ++iter;
    printf("operator ++ test iter location is : %d\n",iter.node);
    //operator-- test
    printf("operator-- test iter location is : %d\n",iter.node);
    iter--;
    printf("operator-- test iter location is : %d\n",iter.node);
    for(int i = 1;i<iter.buf_sz;++i) iter--;
    printf("operator-- test iter location is : %d\n",iter.node);
    //operator+= test
    printf("operator+= test 1: %d\n",iter.cur);
    iter += 511;
    printf("operator=+ test 2: %d\n",iter.cur);
    printf("OK\n");
    return 0;
}

