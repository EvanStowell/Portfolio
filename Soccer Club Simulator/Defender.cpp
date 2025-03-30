//
// Created by Evan on 2/22/2025.
//

#include "Defender.h"

Defender::Defender() : Player(playerPosition::LB) {
}

Defender::Defender(playerPosition playerPos, int playerOverall) : Player(playerPos, playerOverall) {
    if (playerPos != playerPosition::LB && playerPos != playerPosition::LCB && playerPos != playerPosition::RCB && playerPos != playerPosition::RB) {
        setPlayerPosition(playerPosition::LB);
    }
}

Defender::Defender(playerPosition playerPos, int playerOverall, vector<statistic> playerStats) : Player(playerPos, playerOverall, std::move(playerStats)){
    if (playerPos != playerPosition::LB && playerPos != playerPosition::LCB && playerPos != playerPosition::RCB && playerPos != playerPosition::RB) {
        setPlayerPosition(playerPosition::LB);
    }
}

string Defender::leaveClub() {
    return "The defender made a harrowing tackle that earned him a red card, never to be seen again.<br>";
}