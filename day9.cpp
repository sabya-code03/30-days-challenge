#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    //  Create the new node
    DoublyLinkedListNode* newNode = new DoublyLinkedListNode(data);

    // if List is empty
    if (llist == nullptr) {
        return newNode;
    }

    // if Insert at the very beginning (New Head)
    if (data < llist->data) {
        newNode->next = llist;
        llist->prev = newNode;
        return newNode;
    }

    // Insert in the middle or at the end
    DoublyLinkedListNode* current = llist;

    while (current->next != nullptr && current->next->data < data) {
        current = current->next;
    }

    // insert newNode
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != nullptr) {
        current->next->prev = newNode;
    }

    current->next = newNode;

    return llist;
}
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    //  Create the new node
    DoublyLinkedListNode* newNode = new DoublyLinkedListNode(data);

    // if List is empty
    if (llist == nullptr) {
        return newNode;
    }

    // if Insert at the very beginning (New Head)
    if (data < llist->data) {
        newNode->next = llist;
        llist->prev = newNode;
        return newNode;
    }

    // Insert in the middle or at the end
    DoublyLinkedListNode* current = llist;

    while (current->next != nullptr && current->next->data < data) {
        current = current->next;
    }

    // insert newNode
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != nullptr) {
        current->next->prev = newNode;
    }

    current->next = newNode;

    return llist;
}
