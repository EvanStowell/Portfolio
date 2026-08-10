# Using ML to Predict NBA 2025 Season Award Winners

## Motivation
Major NBA individual awards are highlight the excellence and domination exhibited by the top players in the league. However, what defines excellence in any given category is subjective as some statistics are valued more highly than others. My group investigated the statistics' predictive power for whether a player wins an award and used ML models to predict the winners of each award for the 2025 NBA season.

## Data
Our data is a comprehensive dataset of NBA player, game, and season statistics from 1947-present. The dataset originates from Kaggle, which was scraped from
basketball-reference.com. Advanced statistics were not calculated until 1980, so we filtered between the years 1980 and 2024.

Link: https://www.kaggle.com/datasets/sumitrodatta/nba-aba-baa-stats?select=Advanced.csv

## Approach
In this analysis, we created prediction models for four major individual awards: Most Valuable Player (MVP), Defensive Player of the Year (DPOY), Rookie of the Year (ROTY), and All-NBA Team. Each category tested a blend of models such as Logistic Regression, Random Forests, and XGBoost to 1) determine whether approaching this question as a regression problem (voting points) or a classification problem (did or did not win award) would yield the most accurate predictions and 2) which specific ML model performed strongest. With the best performing models, we then inputted data from the ongoing 2025 NBA season to gather predictions for the season.

## Results
Across all award categories, the ML models performed moderately well with $R^2$ values of approximately 0.6. Unsurprisingly, the primary predictor for winning MVP, ROTY, and All-NBA proved to be points and the primary predictors for DPOY were rebounds, steals, and blocks. Furthermore, the models' predictions for the 2025 NBA season were plausible as the top five players predicted in various sportsbooks and the models were roughly similar. Award-specific results can be found in the report.

## How to Run
To run the script:
- Clone this repository
- Open the jupyter notebook
- Install sci-kit learn, pandas, matplotlib, and seaborn
- Run the notebook

Co-authored by: Joseph Gilmartin, Ryan Smith, Jack Vickers

# Future Work
With more time, we would investigate more advanced statistics like box score and win shares to evaluate their predictive power. Additionally, in our data cleaning phase, players who were contracted for two teams in one season (e.g. traded mid-season) were removed due to redundancy in model training which led to the removal of DPOY Dikembe Mutombo. Future work should ensure these players are included in the training and testing datasets and have their statistics consolidated into one entry.
