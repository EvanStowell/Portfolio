/*
   Evan Stowell
   CS 2100
   Abstract class for categories to be used on Scorecard
*/

public abstract class Category
{
   private int score;
   private boolean used;
   
   /*
      Abstract method for determining value of collection of Die objects
      @param Dice ArrayList
      @return int dice value
   */
   public abstract int evaluate(Dice d);
   
   /*
      Adds value of Dice to score
      @param Dice ArrayList
      @return void
   */
   public void addValue(Dice d)
   {
      score = evaluate(d);
      used = true;
   }
   
   /*
      Accessor method for score of category
      @param void
      @return int score of category
   */
   public int getScore()
   {
      return score;
   }
   /*
      Accessor method for whether a category has been used
      @param void
      @return boolean true if category has been used
                      false otherwise
   */
   public boolean getUsed()
   {
      return used;
   }
}