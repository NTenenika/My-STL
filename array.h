#pragma once

template<class T, size_t N>
class Array { 
  public:
    Array() : size_(N), array_[new T(N)] {}
    ~Array() {
        delete[] array_;
    }
    // Copy and Move constructors
    Array(const Array& other) {
      if (this != &other) {
        size_ = other.size_;
        for (auto i{uz}; i < size_; i++) {
          array_[i] = other.array_[i];
        }
      }
      return *this;
    }
    Array(Array&& other) noexcept : size_(other.size_), array_(other.array_) {
      other.size_ = 0;
      other.array_ = nullptr;
    }
    // Assignment operators
    Array& operator=(const Array& other) {
      if (this != other) {
        delete[] array_;

        size_ = other.size_;
        array_ = new T[size_];
        for (auto i{uz}; i < size_; i++) {
          array_[i] = other.array_[i];
        }
      }
      return *this;
    }
    Array& operator=(Array&& other) {
      if (this != other) {
        delete[] array_;

        array_ = other.array_;
        size_ = other.size_;
      }
      return *this;
    }

  private:
    T* array_;
    size_t size_;
};