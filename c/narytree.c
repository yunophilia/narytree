#include "narytree.h"

#include <stdlib.h>

#define NARYTREE_INITIAL_CHILDREN_SIZE 16


narytree_node_t *narytree_node_new(void *data, destructor_callback_t dtor)
{
	narytree_node_t *node = malloc(sizeof(*node));

	if (!node)
		return NULL;

	node->data.data = data;
	node->data.destroy = dtor;

	node->children = NULL;
	node->children_len = node->children_size = 0;

	return node;
}


void narytree_node_free(narytree_node_t *node)
{
	if (!node)
		return;

	for (size_t i = 0; i < node->children_len; ++i)
		narytree_node_free(node->children[i]);

	free(node->children);

	if (node->data.destroy)
		node->data.destroy(node->data.data);

	free(node);
}


narytree_node_t *narytree_node_add_child(narytree_node_t *node, void *data, destructor_callback_t dtor)
{
	if (!node)
		return NULL;

	// Grow the children array when necessary.
	if (node->children_len == node->children_size) {
		size_t new_size = (node->children_size == 0) ?
			NARYTREE_INITIAL_CHILDREN_SIZE :
			node->children_size * 2;

		narytree_node_t **tmp = realloc(
			node->children,
			sizeof(*node->children) * new_size
		);

		if (!tmp)
			return NULL;

		node->children = tmp;
		node->children_size = new_size;
	}

	// Create the new child.
	narytree_node_t *new_node =
		narytree_node_new(data, dtor);

	if (!new_node)
		return NULL;

	node->children[node->children_len] = new_node;
	node->children_len++;

	return new_node;
}


void narytree_node_traverse(narytree_node_t *node, traversal_callback_t callback)
{
	if (!node)
		return;

	if (callback)
		callback(node->data.data);

	for (size_t i = 0; i < node->children_len; ++i)
		narytree_node_traverse(node->children[i], callback);
}