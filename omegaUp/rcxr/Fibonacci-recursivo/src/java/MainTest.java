import static org.junit.Assert.assertTrue;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import org.junit.runners.Parameterized.Parameter;
import org.junit.runners.Parameterized.Parameters;
import java.io.ByteArrayOutputStream;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Collection;
import java.util.LinkedList;
import java.util.Scanner;

@RunWith(Parameterized.class)
public class MainTest {
  final static int SUPPORTED_TEST_CASES = 3;
  
  @Parameters
  public static Collection<String> getParameters() {
    Collection<String> parameters = new LinkedList<String>();
    for (int i = 0; i < SUPPORTED_TEST_CASES; i++) {
      parameters.add(String.format("%02d", i));
    }
    return parameters;
  }

  @Parameter
  public String param;

  @Test
  public void test() {
    InputStream input = this.getClass().getResourceAsStream("input" + param + ".txt");
    System.setIn(input);
    ByteArrayOutputStream output = new ByteArrayOutputStream();
    System.setOut(new PrintStream(output));
    Main.main(null);
    assertTrue(normalize(getExpected()).equals(normalize(output.toString())));
  }

  private String getExpected() {
    @SuppressWarnings("resource")
    Scanner scanner = new Scanner(this.getClass().getResourceAsStream("output" + param + ".txt")).useDelimiter("\\A");
    return scanner.hasNext() ? scanner.next() : "";
  }

  private String normalize(String s) {
    return s.replaceAll("\\s+", " ").trim();
  }
}
