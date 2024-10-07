/*
   Evan Stowell
   CS 2100
   Fives Category; Upper Section
*/
public class Fives extends Category
{
   /**
      Determines score of dice in terms of the Fives category
      @param Dice ArrayList
      @return int score in Fives category
   */
   @Override
   public int evaluate(Dice d)
   {
      int scoringDice = d.count(5);
      return scoringDice * 5;
   }
}