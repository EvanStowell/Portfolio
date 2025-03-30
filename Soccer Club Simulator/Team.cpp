//
// Definition of methods from Team class
//
#include "Team.h"
#include <stdlib.h>
#include <fstream>
#include <utility>
using std::ifstream, std::move;

Team::Team() : fClubStatus(clubStatus::Grassroots), fOverallRating(60) {
    fillTeam(60);
};

Team::Team(int pOverallRating) : fClubStatus(clubStatus::Grassroots), fOverallRating(pOverallRating) {
    fillTeam(pOverallRating);
}

clubStatus Team::getClubStatus() const {
    return fClubStatus;
}

float Team::getOverallRating() const {
    return fOverallRating;
}

void Team::setClubStatus(clubStatus pClubStatus) {
    fClubStatus = pClubStatus;
}

void Team::setOverallRating(float pOverallRating) {
    fOverallRating = pOverallRating;
}

float Team::calculateOverallRating() const {
    if (players.empty()) {
        return 0.0;
    }

    float sum = 0;
    for (auto& p : players) {
        sum += p->getPlayerOverall();
    }
    return sum / players.size();
}

clubStatus Team::calculateClubStatus() const {
    clubStatus calculatedStatus;
    float overallRating = getOverallRating();

    //determine status given overall rating is within certain range
    if (overallRating >= 60 && overallRating < 70) {
        calculatedStatus = clubStatus::Grassroots;
    } else if (overallRating >= 70 && overallRating < 80) {
        calculatedStatus = clubStatus::Semiprofessional;
    } else if (overallRating >= 80 && overallRating < 90) {
        calculatedStatus = clubStatus::Professional;
    } else if (overallRating >= 90 && overallRating < 95) {
        calculatedStatus = clubStatus::Champion;
    } else {
        calculatedStatus = clubStatus::Legend;
    }

    return calculatedStatus;
}

playerPosition Team::generatePosition() {
    playerPosition randPosition;

    //create random index to be used on playerPosition enum
    int index = rand() % 11;

    //assign random playerPosition to randPosition
    randPosition = static_cast<playerPosition>(index);

    return randPosition;
}

void Team::fillTeam(int teamOverall) {
    vector<playerPosition> positions = {
            playerPosition::GK, playerPosition::LB, playerPosition::LCB,
            playerPosition::RCB, playerPosition::RB, playerPosition::CDM,
            playerPosition::CM, playerPosition::CAM, playerPosition::LW,
            playerPosition::ST, playerPosition::RW
    };

    for (playerPosition p : positions) {
        if (p == playerPosition::GK) {
            Goalkeeper player(p, teamOverall);
            player.fillStatistics(teamOverall);
            players.push_back( make_unique<Goalkeeper>(player) );
        } else if (p == playerPosition::LB || p == playerPosition::LCB || p == playerPosition::RCB || p == playerPosition::RB) {
            Defender player(p, teamOverall);
            player.fillStatistics(teamOverall);
            players.push_back( make_unique<Defender>(player) );
        } else if (p == playerPosition::CDM || p == playerPosition::CM || p == playerPosition::CAM) {
            Midfielder player(p, teamOverall);
            player.fillStatistics(teamOverall);
            players.push_back( make_unique<Midfielder>(player) );
        } else {
            Forward player(p, teamOverall);
            player.fillStatistics(teamOverall);
            players.push_back( make_unique<Forward>(player) );
        }
    }
}

int Team::generatePlayerRating(int currRating) {
    // raise floor of range depending on current player's rating
    // new player is guaranteed to be at least as good as current player
    return (rand() % (99 - currRating+1)) + currRating;
}

int Team::generateOpponentRating() {
    // Return integer opponent rating in range of 50-99
    return (rand() % 50) + 50;
}

int Team::playMatch(Team &opponent) const {
    //compare overall ratings
    if (*this > opponent) {
        //user wins match
        return 1;
    } else if (*this < opponent) {
        //user loses match
        return 0;
    } else {
        //tie game
        return -1;
    }
}

unique_ptr<Player> Team::createPlayer(playerPosition position, int rating) {
    if (position == playerPosition::GK) {
        return make_unique<Goalkeeper>(position, rating);
    } else if (position == playerPosition::LB || position == playerPosition::LCB || position == playerPosition::RCB || position == playerPosition::RB) {
        return make_unique<Defender>(position, rating);
    } else if (position == playerPosition::CDM || position == playerPosition::CM || position == playerPosition::CAM) {
        return make_unique<Midfielder>(position, rating);
    } else if (position == playerPosition::LW || position == playerPosition::ST || position == playerPosition::RW) {
        return make_unique<Forward>(position, rating);
    } else {
        return nullptr;
    }
}

bool Team::signPlayer(playerPosition pPosition, int pPlayerRating) {
    for (auto& p : players) {
        if (p->getPlayerPos() == pPosition) {
            p->setPlayerOverall(pPlayerRating);
            p->fillStatistics(pPlayerRating);
            return true;
        }
    }
    //player not found
    return false;
}

bool Team::replacePlayer(playerPosition pPosition, int pRating) {
    for (auto& p : players) {
        if (p->getPlayerPos() == pPosition) {
            p->setPlayerOverall(pRating);
            p->fillStatistics(pRating);
            return true;
        }
    }
    //player not found
    return false;
}

void Team::addPlayer(unique_ptr<Player> player) {
    players.push_back(std::move(player));
}

int Team::findPlayer(playerPosition pPosition) {
    for (int i=0; i < players.size(); ++i) {
        if (players[i]->getPlayerPos() == pPosition) {
            return i;
        }
    }
    return -1;
}

Player Team::getPlayer(int pIndex) {
    return *players[pIndex];
}

int Team::getMenuInput() {
    string input;
    int inputMenu;
    bool validInput = false;

    while (!validInput) {
        //clear stream
        cin.clear();

        //print main menu
        cout << "(1) Play a match" << endl;
        cout << "(2) Check team" << endl;
        cout << "(3) Read game description & rules" << endl;
        cout << "(4) Import team" << endl;
        cout << "(5) Exit simulator\n" << endl;
        cout << ">>";

        //Get input and read it in
        getline(cin, input);
        stringstream ss;
        ss << input;

        //validate input
        if (input.empty()) {
            //input is empty
            cout << "No input entered. Enter an option from menu." << endl;
        } else if (!(ss >> inputMenu)) {
            //input cannot be converted to integer
            cout << "Invalid input. Enter 1, 2, 3, or 4." << endl;
        } else if (inputMenu < 1 || inputMenu > 5) {
            //input is outside of range of options
            cout << "Input is outside range of options. Enter 1, 2, 3, 4, or 5." << endl;
        } else {
            //check for extra input
            string inputRemaining;
            ss >> inputRemaining;
            if (!inputRemaining.empty()) {
                //there are invalid characters remaining in the stream
                cout << "Invalid input. Enter 1, 2, 3, 4, or 5." << endl;
            } else {
                validInput = true;
            }
        }
    }

    return inputMenu;
}

char Team::getNewSigningInput() {
    string input;
    char inputSigning;
    bool validInput = false;

    while (!validInput) {
        //clear stream
        cin.clear();

        //get user input
        cout << ">> ";
        getline(cin, input);
        stringstream ss;
        ss << input;

        //validate input
        if (input.empty()) {
            //input is empty
            cout << "No input. Enter 'y' for yes, 'n' for no." << endl;
        } else if (input.length() > 1 || !(ss >> inputSigning)) {
            //input is not a char
            cout << "Invalid input. Enter 'y' for yes, 'n' for no.";
        } else if (inputSigning != 'y' && inputSigning != 'n') {
            //input is not 'y' or 'n'
            cout << "Not a valid option. Enter 'y' for yes, 'n' for no.";
        } else
            validInput = true;
    }

    return inputSigning;
}

string Team::getFileInput() {
    string input;
    bool validInput = false;

    while (!validInput) {
        //clear stream
        cin.clear();
        cout << "Enter filename: ";
        getline(cin, input);

        //validate input
        if (input.empty()) {
            //input is empty
            cout << "No input. ";
        } else {
            validInput = true;
        }
    }

    return input;
}

void Team::printRules() {
    cout << "This program is a simulator where you manage your own soccer club!<br>" << endl;
    cout << "You begin with a squad of 11 60-rated players.<br>" << endl;
    cout << "Each player has a unique position in the team:<br>" << endl;
    cout << "- GK = Goalkeeper<br>" << endl;
    cout << "- LB = Left Back<br>" << endl;
    cout << "- LCB = Left Center Back<br>" << endl;
    cout << "- RCB = Right Center Back<br>" << endl;
    cout << "- RB = Right Back<br>" << endl;
    cout << "- CDM = Center Defensive Midfielder<br>" << endl;
    cout << "- CM = Center Midfielder<br>" << endl;
    cout << "- CAM = Center Attacking Midfielder<br>" << endl;
    cout << "- LW = Left Winger<br>" << endl;
    cout << "- ST = Striker<br>" << endl;
    cout << "- RW = Right Winger<br><br>" << endl << endl;
    cout << "When you play a match, you will be put up against an opponent with an overall rating ranging from 50-99.<br>" << endl;
    cout << "If your team has a higher overall rating, you win. If it is lower, you lose. If they are equal, you draw.<br>" << endl;
    cout << "A win means a player in a random position with a rating ranging from 60-99.<br>" << endl;
    cout << "will offer to join your squad, and you can decide whether to sign him.<br>" << endl;
    cout << "On the other hand, losing will anger one of your players to the point of leaving the club.<br>" << endl;
    cout << "As your team improves, so does you club status. With higher club status, you will recruit higher rated talent more often.<br>" << endl;
    cout << "The goal of the game is to build the strongest squad, win games, and reach Legend Club Status!<br><br>" << endl << endl;
}

string Team::clubStatusToString(clubStatus pClubStatus) {
    switch (pClubStatus) {
        case clubStatus::Grassroots:
            return "Grassroots";
        case clubStatus::Semiprofessional:
            return "Semiprofessional";
        case clubStatus::Professional:
            return "Professional";
        case clubStatus::Champion:
            return "Champion";
        case clubStatus::Legend:
            return "Legend";
        default:
            //error case
            return "Error";
    }
}

void Team::saveTeam() {
    //clear content from team_save.txt
    ofstream outfile("team_save.txt", std::ios::trunc);
    if (!outfile) {
        cout << "Error in opening team_save.txt<br>" << endl;
        return;
    }

    //append players info to team_save.txt
    for (auto& p : players) {
        //write player overall
        outfile << p->getPlayerOverall() << "\n";
        //write player statistic ratings
        for (statistic s : p->getStats()) {
            outfile << s.statRating << "\n";
        }
    }

    outfile.close();
}

string Team::importTeam(string filename) {
    if (readTeamFromFile(filename)) {
        return "Successfully imported team!<br>";
    } else {
        return "File not found. Initializing team to 60-rated...<br>";
    }
}

bool operator == (const Team &lhs, const Team &rhs) {
    return lhs.fOverallRating == rhs.fOverallRating;
}

bool operator > (const Team &lhs, const Team &rhs) {
    return lhs.fOverallRating > rhs.fOverallRating;
}

bool operator < (const Team &lhs, const Team &rhs) {
    return lhs.fOverallRating < rhs.fOverallRating;
}

ostream& operator << (ostream& outs, const Team &rhs) {
    outs << "***** Club Status: " << Team::clubStatusToString(rhs.getClubStatus()) << " *****<br>";
    outs << "***** Overall Rating: " << rhs.getOverallRating() << " *****<br><br>";
    outs << "Player Ratings:<br>";
    for (auto& p : rhs.players) {
        outs << *p << "<br>" << endl;
    }

    return outs;
}

bool Team::readTeamFromFile(string filename) {
    // Reset Player vector
    players.clear();

    // Open the file
    ifstream inFile("../" + filename);

    int MAX_PLAYERS = 11;
    vector<int> statRatings;
    int playerOverall = 0;

    string newline;
    if (inFile) {
        for (int index = 0; index < MAX_PLAYERS; ++index) {
            //clear stat ratings
            statRatings.clear();

            // get position
            auto position = static_cast<playerPosition>(index);

            //read player overall and stat ratings
            for (int j = 0; j < 7; ++j) {
                // validate file line, set to 60 if invalid or below range, set to 99 if above range
                string line;
                getline(inFile, line);
                stringstream ss;
                ss << line;

                int stat;
                if (!(ss >> stat)) {
                    stat = 60;
                } else {
                    string inputRemaining;
                    if (ss >> inputRemaining) {
                        stat = 60;
                    } else if (stat < 55) {
                        // 55 is lowest possible stat rating
                        stat = 60;
                    } else if (stat > 99) {
                        stat=99;
                    }
                }
                if (j % 7 == 0) {
                    // first line for position is overall Rating
                    playerOverall = stat;
                } else {
                    // remaining lines are individual stats
                    statRatings.push_back(stat);
                }
            }

            // create Player object
            unique_ptr<Player> p = createPlayer(position, playerOverall);

            // fill player's statistics
            p->fillStatistics(statRatings);

            //add player to Team's Player vector
            addPlayer(std::move(p));
        }
    } else {
        fillTeam(60);
        return false;
    }

    inFile.close();
    return true;
}