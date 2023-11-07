#ifndef INCLUDE_NODE_CPP
#define INCLUDE_NODE_CPP
namespace wolfram_code {

template <typename T>
class Node {
  Node<T>* prev_;
  Node<T>* next_;
  T value_;

 public:
  Node();
  Node(Node<T>* prev, Node* next, T const &value);
  Node(Node<T>* prev, Node* next);
  Node(T const& value);
  Node(Node<T> const &other);
  ~Node();
  Node<T>& operator=(Node<T> const &other);
  void Swap(Node<T>& other);

};

template <typename T>
Node<T>::Node(T const& value) {
  this->prev_ = nullptr;
  this->next_ = nullptr;
  this->value_ = value;
}

template <typename T>
Node<T>::Node() {
  this->prev_ = nullptr;
  this->next_ = nullptr;
}

template <typename T>
Node<T>::Node(Node<T>* prev, Node* next, T const &value) {
  this->prev_ = prev;
  this->next_ = next;
  this->value_ = value;
}

template <typename T>
Node<T>::Node(Node<T>* prev, Node* next) {
  this->prev_ = prev;
  this->next_ = next;
}

template <typename T>
Node<T>::~Node() {
  this->prev_ = nullptr;
  this->next_ = nullptr;
}

template <typename T>
Node<T>::Node(Node<T> const &other){
  this->prev_ = other.prev_;
  this->next_ = other.next_;
  this->value_ = other.value_;

}

template <typename T>
void Node<T>::Swap(Node<T>& other) {
  swap(this->prev_, other.prev_);
  swap(this->next_, other.next_);
  swap(this->value_, other.value_);
  }
template <typename T>
Node<T>& Node<T>::operator=(Node<T> const &other){
  Node<T> temp(other);
  this->Swap(temp);
  return *this;
 }

}  // namespace wolfram_code

#endif