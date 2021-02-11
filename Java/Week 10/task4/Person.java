import java.util.Objects;

public class Person
{
    private String firstname, lastname;
    private String occup;
    private Gender gen;
    private int birthYear;

    public Person(String firstname, String lastname, String occup, Gender gen, int birthYear)
    {
        this.firstname = firstname;
        this.lastname = lastname;
        this.occup = occup;
        this.gen = gen;
        this.birthYear = birthYear;
    }

	@Override
    public String toString()
    {
        return "(" + firstname + "," + lastname + "," + occup + "," + gen + "," + birthYear + ")";
    }
	
	@Override
	public boolean equals(Object that){
		
		if( that == this ) return true;
		if( that == null ) return false;
		
		if(that instanceof Person){
			Person thatPerson = (Person)that;
			return  this.firstname.equals(thatPerson.firstname) &&
					   this.lastname.equals(thatPerson.lastname) &&
					   this.occup.equals(thatPerson.occup) &&
					   this.gen == thatPerson.gen &&
					   this.birthYear == thatPerson.birthYear;
		}
		return false;
		
	}
	
	@Override
	public int hashCode(){
		return Objects.hash(firstname, lastname, occup, gen, birthYear);		
	}
	
}