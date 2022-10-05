package unittest;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class SimpleCalculatorTest {
        @Test
        void isEqual(){
            var calculator=new SimpleCalculator();
            assertEquals(12,calculator.add(5,7));

        }
}