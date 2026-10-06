#[derive(Clone)]
struct Node<T> {
	item: T,
	children: Vec<Node<T>>,
}

impl<T> Node<T> {
	fn new(item: T) -> Self {
		Node {
			item,
			children: Vec::new(),
		}
	}

	fn add_children(&mut self, items: Vec<T>) {
		self.children.extend(items.into_iter().map(Node::new));
	}

	fn del_children<F>(&mut self, to_delete: F)
	where
		F: Fn(&Node<T>) -> bool,
	{
		self.children.retain(|child| !to_delete(child));
	}
}

fn main() {
	let mut root = Node::new("hello");
	root.add_children(vec!["hello"]);
	println!("hello");
}
