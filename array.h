#pragma once
#include <print>
#include <initializer_list>

template<class T, size_t N>
class Array { 
  public:
    constexpr Array() : size_(N), array_(new T[N]) {}
    constexpr ~Array() {
        delete[] array_;
    }

    // Takes { } arguments
    constexpr Array(std::initializer_list<T> list) : size_(N), array_(new T[N]) {
        size_t count = 0;
        for (const T& item : list) {
            if (count < N) {
                array_[count] = item;
                count++;
            }
        }
        while (count < N) {
            array_[count] = T{}; 
            count++;
        }
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

        other.array_ = nullptr; 
        other.size_ = 0;
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
    void Fill(const T& value) {
      for (auto i{0uz}; i < size_; i++) {
        array_[i] = value;
      }
    }
    void Reverse() {
      for (auto i{0uz}; i < size_ / 2; i++) {
        size_t mirrorIndex = size_ - 1 - i;
        std::swap(array_[i], array_[mirrorIndex]);
      }
    }
    constexpr T& At(size_t index) {
        if (index >= size_) {
            std::println("Error: Index {} out of bounds!", index);
            return array_[size_ - 1]; 
        }
        return array_[index];
    }
    constexpr const T& At(size_t index) const {
        if (index >= size_) {
            std::println("Error: Index {} out of bounds!", index);
            return array_[size_ - 1];
        }
        return array_[index];
    }
    void Clear() {
      for (auto i{0uz}; i < size_; i++) {
        array_[i] = T{};
      }
    }
    size_t GetSize() const {
      return size_;
    }

    // Operator overloads
    T& operator[](auto index) {
      return array_[index];
    }
    const T& operator[](auto index) const {
      return array_[index];
    }
    bool operator==(const Array& other) {
      for (auto i{0uz}; i < size_; i++) {
        if (other.array_[i] != array_[i]) {
          return false;
        }
      }
      return true;
    }

    // Search functions
    template<typename T>
    bool Search(T&& item) {
      for (int i{0uz}; i < size_; i++) {
        if (array_[i] == item) {
          return true;
        }
      }
      return false;
    }
    // Returns first and last elements
    decltype(auto) First() {
      return array_[0];
    }
    decltype(auto) Last() {
      return array_[size_-1];
    }
    // Returns Beginnning and End pointers
    decltype(auto) Begin() {
      return array_;
    }
    decltype(auto) End() {
      return array_ + size_;
    }
    // Const versions only for reading
    // Returns first and last elements
    constexpr const T& const First() {
      return array_[0];
    }
    constexpr const T& const Last() {
      return array_[size_-1];
    }
    // Returns Beginnning and End pointers
    constexpr const T* const Begin() {
      return array_;
    }
    constexpr const T* const End() {
      return array_ + size_;
    }
    constexpr bool Empty() const {
        return size_ == 0;
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