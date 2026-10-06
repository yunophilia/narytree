package narytree

type Node[T any] struct {
	data     T
	children []Node[T]
}

func New[T any](data T, childrenCapacity int) *Node[T] {
	return &Node[T]{
		data:     data,
		children: make([]Node[T], 0, childrenCapacity),
	}
}

func (n *Node[T]) AddChild(child *Node[T]) {
	n.children = append(n.children, *child)
}

func (n *Node[T]) Traverse(callback func(data T) bool) (T, bool) {
	if callback(n.data) {
		return n.data, true
	}

	for _, c := range n.children {
		if result, found := c.Traverse(callback); found {
			return result, true
		}
	}

	return *new(T), false
}
