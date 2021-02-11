import java.util.Iterator;
import java.util.NoSuchElementException;

public class ArrayStack<T> implements Stack<T>, Iterable<T> {
	
	private T[] items;
	private int n;
	
	@SuppressWarnings("unchecked")
	public ArrayStack(){
		items = (T[])new Object[4];
		n = 0;
	}
	
	public boolean empty() { return n == 0; }
	
	public void push(T item){
		if( n == items.length ){
			resize(n*2);
		}
		
		items[n++] = item;
	}
	
	public T pop(){
		if(empty()) throw new NoSuchElementException("Empty stack");
	
		T popped = items[n-1];
		items[n-1] = null;
		--n;
		
		if(n > 0 && n == items.length / 4){
			resize(n/2);
		}
		return popped;
	}
	
	public Iterator<T> iterator(){
		return new ReverseArrayIterator();
	} 
	
	@SuppressWarnings("unchecked")
	private void resize(int capacity){
		T[] tmp = (T[])new Object[capacity];
		for(int i =0; i< n; ++i){
			tmp[i] = items[i];
		}
		items = tmp;
	}	
	
	private class ReverseArrayIterator implements Iterator<T> {
		private int i;
		
		public ReverseArrayIterator() { i = n-1; }
		
		public boolean hasNext(){
			return i >= 0;
		}
		
		public T next(){
			if(!hasNext()) throw new NoSuchElementException("No more things to iterate");
			return items[i--];
			
		}
		
	}
	
}