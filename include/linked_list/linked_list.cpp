#ifndef INCLUDE_LINKED_LIST_CPP
#define INCLUDE_LINKED_LIST_CPP
#include "node.cpp"
#include <random>
#include <time.h>

namespace wolfram_code {
  template <typename T>
  class LinkedList {
 public:
  friend Node<T>;
    Node<T>* head_;
    int size_;

   public:
    LinkedList();
    LinkedList(int size, T const& value);
    LinkedList(int size);  //заполняет список случайными значениями
    LinkedList(LinkedList<T> const &other);
    void RandomFilling();
    void Swap();
    LinkedList& operator=(LinkedList<T>& other);
    ~LinkedList() = default;
    void PushTail(Node<T> node);
    void PushTail(LinkedList<T> other);
    void PushHead(Node<T> node);
    void PushHead(LinkedList<T> other);
    void PopHead();
    void PopTail();
    void DeleteNode(T const &value);
    Node<T>& operator[](int index);
    Node<T> operator[](int index) const;
  };


  template <typename T>
  LinkedList<T>::LinkedList() {
    this->size_ = 0;
    this->head_ = nullptr;
  }


  template <typename T>
  LinkedList<T>::LinkedList(int size, T const& value) {
    this->size_ = size;
    this->head_ = new Node<T>(value);
    Node<T>* ptr = this->head_;
    for (int i = 0; i<this> size_ - 1; ++i) {
      ptr->next_ = new Node<T>(value);
      ptr->next_->prev_ = ptr;
      ptr = ptr->next_;
    }
    ptr->next_ = this->head_;
    this->prev_ = ptr;
  }

  template <typename T>
  LinkedList<T>::LinkedList(int size) {
    this->size_ = size;
    this->head_ = new Node<T>;
    Node<T> *ptr = this->head_;
    srand((unsigned int)time(NULL));
    for (int i = 0; i<this> size_ - 1; ++i) {
      ptr->value_ = rand() % 2;
      ptr->next_ = new Node<T>;
      ptr->next_->prev_ = ptr;
      ptr = ptr->next_;
    }
    ptr->value_ = rand()%2;
    ptr->next_ = this->head_;
    this->prev_ = ptr;
  }
  template <typename T>
  LinkedList<T>::LinkedList(LinkedList const& other) {
    this->size_ = other.size_;
    Node<T> *other_ptr = other->head_;
    this->head_ = new Node<T>(other_ptr->value_);
    Node<T>* ptr = this->head_;
    while (other.head_->prev_ != other_ptr) {
      ptr->next_ = new Node<T>(other_ptr->next);
      ptr->next_->prev_ = ptr;
      other_ptr = other_ptr->next_;
      ptr = ptr->next_;
    }
    ptr->next_ = this->head_;
    this->head_->prev = ptr;
  }

  }//namespace wolfram_code


#endif