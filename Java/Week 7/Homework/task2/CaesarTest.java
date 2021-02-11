import static org.junit.Assert.assertEquals;

import java.util.Arrays;
import java.util.Collection;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import org.junit.runners.Parameterized.Parameters;

@RunWith(Parameterized.class)
public class CaesarTest {
    @Parameters
    public static Collection<Object[]> data() {
        return Arrays.asList(new Object[][] {     
                 { "abc", "cde", 2 }, { "ABC", "DEF", 3 }, {"Khoa" , "Khoa", 0 }  
           });
    }

    private String fInput;
    private String fExpected;
    private int number;

    public CaesarTest(String input, String expected, int n) {
        this.fInput = input;
        this.fExpected = expected;
        this.number = n;
    }

    @Test
    public void test() {
        Caesar c = new Caesar(number);
        assertEquals(fExpected, c.cipher(fInput));
    }
    @Test
    public void test1() {
        Caesar c = new Caesar(number);
        assertEquals(fInput, c.decipher(fExpected));
    }

    @Test (expected = IllegalArgumentException.class)
    public void test2() {
        Caesar c = new Caesar(3);
        c.cipher("123");
    }
}