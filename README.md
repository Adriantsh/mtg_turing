# mtg_turing

This project simulates enough of Magic the Gathering to show that it is Turing complete.

## Features

- Users can create a starting list of creatures, artifacts and enchantments that begin on the battlefield or in the graveyard. This is imputed in a separate .txt file.
- Creatures have any number of types and a toughness, and they can be tokens (they disappear when they die) or non-token (they go to the graveyard).
- There are static abilities “all creatures of type X get +1 buff” or “all creatures of type X are also type Y”.
- There are triggered abilities “Whenever a creature of type X dies, create a creature of type Y”, which go on a stack.
- When multiple triggers happen at the same time, the user can input the order they should go on the stack in.

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


