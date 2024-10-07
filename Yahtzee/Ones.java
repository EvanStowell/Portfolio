/*
   Evan Stowell
   CS 2100
   Ones Category; Upper Section
*/
public class Ones extends Category
{
   /**
      Determines score of dice in terms of the Ones category
      @param Dice ArrayList
      @return int score in ones category
   */
   @Override
   public int evaluate(Dice d)
   {
      int scoringDice = d.count(1);
      return scoringDice;
   }
}