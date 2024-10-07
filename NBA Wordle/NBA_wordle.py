# Authors: Andy English, Evan Stowell
'''

NBA Wordle

'''
import random
from matplotlib import pyplot as plt
from colorama import Back, Style

from players import players

KEYS = ["name", "conf", "team_abbr", "pos", "ht", "age", "num"]

def choose_player(): # Computer randomly selects player to be the mystery player
    return random.choice(list(players.keys())) # returns player id

def real_player(guess): # Returns True if player's guess is a real NBA player
    for plyr in players.keys():
        plyr_name = players[plyr]["name"]
        if guess.lower() == plyr_name.lower():
            return True
    return False # Player not found in dictionary

def name_to_id(player_name): # Converts name of player to their id in the players dictionary
    for p in players:
        p_dict = players[p]
        if player_name in list(p_dict.values()):
            return p

def play_again(): # Validates user input on whether they want to play again:
    play_again = input("Do you want to play again? (y/n) ")
    while True:
        if play_again == "y":
            print("\n") # Creates separation between next game and previous game
            return True
        elif play_again == "n":
            print("\n") # Creates separation between menu and previous game
            return False
        else:
            play_again = input("Invalid input. Do you want to play again? (y/n) ")
    
def guess_info(player): # Returns dictionary of important info about player's guess
    player_dict = {}
    for x in KEYS:
        player_dict[x] = players[player][x]
    return player_dict

def mystery_info(mystery): # Returns dictionary of important info about mystery player
    mystery_dict = {}
    for x in KEYS:
        mystery_dict[x] = players[mystery][x]
    return mystery_dict

def guess_compare(player_info, mystery_info): # Compares player's guess to mystery player and returns list of comparison results
    results = []
    # results[0] = name; True if same, False if incorrect
    # results[1] = conf; True if same, False if incorrect
    # results[2] = team (abbreviated); True if same, False if incorrect
    # results[3] = pos; True if same, "close" if one of the positions is correct, False if incorrect
    # results[4] = ht; True if same, ("warm", "higher") if off by more than -2 inches, ("warm", "higher") if off by less than 2 inches,
    #              ("cold", "higher") if off by less than -2 inches, ("cold", "lower") if off by more than 2 inches
    # results[5] = age; True if same, ("warm", "higher") if off by more than -2 years, ("warm", "higher") if off by less than 2 years,
    #              ("cold", "higher") if off by less than -2 years, ("cold", "lower") if off by more than 2 years
    # results[6] = num; True if same, ("warm", "higher") if off by more than -2, ("warm", "higher") if off by less than 2,
    #              ("cold", "higher") if off by less than -2, ("cold", "lower") if off by more than 2
    
    # name:
    if player_info["name"] == mystery_info["name"]:
        results.append(True)
    else:
        results.append(False)
    
    # conference:
    if player_info["conf"] == mystery_info["conf"]:
        results.append(True)
    else:
        results.append(False)
        
    # team (abbreviated)
    if player_info["team_abbr"] == mystery_info["team_abbr"]:
        results.append(True)
    else:
        results.append(False)
        
    # position:
    plyr_pos = player_info["pos"].split("-")
    myst_pos = mystery_info["pos"].split("-")
    sim = [] # List of similar positions between plyr_pos and myst_pos
    for p in plyr_pos:
        if p in myst_pos:
            sim.append(p)
    if plyr_pos == myst_pos:
        results.append(True)
    elif sim != []: # Will have an element if a similarity exists
        results.append("close")
    else: # No similarities exist
        results.append(False)
        
    # height:
    p_ht = player_info["ht"].split("-")
    p_ht = int(p_ht[0]) * 12 + int(p_ht[1])
    m_ht = mystery_info["ht"].split("-")
    m_ht = int(m_ht[0]) * 12 + int(m_ht[1])
    if p_ht == m_ht:
        results.append(True)
    elif p_ht - m_ht < -2:
        results.append(("cold", "higher"))
    elif -2 <= p_ht - m_ht < 0:
        results.append(("warm", "higher"))
    elif 0 < p_ht - m_ht <= 2:
        results.append (("warm", "lower"))
    elif p_ht - m_ht > 2:
        results.append(("cold", "lower"))
    
    # age
    p_age = int(player_info["age"])
    m_age = int(mystery_info["age"])
    if p_age == m_age:
        results.append(True)
    elif p_age - m_age < -2:
        results.append(("cold", "higher"))
    elif -2 <= p_age - m_age < 0:
        results.append(("warm", "higher"))
    elif 0 < p_age - m_age <= 2:
        results.append (("warm", "lower"))
    elif p_age - m_age > 2:
        results.append(("cold", "lower"))
    
    # jersey number
    p_num = int(player_info["num"])
    m_num = int(mystery_info["num"])
    if p_num == m_num:
        results.append(True)
    elif p_num - m_num < -2:
        results.append(("cold", "higher"))
    elif -2 <= p_num - m_num < 0:
        results.append(("warm", "higher"))
    elif 0 < p_num - m_num <= 2:
        results.append (("warm", "lower"))
    elif p_num - m_num > 2:
        results.append(("cold", "lower"))
    return results
    
def print_compare(player_info, results): # Takes guess info and comparison results from guess_compare(), prints visual of results
    for i in range(7):
        output = ""
        if results[i] == True: # Correct in category
            print(f"{KEYS[i].capitalize()}: " + Back.GREEN + f"{player_info[KEYS[i]]}" + Style.RESET_ALL)
        elif results[i] == "close": # One of mystery players' positions is correct
            print(f"{KEYS[i].capitalize()}: " + Back.YELLOW + f"{player_info[KEYS[i]]}" + Style.RESET_ALL)
        elif results[i] == ("warm", "higher"): # Slightly under correct number
            print(f"{KEYS[i].capitalize()}: " + Back.YELLOW + f"{player_info[KEYS[i]]}" + "^" + Style.RESET_ALL)
        elif results[i] == ("warm", "colder"): # Slightly over correct number
            print(f"{KEYS[i].capitalize()}: " + Back.YELLOW + f"{player_info[KEYS[i]]}" + "v" + Style.RESET_ALL)
        elif results[i] == ("cold", "higher"): # Significantly under correct number
            print(f"{KEYS[i].capitalize()}: " +  f"{player_info[KEYS[i]]}" + "^")
        elif results[i] == ("cold", "lower"): # Significantly over correct number
            print(f"{KEYS[i].capitalize()}: " + f"{player_info[KEYS[i]]}" + "v")
        elif results[i] == False: # Incorrect in category
            print(f"{KEYS[i].capitalize()}: " + f"{player_info[KEYS[i]]}")

def get_hist(dist): # Creates histogram of player's guesses before discovering the player
    hist = plt.hist(dist, bins = 8, range = (0.5, 8.5), color = "g")
    plt.xlabel("Number of Guesses")
    plt.ylabel("Count")
    plt.title("Session's Guess Distribution")
    plt.show()

def play_game(): # Play one round, returns number of guesses needed to find mystery player
    mystery = choose_player()
    myst_info = mystery_info(mystery)
    guess_count = 0
    
    print("\nA mystery NBA player has been chosen! You have eight guesses to find the mystery player.")
    print("Use the information shown from each guess to close in on the mystery player.")
    print("Note: Make sure to spell names correctly with correct capitalization")
    
    while guess_count != 8: # 8 guess limit
        guess = input(f"Enter a player({guess_count + 1}/8): ")
        valid_player = False # Assumes guess is invalid player until proven valid
        while not valid_player: 
            if not real_player(guess): # Validates user's guess
                guess = input(f"Not a valid player. Enter a player({guess_count + 1}/8): ")
            else:
                valid_player = True # Guess player is approved
        guess_count += 1 # Guess is counted
        guess = name_to_id(guess) # Converts guess string (name) to player's respective id
        plyr_info = guess_info(guess)
        comparison = guess_compare(plyr_info, myst_info)
        print_compare(plyr_info, comparison)
        if plyr_info["name"] == myst_info["name"]: # Successfully guessed mystery player
            print(f"Congrats! You guessed {myst_info['name']} correctly in {guess_count} tries!")
            return guess_count
    if guess_count == 8: # Failed to guess mystery player
        print(f"Out of guesses! The player was {myst_info['name']}")

def main(): # Starts game
    guess_dist = [] # List where guess_counts from games will be
    print("Welcome to the NBA Wordle!\n" + 'Type "play" to play the game\n' +
          'Type "stats" to see a histogram of your games\n' +
          'Type "exit" to leave the NBA Wordle\n')
    while True:
        command = input("Enter command (play/stats/exit): ")
        if command == "play":
            in_game = True
            while in_game:
                guess_dist.append(play_game())
                if play_again() == False: # If user does not want to play again
                    in_game = False
        elif command == "stats":
            try:
                get_hist(guess_dist)
            except TypeError:
                print("No data available")
        elif command == "exit":
            return
        else:
            command = input("Invalid input. Enter another command: ")

if __name__ == "__main__":
    main()