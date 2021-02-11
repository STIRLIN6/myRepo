import org.junit.*;

//import jdk.internal.jline.internal.TestAccessible;

import static org.junit.Assert.*;

import java.util.NoSuchElementException;
//import org.junit.Test;

//import jdk.internal.jline.internal.TestAccessible;

public class StackTest {
    @Test
    public void TestCases () {
        Stack s = new Stack();

        s.push(3).push(4);
        assertEquals(4, s.pop());

        Stack friss = new Stack();
        assertTrue(friss.empty());

        assertFalse(friss.push(1).empty());

    }

    @Test(expected = NoSuchElementException.class)
    public void emptyPop() {
        Stack s = new Stack();
        s.pop();
    }

    @Test
    public void TestCases2 () {
        Stack s = new Stack();

        assertEquals(0, s.size());
        assertEquals(1, s.push(32).size());

        //A popot nem lehet lancolni, ezert nem irom meg, mert a leszedettel ter vissza es nem a stackkel.
        assertEquals(5, s.push(1).push(2).push(3).push(5).pop());

        Stack v = new Stack();
        v.push(496);
        v.pop();
        assertTrue(v.empty());
    }
}

//javac -cp .;junit-4.12.jar;hamcrest-core-1.3.jar StackTest.java
//java -cp .;junit-4.12.jar;hamcrest-core-1.3.jar org.junit.runner.JUnitCore StackTest