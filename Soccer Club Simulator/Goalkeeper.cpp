//
// Created by Evan on 2/22/2025.
//

#include "Goalkeeper.h"

Goalkeeper::Goalkeeper() : Player(playerPosition::GK) {
}

Goalkeeper::Goalkeeper(playerPosition playerPos) : Player(playerPos) {
    if (playerPos != playerPosition::GK) {
        setPlayerPosition(playerPosition::GK);
    }
}

Goalkeeper::Goalkeeper(playerPosition playerPos, int playerOverall) : Player(playerPos, playerOverall) {
    if (playerPos != playerPosition::GK) {
        setPlayerPosition(playerPosition::GK);
    }
}

Goalkeeper::Goalkeeper(playerPosition playerPos, int playerOverall, vector<statistic> playerStats) : Player(playerPos, playerOverall, std::move(playerStats)){
    if (playerPos != playerPosition::GK) {
        setPlayerPosition(playerPosition::GK);
    }
}

void Goalkeeper::fillStatistics(int playerRating) {
    playerStats.clear();
    vector<string> statNames = {"Speed", "Reflexes", "Diving", "Handling", "Kicking", "Positioning"};
    for (string &n : statNames) {
        addStatistic(n, genStatisticRating(playerRating));
    }
}

void Goalkeeper::fillStatistics(vector<int> playerStats) {
    playerStats.clear();
    vector<string> statNames = {"Speed", "Reflexes", "Diving", "Handling", "Kicking", "Positioning"};
    for (int index = 0; index < statNames.size(); ++index) {
        addStatistic(statNames[index], playerStats[index]);
    }
}

string Goalkeeper::leaveClub() {
    return "The goalkeeper throws their gloves at you as they pout off!<br>";
}