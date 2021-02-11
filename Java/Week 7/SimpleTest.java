
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.fail;
import org.junit.Test;

public class SimpleTest {
  @Test
  public void testTrue() {
    assertTrue(1 == 1);
  }

  @Test
  public void testFalse() {
    assertTrue(0 == 1);
  }

  @Test
  public void manualSuccess() {
    return;
  }

  @Test
  public void manualFail() {
    fail("Always fails");
    assertTrue(1 == 1);
  }

  @Test
  public void testUnexpectedException() {
    throw new RuntimeException("Unexpected error");
  }

  @Test(expected = RuntimeException.class)
  public void testExpectedException() {
    throw new RuntimeException("Expected error");
  }

  @Test
  public void testExpectedException2() {
    try{
      int x = 3/0;
      fail("No exception");
    } catch(ArithmeticException e){}
  }


  @Test(timeout=2000)
  public void abortWhenInfiniteLoop(){
    while(true){}
  }
}
