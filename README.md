# mtg_turing

This project simulates enough of Magic the Gathering to show that it is Turing complete.

## Features

- Feature 1: Initialize Boardstate: Users can create a starting list of creatures, artifacts and enchantments that begin on the battlefield or in the graveyard. This is imputed in a separate .txt file. The boardstate can be displayed to the terminal using the display function.
- Feature 2: Static effects + Remove Dead: Buffs, Type changing, removeDead function all work.
- Feature 3: Event class + deried classes and Action class + derived classes. Populate the event and action class and subclasses and allow the user to imput an initial action.
- Feature 4: Triggered Abilities: Triggered abilities are triggered by certain events and create new actions, which go on the stack.
- Feature 5: Multiple Triggered Abilities happen simulatiously: The user chooses the order they go on the stack.
- Feature 6: Simulation Report: The program outputs a simulation report to a file after its done running.

## Building
```
cmake -S . -B build
cmake --build build
```

## Running
```
./build/mtg_turing
```

## Running Tests
```
ctest --test-dir build --verbose
```

## Author
Adrian Shuh-Humphries - CIS 25 Final Project

## Current Status
 
**Implemented Features**:
- Feature 1: Initialize Boardstate: Users can create a starting list of creatures, artifacts and enchantments that begin on the battlefield or in the graveyard. This is imputed in a separate .txt file. The boardstate can be displayed to the terminal using the display function.
- Feature 2.a: Zone and Game classes have ability to buff permanents, make permanents of one type additionally another type, and remove dead creatures (non token creatures go to graveyard).
- Feature 2.b: The user can input creature type buffs and permanent subtype changes in the board initialization doc.

**Stubbed (compile but not implemented)**:
- Feature 3: Event class + deried classes and Action class + derived classes. Populate the event and action class and subclasses and allow the user to imput an initial action.
- Feature 4: Triggered Abilities: Triggered abilities are triggered by certain events and create new actions, which go on the stack.
- Feature 5: Multiple Triggered Abilities happen simulatiously: The user chooses the order they go on the stack.
- Feature 6: Simulation Report: The program outputs a simulation report to a file after its done running.
 
**Known Issues**:
- None



