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
    Node* afterNode = this->_next;      // an element, which was after node
    this->_next = insNode;
    insNode->_prev = this;
    if (afterNode)
    {
        insNode->_next = afterNode;
        afterNode->_prev = insNode;
    }
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
    Node* temp = _head;
    while (temp)
    {
        Node* del = temp;
        temp = temp->_next;
        delete del;
    }
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
    Node* temp = _head;
    size_t s = 0;
    while (temp)
    {
        s++;
        temp = temp->_next;
    }
    _size = s;
}


template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::getLastNode() const
{
    return _tail;
}


template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::appendEl(const T& val)
{
    Node* newNode = new Node(val);

    Node * temp = insertNodeAfter(getLastNode(), newNode);
    _tail = newNode;

    return temp;
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
    {
        _head = insNode;
        _tail = insNode;
    }
    else
    {
        if (!node->_next)
            _tail = insNode;
        node->insertAfterInternal(insNode);
    }
        
    if (_size != NO_SIZE)
        _size++;

    return insNode;
}



template <typename T>
void BidiLinkedList<T>::insertNodesAfter(Node* node, Node* beg, Node* end)
{
    if (!beg) 
        throw std::invalid_argument("`beg` is nullptr");
    if (!end)
        throw std::invalid_argument("`end` is nullptr");
    if (beg->_prev || end->_next)
        throw std::invalid_argument("`beg` or `end` has siblings. It seems chain isn't free");
    if (!node)
        node = getLastNode();
    if (!node)
    {
        _head = beg;
        _tail = end;
    }
    else if (!node->_next)
    {
        node->_next = beg;
        beg->_prev = node;
        _tail = end;
    }
    else
    {
        end->_next = node->_next;
        beg->_prev = node;
        node->_next->_prev = end;
        node->_next = beg;

    }

    invalidateSize();
}


#ifdef IWANNAGET10POINTS


template <typename T>
typename BidiLinkedList<T>::Node*
    BidiLinkedList<T>::insertNodeBefore(Node* node, Node* insNode)
{
    if (!insNode)
        throw std::invalid_argument("`insNode` is nullptr");

    // check if a node is alone
    if (insNode->_next || insNode->_prev)
        throw std::invalid_argument("`insNode` has siblings. It seems it isn't free");


    if (!node)
        node = getHeadNode();

    // if last node is nullptr itself, it means that no elements in the list at all
    if (!node)
    {
        _head = insNode;
        _tail = insNode;
    }
    else if (!node->_prev)
    {
        _head = insNode;
        insNode->_next = node;
        node->_prev = insNode;
    }
    else 
        node->_prev->insertAfterInternal(insNode);

    if (_size != NO_SIZE)
        _size++;

    return insNode;
}


template <typename T>
void BidiLinkedList<T>::insertNodesBefore(Node* node, Node* beg, Node* end)
{
    if (!beg)
        throw std::invalid_argument("`beg` is nullptr");
    if (!end)
        throw std::invalid_argument("`end` is nullptr");
    if (beg->_prev || end->_next)
        throw std::invalid_argument("`beg` or `end` has siblings. It seems chain isn't free");
    if (!node)
        node = getHeadNode();
    if (!node)
    {
        _head = beg;
        _tail = end;
    }
    else if (!node->_prev)
    {
        node->_prev = end;
        end->_next = node;
        _head = beg;
    }
    else
    {
        end->_next = node;
        beg->_prev = node->_prev;
        node->_prev->_next = beg;
        node->_prev = end;
    }

    invalidateSize();
}

#endif // IWANNAGET10POINTS


template <typename T>
void BidiLinkedList<T>::cutNodes(Node* beg, Node* end)
{
    if (!beg || !end)
        throw std::invalid_argument("Either `beg` or `end` is nullptr");
    if (!end->_next && !beg->_prev)
    {
        _head = nullptr;
        _tail = nullptr;
    }
    else if (!end->_next)
    {
        _tail = beg->_prev;
        beg->_prev->_next = nullptr;
        beg->_prev = nullptr;
    }
    else if (!beg->_prev)
    {
        _head = end->_next;
        end->_next->_prev = nullptr;
        end->_next = nullptr;
    }
    else
    {
        beg->_prev->_next = end->_next;
        end->_next->_prev = beg->_prev;
        beg->_prev = nullptr;
        end->_next = nullptr;
    }
    invalidateSize();
}


template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::cutNode(Node* node)
{
    if (!node)
        throw std::invalid_argument("`node` is nullptr");
    if (!node->_next && !node->_prev)
    {
        _head = nullptr;
        _tail = nullptr;
        return node;
    }
    else if (!node->_next)
    {
        _tail = node->_prev;
        node->_prev->_next = nullptr;
        node->_prev = nullptr;
    }
    else if (!node->_prev)
    {
        _head = node->_next;
        node->_next->_prev = nullptr;
        node->_next = nullptr;
    }
    else
    {
        node->_prev->_next = node->_next;
        node->_next->_prev = node->_prev;
        node->_prev = nullptr;
        node->_next = nullptr;
    }
    invalidateSize();
    return node;
}


template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::findFirst(Node* startFrom, const T& val)
{
    if (!startFrom)
        return nullptr;

    Node* temp = startFrom;
    while (temp)
    {
        if (temp->getValue() == val)
            return temp;
        temp = temp->_next;
    }
    

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
    
    Node* temp = startFrom;

    while (startFrom)
    {
        if (startFrom->_val == val)
            size++;
        startFrom = startFrom->_next;
    }

    if (size > 0)
        res = new Node*[size];
    
    int index = 0;
    if (res)
        while (temp)
        {
            if (temp->_val == val)
            {
                res[index] = temp;
                index++;
            }
            temp = temp->_next;
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
    if (!startFrom)
        return nullptr;

    // try not to use any standard containers. create an array only when found a first occurence  
    Node** res = nullptr;
    size = 0;

    Node* temp = startFrom;

    while (startFrom)
    {
        if (startFrom->_val == val)
            size++;
        startFrom = startFrom->_next;
    }
        
    if (size > 0)
        res = new Node*[size];

    int index = 0;
    if (res)
        while (temp)
            if (temp->_val == val)
            {
                Node* cut = temp;
                temp = temp->_next;
                res[index] = cutNode(cut);
                index++;
            }
            else
                temp = temp->_next;

    return res;
}

#endif // IWANNAGET10POINTS
