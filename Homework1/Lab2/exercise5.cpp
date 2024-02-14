#include <iostream>
using namespace std;

int main()
{
    // declaring the response variable
    string response;

    // printing out the game board
    cout << "******************************************************" << endl;
    cout << "                       Welcome!                       " << endl;
    cout << endl;
    cout << "        What Game Would You Like To Play?             " << endl;
    cout << "1.      Choose Your Own Adventure? (A)                " << endl;
    cout << "2.      MadLib (B)                                    " << endl;
    cout << "******************************************************" << endl;
    // Asking the user for their Game Choice, user input is stored in the response variable.
    cout << "Game Choice: (A or B) ";
    cin >> response;
    cout << endl;

    // if the user types in A as their game choice, they will be prompted with the Choose Your Own Adventure Game
    if (response == "A")
    {
        // declaring the power variable.
        string power;

        cout << "Choose Your Own Adventure - Superhero Edition" << endl;
        cout << "**********************************************" << endl;

        // asking the user what superpower they want and storing their answer in the power variable.
        cout << "What is your SuperPower? Options (Strength, Visibility, MindReading, Speed)" << endl;
        cin >> power;

        // if they chose strength as their power, they will be prompted with a scenario for strength
        if (power == "strength")
        {
            cout << "You chose " << power << "!" << endl;
            cout << " you need to use your Super " << power << " to help the old lady that is stuck under the Empire State Building!" << endl;

            string route;

            cout << "What route will you take to save the old lady? (A or B): ";
            cin >> route;

            if (route == "A")
                cout << "You were attacked by a pack of wolves on your way to the Empire State Building!" << endl;
            else if (route == "B")
                cout << "You made it on time to save the old lady, congratulations!";
            else
                cout << "You did not pick route A or B, the old lady died!";
        } 

        // if they chose invisibility as their power, they will be prompted with a scenario for strength
        else if (power == "invisibility")
        {
            cout << "You chose " << power << "!" << endl;
            cout << "You need to use your " << power << " power to go into MoJo JoJo's Evil Lab and spy on his evil plans to destroy NYC!" << endl;

            // ask them the color of their invisibility clock
            string color;
            cout << "What is the color of your cloak? (Blue or Red)" << endl;
            cin >> color;

            if (color == "blue")
                cout << "You were able to use your invisibility to sneak into the lair and save the princess!";
            else if (color == "red")
                cout << "You invisibility powers ran out when you got into the lab, MoJo JoJo caught you!" << endl;
            else
                cout << "The invisibility did not work, you did not choose a cloak option!" << endl;
        }

        // if they chose mindreading as their power, they will be prompted with a scenario for strength
        else if (power == "mindreading")
        {
            cout << "You chose " << power << "!" << endl;
            cout << " you need to use your " << power << " abilities to read the mind of the bank robbers to figure out where their next heist will be!" << endl;

            // ask them who's mind they will be reading
            string person;
            cout << "You have to decide who the robber is, who's mind are you reading (A or B)" << endl;
            cin >> person;

            if (person == "A")
                cout << "You were able to successfully read the mind of Person A and stop their crew from robbing the bank!";
            else if (person == "B")
                cout << "You read the mind of the ring leader! You have uncovered the get away location!";
            else
                cout << "You did not choose the right person! The robbers got away!";
        }

        // if they chose time travel as their power, they will be prompted with a scenario for strength
        else if (power == "speed")
        {
            cout << "You chose " << power << "!" << endl;
            cout << "You need to use your " << power << " abilities to travel back in time to stop the killer from escaping! " << endl;

            // ask them what year they will be time traveling to
            int year;
            cout << "What year will you be time traveling back to?" << endl;
            cout << "Options: 1849 | 1879 | 1969: ";
            cin >> year;

            if (year == 1849)
                cout << "You went back in time to see the first telephone invention!";

            else if (year == 1879)
                cout << "You went back in time to see the first light bulb and join the invention process!";
            else if (year == 1969)
                cout << "You joined the first man on his trip to the moon!";
            else
                cout << "You did not select an option, you can't travel back in time!";
        }
        else
            cout << "You did not choose a valid superpower!";
    }

    // if the user response is B, they will be prompted with the Madlib Game
    else if (response == "B")
    {
        string noun, verb, adj;
        int number;

        cout << "MadLib - GhostBusters Edition" << endl;
        cout << "**********************************************" << endl;

        cout << "Number: " << endl;
        cin >> number;

        cout << "Noun: " << endl;
        cin >> noun;

        cout << "Verb, ending in 'ing': " << endl;
        cin >> verb;

        cout << "Adjective: " << endl;
        cin >> adj;

        cout << "The Ghost Busters found " << number << " ghouls living in the attic!" << endl;
        cout << verb << " as fast as they could, they ran into more in the basement." << endl;
        cout << "They ran for their lives, " << adj << ", hoping it would all end soon." << endl;
        cout << "Finding " << noun << " turned out to be a lot more complicated than anticipated!" << endl;
    }

    // if the user does not select A or B, they will receive this error letting them know that they did not select an option.
    else
        cout << "You did not select one of the options! :(" << endl;

    return 0;
}