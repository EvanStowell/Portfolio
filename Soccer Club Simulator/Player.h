//
// Created by Evan on 2/21/2025.
//

#ifndef M2OEP_ELSTOWEL_PLAYER_H
#define M2OEP_ELSTOWEL_PLAYER_H

#include <string>
#include <vector>
using std::string, std::vector, std::ostream;

// Global Enums
enum class playerPosition {GK, LB, LCB, RCB, RB, CDM, CM, CAM, LW, ST, RW};

// struct for player statistic
struct statistic {
    string statName;
    int statRating;
};

class Player {
protected:
    playerPosition playerPos;
    int playerOverall;
    vector<statistic> playerStats;
public:
    /**
     * Requires: playerPosition
     * Modifies: playerPosition
     * Effects: Calls default constructor and initializes player position
     */
    explicit Player(playerPosition);

    /**
     * Requires: playerPosition, playerOverall
     * Modifies: playerPosition, playerOverall
     * Effects: Initializes player with given position and overall rating
     */
    Player(playerPosition playerPos, int playerOverall);

    /**
     * Requires: playerPosition, playerOverall, stats (vector of statistics)
     * Modifies: playerPosition, playerOverall, playerStats
     * Effects: Initializes player with given position, overall rating, and custom statistics
     */
    Player(playerPosition playerPos, int playerOverall, vector<statistic> stats);
    /**
     * Effects: Default virtual destructor for Player class
     */
    virtual ~Player() = default;

    /**
     * Requires: None
     * Modifies: None
     * Effects: Returns the player's position
     */
    playerPosition getPlayerPos() const;

    /**
     * Requires: None
     * Modifies: None
     * Effects: Returns the player's overall rating
     */
    int getPlayerOverall() const;

    /**
     * Requires: None
     * Modifies: None
     * Effects: Returns the player's statistics as a vector
     */
    vector<statistic> getStats() const;

    /**
     * Requires: None
     * Modifies: None
     * Effects: Returns the number of statistics associated with the player
     */
    int getNumStats() const;

    /**
     * Requires: Valid playerPosition value
     * Modifies: playerPosition
     * Effects: Updates the player's position
     */
    void setPlayerPosition(playerPosition playerPos);

    /**
     * Requires: Valid overall rating (integer)
     * Modifies: playerOverall
     * Effects: Updates the player's overall rating
     */
    void setPlayerOverall(int playerOverall);

    /**
     * Requires: statName (string), statRating (integer)
     * Modifies: playerStats
     * Effects: Updates the rating of a statistic if it exists, otherwise does nothing
     */
    void setStatistic(string statName, int statRating);

    /**
     * Requires: A statistic struct
     * Modifies: playerStats
     * Effects: Adds a new statistic to the player's statistics
     */
    void addStatistic(statistic stat);

    /**
     * Requires: statName (string), statRating (integer)
     * Modifies: playerStats
     * Effects: Creates and adds a new statistic to the player's statistics
     */
    void addStatistic(string statName, int statRating);

    /**
     * Requires: index (valid position in statistics vector)
     * Modifies: playerStats
     * Effects: Removes a statistic at the given index; returns true if successful, false otherwise
     */
    bool removeStatistic(int index);

    /**
     * Requires: statName (string)
     * Modifies: playerStats
     * Effects: Removes a statistic by name; returns true if successful, false otherwise
     */
    bool removeStatistic(string statName);

    /**
     * Requires: playerOverall (integer)
     * Modifies: None
     * Effects: Generates a statistic rating within the range [playerOverall - 5, playerOverall + 5]
     */
    static int genStatisticRating(int playerOverall);

    /**
     * Requires: None
     * Modifies: playerStats
     * Effects: Clears all statistics associated with the player
     */
    void clearStatistics();

    /**
      * Requires: playerRating (integer)
     * Modifies: playerStats
     * Effects: Populates the player's statistics based on their overall rating
     */
    virtual void fillStatistics(int playerRating);

    /**
     * Requires: statRatings (vector of integers)
     * Modifies: playerStats
     * Effects: Populates the player's statistics using provided ratings
     */
    virtual void fillStatistics(vector<int> statRatings);

    /**
     * Requires: None
     * Modifies: None
     * Effects: Returns a string message indicating the player has left the club
     */
    virtual string leaveClub();

    /**
     * Requires: Player position enum state
     * Modifies: None
     * Effects: Converts the playerPosition into a string
     */
    string playerPositionToString() const;

    friend ostream& operator << (ostream& outs, const Player& p);
};


#endif //M2OEP_ELSTOWEL_PLAYER_H
