# Evan Stowell - Soccer Club Simulator

## Program Summary
My program is a soccer club simulator where the user manages their
own soccer club. The user plays games with their team against randomly
generated opponents and can strengthen the team with every win or weaken 
the team with every loss. As they continue to reinforce the squad, the 
club status improves all the way up to "Legend" status. 

Link to simulator webpage: pending...

## Languages
- C++
- HTML
- PHP
- CSS

## Installations Needed
Simulator can be played from link above.
Otherwise, download the simulator folder and run club.php through a local server environment of your choosing.

## Extended Program Description
The simulator is played from the simulator webpage (club.php). Choose one of the options from the
menu and submit so the action can be processed (through action.php). The output of your action will appear below the
menu. 

## Known bugs
Session folder cannot be deleted when attempting to start a new session. I tried
many different strategies to solve this problem, but none worked. It might be a matter
of a lack of permissions or not using the right commands. If you wish to restart, I suggest
manually deleting team_save.txt so a new txt file can replace it, thus you will have a new team.

## Citations
Team.cpp, line 170 adapted from:
https://stackoverflow.com/questions/10910615/c-randomly-assigning-an-enumerated-type-to-a-variable
Retrieved on 2/2/2025

move() in Team.cpp
https://stackoverflow.com/questions/3413470/what-is-stdmove-and-when-should-it-be-used
Retrieved on 3/23/2025
