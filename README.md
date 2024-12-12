# 8 American Card Game

## Description
8 American is a terminal-based implementation of the popular card game. The game supports:
- Basic gameplay mechanics
- Special cards (Ace, Jack, Queen, King)
- Card drawing and shuffling

## Features
- **Standard cards**: Cards with numeric values and colors (Spades, Hearts, Diamonds, Clubs).
- **Special cards**: Includes Ace, Jack, Queen, and King with specific functionalities.
- **Game mechanics**: Supports actions like picking, playing, and shuffling cards.
- **Terminal interface**: User-friendly output for card display and gameplay.

## Getting Started

### Prerequisites
- A C compiler (e.g., `gcc`)
- Make utility (optional for building)
- Terminal emulator

### Compilation
1. Clone the repository:
   ```bash
   git clone https://github.com/your-repo/eight-american.git
   cd eight-american
   ```
2. Compile the code using the provided Makefile:
   ```bash
   make
   ```
   This generates an executable named `eight_american`.

3. To clean up the compiled files:
   ```bash
   make clean
   ```

### Running the Game
Run the executable:
```bash
./eight_american
```
Follow the on-screen instructions to play.

## Game Rules
- Players take turns playing cards.
- A player can play a card if it matches the color or value of the last played card.
- Special cards have unique effects:
  - **Ace**: Skip the next player's turn.
  - **Jack**: Reverse the order of play.
  - **Queen**: Allow the player to choose a new color.
  - **King**: Forces the next player to draw cards.

## Code Structure
- **`cards.h`**: Defines the core structures (`BaseCard`, `SpecialCard`, `pack`, etc.) and enumerations.
- **`game.c`**: Implements the main game logic and user interactions.
- **`utils.c`**: Utility functions for card shuffling, drawing, and displaying.
- **`main.c`**: Entry point for the game.

## Example
Example of a card display in the terminal:

```

## Contributions
Contributions are welcome! Please follow these steps:
1. Fork the repository.
2. Create a new branch:
   ```bash
   git checkout -b feature/your-feature
   ```
3. Commit your changes:
   ```bash
   git commit -m "Add your feature description"
   ```
4. Push to your branch:
   ```bash
   git push origin feature/your-feature
   ```
5. Open a pull request.

## License
This project is licensed under the MIT License. See the `LICENSE` file for more details.

## Acknowledgments
- Thanks to [Player Name] for inspiration and testing.
- The project was built as part of a learning exercise in C programming.

---
Enjoy the game!
