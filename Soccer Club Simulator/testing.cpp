//
// Created by Evan on 2/23/2025.
//
#include "Team.h"

bool test_Player();
bool test_Forward();
bool test_Midfielder();
bool test_Defender();
bool test_Goalkeeper();
bool test_Team();

int main() {
    if (test_Player()) {
        cout << "Passed all Player test cases" << endl;
    }
    if (test_Forward()) {
        cout << "Passed all Forward test cases" << endl;
    }
    if (test_Midfielder()) {
        cout << "Passed all Midfielder test cases" << endl;
    }
    if (test_Defender()) {
        cout << "Passed all Defender test cases" << endl;
    }
    if (test_Goalkeeper()) {
        cout << "Passed all Goalkeeper test cases" << endl;
    }
    if (test_Team()) {
        cout << "Passed all Team test cases" << endl;
    }
    return 0;
}

bool test_Player() {
    bool passed = true;

    Player player1(playerPosition::ST);
    if (player1.getPlayerOverall() != 60) {
        cout << "FAILED position-only constructor Overall test case " << endl;
        passed = false;
    }
    if (player1.getNumStats() != 0) {
        cout << "FAILED position-only constructor numStats test case" << endl;
        passed = false;
    }
    Player player2(playerPosition::ST, 80);
    if (player2.getPlayerOverall() != 80) {
        cout << "FAILED position+overall constructor Overall test case" << endl;
        passed = false;
    }
    if (player2.getNumStats() != 0) {
        cout << "FAILED position+overall constructor numStats test case" << endl;
        passed = false;
    }
    vector<statistic> player3Stats = {{"Speed", 99}, {"Shooting", 98}};
    Player player3(playerPosition::ST, 90,player3Stats);
    if (player3.getPlayerOverall() != 90) {
        cout << "FAILED position+overall+stats constructor Overall test case";
        passed = false;
    }
    if (player3.getNumStats() != 2) {
        cout << "FAILED position+overall+stats constructor numStats test case";
        passed = false;
    }
    player1.setPlayerOverall(61);
    if (player1.getPlayerOverall() != 61) {
        cout << "FAILED setPlayerOverall test case" << endl;
        passed = false;
    }
    player1.setPlayerPosition(playerPosition::CAM);
    if (player1.getPlayerPos() != playerPosition::CAM) {
        cout << "FAILED setPlayerPos test case" << endl;
        passed = false;
    }
    player3.removeStatistic(0);
    if (player3.getNumStats() != 1) {
        cout << "FAILED removeStatistic by index test case" << endl;
        passed = false;
    }
    player3.removeStatistic("Shooting");
    if (player3.getNumStats() != 0) {
        cout << "FAILED removeStatistic by name test case" << endl;
        passed = false;
    }
    player3.addStatistic("Example", 75);
    if (player3.getNumStats() != 1) {
        cout << "FAILED addStatistic test case" << endl;
        passed = false;
    }
    int generatedStat = Player::genStatisticRating(80);
    if (generatedStat < 75 || generatedStat > 85) {
        cout << "FAILED genStatisticRating test case" << endl;
        passed = false;
    }
    player3.clearStatistics();
    if (player3.getNumStats() != 0) {
        cout << "FAILED clearStatistics test case" << endl;
        passed = false;
    }
    player3.fillStatistics(70);
    if (player3.getNumStats() != 6) {
        cout << "FAILED fillStatistics test case" << endl;
        passed = false;
    }
    string leavingMessage = player1.leaveClub();
    if (leavingMessage != "The player was furious and decided to leave!") {
        cout << "FAILED leaveClub test case" << endl;
        passed = false;
    }
    if (player1.playerPositionToString() != "Center Attacking Midfielder (CAM)") {
        cout << "FAILED playerPositionToString test case" << endl;
        passed = false;
    }
    return passed;
}

bool test_Forward() {
    bool passed = true;

    Forward player1;
    if (player1.getPlayerPos() != playerPosition::ST) {
        cout << "FAILED default constructor test case" << endl;
        passed = false;
    }
    Forward player2(playerPosition::LW, 70);
    if (player2.getNumStats() != 0) {
        cout << "FAILED position+overall constructor test case" << endl;
        passed = false;
    }
    Forward player3(playerPosition::RB, 70);
    if (player3.getPlayerPos() != playerPosition::ST) {
        cout << "FAILED wrong position+overall constructor test case" << endl;
        passed = false;
    }
    vector<statistic> player4Stats = {{"Speed", 99}, {"Shooting", 98}};
    Forward player4(playerPosition::RW, 85, player4Stats);
    if (player4.getNumStats() != 2) {
        cout << "FAILED position+overall+stats constructor test case" << endl;
        passed = false;
    }
    string leavingMessage = player4.leaveClub();
    if (leavingMessage != "After skying his shot, the forward ran off the pitch cussing a storm!") {
        cout << "FAILED leaveClub test case" << endl;
        passed = false;
    }

    return passed;
}

bool test_Midfielder() {
    bool passed = true;

    Midfielder player1;
    if (player1.getPlayerPos() != playerPosition::CM) {
        cout << "FAILED default constructor test case" << endl;
        passed = false;
    }
    Midfielder player2(playerPosition::CAM, 70);
    if (player2.getNumStats() != 0) {
        cout << "FAILED position+overall constructor test case" << endl;
        passed = false;
    }
    Midfielder player3(playerPosition::RB, 70);
    if (player3.getPlayerPos() != playerPosition::CM) {
        cout << "FAILED wrong position+overall constructor test case" << endl;
        passed = false;
    }
    vector<statistic> player4Stats = {{"Speed", 99}, {"Shooting", 98}};
    Midfielder player4(playerPosition::CDM, 85, player4Stats);
    if (player4.getNumStats() != 2) {
        cout << "FAILED position+overall+stats constructor test case" << endl;
        passed = false;
    }
    string leavingMessage = player4.leaveClub();
    if (leavingMessage != "The midfielder's cross went out for a throw-in for the last time before they took their leave.") {
        cout << "FAILED leaveClub test case" << endl;
        passed = false;
    }

    return passed;
}

bool test_Defender() {
    bool passed = true;

    Defender player1;
    if (player1.getPlayerPos() != playerPosition::LB) {
        cout << "FAILED default constructor test case" << endl;
        passed = false;
    }
    Defender player2(playerPosition::RB, 70);
    if (player2.getNumStats() != 0) {
        cout << "FAILED position+overall constructor test case" << endl;
        passed = false;
    }
    Defender player3(playerPosition::CM, 70);
    if (player3.getPlayerPos() != playerPosition::LB) {
        cout << "FAILED wrong position+overall constructor test case" << endl;
        passed = false;
    }
    vector<statistic> player4Stats = {{"Speed", 99}, {"Shooting", 98}};
    Defender player4(playerPosition::RCB, 85, player4Stats);
    if (player4.getNumStats() != 2) {
        cout << "FAILED position+overall+stats constructor test case" << endl;
        passed = false;
    }
    string leavingMessage = player4.leaveClub();
    if (leavingMessage != "The defender made a harrowing tackle that earned him a red card, never to be seen again.") {
        cout << "FAILED leaveClub test case" << endl;
        passed = false;
    }

    return passed;
}

bool test_Goalkeeper() {
    bool passed = true;

    Goalkeeper player1;
    if (player1.getPlayerPos() != playerPosition::GK) {
        cout << "FAILED default constructor test case" << endl;
        passed = false;
    }
    player1.fillStatistics(60);
    if (player1.removeStatistic("Shooting")) {
        cout << "FAILED fillStatistics override test case" << endl;
        passed = false;
    }
    Goalkeeper player2(playerPosition::GK, 70);
    if (player2.getNumStats() != 0) {
        cout << "FAILED position+overall constructor test case" << endl;
        passed = false;
    }
    Goalkeeper player3(playerPosition::CM, 70);
    if (player3.getPlayerPos() != playerPosition::GK) {
        cout << "FAILED wrong position+overall constructor test case" << endl;
        passed = false;
    }
    vector<statistic> player4Stats = {{"Speed", 99}, {"Reflexes", 98}};
    Goalkeeper player4(playerPosition::GK, 85, player4Stats);
    if (player4.getNumStats() != 2) {
        cout << "FAILED position+overall+stats constructor test case" << endl;
        passed = false;
    }
    string leavingMessage = player4.leaveClub();
    if (leavingMessage != "The goalkeeper throws their gloves at you as they pout off!") {
        cout << "FAILED leaveClub test case" << endl;
        passed = false;
    }

    return passed;
}

bool test_Team() {
    bool passed = true;

    Team team1;
    if (team1.getOverallRating() != 60) {
        cout << "FAILED default constructor overall test case" << endl;
        passed = false;
    }
    if (team1.getClubStatus() != clubStatus::Grassroots) {
        cout << "FAILED default constructor clubStatus test case" << endl;
        passed = false;
    }
    team1.setClubStatus(clubStatus::Legend);
    if (team1.getClubStatus() != clubStatus::Legend) {
        cout << "FAILED setClubStatus test case" << endl;
        passed = false;
    }
    team1.setOverallRating(96);
    if (team1.getOverallRating() != 96) {
        cout << "FAILED setOverallRating test case" << endl;
        passed = false;
    }
    Team team2(99);
    if (team2.getOverallRating() != 99) {
        cout << "FAILED overallRating-only constructor test case" << endl;
        passed = false;
    }
    if (team2.calculateClubStatus() != clubStatus::Legend) {
        cout << "FAILED calculateClubStatus test case" << endl;
        passed = false;
    }
    playerPosition examplePosition = team2.generatePosition();
    switch (examplePosition) {
        case playerPosition::GK:
            break;
        case playerPosition::LB:
            break;
        case playerPosition::LCB:
            break;
        case playerPosition::RCB:
            break;
        case playerPosition::RB:
            break;
        case playerPosition::CDM:
            break;
        case playerPosition::CM:
            break;
        case playerPosition::CAM:
            break;
        case playerPosition::LW:
            break;
        case playerPosition::ST:
            break;
        case playerPosition::RW:
            break;
        default:
            cout << "FAILED generatePosition test case" << endl;
            passed = false;
    }
    if (Team::generatePlayerRating(clubStatus::Legend) < 85) {
        cout << "FAILED generatePlayerRating test case" << endl;
        passed = false;
    }
    int exampleOppRating = Team::generateOpponentRating();
    if (exampleOppRating < 50 || exampleOppRating > 99) {
        cout << "FAILED generatePlayerRating test case" << endl;
        passed = false;
    }
    Team exampleOpponent(exampleOppRating);
    if (team2.playMatch(exampleOpponent) == 0) {
        cout << "FAILED playMatch test case" << endl;
        passed = false;
    }
    unique_ptr<Player> player1 = team2.createPlayer(playerPosition::CDM, 80);
    if (player1->getPlayerPos() != playerPosition::CDM) {
        cout << "FAILED createPlayer position test case";
        passed = false;
    }
    if (player1->getPlayerOverall() != 80) {
        cout << "FAILED createPlayer overall test case";
        passed = false;
    }
    if (player1->leaveClub() != "The midfielder's cross went out for a throw-in for the last time before they took their leave.") {
        cout << "FAILED createPlayer correct subclass test case";
        passed = false;
    }
    team2.signPlayer(playerPosition::LB, 94);
    team2.setOverallRating(team2.calculateOverallRating());
    if (team2.getOverallRating() == 99) {
        cout << "FAILED signPlayer test case";
        passed = false;
    }
    team2.replacePlayer(playerPosition::RB);
    team2.setOverallRating(team2.calculateOverallRating());
    if (team2.getOverallRating() > 95) {
        cout << "FAILED replacePlayer test case";
        passed = false;
    }
    team2.addPlayer(team2.createPlayer(playerPosition::CDM, 62));
    team2.setOverallRating(team2.calculateOverallRating());
    if (team2.getOverallRating() > 94) {
        cout << "FAILED addPlayer test case";
        passed = false;
    }
    if (Team::clubStatusToString(clubStatus::Professional) != "Professional") {
        cout << "FAILED clubStatusToString test case";
        passed = false;
    }

    return passed;
}