#ifndef INCLUDE_IMAGE_CPP
#define INCLUDE_IMAGE_CPP
#include <fstream>
#include <iostream>
#include <linked_list.cpp>
#include <string>
namespace wolfram_code {

class Image {
  int width_;
  int height_;
  std::string file_name_;

 public:
  Image(std::string const& file_name, int width, int height);
  void AddLine(LinkedList<int> const& list);
};

Image::Image(std::string const& file_name, int width, int height) {
  this->file_name_ = file_name;
  this->width_ = width;
  this->height_ = height;
  std::ofstream out;     // поток для записи
  out.open(file_name_);  // открываем файл для записи
  if (out.is_open()) {
    out << "P3" << std::endl
        << this->width_ << " " << this->height_ << std::endl
        << "1" << std::endl;
  }
  out.close();
}

void Image::AddLine(LinkedList<int> const& list) {
  std::ofstream out(this->file_name_, std::ios::app);
  if (out.is_open()) {
    Node<int>* ptr = list.GetHead();
    for (int i = 0; i < list.GetSize() - 1; ++i) {
      int value = ptr->GetValue();
      out << value << " " << value << " " << value << "    ";
      ptr = ptr->GetNext();
    }
    int value = ptr->GetValue();
    out << value << " " << value << " " << value << std::endl;
  }
  out.close();
}

// void Image::AddLine(LinkedList<int> const& list) {

//}

}  // namespace wolfram_code

#endif