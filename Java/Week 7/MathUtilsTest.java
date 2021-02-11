import org.junit.Assert.*;
import org.junit.Test;

 

public class MathUtilsTest{
    
    @Test
    public void test_positive() {
        int result = MathUtils.Increment(3);
        assertEquals(4, result);
    }
    
    @Test
    public void test_negative() {
        int result = MathUtils.Increment(-2);
        assertEquals(-1, result);
    }
    
    @Test
    public void test_zero() {
        int result = MathUtils.Increment(0);
        assertEquals(1, result);
    }
    
    @Test
    public void test_maxValue() {
        int result = MathUtils.Increment(Integer.MAX_VALUE);
        assertEquals(Integer.MAX_VALUE, result);
    }
    
    @Test
    public void test_maxValue2() {
        int result = MathUtils.Increment(Integer.MAX_VALUE - 1);
        assertEquals(Integer.MAX_VALUE, result);
    }
    
}