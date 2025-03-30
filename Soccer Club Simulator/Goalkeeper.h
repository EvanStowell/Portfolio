//
// Created by Evan on 2/22/2025.
//

#ifndef M2OEP_ELSTOWEL_GOALKEEPER_H
#define M2OEP_ELSTOWEL_GOALKEEPER_H

#include "Player.h"

class Goalkeeper : public Player {
public:
    /**
     * Requires: none
     * Modifies: playerPosition, playerOverall, playerStats
     * Effects: calls default constructor
     */
    Goalkeeper();

    /**
     * Requires: none
     * Modifies: playerPosition, playerOverall, playerStats
     * Effects: calls default constructor, but uses Goalkeeper specific
     *          stats
     */
    explicit Goalkeeper(playerPosition playerPosition);

    /**
     * Requires: playerPosition (GK), playerOverall
     * Modifies: playerPosition, playerOverall, playerStats
     * Effects: calls default constructor, changes player position
     *          to GK if input is not in domain above, fills stats
     *          related to goalkeeper
     */
    Goalkeeper(playerPosition playerPos, int playerOverall);

    /**
      * Requires: playerPosition (GK), playerOverall, vector player statistics
      * Modifies: playerPosition, playerOverall, playerStats
      * Effects: calls default constructor, changes player position
     *          to ST if input is not in domain above
      *
      */
    Goalkeeper(playerPosition playerPos, int playerOverall, vector<statistic> playerStats);

    /**
     * Requires: player rating
     * Modifies: player stats
     * Effects: overrides Player's fillStatistics to add GK-specific stats
     */
    void fillStatistics(int playerRating) override;

    /**
     * Requires: player stats
     * Modifies: playerStats
     * Effects: overrides Player's fillStatistics to add GK-specific stats as specified in playerStats
     */
    void fillStatistics(vector<int> playerStats) override;

    /**
     * Requires: none
     * Modifies: none
     * Effects: returns statement unique to forwards when leaving club
     */
    string leaveClub() override;
};



#endif //M2OEP_ELSTOWEL_GOALKEEPER_H
