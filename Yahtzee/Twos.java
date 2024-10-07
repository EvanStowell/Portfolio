/*
   Evan Stowell
   CS 2100
   Twos Category; Upper Section
*/
public class Twos extends Category
{
   /**
      Determines score of dice in terms of the Twos category
      @param Dice ArrayList
      @return int score in Twos category
   */
   @Override
   public int evaluate(Dice d)
   {
      int scoringDice = d.count(2);
      return scoringDice * 2;
   }
}