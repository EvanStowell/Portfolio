/*
   Evan Stowell
   CS 2100
   Three of a Kind Category; Lower Section
*/
public class ThreeOfAKind extends Category
{
   /**
      Determines score of dice in terms of the Three of a Kind category
      @param Dice ArrayList
      @return int score in Three of a Kind category
   */
   @Override
   public int evaluate(Dice d)
   {
      for (int num = 1; num <= 6; num++)
         {
            if (d.count(num) >= 3) // Three dice with same value
            {
               return d.sum();
            }
         }
      return 0;
   }
}