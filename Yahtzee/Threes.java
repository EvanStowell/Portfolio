/*
   Evan Stowell
   CS 2100
   Threes Category; Upper Section
*/
public class Threes extends Category
{
   /**
      Determines score of dice in terms of the Threes category
      @param Dice ArrayList
      @return int score in Threes category
   */
   @Override
   public int evaluate(Dice d)
   {
      int scoringDice = d.count(3);
      return scoringDice * 3;
   }
}