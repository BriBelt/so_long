# so_long 👾
First graphical project of the 42 cursus.

This project is a 2D mini-game that uses the 42 school's library "MinilibX". Its purpose is to familiarize you with textures, sprites, and some basic
graphical elements in general.
  **DISCLAIMER:**
  This project works with macOS ONLY, this is because of the library used. In order to run this program you must set up the MinilibX library on your
  Mac.

## Preview
<div style="text-align: center;">

![ezgif com-video-to-gif](https://github.com/BriBelt/so_long/assets/114313875/266c5ffd-85bb-47bf-95b7-e400f5802fda)

</div>


## 🕹 How to run so_long
```
git clone git@github.com:BriBelt/so_long.git
cd so_long
make / make bonus
./so_long [map].ber
```
## 🎮 How to play
This game is pretty simple, the goal is to collect all collectibles on the map until the door appears and 
you can exit.

| Keyboard     | Action     |
| :------------|:-----------|
| W or ↑       | Up         |
| S or ↓       | Down       |
| A or ←       | Down       |
| D or →       | Down       |
| ESC          | Close the game window       |

### 🗺 Try your own maps
If you want to, you can try and create your own maps, you only have to create a ".ber" file and follow the next requirements.
- Only permitted characters (0, 1, C, E, P).
- Map must be surrounded by walls.
- There should be a valid path for the player to be able to reach all the targets.
- Only one player, one exit and at least one collectible.

### 🐱 Textures 
Thanks to [cup nooble](https://cupnooble.itch.io/sprout-lands-asset-pack) for creating the textures and making them available online.
