/*
   Evan Stowell
   CS 2100
   Sixes Category; Upper Section
*/
public class Sixes extends Category
{
   /**
      Determines score of dice in terms of the Sixes category
      @param Dice ArrayList
      @return int score in Sixes category
   */
   @Override
   public int evaluate(Dice d)
   {
      int scoringDice = d.count(6);
      return scoringDice * 6;
   }
}