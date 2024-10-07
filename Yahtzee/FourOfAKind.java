/*
   Evan Stowell
   CS 2100
   Four of a Kind Category; Lower Section
*/
public class FourOfAKind extends Category
{
   /**
      Determines score of dice in terms of the Four of a Kind category
      @param Dice ArrayList
      @return int score in Four of a Kind category
   */
   @Override
   public int evaluate(Dice d)
   {
      for (int num = 1; num <= 6; num++)
         {
            if (d.count(num) >= 4) // Four dice with same value
            {
               return d.sum();
            }
         }
      return 0;
   }
}