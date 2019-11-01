//File: SLL_Node.h
//Author: Jairun Diemert
//Class: COP3530
//Project: Class work
//Description: This is the header file for the SLL_Node class

#ifndef SLL_NODE_H
#define SLL_NODE_H

#include <iostream>
using namespace std;

class SLL_Node
 {
  int  data;
  SLL_Node *next;
	SLL_Node *currNodePtr;
	SLL_Node *newNodePtr;
	SLL_Node *head = NULL;  //nullptr for C++11

  public :
  SLL_Node(){};
  void  create();
  void  insert();
  void  del();
  void  display();
};


#endif 