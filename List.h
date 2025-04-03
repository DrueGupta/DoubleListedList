#pragma once
#include <cstdlib>
#include <iostream>
using namespace std;

template <typename Type>
struct Node
{
	Type data;
	Node* next;
	Node* prev;

	Node(Type data)
	{
		data = NULL;
		next = nullptr;
		prev = nullptr;
	}

	Node()
	{
		data = NULL;
	}
};

template <typename Type>
class List
{
private:
	Type data;
	Node<Type>* head;
	Node<Type>* tail;
	
public:
	List()
	{
		head = nullptr;
		tail = nullptr;
	}

	Type get(int index)
	{
		Node<Type>* current = head;
		while (index > 0 && != nullptr)
		{
			current = current->next;
			index--;
		}
		if (current == nullptr)
			return nullptr;
		return current->data;
	}

    void insert(Type value, int index) {
        Node<Type>* noob = new Node<Type>(value);

        // EMPTY LIST
        if (head == nullptr) {
            head = noob;
            tail = noob;
            return;
        }

        // INSERT AT FRONT OF LIST
        if (index == 0) {
            noob->next = head;
            head->prev = noob;
            head = noob;
            return;
        }

        // TRAVERSE LIST
        Node<Type>* current = head;
        while (index > 0 && current != nullptr) {
            current = current->next;
            index--;
        }

        // INSERT AT END OF LIST
        if (current == nullptr) {
            noob->prev = tail;
            tail->next = noob;
            tail = noob;
            return;
        }

        // INSERT IN MIDDLE
        noob->next = current;
        noob->prev = current->prev;
        current->prev = noob;
        noob->prev->next = noob;
    }

    void remove(int index) {
        Node<Type>* current = head;

        // REMOVE FROM EMPTY LIST
        if (head == nullptr)
            return;

        // REMOVE ONLY NODE
        if (current == head && current == tail) {
            head = nullptr;
            tail = nullptr;
            delete current;
            return;
        }

        int sizeOfList()
        {
            int size = 0;
            Node<Type>* current = head;
            while (current != nullptr)
            {
                size++;
                current = current->net;
            }
            return size;
        }
        // TRAVERSE
        while (current != nullptr) {
            current = current->next;
            size++;
        }

        // REMOVE FIRST NODE
        if (current == head) {
            current->next->prev = nullptr;
            head = current->next;
            delete current;
            return;
        }

        // REMOVE LAST NODE
        if (current == tail) {
            current->prev->next = nullptr;
            tail = current->prev;
            delete current;
            return;
        }

        // REMOVE FROM MIDDLE
        current->next->prev = current->prev;
        current->prev->next = current->next;
        delete current;
    }

    void remove(Type value) {
        int index = this->search(value);
        if (index != -1)
            this->remove(index);
    }

    void display() {
        int index = 0;
        Node<Type>* current = head;
        while (current != nullptr) {
            cout << index << ". " << current->data << endl;
            index++;
            current = current->next;
        }
    }

    int search(Type value) {
        Node<Type>* current = head;
        int index = 0;
        while (current != nullptr) {
            if (current->data == value)
                return index;
            index++;
            current = current->next;
        }
        return -1;
    }

    void insert(Type value) {
        // Create New Node
        Node<Type>* noob = new Node<Type>(value);

        // EMPTY LIST
        if (head == nullptr) {
            head = noob;
            tail = noob;
            return;
        }

        // NORMAL CASE
        tail->next = noob;
        noob->prev = tail;
        tail = noob;
    }

};
