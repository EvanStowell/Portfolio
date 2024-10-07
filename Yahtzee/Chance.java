/*
   Evan Stowell
   CS 2100
   Chance Category; Lower Section
*/
public class Chance extends Category
{
   /**
      Determines score of dice in terms of the Chance category
      @param Dice ArrayList
      @return int score in Chance category
   */
   @Override
   public int evaluate(Dice d)
   {
      return d.sum();
   }
}