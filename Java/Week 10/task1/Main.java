public class Main{
	public static void main(String[] args){
		
		ArrayStack<Integer> as = new ArrayStack<>();
		System.out.println(as.empty());
		as.push(1);
		System.out.println(as.empty());
		
		System.out.println("popping: " + as.pop());
		System.out.println(as.empty());
		
		
		as.push(1);
		as.push(2);
		as.push(3);
		
		for(int value : as )
			System.out.println(value);
		
		as.forEach( i -> System.out::println);
	}
}