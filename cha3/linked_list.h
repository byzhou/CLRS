
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

template<typename V> class linked_list : public node<V> {
	public:
		V* start_node;
		// search for the first element that matches the value
		node<V> list_search (V value);
		// attach the value to the end of the linked list
		void list_insert (V value);
		// delete the first matched node
		void list_delete (V value);
};

#endif

