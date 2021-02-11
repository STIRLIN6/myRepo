public class Main{
	
	public static void main(String[] args){
		
		LinkedQueue<Integer> lq = new LinkedQueue<>();
		System.out.println(lq.empty());
		lq.enqueue(1);
		System.out.println(lq.empty());
		
		System.out.println("dequeuing: " + lq.dequeue());
		System.out.println(lq.empty());
		
	}
	
}