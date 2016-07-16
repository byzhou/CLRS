#include "node.h"
#include "linked_list.h"
#include <cstddef>

template<typename V> node<V> linked_list<V> :: list_search (V value) {
	for (node<V>* tmp_node = start_node; tmp_node != NULL; tmp_node = tmp_node -> next){
		if (value == tmp_node -> value) {
			return tmp_node ;
		}
	}
}
