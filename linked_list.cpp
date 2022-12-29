#include <iostream>
#include <cmath>
#include "linked_list.h"

using namespace std;

/******************************************************
** Program: linked_list.cpp
** Author: Raz Poradosu
** Date: 12/04/2022
** Description: An implementation file containing functions that can alter a linked list. 
If functions are called, a linked list with an inserted node in the front, back,
and specified index could be created. A sorted linked list in ascending or descending order can be printed.
A count for the number of primes in the linked list can be portrayed.
** Input: None
** Output: None
******************************************************/

/********************************************************************* 
** Function: Linked_List()
** Description: A default constructor that that sets the length of a linked list to zero and the head pointing to NULL.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Memory will be deleted after the end of the program.
*********************************************************************/
Linked_List::Linked_List() {
    this->length = 0;
    this->head = NULL;
}

/********************************************************************* 
** Function: get_length()
** Description: Returns the length of a linked list
** Parameters: None
** Pre-Conditions: The linked list has been constructed.
** Post-Conditions: None
*********************************************************************/
int Linked_List::get_length() {
    return this->length;
}

/********************************************************************* 
** Function: get_head()
** Description: Returns the head of a linked list
** Parameters: None
** Pre-Conditions: The linked list has been constructed.
** Post-Conditions: None
*********************************************************************/
Node* Linked_List::get_head() {
    return this->head;
}

/********************************************************************* 
** Function: print()
** Description: Prints the values of a linked list
** Parameters: None
** Pre-Conditions: The linked list has been constructed and populated
** Post-Conditions: None
*********************************************************************/
void Linked_List::print() {
	Node* current = head;
	while (current != NULL) { //as long as current is pointing to a node
		cout << current->val << " ";
		current = current->next;
	}
	cout << endl;
}

/********************************************************************* 
** Function: clear()
** Description: Frees the memory allocated and clears the linked list.
** Parameters: None
** Pre-Conditions: The linked list has been constructed and populated.
** Post-Conditions: All memory has been freed with no memory leaks.
*********************************************************************/
void Linked_List::clear() {
	Node* current = head;
	Node* temp = NULL;
	while (current != NULL) { // as long as current is pointing to a node
		temp = current->next;
		delete current;
		current = temp;
	}

	head = NULL;
    this->length = 0;
}

/********************************************************************* 
** Function: push_front(int)
** Description: Adds a node element to the beginning of a linked list.
** Parameters: int value
** Pre-Conditions: The linked list has been constructed and populated. The passed-in
value has been set to the value of the added node.
** Post-Conditions: The length of the linked list has been updated.
*********************************************************************/
void Linked_List::push_front(int value) {
    Node* new_node = new Node; // create a new node
    new_node->val = value; // set the inputted value to the new node's value
    new_node->next = head; // set the new node's pointer to head
    head = new_node; // set the new node to the head of the linked list

    this->length++;
}

/********************************************************************* 
** Function: push_back(int)
** Description: Adds a node element to the end of a linked list.
** Parameters: int value
** Pre-Conditions: The linked list has been constructed and populated. The passed-in
value has been set to the value of the added node.
** Post-Conditions: The length of the linked list has been updated.
*********************************************************************/
void Linked_List::push_back(int value) {
    Node* new_node = new Node; // create a new node to add to the list
    new_node->val = value; // set the new node's valus to inputted value
    new_node->next = NULL;
   
   if (this->length == 0) { // Error handling if the linked list is initially empty
        head = new_node;
    }

    else {
        Node* current = head; // using current as an iterator and setting it to head
        while (current->next != NULL) { // as long as there is another node after
            current = current->next; 
        }
        current->next = new_node; // set the last element to point to the new node
    }

    this->length++; // increment the length of the list
}

/********************************************************************* 
** Function: insert(int, unsigned int)
** Description: Adds a node element at a specific index of a linked list.
** Parameters: int value, unsigned int index
** Pre-Conditions: The linked list has been constructed and populated. The passed-in
value has been set to the value of the added node.
** Post-Conditions: The length of the linked list has been updated.
*********************************************************************/
void Linked_List::insert(int value, unsigned int index) {
    // Error handling if a user wants to add a value to the end of the list
    if ((index < 0) || (index > this->length)) {
        return;
    }
    
    else if (index == 0) {
        push_front(value);
    }

    else if (index == this->length) {
        push_back(value);
    }

    else {
        Node* new_node = new Node;
        new_node->val = value;
        Node* current = head; // using current as an iterator and setting it to head
        for (unsigned int i = 1; i < index; ++i) {
            current = current->next;
        }

        new_node->next = current->next; // assign new node's next pointer to the address of (n+1)th node.
        current->next = new_node;
        this->length++; // increment the length of the list
    }
}

/********************************************************************* 
** Function: merge_sort(Node*, Node*)
** Description: Recursively merges and sorts two linked lists
** Parameters: Node* list1, Node* list2
** Pre-Conditions: The linked list has been split to single linked list nodes.
** Post-Conditions: This function must be called recursively on multiple linked lists and used only
in sort_ascending.
*********************************************************************/
Node* Linked_List::merge_sort(Node* list1, Node* list2) {
	Node* result = NULL; 

	// base cases
	if (list1 == NULL) {
		return (list2); 
    }
	else if (list2 == NULL) {
		return (list1); 
    }

	// recursively merging two lists
	if (list1->val <= list2->val) { 
		result = list1; 
		result->next = merge_sort(list1->next, list2); 
	} 
	else { 
		result = list2; 
		result->next = merge_sort(list1, list2->next); 
	} 
	return result; 
}

/********************************************************************* 
** Function: merge_sort2(Node*, Node*)
** Description: Recursively merges and sorts two linked lists
** Parameters: Node* list1, Node* list2
** Pre-Conditions: The linked list has been split to single linked list nodes.
** Post-Conditions: This function must be called recursively on multiple linked lists and used only
in sort_descending.
*********************************************************************/
Node* Linked_List::merge_sort2(Node* list1, Node* list2) {
	Node* result = NULL; 

	// base cases
	if (list1 == NULL) {
		return (list2); 
    }
	else if (list2 == NULL) {
		return (list1); 
    }

	// recursively merging two lists
	if (list1->val >= list2->val) { 
		result = list1; 
		result->next = merge_sort2(list1->next, list2); 
	} 
	else { 
		result = list2; 
		result->next = merge_sort2(list1, list2->next); 
	} 
	return result; 
}

/********************************************************************* 
** Function: split(Node*, Node*&, Node*&)
** Description: Splits a linked list into two and updates the values of the 2 heads
of the split linked lists by reference.
** Parameters: Node* list, Node*& left, Node*& right
** Pre-Conditions: The linked lists have been constructed.
** Post-Conditions: The two split lists were updated by refernce.
*********************************************************************/
void Linked_List::split(Node* list, Node*& left, Node*& right) {
    // splitting two into halves.
    // if the size of the list is odd, then extra element goes in the first list.

    Node* left_node = list;
	Node* right_node = list; 

	// left_node is incrmented twice and right_node is icremented once.   
    while (left_node != NULL) { 
        left_node = left_node->next;
        if (left_node != NULL && left_node->next != NULL) {
            left_node = left_node->next;
            right_node = right_node->next;
        }
	} 

	// right_node is at the midpoint.
	left = list; 
    right = right_node->next;
    right_node->next = NULL;
}

// void Linked_List::print_help(Node* list) {
// 	Node* current = list;
// 	while (current != NULL) { //as long as current is pointing to a node
// 		cout << current->val << " ";
// 		current = current->next;
// 	}
// 	cout << endl;
// }


/********************************************************************* 
** Function: helper(Node*&)
** Description: recursively splits, merges and sorts a linked list in ascending order.
** Parameters: Node*& list
** Pre-Conditions: The linked lists have been constructed. 
** Post-Conditions: The linked list's head value has been altered.
*********************************************************************/
void Linked_List::helper(Node*& list) {
	Node* ptr1 = NULL; 
	Node* ptr2 = NULL; 

    // Base Case
	if ((list == NULL) || (list->next == NULL)) { 
		return; 
	} 

	// Splitting list
	split(list, ptr1, ptr2);
    helper(ptr1);
    helper(ptr2);

	// Recursively sorting two lists.
	list = merge_sort(ptr1, ptr2);
}

/********************************************************************* 
** Function: helper2(Node*&)
** Description: recursively splits, merges and sorts a linked list in descending order.
** Parameters: Node*& list
** Pre-Conditions: The linked lists have been constructed. 
** Post-Conditions: The linked list's head value has been altered.
*********************************************************************/
void Linked_List::helper2(Node*& list) {
	Node* ptr1 = NULL; 
	Node* ptr2 = NULL; 

    // Base Case
	if ((list == NULL) || (list->next == NULL)) { 
		return; 
	} 

	// Splitting list
	split(list, ptr1, ptr2);
    helper2(ptr1);
    helper2(ptr2);

	// Recursively sorting two lists.
	list = merge_sort2(ptr1, ptr2);
}

/********************************************************************* 
** Function: sort_ascending()
** Description: Sorts a linked list in ascending order.
** Parameters: None
** Pre-Conditions: The linked lists have been constructed and populated.
** Post-Conditions: The linked list's head value has been altered.
*********************************************************************/
void Linked_List::sort_ascending() {
    helper(this->head);
} 

/********************************************************************* 
** Function: sort_descending()
** Description: Sorts a linked list in ascending order.
** Parameters: None
** Pre-Conditions: The linked lists have been constructed and populated.
** Post-Conditions: The linked list's head value has been altered.
*********************************************************************/
void Linked_List::sort_descending() {
    helper2(this->head);
} 

/********************************************************************* 
** Function: count_prime(Linked_List&)
** Description: Counts and returns the number of positive prime numbers in a linked list.
** Parameters: Linked_List& head_ptr
** Pre-Conditions: The length of the linked list is accurate.
** Post-Conditions: None
*********************************************************************/
unsigned int count_prime(Linked_List& head_ptr) {
    int count = 0;
    Node* current = head_ptr.get_head();

    while (current != NULL) {
        if (current->val < 2 ) {
            count ++;
        }
        for (int i = 2; i < (current->val)/2; ++i) {
            if (current->val % i == 0) {
                count++;
                break;
            }
        }
        current = current->next;
    }

    return head_ptr.get_length() - count;
}
