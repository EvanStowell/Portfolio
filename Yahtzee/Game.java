/*
   Evan Stowell
   CS 2100
   Structure for Yahtzee game
*/
import java.util.Scanner;
import java.util.ArrayList;

public class Game
{
   private final int ROLLS_CAP = 2; // Maximum two additional rolls allowed
   private Dice dice; // dice initialized
   private boolean[] saved; // Array recording saved die in dice
   
   /**
      Prints welcome statement
      @param void
      @return void
   */
   public void welcome()
   {
      String s = String.format("************************************\n" + "%25s" +
                               "\n************************************\n", "WELCOME TO YAHTZEE");
      System.out.println(s);
   }
   /**
      Validates die value; returns 0 if not a valid die value
      @param String die val
      @return integer die value 1-5; 0 if not valid
   */
   public int saveDie(String val)
   {
      int dieVal;
      try
      {
         dieVal = Integer.parseInt(val); 
      }
      catch (NumberFormatException e)
      {
         return 0; // Input is not an integer value
      }
      
      if (dieVal >= 1 && dieVal <= 5)
      {
         return dieVal; // Input is valid
      }
      return 0; // Input is not a die value
   }
   /**
      Rolls unsaved dice in collection, returns new dice
      @param ArrayList<Die> dice with unsaved dies, boolean[] saved array
      @return ArrayList<Die> rolledDice with randomized die(s)
   */
   public Dice rollDice(Dice dice, boolean[] saved)
   {
      Dice rolledDice = new Dice();
      for (int index = 0; index < dice.getNumDice(); index++)
      {
         if (saved[index] == false) // Die is not saved
         {
            rolledDice.addDie(new Die());
         }
         else //Die is saved
         {
            rolledDice.addDie(dice.getDie(index));
         }
      }
      return rolledDice;
   }
   /**
      Validates category input, then adds points to scorecard
      and returns points
      @param ScoreCard player scorecard, String user input for 
             category number, Dice dice to be scored
      @return integer number of points scored
              if -1: Invalid category input
              if -2: Category has already been scored
   */
   public int scoreCategory(ScoreCard s, String input, Dice dice)
   {
      int catNum;
      CategoryValue cvChosen = CategoryValue.ONES; // Initialized temporarily to ONES
      try
      {
         catNum = Integer.parseInt(input); 
      }
      catch (NumberFormatException e)
      {
         return -1; // Input is not an integer value
      }
      if (catNum < 1 || catNum > 13)
      {
         return -1; // Input is not a valid category number
      }
      for (CategoryValue cv : CategoryValue.values())
      {
         if (cv.getValue() == catNum-1)
         {
            cvChosen = cv;
         }
      }
      if (s.checkScored(cvChosen) && cvChosen != CategoryValue.YAHTZEE) // Allows yahtzee bonus
      {
         return -2; // Category has already been scored
      }
      s.choose(cvChosen, dice); // Scorecard updates
      return s.getEvaluation(cvChosen, dice);
   }
   /**
      Determines output to be printed given score in category,
      returns boolean indicating depending on successful scoring
      @param integer category score, String category input from user
      @return true if scoring was successful
              false otherwise
   */
   public boolean categoryOutput(int score, String cat_input)
   {
      if (score == -1)
      {
         System.out.printf("\n%s is not a valid category\n", cat_input);
         return false;
      }
      else if (score == -2)
      {
         System.out.println("\nThis category has already been scored");
         return false;
      }
      else
      {
         CategoryValue cvChosen = CategoryValue.ONES; // Temporarily initialized to ONES
         for (CategoryValue cv : CategoryValue.values())
         {
            if (cv.getValue() == (Integer.parseInt(cat_input))-1)
            {
               cvChosen = cv;
            }
         }
         System.out.printf("You have scored %d points in %s\n", score, cvChosen);
         return true;
      }
   }
   /**
      Plays turn for a player
      @param ScoreCard player's scorecard
      @return void
   */
   public void playTurn(ScoreCard card)
   {
      Scanner keyboard = new Scanner(System.in);
      
      dice = new DiceRoll();
      int rollsUsed = 0;
      saved = new boolean[5]; // Create saved array with false elements
      for (int i = 0; i < saved.length; i++)
      {
         saved[i] = false;
      }
      
      boolean rolling = true; // Player is rolling and choosing dice (not ready to score yet)
      while (rolling)
      {
         System.out.print(card);
         for (int index = 0; index < dice.getNumDice(); index++)
         {
            if (saved[index] == true)
            {
               System.out.printf("\n%d: %8s%7s", index+1, dice.getDie(index), "SAVE");
            }
            else
            {
               System.out.printf("\n%d: %8s", index+1, dice.getDie(index));
            }
         }
         System.out.print("\nPlease select a die # to toggle it between save and unsave, \"roll\" or \"score\":" );
         String input = keyboard.nextLine();
         if (input.toLowerCase().equals("roll"))
         {
            if (rollsUsed < ROLLS_CAP)
            {
               dice = rollDice(dice, saved);
               rollsUsed++;
            }
            else
            {
               System.out.println("You are out of rolls");
            }
              
         }
         else if (input.toLowerCase().equals("score"))
         {
            rolling = false; // Player is done rolling, ready to score
         }
         else // Test for valid die value
         {
            int dieVal = saveDie(input);
            if (dieVal == 0) // Invalid die value
            {
               System.out.printf("%s is not a valid die value\n", input);
            }
            else
            {
               saved[dieVal-1] = !(saved[dieVal-1]); // Toggles saved status of die
            }
         }
      }
      
      // Print Categories w/scores
      boolean scoring = true;
      while (scoring)
      {
         System.out.println("Select a category that you have not scored in yet:");
         for (CategoryValue cv : CategoryValue.values())
         {
            System.out.printf("%2d: %s, %d points\n", cv.getValue()+1, cv, card.getCategoryScore(cv));
         }
         String cat_input = keyboard.nextLine();
         int cat_score = scoreCategory(card, cat_input, dice);
         if (categoryOutput(cat_score, cat_input)) // Scoring was successful
         {
            scoring = false; // Turn ends therin
         }
      }
   }
   /**
      Carries out the game
      @param void
      @return void
   */
   public void playGame()
   {
      // Players' turn counts; players stops after thirteen turns
      int p1Turns = 0;
      int p2Turns = 0;
   
      welcome();
      // Create scorecards for two players
      ScoreCard s1 = new ScoreCard(); // Player 1
      ScoreCard s2 = new ScoreCard(); // Player 2
      while (p1Turns < 13 || p2Turns < 13)
      {
         if (p1Turns < 13)
         {
            System.out.println("*****PLAYER 1*****");
            playTurn(s1);
            p1Turns++;
         }
         if (p2Turns < 13)
         {
            System.out.println("*****PLAYER 2*****");
            playTurn(s2);
            p2Turns++;
         }
      }
      System.out.println("*****GAME OVER*****");
      if (s1.scoreTop() >= 63)
      {
         System.out.println("Player 1 earned a 35-point bonus for having at" + 
         "least 63 points in the Upper Total!");
         System.out.printf("Player 1 Final Score: %d\n", s1.score() + 35);
      }
      else
      {
         System.out.printf("Player 1 Final Score: %d\n", s1.score());
      }
      if (s2.scoreTop() >= 63)
      {
         System.out.println("Player 2 earned a 35-point bonus for having at" + 
         "least 63 points in the Upper Total!");
         System.out.printf("Player 2 Final Score: %d", s2.score() + 35);
      }
      else
      {
         System.out.printf("Player 2 Final Score: %d", s2.score());
      }
   }

}