public class EBook extends Book {
	
	private int size;
	
	public EBook(String author, String title, int pages, int size){
		super(author, title, pages);
		this.size = size;
	}
	
	public int getPrice(){
		return this.pages + this.size;
	}
	
	//ősosztály toString()-je (PDF size: méret) [kezdőoldalszám-végoldalszám] referenced in article: cikknév
	
	@Override
	public String createReference(String article, int from, int to){
		return super.toString() + "(PDF size: " + this.size + ") [" + from + "-" + to + "] referenced in article: " + article;
	}
	
	//ősosztály toString()-je (PDF size: méret) referenced in article: cikknév, accessing PDF date: dátum
	
	public String createReference(String article, String date){
		return super.toString() + " (PDF size: " + this.size + ") referenced in article: " + article + " accessing PDF date: " + date;
	}
	
}