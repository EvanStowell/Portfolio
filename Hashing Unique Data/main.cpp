#include "OpenAddressing.h"
#include "SeparateChaining.h"
#include "Players.h"
#include <fstream>
#include <iostream>
using namespace std;
using std::vector, std::cout, std::endl, std::string;

/* Examples of getKey functions
 *
 * If your unique attribute is a string:
 * string getLecturerName(Lecturer lec) {
 *     return lec.getName();
 * }
 *
 * If your unique attribute is not a string:
 * string getEmployeeID(Employee e) {
 *     return to_string(e.getID());
 * }
 *
 * If you only have one unique field in your class,
 * concatenate it with another field for your second key:
 * string getLecturerClassName(Lecturer lec) {
 *     return to_string(lec.getClass1()) + lec.getName();
 * }
 * */

//First getKey function (concatenates Index with Name)
string getPlayerIndexName(Players player) {
    return to_string(player.getIndex()) + player.getName();
}

//Second getKey function (concatenates (Index with Nationality)
string getPlayerIndexNationality(Players player) {
    return to_string(player.getIndex()) + player.getNationality();
}

int main() {
    vector<Players> playerlist;
    if (!getFileData(playerlist)) {
        cout << "Error creating Player vector" << endl;
    }
    cout << "playerlist vector size: " << playerlist.size() << endl;

    //Initialize hash tables
    SeparateChaining<Players> sep1(3000);
    SeparateChaining<Players> sep2(5000);
    SeparateChaining<Players> sep3(7000);
    SeparateChaining<Players> sep4(9000);
    SeparateChaining<Players> sep5(11000);
    SeparateChaining<Players> sep6(3000);
    SeparateChaining<Players> sep7(5000);
    SeparateChaining<Players> sep8(7000);
    SeparateChaining<Players> sep9(9000);
    SeparateChaining<Players> sep10(11000);

    QuadraticProbing<Players> quad1(3000);
    QuadraticProbing<Players> quad2(5000);
    QuadraticProbing<Players> quad3(7000);
    QuadraticProbing<Players> quad4(9000);
    QuadraticProbing<Players> quad5(11000);
    QuadraticProbing<Players> quad6(3000);
    QuadraticProbing<Players> quad7(5000);
    QuadraticProbing<Players> quad8(7000);
    QuadraticProbing<Players> quad9(9000);
    QuadraticProbing<Players> quad10(11000);

    int sep1_collisions = 0, sep2_collisions = 0, sep3_collisions = 0, sep4_collisions = 0, sep5_collisions = 0,
        sep6_collisions = 0, sep7_collisions = 0, sep8_collisions = 0, sep9_collisions = 0, sep10_collisions = 0,
        quad1_collisions = 0, quad2_collisions = 0, quad3_collisions = 0, quad4_collisions = 0, quad5_collisions = 0,
        quad6_collisions = 0, quad7_collisions = 0, quad8_collisions = 0, quad9_collisions = 0, quad10_collisions = 0; //Counts total number of collisions for every object added
    ofstream outFile;

    //Fill tables and report collisions
    outFile.open("../collision_output.csv");
    outFile << "sep1, sep2, sep3, sep4, sep5, sep6, sep7, sep8, sep9, sep10, "
               "quad1, quad2, quad3, quad4, quad5, quad6, quad7, quad8, quad9, quad10" << endl;
    for (Players p : playerlist) {
        sep1.insert(getPlayerIndexName(p), p, sep1_collisions);
        outFile << sep1_collisions << ", ";
        sep2.insert(getPlayerIndexName(p), p, sep2_collisions);
        outFile << sep2_collisions << ", ";
        sep3.insert(getPlayerIndexName(p), p, sep3_collisions);
        outFile << sep3_collisions << ", ";
        sep4.insert(getPlayerIndexName(p), p, sep4_collisions);
        outFile << sep4_collisions << ", ";
        sep5.insert(getPlayerIndexName(p), p, sep5_collisions);
        outFile << sep5_collisions << ", ";
        sep6.insert(getPlayerIndexNationality(p), p, sep6_collisions);
        outFile << sep6_collisions << ", ";
        sep7.insert(getPlayerIndexNationality(p), p, sep7_collisions);
        outFile << sep7_collisions << ", ";
        sep8.insert(getPlayerIndexNationality(p), p, sep8_collisions);
        outFile << sep8_collisions << ", ";
        sep9.insert(getPlayerIndexNationality(p), p, sep9_collisions);
        outFile << sep9_collisions << ", ";
        sep10.insert(getPlayerIndexNationality(p), p, sep10_collisions);
        outFile << sep10_collisions << ", ";
        quad1.insert(getPlayerIndexName(p), p, quad1_collisions);
        outFile << quad1_collisions << ", ";
        quad2.insert(getPlayerIndexName(p), p, quad2_collisions);
        outFile << quad2_collisions << ", ";
        quad3.insert(getPlayerIndexName(p), p, quad3_collisions);
        outFile << quad3_collisions << ", ";
        quad4.insert(getPlayerIndexName(p), p, quad4_collisions);
        outFile << quad4_collisions << ", ";
        quad5.insert(getPlayerIndexName(p), p, quad5_collisions);
        outFile << quad5_collisions << ", ";
        quad6.insert(getPlayerIndexNationality(p), p, quad6_collisions);
        outFile << quad6_collisions << ", ";
        quad7.insert(getPlayerIndexNationality(p), p, quad7_collisions);
        outFile << quad7_collisions << ", ";
        quad8.insert(getPlayerIndexNationality(p), p, quad8_collisions);
        outFile << quad8_collisions << ", ";
        quad9.insert(getPlayerIndexNationality(p), p, quad9_collisions);
        outFile << quad9_collisions << ", ";
        quad10.insert(getPlayerIndexNationality(p), p, quad10_collisions);
        outFile << quad10_collisions << endl;
    }
    outFile.close();

    //Report Quadratic Probing table sizes
    cout << "Quadratic Probing table sizes:" << endl;
    cout << "getKey1(n=3000): " << quad1.getTableSize() << endl;
    cout << "getKey1(n=5000): " << quad2.getTableSize() << endl;
    cout << "getKey1(n=7000): " << quad3.getTableSize() << endl;
    cout << "getKey1(n=9000): " << quad4.getTableSize() << endl;
    cout << "getKey1(n=11000): " << quad5.getTableSize() << endl;
    cout << "getKey2(n=3000): " << quad6.getTableSize() << endl;
    cout << "getKey2(n=5000): " << quad7.getTableSize() << endl;
    cout << "getKey2(n=7000): " << quad8.getTableSize() << endl;
    cout << "getKey2(n=9000): " << quad9.getTableSize() << endl;
    cout << "getKey2(n=11000): " << quad10.getTableSize() << endl;
    return 0;
}
