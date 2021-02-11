public class PrintedBook extends Book {
	
	private CoverType coverType;
	
	public PrintedBook(){
		super();
		this.pages += 6;
		this.coverType = CoverType.Hardcover;
	}
	
	public PrintedBook(String author, String title, int pages, CoverType coverType){
		super(author, title, pages + 6);
		this.coverType = coverType;
	}
	
	
	public int getPrice(){
		if(coverType == CoverType.Hardcover) return this.pages * 3;
		else return this.pages * 2;
	}
	
	//ősosztály toString()-je [kezdőoldalszám-végoldalszám] referenced in article: cikknév
	
	@Override
	public String createReference(String article, int from, int to){
		return super.toString() + " [" + from + "-" + to + "] referenced in article: " + article;
	}
	
	@Override
	public String toString(){
		return super.toString() + this.coverType.toString();
	}
	
}