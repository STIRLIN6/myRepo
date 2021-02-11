import java.util.HashSet;

public class Main{

	public static void main(String[] args){
		//(String firstname, String lastname, String occup, Gender gen, int birthYear)
		HashSet<Person> set = new HashSet<>();
		set.add(new Person("first", "last", "occup", Gender.MALE, 1994));
		set.add(new Person("first", "last", "occup", Gender.MALE, 1994));
		set.add(new Person("first", "last", "occup", Gender.FEMALE, 1994));
		
		System.out.println("size of set: " + set.size());
		System.out.println("items of set: " + set);
	}

}