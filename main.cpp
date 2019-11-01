//Code for Single Linked List functions
//sllTest1.cpp
//Amit 191014

#include <iostream>
#include<stdlib.h>
using namespace std;

#include "LinkList/SLL_Node.h"

int main()
{
    std::cout << "\n========================================================================" << std::endl;
    std::cout << " Welcome to the world of Linked Lists! \n" << std::endl;
    std::cout << " This program creates a single linked list and allows operation on the list." << std::endl;
    std::cout << "\n The single linked list created will just have a single, integer type data in it." << std::endl;
    
    SLL_Node nodeBox;
    while(1)
    {
         std::cout<<"\n\n---------- Menu --------- \n";
         std::cout<<"\n Create List  - 1\n\n Insert Node  - 2\n\n Delete Node  - 3 \n\n Display List - 4\n\n Exit         - 5\n";
         std::cout<<"\n------------------------- \n";
         int userChoice;
         std::cout<<"\n Please enter your choice (1-5): ";
         std::cin>>userChoice;
         switch(userChoice)
         {
           case 1: nodeBox.create();
		   break;
           case 2 :nodeBox.insert();
		   break;
           case 3: nodeBox.del();
		   break;
           case 4: nodeBox.display();
		   break;
           case 5: std::cout << "\n\n\n ." << std::endl;
                   std::cout << " .." << std::endl;
                   std::cout << " ..." << std::endl;
                   std::cout << " Thanks for using this program. Now ending the program... \n\n" << std::endl;
                   exit(0);
        } //end switch
    } //end while
  
    return 0;
} //end main()
