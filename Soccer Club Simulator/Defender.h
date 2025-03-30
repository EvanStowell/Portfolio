//
// Created by Evan on 2/22/2025.
//

#ifndef M2OEP_ELSTOWEL_DEFENDER_H
#define M2OEP_ELSTOWEL_DEFENDER_H

#include "Player.h"

class Defender : public Player {
public:
    /**
     * Requires: none
     * Modifies: playerPosition, playerOverall, playerStats
     * Effects: calls default constructor
     */
    Defender();

    /**
     * Requires: playerPosition (LB, LCB, RCB, RB), playerOverall
     * Modifies: playerPosition, playerOverall, playerStats
     * Effects: calls default constructor, changes player position
     *          to LB if input is not in domain above
     */
    Defender(playerPosition playerPos, int playerOverall);

    /**
      * Requires: playerPosition (LB, LCB, RCB, RB), playerOverall, vector player statistics
      * Modifies: playerPosition, playerOverall, playerStats
      * Effects: calls default constructor, changes player position
     *          to ST if input is not in domain above
      *
      */
    Defender(playerPosition playerPos, int playerOverall, vector<statistic> playerStats);

    /**
     * Requires: none
     * Modifies: none
     * Effects: returns statement unique to forwards when leaving club
     */
    string leaveClub() override;
};


#endif //M2OEP_ELSTOWEL_DEFENDER_H
