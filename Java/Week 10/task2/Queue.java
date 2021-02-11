public interface Queue<T>{
	boolean empty();
	void enqueue(T item);
	T dequeue();
}