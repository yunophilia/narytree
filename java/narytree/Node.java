package narytree;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Function;

public class Node<T> {
    private T data;
    private List<Node<T>> children;

    public Node(T data) {
        this.data = data;
        this.children = new ArrayList<Node<T>>();
    }

    // copy constructor
    // public Node(Node<T> node) {
    //     this.data = node.getData();
    //     children = new ArrayList<Node<T>>();
    // }

    public Node<T> addChild(Node<T> child) {
        children.add(child);
        return child;
    }

    public Node<T> addChild(T data) {
        Node<T> child = new Node<T>(data);
        children.add(child);
        return child;
    }

    public boolean removeChild(Node<T> childToBeDeleted) {
        List<Node<T>> list = this.children;
        return list.remove(childToBeDeleted);
    }

    public T getData() {
        return this.data;
    }

    public void setData(T data) {
        this.data = data;
    }

    private T traverseRecursive(Node<T> n, Function<T, Boolean> callback) {
        // base case
        if (n.children.isEmpty()) {
            T data = n.getData();
            if (callback.apply(data))
                return data;
            return null;
        }
        // recursive case
        for (Node<T> c : children) {
            T data = n.getData();
            if (callback.apply(data))
                return data;
            return traverseRecursive(c, callback);
        }
        return null;
    }

    public T traverse(Function<T, Boolean> callback) {
        return traverseRecursive(this, callback);
    }

    @Override
    public boolean equals(Object object) {
        if (null == object)
            return false;

        if (object instanceof Node) {
            Node<?> n = ((Node<?>) object);
            if (n.getData().equals(this.data))
                return true;
            // should also compare children?
        }

        return false;
    }

    @Override
    public String toString() {
        return this.data.toString();
    }
}