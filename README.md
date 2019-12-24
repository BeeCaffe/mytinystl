# myTinySTL
The implementation of Standard C++ Template Library. 
## Introduction
This project is a simply implement version of C++ standard template library
which mainly refers to 《STL Source Code Analysis》.The propose of
I implement this project is to enhance my programming skills and practice
C++ language. Therefore,as a practice project,there are many bugs
exist,which I may do some modify in the future version.Meanwhile,in 
order to simply the implement process, I do not take a consideration of the "type_traits"
mechanism and the speed enhancement of some build-in type.Many operation of 
some functions follows my own thoughts, so there is many 
different between my implementation and standard implementation.
But in the future version, I may do some modify about this. 

## [Developing Docs](/doc/category.md)
"Developing Docs" simply introduces the mechanism of STL 
container or algorithm.Meanwhile,member function and member
variance are listed in this documents, which facilitates 
the STL implementation.please refer to the book to get the 
details of those function and container.
## Supports

* operating system

    * linux
    
    * windows
    
* compiler

    * g++ 8.1.0 or higher version
    
* others

    * CLion
    
    * Cmake
    
## Run
* linux
  
    * git clone https://github.com/BeeCaffe/mytinystl.git
    
    * cd mytinystl
     
    * mkdir build && cd build
     
    * cmake ..
    
    * make
    
    * cd ../bin && ./xxx_test
    
* windows  
This project is developed in CLion(Cmake linked),the simplest
way is to install CLion IDE in windows platform directly.
After the relevant environment is configured ,clicking run to 
execute the xxx.cpp file.Please mention the version of g++ compiler.

## 简介
本项目主要是参考《STL源码解析》实现的一个简单版的STL，实现
了标准模板库中的大部分的容器和算法。本项目主要用于练手，熟悉
C++标准模板库，以及相关的原理，因此代码中应该还存在比较多的
bug，在后续的版本中应当会进行相应的修改。为了简化实现过程在1
.0.0版本中没有采用特性萃取机制和区分迭代器种类，以及忽略了
内置类型的一个速度优化的操作，并且很多操作是按照自己的思路
实现的和STL本身代码有所差异。后面应该会继续维护，加入特性萃取
以及一些其它的优化。
## [开发文档](/doc/category.md)
开发文档主要介绍了一下相应容器或者算法的实现机制，以及列举了一下其对应
的成员变量以及成员函数，主要目的是在开发的时候方便参考。具体的实现细节
还请参考《STL源码解析》
## 支持

* 操作系统
  
    * linux
    
    * windows
    
* 编译器

    * g++ 8.1.0以上
    
* 其它

    * CLion
    
    * Cmake
      
## 运行

* linux
  
    * git clone https://github.com/BeeCaffe/mytinystl.git
    
    * cd mytinystl
     
    * mkdir build && cd build
     
    * cmake ..
    
    * make
    
    * cd ../bin && ./xxx_test
    
* windows  
本项目采用CLion+Cmake进行开发，建议最简单的办法是直接安装CLion
配置好相关环境之后直接点击运行就可以了，注意g++编译器的版本要求。