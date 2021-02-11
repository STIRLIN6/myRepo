public class Main{
	
	public static void main(String[] args){
		
		Book pb = createBook();
		System.out.println(pb.getPrice());
		
		PrintedBook pbook = new PrintedBook("author2", "title2", 94, CoverType.Hardcover);
		EBook ebook = new EBook("author3", "title3", 100, 500);
		System.out.println(pbook.getShortName());
		//System.out.println(pbook.getPrice());
		System.out.println(ebook.getShortName());
		System.out.println(ebook.getPrice());
		
		System.out.println(pbook.createReference("article2", 42, 75));
		System.out.println(ebook.createReference("article3", 464, 732));
		System.out.println(ebook.createReference("article4", "2020.04.14"));
		
		System.out.println(isSameAuthor(pbook, ebook));
		
	}
	
	public static boolean isSameAuthor(Book book1, Book book2){
		System.out.println(book1.getAuthor());
		System.out.println(book2.getAuthor());
		return book1.getAuthor().equals(book2.getAuthor());
	}
	
	public static Book createBook(){
		
		String beolvas = "gg"; //beolvasas a usertol
		if(beolvas.equals("g")) return new PrintedBook();
		else return new EBook("author3", "title3", 100, 500);
	}
	
}