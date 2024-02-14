#include <iostream>
using namespace std;

/* Nouns are people, places, or things. Verbs are action words. Adjectives are descriptive words.
Use strings and user input to create a Madlib program. Ask the user to enter nouns, verbs, adjectives,
etc., and generate a cohesive story that you will write as output
*/

int main() {

    // declaring the variables needed for the story
    string noun, verb, adj;
    int number;

    // receiving user input for number, noun, adj, and verb
    cout << "Number: " << endl;
    cin >> number;

    cout << "Noun: " << endl;
    cin >> noun;

    cout << "Verb, ending in 'ing': " << endl;
    cin >> verb;

    cout << "Adjective: " << endl;
    cin >> adj;

    // incorporating the user's inputs into the story and displaying it on their screen
    cout << "The Ghost Busters found " << number << " ghouls living in the attic!" << endl;
    cout << verb << " as fast as they could, they ran into more in the basement." << endl;
    cout << "They ran for their lives, " << adj << ", hoping it would all end soon." << endl;
    cout << "Finding " << noun <<  " turned out to be a lot more complicated than anticipated!" << endl;
    

    return 0;
}