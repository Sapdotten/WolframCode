#ifndef INCLUDE_LINKED_LIST_CPP
#define INCLUDE_LINKED_LIST_CPP
#include <time.h>

#include <random>
#include <stdexcept>

#include "node.cpp"

namespace wolfram_code {
template <typename T>
class LinkedList {
  Node<T>* head_;
  int size_;

 public:
  LinkedList();
  LinkedList(int size, T const& value);
  LinkedList(int size);  //заполняет список случайными значениями
  LinkedList(LinkedList<T> const& other);
  void Swap(LinkedList<T>& other);
  LinkedList<T>& operator=(LinkedList<T> const& other);
  ~LinkedList();
  void PushTail(Node<T> const& node);
  void PushTail(LinkedList<T> const& other);
  void PushHead(Node<T> const& node);
  void PushHead(LinkedList<T> const& other);
  void PopHead();
  void PopTail();
  void DeleteNode(T const& value);
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
  if (size <= 0) {
    throw std::runtime_error("Size can't be equal or less 0");
  }
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
  if (size <= 0) {
    throw std::runtime_error("Size can't be equal or less 0");
  }
  this->size_ = size;
  this->head_ = new Node<T>;
  Node<T>* ptr = this->head_;
  srand((unsigned int)time(NULL));
  for (int i = 0; i < this->size_ - 1; ++i) {
    ptr->value_ = rand() % 2;
    ptr->next_ = new Node<T>;
    ptr->next_->prev_ = ptr;
    ptr = ptr->next_;
  }
  ptr->value_ = rand() % 2;
  ptr->next_ = this->head_;
  this->head_->prev_ = ptr;
}
template <typename T>
LinkedList<T>::LinkedList(LinkedList const& other) {
  if (other.size_ == 0) {
    this->head_ = nullptr;
    this->size_ = 0;
  } else {
    this->size_ = other.size_;
    Node<T>* other_ptr = other->head_;
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
}

template <typename T>
void LinkedList<T>::Swap(LinkedList<T>& other) {
  swap(this->head_, other.head_);
  swap(this->size_, other.size_);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> const& other) {
  LinkedList<T> temp(other);
  this->Swap(temp);
  return *this;
}

template <typename T>
LinkedList<T>::~LinkedList() {
  if (this->head_ != nullptr) {
    Node<T>* ptr = this->head_;
    Node<T>* past = this->head_->prev_;
    for (int i = 1; i < this->size_; ++i) {
      ptr = ptr->next_;
      delete ptr->prev_;
    }
    delete ptr;
  }
}

template <class T>
void LinkedList<T>::PushTail(Node<T> const& node) {
  if (this->head_ == nullptr) {
    this->head_ = new Node<T>(node.value_);
    this->head_->next_ = this->head_;
    this->head_->prev_ = this->head_;
  } else {
    this->head_->prev_->next_ = new Node<T>(node.value_);
    this->head_->prev_->prev_ = this->prev_;
    this->head_->prev_ = this->head_->prev_->next_;
    this->head_->prev_->next_ = this->head_;
  }
  this->size_++;
}

template <class T>
void LinkedList<T>::PushHead(Node<T> const& node) {
  this->PushTail(node);
  this->head_ = this->head_->prev_;
}

template <class T>
void LinkedList<T>::PopTail() {
  if (this->head_ == nullptr) {
    throw std::runtime_error("List is empty");
  } else if (this->size_ == 1) {
    delete this->head_;
    this->head_ = nullptr;
  } else {
    Node<T>* ptr = this->head_->prev_;
    this->head_->prev_ = ptr->prev_;
    ptr->prev_->next_ = this->head_;
    delete ptr;
  }
  this->size_--;
}

template <class T>
void LinkedList<T>::PopHead() {
  this->head_ = this->head_->next_;
  this->PopTail();
}

template <class T>
void LinkedList<T>::PushTail(LinkedList<T> const& other) {
  if (this->size_ == 0) {
    *this = LinkedList(other);
  } else if (other.size_) {
    Node<T>* past = this->head_->prev_;
    Node<T>* ptr = past;
    Node<T>* other_ptr = other.head_;
    for (int i = 0; i < other.size_; ++i) {
      ptr->next_ = new Node<T>(other_ptr->value_);
      ptr->next_->prev_ = ptr;
      other_ptr = other_ptr->next_;
      ptr = ptr->next_;
    }
    ptr->next_ = this->head_;
    this->head_->prev_ = ptr;
    this->size_ += other.size_;
  }
}

template <class T>
void LinkedList<T>::PushHead(LinkedList<T> const& other) {
  Node<T>* past = this->head_->prev_;
  this->PushTail(other);
  this->head_ = past->next_;
}

template <class T>
void LinkedList<T>::DeleteNode(T const& value) {
  Node<T>* ptr = this->head_;
  for (int i = 0; i < size_; ++i) {
    if (ptr->value_ == value) {
      ptr->prev_->next_ = ptr->next_;
      ptr->next_->prev_ = ptr->prev_;
      Node<T>* next = ptr->next_;
      delete ptr;
      this->size_--;
      ptr = next;
    } else
      ptr = ptr->next_;
  }
}
template <class T>
Node<T>& LinkedList<T>::operator[](int index) {
  if (index >= this->size_ || index < 0) {
    throw std::runtime_error("Index is invalid");
  }
  Node<T>* ptr = this->head_;
  for (int i = 0; i < index; ++i) {
    ptr = ptr->next_;
  }
  return *ptr;
}

template <class T>
Node<T> LinkedList<T>::operator[](int index) const {
  if (index >= this->size_ || index < 0) {
    throw std::runtime_error("Index is invalid");
  }
  Node<T>* ptr = this->head_;
  for (int i = 0; i < index; ++i) {
    ptr = ptr->next_;
  }
  return *ptr;
}

}  // namespace wolfram_code

#endif