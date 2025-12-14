#pragma once
#include <print>

template<class T, size_t N>
class Array { 
  public:
    Array() : size_(N), array_(new T[N]) {}
    ~Array() {
        delete[] array_;
    }
    // Copy and Move constructors
    Array(const Array& other) : size_(other.size_), array_(new T[other.size_]) {
      if (this != &other) {
        for (auto i{0uz}; i < size_; i++) {
          array_[i] = other.array_[i];
        }
      }
    }
    Array(Array&& other) noexcept : size_(other.size_), array_(other.array_) {
      other.size_ = 0;
      other.array_ = nullptr;
    }
    // Assignment operators
    Array& operator=(const Array& other) {
      if (this != &other) {
        delete[] array_;

        size_ = other.size_;
        array_ = new T[size_];
        for (auto i{0uz}; i < size_; i++) {
          array_[i] = other.array_[i];
        }
      }
      return *this;
    }
    Array& operator=(Array&& other) {
      if (this != &other) {
        delete[] array_;

        array_ = other.array_;
        size_ = other.size_;
      }
      return *this;
    }
    // Setters and Getter
    constexpr void Set() {}
    template<typename... Rest>
    // Requires even amount bc you need index and value
    constexpr void Set(auto index, const T& value, Rest... rest) requires (sizeof...(Rest) % 2 == 0) { // index and value pair
      if (index < size_) {
        array_[index] = value;
      } else {
          std::println("Warning: Index {} out of bounds", index);
      }
      Set(rest...);
    }

    size_t GetSize() const {
      return size_;
    }

    // Print functions
    void Print() const { // Prints whole array
      for (auto i{0uz}; i < size_; i++) {
        if (i == size_ - 1) {
          std::println("{}", array_[i]);
          return;
        }
        std::print("{} ", array_[i]);
      }
    }
    void Print(auto i) const { // Prints 1 index
      if (i < size_) {
        std::println("{}", array_[i]);
      }
      else {
        std::println("Out of bounds error...Size of array is {}!", size_);
      }
    }
  private:
  // Variables
    T* array_;
    size_t size_;
};