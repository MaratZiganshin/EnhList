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

#define IWANNAGET10POINTS 


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
    BidiLinkedList<int>* a = new BidiLinkedList<int>();
    int* m = new int[8]{ 0, 1, 2, 0, 4 , 0, 0, 1};
    for (int i = 0; i < 8; i++)
        a->appendEl(m[i]);

    BidiLinkedList<int>::Node* k = a->cutNode(a->getHeadNode()->getNext());
    system("pause");
    /*
    int size = 0;
    BidiLinkedList<int>::Node* start = a.getHeadNode();
    BidiLinkedList<int>::Node** res = a.cutAll(start, 0, size);
    std::cout << size << std::endl << std::endl;


    BidiLinkedList<int>::Node* out = a.getHeadNode();
    while (out)
    {
        std::cout << out->getValue() << std::endl;
        out = out->getNext();
    }

    std::cout << std::endl;

    out = a.getLastNode();
    while (out)
    {
        std::cout << out->getValue() << std::endl;
        out = out->getPrev();
    }*/



    system("pause");
    return 0;
}

