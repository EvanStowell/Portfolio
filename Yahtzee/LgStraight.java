/*
   Evan Stowell
   CS 2100
   Large Straight Category; Lower Section
*/
public class LgStraight extends Category
{
   /**
      Determines score of dice in terms of the Large Straight category
      @param Dice ArrayList
      @return int score in Large Straight category
   */
   @Override
   public int evaluate(Dice d)
   {
      if (d.contains(2) == true && d.contains(3) == true && // Large straight must have values 2,3,4, and 5, otherwise 0 points
          d.contains(4) == true && d.contains(5) == true) 
      {
         if (d.contains(1) || d.contains(6)) // All possible large straights
         {
            return 40;
         }
      }
      return 0;
   }
}