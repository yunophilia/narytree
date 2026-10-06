import narytree.Node;

public class Main {
    public static void main(String[] args) {
        Node<Integer> n = new Node<>(1);
        n.addChild(2);
        n.addChild(3).addChild(4);
        Node<Integer> c = n.addChild(5);
        c.addChild(new Node<>(6)).addChild(new Node<Integer>(7));
        c.addChild(new Node<>(8));

        n.traverse(e -> {
            System.err.println(e);
            return e == 3;
        });
    }
}