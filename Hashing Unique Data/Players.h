/**
 * Evan Stowell
 * CS 2240
 * Section A
 */

#ifndef PROJECT1_PLAYERS_H
#define PROJECT1_PLAYERS_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
using std::string, std::find, std::cout, std::endl, std::left, std::setw, std::vector, std::ifstream, std::ostream;

/**
 * Class for entries in list of players from the top 5 soccer leagues
 * in the world during the 22/23 season. These leagues include England's
 * Premier League, Spain's La Liga, Germany's Bundesliga, France's Ligue
 * Un, and Italy's Serie A.
 *
 * Fields descriptions from csv file:
 *
 * index: unique index number assigned to player (not official identification number)
 * name: player's common name
 * age: player age in years
 * height: player height in meters
 * nationality: player's nationality
 * price: current price in millions of euros
 * max_price: highest price the player has ever had in millions of euros
 * position: player's position on the field
 * shirt_nr: player's shirt number
 * foot: player's preferred foot (left or right)
 * club: player's current club
 * contract_expires: date when player's contract with current club expires
 * joined_club: date when player joined the current club
 * player_agent: agent representing the player
 * outfitter: brand or company that provides the player sports gear
 * league: league in which the player currently plays
 */

class Players {

private:
    string name, nationality, position, foot, club,
            contract_expires, joined_club, player_agent, outfitter, league;
    int index, age, shirt_nr;
    double height, price, max_price;

public:
    //Constructors

    //Default
    Players() {
        index = -1;
        name = "NONE";
        age = -1;
        height = -1.0;
        nationality = "NONE";
        price = -1.0;
        max_price = -1.0;
        position = "NONE";
        shirt_nr = -1;
        foot = "NONE";
        club = "NONE";
        contract_expires = "NONE";
        joined_club = "NONE";
        player_agent = "NONE";
        outfitter = "NONE";
        league = "NONE";
    }

    //Alternate
    Players(int index,
            string name,
            int age,
            double height,
            string nationality,
            double price,
            double max_price,
            string position,
            int shirt_nr,
            string foot,
            string club,
            string contract_expires,
            string joined_club,
            string player_agent,
            string outfitter,
            string league) {
        this->index = index;
        this->name = name;
        this->age = age;
        this->height = height;
        this->nationality = nationality;
        this->price = price;
        this->max_price = max_price;
        this->position = position;
        this->shirt_nr = shirt_nr;
        this->foot = foot;
        this->club = club;
        this->contract_expires = contract_expires;
        this->joined_club = joined_club;
        this->player_agent = player_agent;
        this->outfitter = outfitter;
        this->league = league;
    }

    //Getters
    int getIndex() const {
        return index;
    }

    int getAge() const {
        return age;
    }

    int getShirtNr() const {
        return shirt_nr;
    }

    double getHeight() const {
        return height;
    }

    double getPrice() const {
        return price;
    }

    double getMaxPrice() const {
        return max_price;
    }

    string getName() const {
        return name;
    }

    string getNationality() const {
        return nationality;
    }

    string getPosition() const {
        return position;
    }

    string getFoot() const {
        return foot;
    }

    string getClub() const {
        return club;
    }

    string getContractExpires() const {
        return contract_expires;
    }

    string getJoinedClub() const {
        return joined_club;
    }

    string getPlayerAgent() const {
        return player_agent;
    }

    string getOutfitter() const {
        return outfitter;
    }

    string getLeague() const {
        return league;
    }

    //Setters
    void setIndex(int index) {
        this->index = index;
    }

    void setAge(int age) {
        this->age = age;
    }

    void setShirtNr(int shirt_nr) {
        this->shirt_nr = shirt_nr;
    }

    void setHeight(double height) {
        this->height = height;
    }

    void setPrice(double price) {
        this->price = price;
    }

    void setMaxPrice(double max_price) {
        this->max_price = max_price;
    }

    void setName(string name) {
        this->name = name;
    }

    void setNationality(string nationality) {
        this->nationality = nationality;
    }

    void setPosition(string position) {
        this->position = position;
    }

    void setFoot(string foot) {
        this->foot = foot;
    }

    void setClub(string club) {
        this->club = club;
    }

    void setContractExpires(string contract_expires) {
        this->contract_expires = contract_expires;
    }

    void setJoinedClub(string joined_club) {
        this->joined_club = joined_club;
    }

    void setPlayerAgent(string player_agent) {
        this->player_agent = player_agent;
    }

    void setOutfitter(string outfitter) {
        this->outfitter = outfitter;
    }

    void setLeague(string league) {
        this->league = league;
    }

    // Overloaded << operator
    // Prints only five player characteristics: index, name, age, nationality,
    // price, club, and league
    friend ostream& operator << (ostream& output, const Players& player) {
        output << left << setw(5) << player.index;
        output << left << setw(25) << player.name;
        output << left << setw(3) << player.age;
        output << left << setw(5) << player.height;
        output << left << setw(15) << player.nationality;
        output << left << setw(6) << player.price;
        output << left << setw(6) << player.max_price;
        output << left << setw(25) << player.position;
        output << left << setw(4) << player.shirt_nr;
        output << left << setw(6) << player.foot;
        output << left << setw(20) << player.club;
        output << left << setw(13) << player.contract_expires;
        output << left << setw(13) << player.joined_club;
        output << left << setw(13) << player.player_agent;
        output << left << setw(10) << player.outfitter;
        output << setw(10) << player.league;
        return output;
    }
    // Overload < operator
    friend bool operator < (const Players& lhs, const Players& rhs) {
        return lhs.index < rhs.index;
    }
    // Overload > operator
    friend bool operator > (const Players& lhs, const Players& rhs) {
        return lhs.index > rhs.index;
    }
    // Overload <= operator
    friend bool operator <= (const Players& lhs, const Players& rhs) {
        return lhs.index <= rhs.index;
    }
    // Overload >= operator
    friend bool operator >= (const Players& lhs, const Players& rhs) {
        return lhs.index >= rhs.index;
    }
    // Overload == operator
    friend bool operator == (const Players& lhs, const Players& rhs) {
        return lhs.index == rhs.index;
    }
};
bool getFileData(vector<Players>& playerlist) {
    ifstream fileIn;
    fileIn.open("../top5_leagues_player.csv");

    if (fileIn) {
        string header;
        getline(fileIn, header);

        string name = "NONE", nationality = "NONE", position = "NONE", foot = "NONE",
            club = "NONE", contract_expires = "NONE", joined_club = "NONE",
            player_agent = "NONE", outfitter = "NONE", league = "NONE",
            newline;
        int index = -1, age = -1, shirt_nr = -1;
        double height = -1.0, price = -1.0, max_price = -1.0;
        char comma;

        while (fileIn.peek() != EOF) {
            //Get index
            fileIn >> index;
            fileIn >> comma;

            //Get name
            getline(fileIn, name, ',');

            //Get age
            fileIn >> age;
            fileIn >> comma;

            //Get height
            if (fileIn.peek() != ',') {
                fileIn >> height;
            }
            fileIn >> comma;

            //Get nationality (second nationality omitted)
            if (fileIn.peek() == '\"') { //nationality contains comma
                string quotation;
                getline(fileIn, quotation, '\"');
                getline(fileIn, nationality, '\"');
                fileIn >> comma;
            }
            else {
                getline(fileIn, nationality, ',');
                if (nationality.find(' ')) {
                    int space_ind = nationality.find(' ');
                    nationality = nationality.substr(0, space_ind);
                }
            }

            //Get price
            if (fileIn.peek() != ',') {
                fileIn >> price;
            }
            fileIn >> comma;

            //Get max price
            if (fileIn.peek() != ',') {
                fileIn >> max_price;
            }
            fileIn >> comma;

            //Get position
            getline(fileIn, position, ',');

            //Get shirt number
            fileIn >> shirt_nr;
            fileIn >> comma;

            //Get foot
            getline(fileIn, foot, ',');

            //Get club
            getline(fileIn, club, ',');

            //Get contract expiration date
            getline(fileIn, contract_expires, ',');

            //Get joined club date
            getline(fileIn, joined_club, ',');

            //Get player agent
            getline(fileIn, player_agent, ',');
            if (player_agent.empty()) {
                player_agent = "NONE";
                fileIn.clear();
            }

            //Get outfitter
            getline(fileIn, outfitter, ',');
            if (outfitter.empty()) {
                outfitter = "NONE";
                fileIn.clear();
            }

            //Get league
            getline(fileIn, league);



            playerlist.push_back(Players(index, name, age, height, nationality,
                                         price, max_price, position, shirt_nr,
                                         foot, club, contract_expires, joined_club,
                                         player_agent, outfitter, league));


        }

    } else {
        cout << "Could not open file" << endl;
        return false;
    }
    fileIn.close();
    return true;
}

#endif //PROJECT1_PLAYERS_H
