/***********************************************************************************************************************
 * Created by caffe on 2019/12/2.
 *
 **********************************************************************************************************************/
#include "../include1.0/List.h"
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int main(){
    mystl::List<int> list;
    mystl::List<int>::node_ptr_type node=list.get_node();
    list.put_node(node);
    mystl::List<int>::node_ptr_type ptr=list.create_node(999);
    cout<<ptr->data<<endl;
    list.destory_node(ptr);
    list.empty_initialized();
    cout<<list.p_node->data<<endl;
    cout<<"OK!"<<endl;
    return 0;
}