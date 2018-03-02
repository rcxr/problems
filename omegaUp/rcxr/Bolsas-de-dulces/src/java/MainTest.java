import static org.junit.Assert.assertTrue;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import org.junit.runners.Parameterized.Parameter;
import org.junit.runners.Parameterized.Parameters;
import java.io.ByteArrayOutputStream;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Collection;
import java.util.Scanner;

@RunWith(Parameterized.class)
public class MainTest {
  @Parameters
  public static Collection<String> data() {
    return Arrays.asList("00");
  }

  @Parameter
  public String test;

  @Test
  public void test() {
    InputStream input = this.getClass().getResourceAsStream("input" + test + ".txt");
    System.setIn(input);
    ByteArrayOutputStream output = new ByteArrayOutputStream();
    System.setOut(new PrintStream(output));
    Main.main(null);
    assertTrue(normalize(getExpected()).equals(normalize(output.toString())));
  }

  private String getExpected() {
    @SuppressWarnings("resource")
    Scanner scanner = new Scanner(this.getClass().getResourceAsStream("output" + test + ".txt")).useDelimiter("\\A");
    return scanner.hasNext() ? scanner.next() : "";
  }

  private String normalize(String s) {
    return s.replaceAll("\\s+", " ").trim();
  }
}
