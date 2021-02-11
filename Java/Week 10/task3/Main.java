import java.util.HashSet;

public class Main{
	
	public static void main(String[] args){
		
		HashSet<Vector> set = new HashSet<>();
		set.add(new Vector(0,0));
		set.add(new Vector(3,4));
		set.add(new Vector(3,4));
		
		System.out.println("size of set: " + set.size());
		System.out.println("items of set: " + set);
		
	}
	
}