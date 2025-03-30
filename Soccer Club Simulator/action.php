<?php
session_start();
?>
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8">
        <meta name="author" content="Evan Stowell">
        <title>Soccer Club Simulator</title>
        <meta name="description" content="This page is for the processing the actions of the soccer club simulator">
    </head>
    <body>
    	<header>
            <h1>Soccer Club Simulator</h1>
    	</header>
        <?php
        if (isset($_POST['choice'])) {
            $user_choice = escapeshellarg($_POST['choice']);

            // Create session folder if it does not exist
            if (!file_exists("session")) {
                $command_mkdir = escapeshellcmd("mkdir session");
                $output_mkdir = shell_exec($command_mkdir);

                // Copy files into folder
                $command_cp1_1 = escapeshellcmd("cp Goalkeeper.h session");
                $output_cp1_1 = shell_exec($command_cp1_1);
                $command_cp1_2 = escapeshellcmd("cp Goalkeeper.cpp session");
                $output_cp1_2 = shell_exec($command_cp1_2);
                $command_cp2_1 = escapeshellcmd("cp Defender.h session");
                $output_cp2_1 = shell_exec($command_cp2_1);
                $command_cp2_2 = escapeshellcmd("cp Defender.cpp session");
                $output_cp2_2 = shell_exec($command_cp2_2);
                $command_cp3_1 = escapeshellcmd("cp Midfielder.h session");
                $output_cp3_1 = shell_exec($command_cp3_1);
                $command_cp3_2 = escapeshellcmd("cp Midfielder.cpp session");
                $output_cp3_2 = shell_exec($command_cp3_2);
                $command_cp4_1 = escapeshellcmd("cp Forward.h session");
                $output_cp4_1 = shell_exec($command_cp4_1);
                $command_cp4_2 = escapeshellcmd("cp Forward.cpp session");
                $output_cp4_2 = shell_exec($command_cp4_2);
                $command_cp5_1 = escapeshellcmd("cp Team.h session");
                $output_cp5_1 = shell_exec($command_cp5_1);
                $command_cp5_2 = escapeshellcmd("cp Team.cpp session");
                $output_cp5_2 = shell_exec($command_cp5_2);
                $command_cp6_1 = escapeshellcmd("cp Player.h session");
                $output_cp6_1 = shell_exec($command_cp6_1);
                $command_cp6_2 = escapeshellcmd("cp Player.cpp session");
                $output_cp6_2 = shell_exec($command_cp6_2);
                $command_cp7 = escapeshellcmd("cp main.cpp session");
                $output_cp7 = shell_exec($command_cp7);
                if (file_exists("customTeam.txt")) {
                    $command_cp8 = escapeshellcmd("cp customTeam.txt session");
                    $output_cp8 = shell_exec($command_cp8);
                }
                if (file_exists("team_save.txt")) {
                    $command_cp9 = escapeshellcmd("cp team_save.txt session");
                    $output_cp9 = shell_exec($command_cp9);
                }
            }

            // Compile main.cpp
            $compile_cmd = "cd session;g++ -std=c++17 -o main.exe main.cpp Team.cpp Player.cpp Goalkeeper.cpp Defender.cpp Midfielder.cpp Forward.cpp 2>&1";
            $compile_out = shell_exec($compile_cmd);
            if (!file_exists("session/main.exe")) {
                echo "main.cpp compilation failed: <pre>$compile_out</pre>";
                exit;
            }

            // Give permissions to main.exe
            shell_exec("cd session;chmod +x main.exe");

            // Run main.exe
            $run_cmd = "cd session; ./main.exe " . $user_choice . ";cd ..";
            $output = shell_exec($run_cmd);
            if ($output === null) {
                echo "main.exe execution failed";
                exit;
            }

            // Write output to txt file
            file_put_contents("sim_output.txt", $output);

            // Save output in session variable
            $_SESSION['sim_output'] = file_get_contents("sim_output.txt");

            // move sim_output.txt out of folder
            shell_exec("mv session/sim_output.txt sim_output.txt");

            // preserve team_save.txt
            if (file_exists("session/team_save.txt")) {
                shell_exec("cp session/team_save.txt team_save.txt");
            }

            //If user exits, delete session
            if ($user_choice == 4) {
                // BUG: session folder not deleting
                array_map("unlink", glob("session/*"));
                rmdir("session");
                $_SESSION["exit"] = true;
            }

            // Redirect to webpage
            header("Location: club.php");
            exit;
        }
        ?>
    </body>
</html>
