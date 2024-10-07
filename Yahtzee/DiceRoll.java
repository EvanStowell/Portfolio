/*
   Evan Stowell
   CS 2100
   Specialization of Dice class. Allows all Dice in Dice list to be rolled
*/
public class DiceRoll extends Dice
{
   private final int NUM_DIE = 5;
   
   /**
      Fills Dice object with NUM_DIE random Die objects
      @param void
      @return void
   */
   public DiceRoll() 
   {
      super();
      for (int index = 0; index < NUM_DIE; index++)
         {
            Die d = new Die();
            addDie(d);
         }
      
   }
   /**
      Rerolls all Die objects in Dice list
      @param void
      @return void
   */
   public void toss()
   {
      for (int index = 0; index < super.getNumDice(); index++)
         {
            super.getDie(index).roll();
         }
   }
}