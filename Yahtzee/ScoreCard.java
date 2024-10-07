/*
   Evan Stowell
   CS 2100
   Scorecard: Collection of categories and their scores
*/
import java.util.ArrayList;

public class ScoreCard
{
   private ArrayList<Category> scorecard;
   private int yahtzeeBonus = 0; // number of yahtzee bonuses counted
   private final int NUM_CATS = 13; // 13 categories
   
   /**
      Constructor for ArrayList of categories
      @param none
      @return ArrayList<Category> scorecard
   */
   public ScoreCard()
   {
      scorecard = new ArrayList<Category>(NUM_CATS);
      scorecard.add(new Ones());
      scorecard.add(new Twos());
      scorecard.add(new Threes());
      scorecard.add(new Fours());
      scorecard.add(new Fives());
      scorecard.add(new Sixes());
      scorecard.add(new ThreeOfAKind());
      scorecard.add(new FourOfAKind());
      scorecard.add(new FullHouse());
      scorecard.add(new SmStraight());
      scorecard.add(new LgStraight());
      scorecard.add(new Yahtzee());
      scorecard.add(new Chance()); 
   }
   /**
      Determines appropriate category and scores dice in that category
      @param CategoryValue cv desired category, Dice ArrayList
      @return void
   */
   public void choose(CategoryValue cv, Dice d)
   {
      // Conditions for yahtzee bonus: 50 points in yahtzee category and <= 3 bonuses used
      if (cv == CategoryValue.YAHTZEE && scorecard.get(cv.getValue()).getScore() == 50 && yahtzeeBonus <= 3)
      {
         yahtzeeBonus++; // Maximum 3 yahtzee bonus allowed
      }
      scorecard.get(cv.getValue()).addValue(d);
   }
   /**
      Returns score from scoring dice in given category
      @param CategoryValue cv desired category, Dice ArrayList
      @return int score in category
   */
   public int getEvaluation(CategoryValue cv, Dice d)
   {
      return scorecard.get(cv.getValue()).evaluate(d);
   }
   /**
      Checks whether category has been used
      @param CategoryValue cv desired category
      @return boolean true if category has been used
                      false otherwise
   */
   public boolean checkScored(CategoryValue cv)
   {
      return scorecard.get(cv.getValue()).getUsed();
   }
   /**
      Accessor method for current score in given category
      @param CategoryValue cv desired value
      @return int score in category
   */
   public int getCategoryScore(CategoryValue cv)
   {
      return scorecard.get(cv.getValue()).getScore();
   }
   /**
      Returns total score from upper section of score card
      @param void
      @return int upper section score
   */
   public int scoreTop()
   {
      int scoreTop = 0;
      for (int index = 0; index < 6; index++)
      {
         scoreTop += scorecard.get(index).getScore();
      }
      return scoreTop;
   }
   /**
      Returns total score from lower section of scorecard
      @param void
      @return int lower section score
   */
   public int scoreBottom()
   {
      int scoreBottom = 0;
      for (int index = 6; index < 13; index++)
      {
         scoreBottom += scorecard.get(index).getScore();
      }
      scoreBottom += yahtzeeBonus * 100;
      return scoreBottom;
   }
   /**
      Returns combined score of upper and lower section of score card
      @param none
      @return int total score of scorecard
   */
   public int score()
   {
      int score = 0;
      for (int index = 0; index < 13; index++)
      {
         score += scorecard.get(index).getScore();
      }
      score += yahtzeeBonus * 100;
      return score;
   }
   /**
      toString() method for ScoreCard
      @param void
      @return String of ScoreCard
   */
   @Override
   public String toString()
   {
      String s = "Current Scorecard:\n";
      for (CategoryValue cv : CategoryValue.values()) // Returns from thirteen main categories
      {
         s += String.format("%18s: %d\n", cv, getCategoryScore(cv));
      }
      // Adds Yahtzee bonus, upper, lower, and total scores
      s += String.format("%18s: %d\n%18s: %d\n%18s: %d\n%18s: %d\n", 
                                       "Yahtzee Bonus",
                                       yahtzeeBonus*100,
                                       "Upper Total",
                                       scoreTop(),
                                       "Lower Total",
                                       scoreBottom(),
                                       "Total",
                                       score());
      s += "********************************";
      return s;
   }
   
}