/***********************************************************************************************************************
 * Created by caffe on 2019/12/2.
 *
 **********************************************************************************************************************/
#include "../include1.0.0/List.h"
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int main(){
    mystl::List<int> list;
    //test one stage
//    mystl::List<int>::node_ptr_type node=list.get_node();
//    list.put_node(node);
//    mystl::List<int>::node_ptr_type ptr=list.create_node(999);
//    cout<<ptr->data<<endl;
//    list.destory_node(ptr);
//    list.empty_initialized();
//    cout<<list.head_node->data<<endl;

    //test two stage
    list.push_back(1);
    list.push_back(2);
    for (int i = 0; i < 10; ++i) {
        list.push_back(i);
    }
    list.push_front(999);
    list.pop_back();
    list.pop_front();
    list.push_front(110);
    list.erase(list.begin());
    for(auto node:list) cout<<node<<" ";
    cout<<endl;
    list.clear();
    for (int i = 0; i < 10; ++i) {
        list.push_back(i);
    }
    list.remove(2);
    list.push_back(2);
    list.push_back(2);
    list.push_back(2);
    list.push_back(3);
    list.push_back(5);
    list.unique();
    for(auto node:list) cout<<node<<" ";
    cout<<endl;
    list.transfer(list.begin(),++list.begin(),--list.end());
    for(auto node:list) cout<<node<<" ";
    cout<<endl;
    cout<<"OK!"<<endl;
    return 0;
}