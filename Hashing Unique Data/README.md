# Data Description  

The data is from registered professional soccer players in the top 5 soccer leagues in the world. There are 2612 entries with  
16 characteristics for each entry including name, age, team, position, price, etc. The name field may use  
special characters, so there may be unusual characters in the names since they are not correctly printed.  
The original dataset is from Kaggle: https://www.kaggle.com/datasets/oles04/top-leagues-player  

Field Descriptions:  
index: unique index number in dataset assigned to player (not official identification number)  

name: player's common name  

age: player age in years  

height: player height in meters  

nationality: player's nationality  

price: current price in millions of euros  

max_price: highest price the player has ever had in millions of euros  

position: player's position on the field  

shirt_nr: player's shirt number  

foot: player's preferred foot (left or right)  

club: player's current club  

contract_expires: date when player's contract with current club expires  

joined_club: date when player joined the current club  

player_agent: agent representing the player  

outfitter: brand or company that provides the player sports gear  

league: league in which the player currently plays  

# Project Description  

Created a total of 20 hash tables, half using seperate chaining and the other  
half using open addressing, specifically quadratic probing. Within the two  
groups, the hash tables vary in size from 3000 to 11000.  
In each group, five tables are determined with the first getKey function,  
and the other five with the second getKey function.  
  
Filled in the tables with Players objects from the dataset.  
  
Analyzed the collision counts for each table, created visualizations of  
the collision counts, and drew conclusions for the optimal getKey function  
and collision detection method.

