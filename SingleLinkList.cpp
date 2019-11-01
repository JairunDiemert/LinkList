//Code for Single Linked List functions
//sllTest1.cpp
//Amit 191014

#include <iostream>
#include<stdlib.h>

class SLL_Node
 {
  int  data;
  SLL_Node *next;
  public :
  SLL_Node()
  {
  }
  void  create();
  void  insert();
  void  del();
  void  display();
  }
   *currNodePtr,*newNodePtr,*head=NULL;  //nullptr for C++11


void SLL_Node::create()
{
    int n;
    currNodePtr=new SLL_Node;
    std::cout<<"\n\n Okay! Creating the list for you...." << std::endl;
    std::cout<<" Enter the integer data for the first node: ";
    char ch='y';
    std::cin>>currNodePtr->data;
    head=currNodePtr;
    currNodePtr->next=NULL;
    std::cout<<"\n\n First Node successfully added.";
    std::cout<<"\n\n Do you wish to add another node? (y/n): ";
    std::cin>>ch;

    while( ch=='y')
    {
	 newNodePtr=new SLL_Node;
	 std::cout<<"\n\n Enter the integer data for the Node: ";
	 std::cin>>newNodePtr->data;
	 currNodePtr->next=newNodePtr;
	 newNodePtr->next=NULL;  //nullptr for C++11
	 currNodePtr=newNodePtr;
         std::cout << "\n Node successfully inserted!" << std::endl;
	 std::cout<<"\n\n Do you wish to add another node? (y/n): ";
	 std::cin>>ch;
    } //end while
} //end create()



void SLL_Node::insert()
  {
    int  ch;

    newNodePtr=new SLL_Node;

    std::cout<<"\n Insert at the beginning of the list - 1 \n Insert at the end of the list       - 2 \n Insert somewhere in the middle      - 3";
    std::cout<<"\n\n\t Please enter your choice (1/2/3): ";
    std::cin>>ch;

    std::cout<<"\n Please enter the data for this node: ";
    std::cin>>newNodePtr->data;
    currNodePtr=head;

    if(head==NULL)
    {
	head=newNodePtr;
	newNodePtr->next=NULL;
    }
    else
    switch(ch)
    {

      case 1:   newNodePtr->next=currNodePtr;
		head=newNodePtr;
                std::cout << "\n Node successfully inserted!" << std::endl;
		break;
      case 2:
		while(currNodePtr->next!=NULL)
		   currNodePtr=currNodePtr->next;

		newNodePtr->next=NULL;
		currNodePtr->next=newNodePtr;
                std::cout << "\n Node successfully inserted!" << std::endl;
		break;

      case 3 :  std::cout<<"\n Enter after which Node (Please specify the Data of that Node)?: ";
	        int item;
	        std::cin>>item;
	        while(currNodePtr->next!=NULL  && currNodePtr->data!=item)
		    currNodePtr=currNodePtr->next;

                if(currNodePtr->data==item)
	         {
		    newNodePtr->next=currNodePtr->next;
		    currNodePtr->next=newNodePtr;
                    std::cout << "\n Node successfully inserted!" << std::endl;
	         }
	        else
		    std::cout<<"\n No such Node exists!!";
	        break;

      default :  std::cout<<"\n\n No Node entered in the List yet. Please reconsider your choice.\n ";
   } //end switch

 } //end insert


void SLL_Node::del()
{
       currNodePtr=head;

       if(head==NULL)
       {
	   std::cout<<"\n No Node in the List!";
	   //getch();

	}

       else if(currNodePtr->next==NULL)
       {
	  std::cout<<"\n Deleted .... No more Nodes in the List!";
	  head=NULL;
	  //getch();
       }

       else
       {
          std::cout<<"\n Delete the first Node          - 1\n Delete the last Node           - 2\n Delete somewhere in the middle - 3" <<std::endl;
          std::cout<<"\n\t Please enter your choice (1/2/3): ";

          int ch;
          std::cin>>ch;

          switch(ch)
          {

             case 1:   head=currNodePtr->next;
		       free(currNodePtr);
		       std::cout<<"\n Node Deleted.";
		       break;

             case 2:   while(currNodePtr->next!=NULL)
		       {
		          newNodePtr=currNodePtr;
		          currNodePtr=currNodePtr->next;
		       }
		       newNodePtr->next=NULL;

		       std::cout<<"\n Node Deleted.";
		       free(currNodePtr);
		       break;

             case 3:   std::cout<<"\n Which Node do you wish to delete? Please specify its integer data: " ;
		       int item,i=0;
		       std::cin>>item;
		       currNodePtr=head;
		       newNodePtr=head;
		       head=newNodePtr;

		       while(currNodePtr->next!=NULL && currNodePtr->data !=item)
		       {
		          i++;
		          newNodePtr=currNodePtr;
		          currNodePtr=currNodePtr->next;
		       }

		       if(currNodePtr->data==item)
		       {
		         if (i==0)
		         {
		            std::cout<<"\n Node Deleted.";
		            head=currNodePtr->next;
		         }
		         else
		         {
		            std::cout<<"\n Node Deleted.";
		            newNodePtr->next=currNodePtr->next;
		            free(currNodePtr);
		         }
	               }

		       else
		         std::cout<<"\n No Node Deleted! " ;
		       break;

              //default : std::cout<<"\n\n Sorry!! That choice is invalid!!";
	    } //end switch
         } //end else
 } //end del()



void SLL_Node::display()
{
   currNodePtr=head;

   if(head==NULL)
       std::cout<<"\n No Node yet!\n";
   else
   {
      while(currNodePtr->next!=NULL)
      {
	 std::cout<<"\n Node Data : "<<currNodePtr->data;
	 currNodePtr=currNodePtr->next;
      }
      std::cout<<"\n Node Data : "<<currNodePtr->data;
   } //end else
} //end display()


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
           case 5: std::cout << "\n\n\n ." << << std::endl;
                   std::cout << " .." << << std::endl;
                   std::cout << " ..." << << std::endl;
                   std::cout << " Thanks for using this program. Now ending the program... \n\n" << std::endl;
                   exit(0);
        } //end switch
    } //end while
  
    return 0;
} //end main()
