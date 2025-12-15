#pragma once

template<class Data>
class Node {
  public:
  // Constructors
    Node() : next_(nullptr), value_(Data{}) {}
    Node(Data&& value) : next_(nullptr), value_(value) {}
    Node(Node* next) : next_(next), value_(Data{}) {}
    Node(Node* next, Data&& value) : next_(next), value_(value) {}
    ~Node() {}

    Node* operator=(const Node* other) {
      if (this != other) {
        this = other;
      }
      return this;
    }

  private:
    Node* next_;
    Data value_;
};

template<class Data>
class LinkedList {
  public:
    LinkedList() : head_(nullptr), current_(nullptr), tail_(nullptr) {}
    ~LinkedList() {
    }
  private:
    Node* head_;
    Node* current_;
    Node* tail_;
};