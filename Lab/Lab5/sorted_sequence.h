#ifndef __SORTED_SEQUENCE__
#define __SORTED_SEQUENCE__

#include <iostream>
#include <sstream>
#include <string>

template <typename T>
class SortedSequence{
  public:
    SortedSequence() : capacity_(0), size_(0), data_(nullptr) {}
    ~SortedSequence() { delete[] data_; }

    void add(const T &a) {  // Task 2 - To Do
      bool newDataUsed = false;
      if(data_==nullptr){
        data_ = new T[1];
        data_[0] = a;
        capacity_ = 1;
        size_ = 1;

        
      }else{
        if(size_ >= capacity_){
          capacity_ = 2 * capacity_;
        }
        // std::cout<<"capacity_: "<<capacity_<<std::endl;
        T* newSpace = new T[capacity_];
        int offset = 0;
        for(int i=0;i<size_;i++){
            // std::cout<<"capacity_: "<<capacity_<<std::endl;
            // std::cout<<"i: "<<i<<std::endl;
            if(!newDataUsed && a<data_[i+offset]){
              newSpace[i] = a;
              size_++;
              offset = offset -1;
              newDataUsed = true;
              // std::cout<<"test"<<std::endl;
            }else{
              // std::cout<<"testXX"<<std::endl;
              newSpace[i] = data_[i+offset]; 
            }
              
        }

        if(!newDataUsed){
          newSpace[size_] = a;
          size_++;
        }


        delete[] data_;
        data_ = newSpace;
        
        
      }
    }

    std::string toString() const {
      std::stringstream ss;
      ss << "capacity: " << capacity_ << ", size: " << size_
        << ", data: " << std::endl;
      if (data_ == nullptr) {
        ss << "None";
      } else {
        for (int i = 0; i < size_; i++) {
          ss << data_[i] << " ";
        }
      }
      return ss.str();
    }

  private:
    int capacity_;
    int size_;
    T *data_;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const SortedSequence<T>& t) {
  os << t.toString();
  return os;
}

#endif 