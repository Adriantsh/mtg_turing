# Implementation Plan

## Feature 1: Initialize Boardstate
**Trigger**: User creates a list of permanents in a seperate text file.
Each permanent has a type, list of subtypes, isToken? tag, starting location (battlefield or graveyard)
Permanents of type creature also have a toughness attribute.
For each permanent, the Game class creates a permanent of that type/attibutes and adds it to the battlefield or graveyard.
The boardstate is then displayed.

## Feature 2: Static effects + Remove Dead
**Trigger** The Game class has a vec of static effects that should be applied to each new permanent on the board. 
There are three varieties of static effects: 
Buff: All creatures of subtype X get +X
Type Change: All creatures of subtype X are also subtype Y

There is also a remove dead that destroys all creatures with toughness 0 or less after every game action.
If those creatures are tokens, they dissapear, 


## Feature 3: Event class + deried classes and Action class + derived classes
**Trigger** The user can input an initial Action (in a seperate txt file?). 
The program then simulates that Action happening in the game. 
Actions change the boardstate, but also add new Events.

Action derived classes:
Grow: all creatures of subtypes Y get buffed by an amount.                              -> Growth event
Destroy: destroy all permanents of type X                                               -> Destruction event
Create: create permanent of type X and subtypes {y1, y2, ...}                           -> Creation event
Reanimate: return all permanents of type X from the graveyard to the battlefield        -> Creation event

Event derived classes:
Growth: a creature of subtypes {y1, y2, ...} got buffed by a positive amount
Destruction: a permanent of type X and subtypes {y1, y2, ...} was destroyed
Creation: a permanent of type X and subtypes {y1, y2, ...} was created

The RemoveDead function can also create Destruction Events.

## Feature 4: Triggered Abilities
**Trigger** The user can now add triggered abilities of the form:
Whenever Event happens, do Action. 
Triggered Abiliities go on the stack, and are inputted in the initialBoardstate file

## Feature 5: Multiple Triggered Abilities happen simulatiously
**Trigger** When multiple triggers go on the stack, 
the program asks the user what order they would like them to go on the stack in.
The user imputs a sequence of numbers in the terminal to make this choice.

## Feature 6: Simulation Report
**Trigger** After the simulation finishes running, the outputs a report of the run to a text file.