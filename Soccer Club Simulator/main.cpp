//
// Soccer Club Simulator
// Main program
//
#include "Team.h"

int main(int argc, char* argv[]) {
    // set seed
    srand(time(NULL));
    Team userTeam;

    //load team if needed
    std::ifstream team_save("team_save.txt");
    if (team_save) {
        userTeam.importTeam("team_save.txt");
    }

    //get user menu input
    int inputMenu = atoi(argv[1]);

    if (inputMenu == 1) {
        //play match
        //create opponent
        int oppRating = Team::generateOpponentRating();
        Team oppTeam(oppRating);

        //simulate match
        int matchOutcome = userTeam.playMatch(oppTeam);

        if (matchOutcome == 1) {
            //user win; new player signing
            cout << "You won!<br>" << endl;

            //generate player
            playerPosition newPlayerPosition = Team::generatePosition();
            int currPlrIndex = userTeam.findPlayer(newPlayerPosition);
            int newPlayerRating = Team::generatePlayerRating(userTeam.getPlayer(currPlrIndex).getPlayerOverall());
            unique_ptr<Player> p = Team::createPlayer(newPlayerPosition, newPlayerRating);

            //replace player
            if (userTeam.signPlayer(newPlayerPosition, newPlayerRating)) {
                //recalculate user team's overall rating
                float newOverallRating = userTeam.calculateOverallRating();
                userTeam.setOverallRating(newOverallRating);
                //recalculate user team's club status
                clubStatus newStatus = userTeam.calculateClubStatus();
                userTeam.setClubStatus(newStatus);

                //output new player info
                cout << "A " << newPlayerRating << " rated " << p->playerPositionToString() << endl;
                cout << " signed for your club!<br>" << endl;
            } else {
                //error
                cout << "Something went wrong while signing player.<br>" << endl;
            }

        } else if (matchOutcome == 0) {
            //user loss; loses player
            cout << "You lost!<br>" << endl;
            playerPosition exitingPlayerPosition = Team::generatePosition();
            unique_ptr<Player> p = Team::createPlayer(exitingPlayerPosition, 60);

            if (!(userTeam.replacePlayer(exitingPlayerPosition, 60))) {
                //in case of error with player leaving
                cout << "Error. Something went wrong with exiting player.<br>" << endl;
            }

            //recalculate user team's overall rating
            float newOverallRating = userTeam.calculateOverallRating();
            userTeam.setOverallRating(newOverallRating);
            //recalculate user team's club status
            clubStatus newStatus = userTeam.calculateClubStatus();
            userTeam.setClubStatus(newStatus);

            //output info on exiting player
            cout << "Your " << p->playerPositionToString();
            cout << " was furious with the result and left the club!<br>" << endl;
            cout << p->leaveClub() << endl;
            cout << "A 60 rated substitute has taken their place.<br>" << endl;

        } else {
            //tie game
            cout << "The match ended in a draw. Nothing happens!<br>" << endl;
        }
    } else if (inputMenu == 2) {
        //recalculate user team's overall rating
        float newOverallRating = userTeam.calculateOverallRating();
        userTeam.setOverallRating(newOverallRating);
        //recalculate user team's club status
        clubStatus newStatus = userTeam.calculateClubStatus();
        userTeam.setClubStatus(newStatus);

        //check team
        cout << userTeam << "<br>" << endl;

    } else if (inputMenu == 3) {
        //write game rules & desc
        Team::printRules();

    } else if (inputMenu == 4) {
        //exit simulator
        //recalculate user team's overall rating
        float newOverallRating = userTeam.calculateOverallRating();
        userTeam.setOverallRating(newOverallRating);
        //recalculate user team's club status
        clubStatus newStatus = userTeam.calculateClubStatus();
        userTeam.setClubStatus(newStatus);

        //output final overall rating and club status
        cout << "You decided to retire from the manager position. Let's see where the club stands...<br>" << endl;
        cout << "Overall Rating: " << userTeam.getOverallRating() << "<br>" << endl;
        cout << "Club Status: " << Team::clubStatusToString(userTeam.getClubStatus()) << "<br>" << endl;
        cout << "The fans will miss you! Come back soon!<br>" << endl;
    } else {
        cout << "Invalid Option!<br>" << endl;
    }

    //save team
    userTeam.saveTeam();

    return 0;
}