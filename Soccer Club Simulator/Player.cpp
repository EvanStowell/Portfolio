//
// Created by Evan on 2/21/2025.
//

#include <iostream>
#include <utility>
#include "Player.h"
using std::endl, std::cout;

Player::Player(playerPosition playerPos) : playerPos(playerPos), playerOverall(60), playerStats() {
}

Player::Player(playerPosition playerPos, int playerOverall) : playerPos(playerPos), playerOverall(playerOverall), playerStats() {
}

Player::Player(playerPosition playerPos, int playerOverall, vector<statistic> stats) : playerPos(playerPos), playerOverall(playerOverall), playerStats(std::move(stats)) {
}

playerPosition Player::getPlayerPos() const {
    return playerPos;
}

int Player::getPlayerOverall() const {
    return playerOverall;
}

vector<statistic> Player::getStats() const {
    return playerStats;
}

int Player::getNumStats() const {
    return playerStats.size();
}

void Player::setPlayerPosition(playerPosition playerPos) {
    this->playerPos = playerPos;
}

void Player::setPlayerOverall(int playerOverall) {
    this->playerOverall = playerOverall;
}

void Player::setStatistic(std::string statName, int statRating) {
    for (statistic& s : playerStats) {
        if (s.statName == statName) {
            s.statRating = statRating;
            return;
        }
    }
    //statistic not found, create it
    addStatistic({statName, statRating});
}

void Player::addStatistic(statistic stat) {
    playerStats.push_back(stat);
}

void Player::addStatistic(string statName, int statRating) {
    playerStats.push_back({statName, statRating});
}

bool Player::removeStatistic(int index) {
    if (index < 0 || index >= playerStats.size()) {
        return false;
    }
    playerStats.erase(playerStats.begin() + index);
    return true;
}

bool Player::removeStatistic(std::string statName) {
    bool removed = false;
    for (int i=0; i < playerStats.size(); ++i) {
        if (playerStats[i].statName == statName) {
            playerStats.erase(playerStats.begin() + i);
            --i;
            removed = true;
        }
    }
    return removed;
}

int Player::genStatisticRating(int playerOverall) {
    int adjustment = (rand() % 11) - 5;
    int statRating = playerOverall + adjustment;
    if (statRating < 1) {
        return 1;
    }
    else if (statRating > 99) {
        return 99;
    }
    return statRating;
}

void Player::clearStatistics() {
    playerStats.clear();
}

void Player::fillStatistics(int playerRating) {
    playerStats.clear();
    vector<string> statNames = {"Speed", "Shooting", "Passing", "Dribbling", "Defending", "Physicality"};
    for (string &name : statNames) {
        addStatistic(name, genStatisticRating(playerRating));
    }
}

void Player::fillStatistics(vector<int> statRatings) {
    playerStats.clear();
    vector<string> statNames = {"Speed", "Shooting", "Passing", "Dribbling", "Defending", "Physicality"};
    for (int index = 0; index < statNames.size(); ++index) {
        addStatistic(statNames[index], statRatings[index]);
    }
}

string Player::leaveClub() {
    return "The player was furious and decided to leave!";
}

string Player::playerPositionToString() const {
    switch (playerPos) {
        case playerPosition::GK:
            return "Goalkeeper (GK)";
        case playerPosition::LB:
            return "Left back (LB)";
        case playerPosition::LCB:
            return "Left Center Back (LCB)";
        case playerPosition::RCB:
            return "Right Center Back (RCB)";
        case playerPosition::RB:
            return "Right Back (RB)";
        case playerPosition::CDM:
            return "Center Defensive Midfielder (CDM)";
        case playerPosition::CM:
            return "Center Midfielder (CM)";
        case playerPosition::CAM:
            return "Center Attacking Midfielder (CAM)";
        case playerPosition::LW:
            return "Left Winger (LW)";
        case playerPosition::ST:
            return "Striker (ST)";
        case playerPosition::RW:
            return "Right Winger (RW)";
        default:
            //error case
            return "error";
    }
}

ostream& operator << (ostream& outs, const Player& p) {
    outs << "**********<br>" << endl;
    outs << "Position : " << p.playerPositionToString() << "<br>" << endl;
    outs << "Overall Rating: " << p.playerOverall << "<br>" << endl;
    for (const statistic& s : p.playerStats) {
        outs << s.statName << ": " << s.statRating << "<br>" << endl;
    }
    return outs;
}