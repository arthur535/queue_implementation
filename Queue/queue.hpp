#include "queue_class.h"
template <typename T>
Queue<T>::Queue(){
    head = nullptr;
    tail = nullptr;
    m_size = 0;
}

template <typename T>
Queue<T>::Queue(const Queue& obj){
    if (!obj.head) {
        return;
    }
    m_size = obj.m_size;
    head = new Node(obj.head->val);
    Node* tmp1 = head;
    Node* tmp2 = obj.head->next;
    while (tmp2) {
        tmp1->next = new Node(tmp2->val);
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
        tail = tmp1;
    }
}

template <typename T>
Queue<T>::Queue(Queue&& rhs){
    head = std::move(rhs.head);
    tail = std::move(rhs.tail);
    m_size = rhs.m_size;
    rhs.m_size = 0;
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& obj) {
    if (this != &obj) {
        if (!obj.head) {
            return *this;
        }
        head = new Node(obj.head->val);
        Node* tmp1 = head;
        Node* tmp2 = obj.head->next;
        while (tmp2) {
            tmp1->next = new Node(tmp2->val);
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
            tail = tmp1;
        }
    }
    return *this;
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue<T>&& rhs) {
    if (this != &rhs) {
        head = std::move(rhs.head);
        tail = std::move(rhs.tail);
        m_size = rhs.m_size;
        rhs.m_size = 0;
    }
    return *this;
}

template <typename T>
Queue<T>::~Queue(){
    while(head){
        pop();
    }
    tail = nullptr;
}

template <typename T>
void Queue<T>::push(const T& val) {
    if(!head){
        head = new Node(val);
        tail = head;
        m_size++;
    }
    else {
        tail -> next = new Node(val);
        tail = tail->next;
        tail->next = nullptr;
        m_size++;
    }
}

template <typename T>
void Queue<T>::push(T&& val) {
    if(!head){
        head = new Node(val);
        tail = head;
        m_size++;
    }
    else {
        tail -> next = new Node(val);
        tail = tail->next;
        tail->next = nullptr;
        m_size++;
    }
}

template <typename T>
void Queue<T>::pop() {
    if(head == nullptr){
        throw 404;
    }
    Node* tmp = head;
    head = head->next;
    delete tmp;
    tmp = nullptr;
    m_size--;
}

template <typename T>
const T& Queue<T>::front() const{
    if(head == nullptr){
        throw 404;
    }
    return head->value;
}
template <typename T>
const T& Queue<T>::back() const{
    if(head == nullptr){
        throw 404;
    }
    return tail->value;
}

template <typename T>
unsigned int Queue<T>::size() const{
    if(head == nullptr){
        return 0;
    }
    return m_size;
}

template <typename T>
bool Queue<T>::empty() const{
    if(0 == m_size){
        return true;
    }
    return false;
}

template <typename T>
void Queue<T>::swap(Queue<T>& rhs) {
    std::swap(head, rhs.head);
    std::swap(tail, rhs.tail);
    std::swap(m_size, rhs.m_size);
}

