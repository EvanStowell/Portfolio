/*
   Evan Stowell
   CS 2100
   Small Straight Category; Lower Section
*/
public class SmStraight extends Category
{
   /**
      Determines score of dice in terms of the Small Straight category
      @param Dice ArrayList
      @return int score in Small Straight category
   */
   @Override
   public int evaluate(Dice d)
   {
      if (d.contains(3) == true && d.contains(4) == true) // Small straight must have values 3 and 4, otherwise 0 points
      {
         if (d.contains(1) && d.contains(2) || // All possible small straights
             d.contains(2) && d.contains(5) ||
             d.contains(5) && d.contains(6))
         {
            return 30;
         }
      }
      return 0;
   }
}