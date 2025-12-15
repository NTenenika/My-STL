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
    void SetNext(Node* next) {
      next_ = next;
    }
    Node* Next() {
      return next_;
    }

  private:
    Node* next_;
    Data value_;
};

template<class Data>
class LinkedList {
  public:
    LinkedList() : head_(nullptr), current_(Node{}), tail_(Node{}) {}
    ~LinkedList() {
      current_->SetNext(head_); // This sets current's ptr to head
      if (current->Next() == nullptr) {
        return;
      }
      do {
        Node* next_node(current->Next());
        delete current_;
        current_->SetNext(next_node);
      } while(current != nullptr)
      head_ = nullptr;
    }
  private:
    Node* head_;
    Node current_;
    Node tail_;
};