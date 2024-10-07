/*
   Evan Stowell
   CS 2100
   Full House Category; Lower Section
*/
public class FullHouse extends Category
{
   /**
      Determines score of dice in terms of the Full House category
      @param Dice ArrayList
      @return int score in Full House category
   */
   @Override
   public int evaluate(Dice d)
   {
      for (int firstNum = 1; firstNum <= 6; firstNum++)
         {
            if (d.count(firstNum) == 3) // Three of a kind found
            {
               for (int secNum = 1; secNum <= 6; secNum++)
               {
                  if (d.count(secNum) == 2 && secNum != firstNum) // Two of a kind of different value found
                  {
                     return 25;
                  }
               }
            }
         }
      return 0;
   }
}