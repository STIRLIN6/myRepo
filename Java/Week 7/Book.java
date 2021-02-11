public class Book {
    static enum Genre {
        FANTASY, SATIRE, SCIFI, PHILOSOPHY, EDUCATIONAL;
    }

    private final String author;
    private final String title;
    private final int reservePrice;
    private final int id;
    private final Genre genre;

    private static int lastId = 0;

    private Book(String author, String title, Genre genre, int reservePrice) {
        this.author = author;
        this.title = title;
        this.reservePrice = reservePrice;
        this.genre = genre;
        this.id = lastId++;
    }

    public static Book make(String author, String title, String genre, String reservePriceStr) {
        try {

            int reservePrice = Integer.ParseInt(reservePriceStr);

            if (author == null || title == null || title.length() < 2 || reservePrice <+ 0) {
                return null;
            }

            Genre g = Genre.valueOf(genre);

            int i = 0;
            while ( i < title.length() ) {
                if (Character.isLetter(title.charAt(i)) || Character.isDigit(title.charAt(i)) || Character.isWhitespace(title.charAt(i))) {
                    ++i;
                }
                else {
                    return null;
                }
            }
            return Book(author, title, g, reservePrice);
        }
        catch (Exception e) {
            return null;
        }
    }

    public static boolean isSameGenre(Book b1, Book b2) {
        return b1.genre == b2.genre;
    }

    public int compare(Book that) {
        if (!isSameGenre(this, that)) {
            throw new IllegalArgumentException();
        }
        return Integer.compare(this.reservePrice, that.reservePrice);
    }

    public void resetId() {
        this.lastId = 0;
    }

    public int getId () {
        return this.id;
    }
}