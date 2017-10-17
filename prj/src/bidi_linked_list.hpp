///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief Contains pseudo-implementation part of bidirectional list structure 
/// template declared in the file's h-counterpart
///
/// © Sergey Shershakov 2015–2017.
///
/// This code is for educational purposes of the course "Algorithms and Data 
/// Structures" provided by the School of Software Engineering of the Faculty 
/// of Computer Science at the Higher School of Economics.
///
/// When altering code, a copyright line must be preserved.
///////////////////////////////////////////////////////////////////////////////

#include <stdexcept>



//==============================================================================
// class BidiList<T>::Node
//==============================================================================


template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::Node::insertAfterInternal(Node* insNode)
{
    // here we use "this" keyword for enhancing the fact we deal with curent node!
    Node* afterNode = this->_next;      // an element, which was after node
    // !...
    // Здесь вырезана часть кода. Ее необходимо реализовать
    // См. документацию к методу insertAfterInternal() и insertAfter()
    // !...
    return insNode;
}

//==============================================================================
// class BidiList<T>
//==============================================================================



template <typename T>
BidiLinkedList<T>::~BidiLinkedList()
{
    clear();
}


template <typename T>
void BidiLinkedList<T>::clear()
{
    // !...
    // Метод необходимо реализовать целиком!
    // !...
}

template <typename T>
size_t BidiLinkedList<T>::getSize()
{
    if (_size == NO_SIZE)
        calculateSize();

    return _size;
}


template <typename T>
void BidiLinkedList<T>::calculateSize()
{
    // !...
    // Метод необходимо реализовать целиком!
    // !...
}


template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::getLastNode() const
{
    // !...
    // Метод необходимо реализовать целиком!
    // !...
}


template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::appendEl(const T& val)
{
    Node* newNode = new Node(val);

    // !...
    // Здесь вырезана часть кода. Ее необходимо реализовать
    // !...

    // inserts after last node, size if going to e invalidated there
    return insertNodeAfter(getLastNode(), newNode);
}


// возможно, этот метод даже не надо изменять
template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::insertNodeAfter(Node* node, Node* insNode)
{
    if (!insNode)
        throw std::invalid_argument("`insNode` is nullptr");

    // check if a node is alone
    if (insNode->_next || insNode->_prev)
        throw std::invalid_argument("`insNode` has siblings. It seems it isn't free");


    if (!node)
        node = getLastNode();

    // if last node is nullptr itself, it means that no elements in the list at all
    if (!node)
        _head = insNode;
    else
        node->insertAfterInternal(insNode);


    invalidateSize();

    return insNode;
}



// !...
// Здесь должна быть реализация метода BidiLinkedList<T>::insertNodesAfter().
// В отличие от других методов, здесь не представлен даже заголовок, поэтому придется потрудиться!
// !...


// Следующий фрагмент кода перестанет быть "блеклым" и станет "ярким", как только вы определите
// макрос IWANNAGET10POINTS, взяв тем самым на себя повышенные обязательства
#ifdef IWANNAGET10POINTS


template <typename T>
typename BidiLinkedList<T>::Node*
    BidiLinkedList<T>::insertNodeBefore(Node* node, Node* insNode)
{
    // !...
    // Реализуй метод, если хочешь получит оценку повыше!
    // !...
}


template <typename T>
void BidiLinkedList<T>::insertNodesBefore(Node* node, Node* beg, Node* end)
{
    // !...
    // Реализуй метод, если хочешь получит оценку повыше!
    // !...
}

#endif // IWANNAGET10POINTS


template <typename T>
void BidiLinkedList<T>::cutNodes(Node* beg, Node* end)
{
    if (!beg || !end)
        throw std::invalid_argument("Either `beg` or `end` is nullptr");
    // !...
    // Здесь вырезана часть кода. Ее необходимо реализовать
    // !...
    invalidateSize();

}


template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::cutNode(Node* node)
{
    // !...
    // Метод необходимо реализовать целиком!
    // !...
}


template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::findFirst(Node* startFrom, const T& val)
{
    if (!startFrom)
        return nullptr;

    // !...
    // Здесь вырезана часть кода. Ее необходимо реализовать
    // !...

    return nullptr;     // not found
}



template <typename T>
typename BidiLinkedList<T>::Node** 
    BidiLinkedList<T>::findAll(Node* startFrom, const T& val, int& size)
{
    if (!startFrom)
        return nullptr;

    // try not to use any standard containers. create an array only when found a first occurence  
    Node** res = nullptr;
    size = 0;
    
    while (startFrom)
    {
        // !...
        // Здесь вырезана часть кода. Ее необходимо реализовать
        // !...
    }
    
    // recreates array if created
    if (res)
    {
        // !...
        // А здесь вырезана еще одна часть кода. И ее тоже необходимо реализовать
        // !...
    }

    return res;
}

// Следующий фрагмент кода перестанет быть "блеклым" и станет "ярким", как только вы определите
// макрос IWANNAGET10POINTS, взяв тем самым на себя повышенные обязательства
#ifdef IWANNAGET10POINTS

template <typename T>
typename BidiLinkedList<T>::Node**  
BidiLinkedList<T>::cutAll(Node* startFrom, const T& val, int& size)
{
    // !...
    // Реализуй метод, если хочешь получит оценку повыше!
    // !...
}

#endif // IWANNAGET10POINTS
