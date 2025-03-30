//
// Created by Evan on 2/22/2025.
//

#include "Forward.h"

Forward::Forward() : Player(playerPosition::ST) {
}

Forward::Forward(playerPosition playerPos, int playerOverall) : Player(playerPos, playerOverall) {
    if (playerPos != playerPosition::LW && playerPos != playerPosition::ST && playerPos != playerPosition::RW) {
        setPlayerPosition(playerPosition::ST);
    }
}

Forward::Forward(playerPosition playerPos, int playerOverall, vector<statistic> playerStats) : Player(playerPos, playerOverall, std::move(playerStats)){
    if (playerPos != playerPosition::LW && playerPos != playerPosition::ST && playerPos != playerPosition::RW) {
        setPlayerPosition(playerPosition::ST);
    }
}

string Forward::leaveClub() {
    return "After skying his shot, the forward ran off the pitch cussing a storm!<br>";
}