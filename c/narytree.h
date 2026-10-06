#pragma once

#include <stddef.h>

typedef void (*destructor_callback_t)(void *);

typedef struct {
	void *data;
	destructor_callback_t destroy;
} narytree_node_data_t;

typedef struct __node {
	narytree_node_data_t data;

	struct __node **children;
	size_t children_len;
	size_t children_size;
} narytree_node_t;

narytree_node_t *narytree_node_new(void *data, destructor_callback_t dtor);

void narytree_node_free(narytree_node_t *node);

narytree_node_t *narytree_node_add_child(narytree_node_t *node, void *data, destructor_callback_t dtor);

typedef void (*traversal_callback_t)(void *);
void narytree_node_traverse(
	narytree_node_t *node,
	traversal_callback_t callback
);
