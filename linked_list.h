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



  private:
    Node* next_;
    Data value_;
};

template<class Data>
class LinkedList {
  public:
    LinkedList() : head_(nullptr), tail_(nullptr) {}
  private:
    Node* head_;
    Node* tail_;
};