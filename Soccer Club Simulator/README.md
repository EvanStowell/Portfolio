# Name
Evan Stowell
# Installations Needed
None
# Program Description
My program is a soccer club simulator where the user manages their
own soccer club. The user plays games with their team against randomly
generated opponents and can strengthen the team with every win. As they
continue to reinforce the squad, the club status improves all the way up
to "Legend" status.

Webpage for game found here: 
# Module 3 concepts
- Languages: C++, HTML, PHP, CSS
file for processing where it executes the C++ main program
# Explanation for each language
- C++: Contains the program for the simulator. Best with C++ because it is object-oriented.
- HTML: Displays structure for simulator's webpage. Makes user input easier with clickable
icons instead of text-based inputs
- PHP: Processes user inputs, executes C++ program, and displays program output. Great for file
handling and data permanence via session variables.
- CSS: Styling for simulator webpage. Makes navigating the simulator easier for the user.
# How the languages connect
- club.php (HTML/PHP) uses PHP starting at line 32 to print simulator output.
- action.php (PHP) compiles the C++ program starting on line 64 and executes it starting on line 75.
- club.php links a stylesheet style.css (CSS) on line 10 for improved aesthetic
# Known bugs
Session folder cannot be deleted when attempting to start a new session. I tried
many different strategies to solve this problem, but none worked. It might be a matter
of a lack of permissions or not using the right commands. If you wish to restart, I suggest
manually deleting team_save.txt so a new txt file can replace it, thus you will have a new team.
# Citations
Team.cpp, line 170 adapted from:
https://stackoverflow.com/questions/10910615/c-randomly-assigning-an-enumerated-type-to-a-variable
Retrieved on 2/2/2025

move() in Team.cpp
https://stackoverflow.com/questions/3413470/what-is-stdmove-and-when-should-it-be-used
Retrieved on 3/23/2025
