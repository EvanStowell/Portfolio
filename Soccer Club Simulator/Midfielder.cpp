//
// Created by Evan on 2/22/2025.
//

#include "Midfielder.h"

Midfielder::Midfielder() : Player(playerPosition::CM) {
}

Midfielder::Midfielder(playerPosition playerPos, int playerOverall) : Player(playerPos, playerOverall) {
    if (playerPos != playerPosition::CDM && playerPos != playerPosition::CM && playerPos != playerPosition::CAM) {
        setPlayerPosition(playerPosition::CM);
    }
}

Midfielder::Midfielder(playerPosition playerPos, int playerOverall, vector<statistic> playerStats) : Player(playerPos, playerOverall, std::move(playerStats)){
    if (playerPos != playerPosition::CDM && playerPos != playerPosition::CM && playerPos != playerPosition::CAM) {
        setPlayerPosition(playerPosition::CM);
    }
}

string Midfielder::leaveClub() {
    return "The midfielder's cross went out for a throw-in for the last time before they took their leave.<br>";
}