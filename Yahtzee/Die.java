/*
   Evan Stowell
   CS 2100
   Individual Die object. Randomizes value with every roll
*/
import java.util.Random;

public class Die
{
   private int value;
   private final int SIDES = 6;
   private static Random r = new Random();
   
   /**
      Constructor for Die object. Gives random value
      @param none
      @return Die object
   */
   public Die()
   {
      value = r.nextInt(SIDES) + 1;
   }
   /**
      Randomizes Die's value. Replaces original value with new value.
      @param void
      @return void
   */
   public void roll()
   {
      this.value = r.nextInt(SIDES) + 1;
   }
   /**
      Accessor method for Die value
      @param void
      @return int Die value
   */
   public int getValue()
   {
      return value;
   }
   /**
      toString() method for Die
      @param void
      @return String Die
   */
   @Override
   public String toString()
   {
      return String.format("value %d", value);
   }
}