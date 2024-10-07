/*
   Evan Stowell
   CS 2100
   Yahtzee Category; Lower Section
*/
public class Yahtzee extends Category
{
   /**
      Determines score of dice in terms of the Yahtzee category
      @param Dice ArrayList
      @return int score in Yahtzee category
   */
   @Override
   public int evaluate(Dice d)
   {
      for (int num = 1; num <= 6; num++)
         {
            if (d.count(num) == 5) // Five dice with same value
            {
               return 50;
            }
         }

      return 0;
   }
}