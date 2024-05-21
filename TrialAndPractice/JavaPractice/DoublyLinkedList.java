public class DoublyLinkedList {

  private Node head;
  private Node tail;

  public DoublyLinkedList() {
      this.head = null;
      this.tail = null;
  }

  public void addNode(int data) {
      Node newNode = new Node(data);

      if (this.head == null) {
          this.head = newNode;
          this.tail = newNode;
      } else {
          this.tail.setNext(newNode);
          newNode.setPrevious(this.tail);
          this.tail = newNode;
      }
  }

  public void printList() {
      Node currentNode = this.head;

      while (currentNode != null) {
          System.out.println(currentNode.getData() + " "+currentNode.next+" "+currentNode.previous);
          currentNode = currentNode.getNext();
      }

      System.out.println();
  }

  public static void main(String[] args) {
      DoublyLinkedList list = new DoublyLinkedList();

      list.addNode(1);
      list.addNode(2);
      list.addNode(3);
      list.addNode(4);

      list.printList();
  }
}

class Node {

  public int data;
  public Node previous;
  public Node next;

  public Node(int data) {
      this.data = data;
      this.previous = null;
      this.next = null;
  }

  public int getData() {
      return this.data;
  }

  public void setData(int data) {
      this.data = data;
  }

  public Node getPrevious() {
      return this.previous;
  }

  public void setPrevious(Node previous) {
      this.previous = previous;
  }

  public Node getNext() {
      return this.next;
  }

  public void setNext(Node next) {
      this.next = next;
  }
}