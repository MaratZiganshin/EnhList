///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief Defines the entry point for the demo application.
///
/// © Sergey Shershakov 2015–2017.
///
/// This code is for educational purposes of the course "Algorithms and Data 
/// Structures" provided by the School of Software Engineering of the Faculty 
/// of Computer Science at the Higher School of Economics.
///
/// When altering code, a copyright line must be preserved.
///////////////////////////////////////////////////////////////////////////////


//#include "stdafx.h"
//#include "demos.hpp"


// uncomment this if you'd like to get the highest mark
// #define IWANNAGET10POINTS 


#include "bidi_linked_list.h"
#include <iostream>


/** \brief Type alias for a list of integers. */
typedef BidiLinkedList<int> IntBidiLinkedList;


/** \brief Simple list creating. */
void demo1()
{
    IntBidiLinkedList lst;
}



//int _tmain(int argc, _TCHAR* argv[])
int main()
{
    //demo1();
    BidiLinkedList<int> a;
    for (int i = 0; i < 5; i++)
        a.appendEl(i);
    BidiLinkedList<int>::Node* test1 = a.getHeadNode();
    BidiLinkedList<int>::Node* test2 = a.getLastNode()->getPrev()->getPrev();
    a.cutNodes(test1, test2);

    BidiLinkedList<int>::Node* out = a.getHeadNode();
    while (out)
    {
        std::cout << out->getValue() << std::endl;
        out = out->getNext();
    }
    system("pause");
    return 0;
}

