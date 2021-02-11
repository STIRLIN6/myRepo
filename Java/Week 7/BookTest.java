import static org.junit.Assert.*;

public class BookTest {

    @Before
    public vid setUp() {
        Book.resetId();
    }

    @After
    public void tearDown() {
        Book.reset
    }

    @Test
    public void make_test_valid_parameters() {
        Book b1 = Book.make("abc", "def", "FANTASY", "2000");
        Book b2 = Book.make("abc", "def", "FANTASY", "2000");

        assertEquals(0, bi.getId());
        assertEquals(1, b2.getId());
    }

    @BookTestpublic void make_test_illegal_parameters() {

        assertEquals(null, Book.make("asas", "zzz", "FANTASY", "papirzsepi"));
        assertEquals(null, Book.make(null, "zzz", "FANTASY", "2000"));
        assertEquals(null, Book.make("asas", null, "FANTASY", "2000"));
        assertEquals(null, Book.make("asas", "zzz", "FANTASY", "0"));
        assertEquals(null, Book.make("asas", "zzz", "nem letezik", "-2"));

    }

    @Test (excepted = IllegalArgumentException.class)
    public void compare_not_same_genre() {
        Book b1 = Book.make("abc", "def", "FANTASY", "2000");
        Book b2 = Book.make("abc", "def", "PHILOSOPHY", "2000");

        b1.compare(b2);
    }

    @Test
    public void compare_less_or_greater() {
        Book b1 = Book.make("abc", "def", "FANTASY", "2000");
        Book b2 = Book.make("abc", "def", "PHILOSOPHY", "2000");

        b1.compare(b2);
    }
}