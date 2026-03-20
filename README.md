# RPG-battle
A C++ terminal-based RPG combat engine demonstrating OOP inheritance, character state management, and file I/O.


# RPG Battle Engine

A C++ console-based simulation of a turn-based combat system. This project explores core Object-Oriented Programming (OOP) principles and character-state logic.

### Features
* **Hero & Boss System:** Supports 12 unique Heroes and 10 randomized Bosses.
* **Ability Mechanics:** Each entity features 3 distinct abilities (Damage, Healing, and Status effects).
* **Energy Management:** A "Super Power" system that charges based on combat actions.
* **Lore Integration:** Loads character and boss backstories from external `.txt` files.

### Technical Details
* **Language:** C++
* **Paradigm:** Object-Oriented Programming (Inheritance & Encapsulation)
* **Storage:** File I/O for game lore and data persistence.

### Project Structure
The engine uses a base `character` class with specialized `HERO` and `ENEMY` derived classes, managed by a central `Battle` controller.
