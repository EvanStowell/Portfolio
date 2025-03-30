//
// Team class for holding team ratings
// and simulating matches with other teams
//

#ifndef M1OEP_ELSTOWEL_TEAM_H
#define M1OEP_ELSTOWEL_TEAM_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include "Goalkeeper.h"
#include "Defender.h"
#include "Midfielder.h"
#include "Forward.h"

using std::string, std::ostream, std::cout, std::endl, std::stringstream, std::cin, std::unique_ptr, std::make_unique, std::ofstream;

// Global Enums
enum class clubStatus {Grassroots, Semiprofessional, Professional, Champion, Legend};

class Team {
public:
    // Default Constructor
    Team();
    // Alternate Constructor
    explicit Team(int pOverallRating);

    // Getters
    clubStatus getClubStatus() const;
    float getOverallRating() const;

    // Setters
    void setClubStatus(clubStatus pClubStatus);
    void setOverallRating(float pOverallRating);

    /*
     * Requires: None
     * Effects: Calculates the average rating from all eleven players' ratings
     * Calls: getRatingGK, getRatingLB, getRatingLCB, getRatingRCB, getRatingRB,
     *        getRatingCDM, getRatingCM, getRatingCAM, getRatingLW, getRatingST,
     *        getRatingRW
     */
    float calculateOverallRating() const;

    /*
     * Requires: None
     * Effects: Calculates club status depending on user team's overall rating
     * Calls: getOverallRating
     */
    clubStatus calculateClubStatus() const;

    /*
     * Requires: None
     * Effects: Generates random player position, used for creating new player
     *          and for selecting random player exiting after loss
     * Calls: None
     */
    static playerPosition generatePosition();

    /*
     * Requires: integer team overall rating
     * Effects: Fills Player vector with 11 players, each of their own position
     * Calls:
     */
    void fillTeam(int teamOverall);

    /*
     * Requires: None
     * Effects: Generates a random player rating between the
     *          rating of the player of the current position and
     *          99.
     * Calls: None
     */
    static int generatePlayerRating(int currRating);

    /*
     * Requires: None
     * Effects: Generates a random opponent team rating between 50-99
     * Calls: None
     */
    static int generateOpponentRating();

     /*
      * Requires: Opponent Team
      * Effects: Returns the outcome (1 if user wins, 0, if user loses, -1 if draw)
      *          of the user's game with the opponent depending on the overall
      *          rating comparison.
      * Calls: None
      */
     int playMatch(Team &opponent) const;

     /*
      * Requires: PlayerPosition position, integer player's rating
      * Effects: Creates a unique pointer for a player based on their position
      *          (ex. LW, ST, RW -> Forward)
      * Calls: None
      */
     static unique_ptr<Player> createPlayer(playerPosition position, int rating);

     /*
      * Requires: New player's position, integer new player's rating
      * Effects: Replaces current player in the given position
      *          with a new player of given rating. Returns true
      *          if signing was successful, false otherwise.
      * Calls:
      */
     bool signPlayer(playerPosition pPosition, int pPlayerRating);

     /*
      * Requires: playerPosition to be replaced
      * Effects: Replaces player exiting team with input rated substitute.
      *          Returns true if successful replacement, false otherwise.
      * Calls: setRatingGK, setRatingLB, setRatingLCB, setRatingRCB, setRatingRB,
     *        setRatingCDM, setRatingCM, setRatingCAM, setRatingLW, setRatingST,
     *        setRatingRW
      */
     bool replacePlayer(playerPosition pPosition, int pRating);

     /*
      * Requires: unique pointer to Player object
      * Effects: Adds unique pointer to players vector
      * Calls: None
      */
     void addPlayer(unique_ptr<Player> player);

     /*
      * Requires: Player position
      * Effects: Finds player in players with matching position and returns
      *          index position if found, -1 otherwise
      * Calls: None
      */
     int findPlayer(playerPosition pPosition);

     /*
      * Requires: Integer index position
      * Effects: Finds player given integer index position and returns unique pointer
      * Calls: none
      */
     Player getPlayer(int pIndex);

     /*
     * Requires: None
     * Effects: Prints main menu, gets and validates user input
     *          (1,2,3,4) on main menu
     * Calls: None
     */
     static int getMenuInput();

     /*
      * Requires: None
      * Effects: Gets and validates user input (y/n) on signing new player
      * Calls: None
      */
     static char getNewSigningInput();

     /*
      * Requires: None
      * Effects: Validates user's input when attempting to import team from txt file
      * Calls: None
      */
     static string getFileInput();

     /*
      * Requires: None
      * Effects: Prints simulator description and rules.
      * Calls: None
      */
     static void printRules();

     /*
      * Requires: Club status enum state
      * Effects: Converts the clubStatus into a string
      * Calls: None
      */
     static string clubStatusToString(clubStatus pClubStatus);

     /*
      * Requires: Vector of unique pointers to players
      * Effects: Writes players information to txt file
      * Calls: None
      */
     void saveTeam();

     /*
      * Requires: string team file name
      * Effects: Imports team from txt file and returns success/failure
      * Calls: readTeamFromFile()
      */
     string importTeam(string filename);

     // Overloaded Operators

     /*
      * Binary Operator
      * Effects: Returns true if overallRating of lhs is equal to that of rhs
      *          Returns false otherwise.
      */
     friend bool operator == (const Team &lhs, const Team &rhs);

     /*
      * Binary Operator
      * Effects: Returns true if overallRating of lhs is greater than that of rhs.
      *          Returns false otherwise.
      */
     friend bool operator > (const Team& lhs, const Team& rhs);

     /*
      * Binary Operator
      * Effects: Returns true if overallRating of lhs is smaller than that of rhs.
      *          Returns false if otherwise.
      */
     friend bool operator < (const Team& lhs, const Team& rhs);

     /*
      * Ostream operator
      * Effects: Prints Team status and ratings in neat manner
      */
     friend ostream& operator << (ostream& outs, const Team &rhs);


private:
    //Fields
    float fOverallRating;
    clubStatus fClubStatus;
    vector<unique_ptr<Player>> players;

    // Helper function to read Team data from file
    bool readTeamFromFile(string filename);
};

#endif //M1OEP_ELSTOWEL_TEAM_H
