/****
@author Ivan Chong Jia Hao
@since 31/7/2023
@version 1.01
*/
#ifndef BSTX_H_INCLUDED
#define BSTX_H_INCLUDED

#include <iostream>

using namespace std;
    /**
     declaring of structure for bst T type
     Each Structure holds left right node and data
    */
template <class T>
struct nodeType
{
    nodeType<T>(T data) : m_data(data), m_leftNode(nullptr), m_rightNode(nullptr) {}; /// Struct constructor
    T m_data; // allocated memory to hold data
    nodeType<T>* m_leftNode; // left node pointer
    nodeType<T>* m_rightNode;// right node pointer
};

template <class T>
class Bstx
{
public:
    Bstx(); // constructor
    ~Bstx(); // destructor that calls delete function

    void insertNode(T data) // public method for inserting node
    {
        insertElement(m_rootNode, data); // calls private function and pass in main node and data
    }

    void deleteBST() // delete bst
    {
        deleteBst(m_rootNode); // calls delete bst private function to delete entire tree
    }

    void inOrder(void (*visit)(T& data)) // inOrder traversal, using function ptr feature
    {
        inOrder(m_rootNode, *visit); // private declared inorder function
    }

    void preOrder(void (*visit)(T& data)) // pre Traversal that takes in function ptr feature
    {
        preOrder(m_rootNode,*visit);// declare funtion pointer to access data
    }

    void postOrder(void (*visit)(T& data)) // postorder traversal that takes in function ptr feature
    {
        postOrder(m_rootNode,*visit); // calls private declared function
    }

    bool searchData(T data) // search data function
    {
        return searchData(m_rootNode, data);
    }

private:
    nodeType<T>* m_rootNode = nullptr; // private declared struct node ptr
    void insertElement(nodeType<T>*& node, T& data); // private declared insert method
    void deleteBst(nodeType<T>*& node); // private declared delete method passing in node
    void inOrder(nodeType<T>* node, void (*visit)(T& data)); // inorder traversal
    void preOrder(nodeType<T>* node,void (*visit)(T& data)); // inorder traversal
    void postOrder(nodeType<T>* node,void (*visit)(T& data)); // inordertraversal
    bool searchData(nodeType<T>* node, T& data)const ; // inordertraversal
};

template <class T>
Bstx<T>::Bstx()
{
    m_rootNode = nullptr;
}

template <class T>
Bstx<T>::~Bstx()
{
    deleteBST(); // calls delete function upon close
}

template <class T>
void Bstx<T>::insertElement(nodeType<T>* &node, T& data)
{
    if (node == nullptr) // if null
    {
        node = new nodeType<T>(data); // just add node
    }
    else
    {
        if (data == node->m_data) // if data is = node ?
        {
            return; // close
        }
        if (data < node->m_data) // if data smaller
        {
            insertElement(node->m_leftNode, data); // recursive left
        }
        else
        {
            insertElement(node->m_rightNode, data); // recursive right
        }
    }
}

template <class T>
void Bstx<T>::deleteBst(nodeType<T>*& node)
{
    if (node != nullptr) // if not null
    {
        deleteBst(node->m_leftNode); // delete left brunch  recursive
        deleteBst(node->m_rightNode);// delete right brunch recursive
        delete node; // delete node
        node = nullptr;// point null
    }
}

template <class T>
void Bstx<T>::inOrder(nodeType<T>* node, void (*visit)(T& data)) // pass in *visit
{
    if (node == nullptr) // if null close
        return;

    inOrder(node->m_leftNode, *visit); // left recursive
    (*visit)(node->m_data); // function ptr that points to followed by data to be placed in parameter
    inOrder(node->m_rightNode, *visit); // right recursive
}



template <class T>
void Bstx<T>::preOrder(nodeType<T>* node,void (*visit)(T& data)) // method
{
    if (node == nullptr) // if null close;
        return;

    (*visit)(node->m_data); // print data
    preOrder(node->m_leftNode,*visit); // call left recursive
    preOrder(node->m_rightNode,*visit); // call right recursive
}

template <class T>
void Bstx<T>::postOrder(nodeType<T>* node,void (*visit)(T& data)) // post order
{
    if (node == nullptr) // if null close
        return;

    postOrder(node->m_leftNode,*visit); // left recursive, calling funtion ptr
    postOrder(node->m_rightNode,*visit); // right recursive  calling function ptr
    (*visit)(node->m_data); // function ptr pass node out
}

template <class T>
bool Bstx<T>::searchData(nodeType<T>* node, T& data) const // search data
{
    if (node == nullptr) // if data is null
        return false;   // return false

    if (data == node->m_data) // if data = data input
    {
        return true; // return true
    }
    else if (data < node->m_data)
    {
        return searchData(node->m_leftNode, data); // recursive left
    }
    else
    {
        return searchData(node->m_rightNode, data); // recursive right
    }
}

#endif // BSTX_H_INCLUDED
