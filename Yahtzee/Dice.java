/*
   Evan Stowell
   CS 2100
   Container for Die objects
*/
import java.util.ArrayList;

public class Dice
{
   private ArrayList<Die> dice;
   private final int DEF_CAP = 5;
   
   /**
      Default constructor for dice ArrayList with default capacity 5
      @param none
      @return ArrayList<Die> dice
   */
   public Dice()
   {
      dice = new ArrayList<Die>(DEF_CAP);
   }
   /**
      Alternate constructor for dice with capacity input
      @param int num capacity
      @return ArrayList<Die> dice
   */
   public Dice(int num)
   {
      dice = new ArrayList<Die>(num);
   }
   /**
      Adds Die object to dice list
      @param Die object
      @return void
   */
   public void addDie(Die d)
   {
      dice.add(d);
   }
   /**
      Accessor method for size of dice list
      @param none
      @return int dice list size
   */
   public int getNumDice()
   {
      return dice.size();
   }
   /**
      Returns Die object from dice list at given index
      @param int index
      @return Die object
   */
   public Die getDie(int i)
   {
      return dice.get(i);
   }
   /**
      Removes Die object from dice list at given index. Returns updated dice list
      @param int index
      @return ArrayList<Die> dice
   */
   public ArrayList<Die> removeDie(int i)
   {
      dice.remove(i);
      return dice;
   }
   /**
      Returns count of Die objects in dice with same value as given value
      @param int value
      @return int count of Die objects with value
   */
   public int count(int val)
   {
      int count = 0;
      for (Die d : dice)
         if (d.getValue() == val)
            {
               count += 1;
            }
      return count;
   }
   /**
      Returns total of values of Die objects in dice list
      @param void
      @return int total of values
   */
   public int sum()
   {
      int total = 0;
      for (Die d : dice)
         total += d.getValue();
      return total;
   }
   /**
      Determines whether any Die object in dice shares 
      the same value as the given value
      @param int value
      @return boolean true if a Die object has same value as given value
                      false otherwise
   */
   public boolean contains(int val)
   {
      for (Die d : dice)
         if (d.getValue() == val)
            {
               return true;
            }
      return false;
   }
   /**
      toString() method for Dice collection
      @param void
      @return String Dice
   */
   @Override
   public String toString()
   {
      String s = "";
      for (int index = 0; index < getNumDice(); index++)
         s += String.format("%d: %s\n", index+1, getDie(index));
      return s;
   }
}