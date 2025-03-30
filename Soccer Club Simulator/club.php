<?php
session_start();
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="author" content="Evan Stowell">
    <meta name="description" content="This page is for the soccer club simulator">
    <link href="style.css" rel="stylesheet" type="text/css" media="screen" />
    <title>Soccer Club Simulator</title>
</head>
<body>
    <header>
        <h1>Soccer Club Simulator</h1>
    </header>
    <form action="action.php" method="post">
        <p>Select one of the options from below: </p>
        <input type="radio" id="play" name="choice" value="1" checked>
        <label for="play">Play a Match</label>
        <input type="radio" id="checkTeam" name="choice" value="2">
        <label for="checkTeam">Check Team</label>
        <input type="radio" id="rules" name="choice" value="3">
        <label for="rules">Read Rules</label>
        <input type="radio" id="exit" name="choice" value="4">
        <label for="exit">Exit Simulator</label>
        <input type="submit" value="Submit">
    </form>
    <div>
        <p>
            <?php
                if (isset($_SESSION["sim_output"])) {
                    echo $_SESSION["sim_output"];
                    unset($_SESSION["sim_output"]);
                    if ($_SESSION["exit"]) {
                        session_destroy();
                    }
                } else {
                    echo "Welcome to the simulator! Submit one of the options above!";
                }
            ?>
        </p>
    </div>
</body>
</html>
