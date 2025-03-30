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
# Module 3 concepts
- Languages: Starts in PHP/HTML file styled with CSS, then moves to another PHP
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
# Future expansion
I would like to improve the look of club.php, maybe add some images and a better layout. Second,
I would also integrate Python's matplotlib to print a line graph that displays how the user's
team has developed over time through the increases and decreases in team overall when they end the session.
# Citations
Team.cpp, line 170 adapted from:
https://stackoverflow.com/questions/10910615/c-randomly-assigning-an-enumerated-type-to-a-variable
Retrieved on 2/2/2025

move() in Team.cpp
https://stackoverflow.com/questions/3413470/what-is-stdmove-and-when-should-it-be-used
Retrieved on 3/23/2025

# The Grade I Think I Deserve
Main program complexity and usability - 38 pts
My program uses multiple languages that we have seen in class, and they are
all connected in a way that makes sense. User input validation remains strong,
and the project is sufficiently complex with its many languages and features.
Some points may be deducted due to the bug with session.

Use of multiple languages - 20 pts
The program uses HTML, PHP, C++, and CSS, and the amount used for each language
contributes to making the simulator more user-friendly. 

Choice of languages - 20 pts
As explained in the "Explanation for each language" section, the languages incorporated
are used for their strengths to improve this simulator.

Command line arguments - 20 pts
action.php used the command line a lot to create the session folder, compile the C++ program,
and execute the simulator. Plus, PHP creates a bridge between the C++ output and the HTML webpage
display.

Style and documentation - 0 pts
Comments and documentization are frequent, explaining each step of a function or script.

Video - 0 pts
Demonstrates all capabilities of simulator

Lifespan of project: -5pts
I think the first commit to the project was less than 7 days ago, which is why there would
be points deducted here.