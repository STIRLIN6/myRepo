import java.util.NoSuchElementException;

public class LinkedQueue<T> implements Queue<T> {
	
	private class Node<T>{
		T item;
		Node<T> next;
		
		Node(T item){
			this.item = item;
			this.next = null;
		}
	}
	
	private Node<T> head;
	private Node<T> tail;
	
	public LinkedQueue(){
		head = null;
		tail = null;
	}
	
	public boolean empty() { return head == null; }
	
	public void enqueue(T item){
		if(empty()){
			head = new Node<T>(item);
			tail = head;
			return;
		}
		
		Node<T> oldTail = tail;
		tail = new Node<T>(item);
		oldTail.next = tail;
	}
	
	public T dequeue(){
		
		if(empty()) throw new NoSuchElementException("Empty queue");
		
		Node<T> oldHead = head;
		head = oldHead.next;
		return oldHead.item;
		
	}
	
}