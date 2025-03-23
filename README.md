Mini save manager for VVVVVV for Archipelago. Used to run multiple separate VVVVVV saves in a singular archipelago game.

Base Setup:
- Create a new folder anywhere - this will be reffered to as the base folder
- Copy your game folder (ie. the folder containing the game .exe and the archipelago mod APCpp.dll) into the base folder
- If it's not named such, rename the copied folder to `vvvvvv`
- Create a text file `config.txt` in the base folder
- Download `VVVVVV Archipelago.exe`, and put it into the base folder

Archipelago Setup:
- Edit the config.txt file to contain the ip and the password, both on a separate line. If the archipelago room is not password-protected, keep only one line in the config file. Example `config.txt` can be seen on this repo.
- Copy the `VVVVVV Archipelago.exe` file as many times as saves you need.
- Rename each executable to `<PlayerName>.exe`, without `<>` braces
- Running each executable will launch its separate save. Multiple games can be launched simultaniously.
- Example setup:
  
![obraz](https://github.com/user-attachments/assets/36eec045-92d6-475e-98dd-cd85e028fcf7)
