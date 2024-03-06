#include<iostream>
using namespace std;
/*
Write a “Choose Your Own Adventure” program. Write a cohesive story that allows the user to
make decisions as to what to do next, and display the story accordingly. For example, you might
ask the user if he/she wants to take the A, F, or B train. Depending on the answer, ask another
question. (Try to download this exe file for a sample!)
*/

int main() {


    // declaring the power variable.
    string power;

    cout << "Choose Your Own Adventure - Superhero Edition" << endl;
    cout << "**********************************************" << endl;

    // asking the user what superpower they want and storing their answer in the power variable.
    cout << "What is your SuperPower? Options (Strength, Invisibility, MindReading, Speed)" << endl;
    cin >> power;



    // if they chose strength as their power, they will be prompted with a scenario for strength
    if (power == "strength" || power == "Strength" || power == "STRENGTH") {
        cout << "You chose " << power << "!" << endl;
        cout << "You need to use your Super " << power << " to help the old lady that is stuck under the Empire State Building!" << endl;

        char route;

        cout << "What route will you take to save the old lady? (A or B): ";
        cin >> route;

        if (route == 'A' || route == 'a') {
            cout << "You were attacked by a pack of wolves on your way to the Empire State Building!" << endl;
        } 
        else if (route == 'B' || route == 'b') {
            cout << "You made it on time to save the old lady, congratulations!";
        }
        else {
            cout << "You did not pick route A or B, the old lady died!";
        }
    } // Closing curly brace added here



    // if they chose invisibility as their power, they will be prompted with a scenario for strength
    else if (power == "invisibility" || power == "Invisibility" || power == "INVISIBILITY") {
        cout << "You chose " << power << "!" << endl;
        cout << "You need to use your " << power << " power to go into MoJo JoJo's Evil Lab and spy on his evil plans to destroy NYC!" << endl;

        // ask them the color of their invisibility clock
        string color;
        cout << "What is the color of your cloak? (Blue or Red)" << endl;
        cin >> color;


        // different output depending on what the user picks
        if (color == "blue" || color == "BLUE" || color == "Blue") {
            cout << "You were able to use your invisibility to sneak into the lair and save the princess!";
        }

        else if (color == "red" || color == "Red" || color == "RED") {
            cout << "You invisibility powers ran out when you got into the lab, MoJo JoJo caught you!" << endl;
        }

        else {
            cout << "The invisibility did not work, you did not choose a cloak option!" << endl;
        }

    }

    // if they chose mindreading as their power, they will be prompted with a scenario for strength
    else if (power == "mindreading" || power == "Mindreading" || power == "MINDREADING") {
        cout << "You chose " << power << "!" << endl;
        cout << "You need to use your " << power << " abilities to read the mind of the bank robbers to figure out where their next heist will be!" << endl;

        // ask them who's mind they will be reading 
        char person;
        cout << "You have to decide who the robber is, who's mind are you reading (A or B)" << endl;
        cin >> person;

        // different output depending on what the user picks
        if (person == 'A' || person == 'a') {
            cout << "You were able to successfully read the mind of Person A and stop their crew from robbing the bank!";
        }

        else if (person == 'B' || person == 'b') {
            cout << "You read the mind of the ring leader! You have uncovered the get away location!";
        }

        else {
            cout << "You did not choose the right person! The robbers got away!";
        }
   
    }

    // if they chose time travel as their power, they will be prompted with a scenario for strength
    else if (power == "speed" || power == "Speed" || power == "SPEED"){
        cout << "You chose " << power << "!" << endl;
        cout << "You need to use your " << power << " abilities to travel back in time to stop the killer from escaping! " << endl;

        // ask them what year they will be time traveling to 
        int year;
        cout << "What year will you be time traveling back to?" << endl;
        cout << "Options: 1849 | 1879 | 1969: ";
        cin >> year;


         // different output depending on what the user picks
        if (year == 1849) {
            cout << "You went back in time to see the first telephone invention!";
        }

        else if ( year == 1879) {
            cout << "You went back in time to see the first light bulb and join the invention process!";
        }

        else if ( year == 1969) {
            cout << "You joined the first man on his trip to the moon!";
        }

        else {
            cout << "You did not select an option, you can't travel back in time!";
        }

    }
    // if they did not choose an option, they will be given this message!
    else {
        cout << "You did not choose a valid superpower!";
    }

    cout << endl << endl;

    return 0;
}
