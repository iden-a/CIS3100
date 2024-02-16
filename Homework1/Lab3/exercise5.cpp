#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
/*
A treasure is hidden someplace – the treasures coordinates are (x1, y1)! The coordinates (x1,y1)
are determined randomly, using the code that is listed at the end of this exercise. The purpose
of the game is for the Explorer to find the Treasure!
The explorer is allowed to go North, South, West or East. The Explorer is first positioned at
location (15,15). If the explorer goes North, only the y coordinate is increased by 1. Similarly, if
the explorer goes South, the y coordinate is decreased by 1. In the same fashion the x
coordinate is increased or decreased by 1 depending if the explorer goes East or West,
respectively.
Each time the Explorer ‘moves’, the distance between the Explorer and the treasure is
computed. The formula for the distance between (x,y) and (x1,y1) is distance =
sqrt(static_cast<double>((x-x1)*(x-x1)+(y-y1)*(y-y1)));
When the Explorer’s position is the same as the Treasure’s position, the Explorer wins the
Treasure!


1. Ask the user to Please enter direction (n,s,e,w), or x to exit:
2. Update the Explorer’s coordinates.
3. Calculate and display the distance from the Explorer to the Treasure (this information
will clue the Explorer to either keep going in the same direction or switch directions).
4. At the end of each loop display the Explorer’s coordinates.
5. Make sure that you print out how many steps it took to reach the treasure.
6. Use the starter code below.

*/

int main()
{

    int x = 15, y = 15; // Explorer’s coordinates
    int x1, y1;         // Treasure’s coordinates
    char direction;
    float distance;
    bool treasure = false;

    srand(time(0));       // secretly seed the rand function !
    x1 = rand() % 30 + 1; // set X1 to random between 1 and 30
    y1 = rand() % 30 + 1; // set y1 to random between 1and 30
    
    //write loop to find the treasure

    return 0;
}