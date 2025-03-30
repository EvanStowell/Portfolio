//
// Created by Evan on 2/22/2025.
//

#ifndef M2OEP_ELSTOWEL_MIDFIELDER_H
#define M2OEP_ELSTOWEL_MIDFIELDER_H

#include "Player.h"

class Midfielder : public Player {
public:
    /**
     * Requires: none
     * Modifies: playerPosition, playerOverall, playerStats
     * Effects: calls default constructor
     */
    Midfielder();

    /**
     * Requires: playerPosition (CDM, CM, CAM), playerOverall
     * Modifies: playerPosition, playerOverall, playerStats
     * Effects: calls default constructor, changes player position
     *          to CM if input is not in domain above
     */
    Midfielder(playerPosition playerPos, int playerOverall);

    /**
      * Requires: playerPosition (CDM, CM, CAM), playerOverall, vector player statistics
      * Modifies: playerPosition, playerOverall, playerStats
      * Effects: calls default constructor, changes player position
     *          to ST if input is not in domain above
      *
      */
    Midfielder(playerPosition playerPos, int playerOverall, vector<statistic> playerStats);

    /**
     * Requires: none
     * Modifies: none
     * Effects: returns statement unique to forwards when leaving club
     */
    string leaveClub() override;
};


#endif //M2OEP_ELSTOWEL_MIDFIELDER_H
