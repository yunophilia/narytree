#include "narytree.h"

#include <stdio.h>

void print_int(void* data) {
	printf("%d\n", *((int*) data));
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7};

	narytree_node_t* n = narytree_node_new(&arr[0], NULL);

	narytree_node_add_child(n, &arr[1], NULL);
	narytree_node_t* n2 = narytree_node_add_child(n, &arr[2], NULL);
	narytree_node_add_child(n, &arr[3], NULL);
	
	narytree_node_add_child(n2, &arr[4], NULL);
	narytree_node_add_child(n2, &arr[5], NULL);
	narytree_node_add_child(n2, &arr[6], NULL);

	narytree_node_traverse(n, print_int);

	narytree_node_free(n);

	return 0;
}