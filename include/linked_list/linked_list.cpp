#ifndef INCLUDE_LINKED_LIST_CPP
#define INCLUDE_LINKED_LIST_CPP
#include "node.cpp"

namespace wolfram_code {
  template <typename T>
  class LinkedList {
    Node<T>* head_;
    int size_;

   public:
    LinkedList();
    LinkedList(bool isRandom);
    LinkedList(LinkedList<T> &other);
    void RandomFilling();
    void Swap();
    LinkedList& operator=(LinkedList<T>& other);
    ~LinkedList();
    void PushTail(Node<T> node);
    void PushTail(LinkedList<T> other);
    void PushHead(Node<T> node);
    void PushHead(LinkedList<T> other);
    void PopHead();
    void PopTail();
    void DeleteNode(T& const value);
    Node& operator[](int index);
    Node operator[](int index) const;
  };

}//namespace wolfram_code


#endif