# AI Collaboration Log
 
## Tools used

Claude on the web
 
## A prompt that worked well

> The chained type behavior should work as follows: if A->B and B->C, apply A->B first if it comes first in the initial board state file. Otherwise apply them in reverse order. The user is responsible for typing them in the correct order. Does this make sense?

**Why it worked:**

Because I clarified how I wanted the type implication process to work, the AI was able to suggest a better data type for the structure that holds which types imply other types. Instead of using a set object, I am using a vector object, because the order in which the type implications are applied changes the final creature types.
 
## A prompt that did not work

> Implement the body of this function, where Zone has a private board of pointers to Permanent objects:
> 
> ```cpp
> void Zone::removePermanent(int index) {
>     // TODO: implement later
> }
> ```

The AI did not understand that I needed pointers to permanents to always be deleted. Without the context of the functions that would be called before this one the AI suggestion could have caused a memory leak.

I explained to the AI how the other function would work, and removed an if statement from the function the AI suggested.

## Code I rejected

> ```cpp
> void Zone::removePermanent(int index) {
>     if (index < 0 || index >= (int)board.size()) return;
>      
>     Permanent* perm = board[index];
>     board.erase(board.begin() + index);
>       
>     if (perm->isToken()) {
>         delete perm;
>     }
> }
> ```

This code would have caused a memory leak because `delete perm` is only run if `perm->isToken()`. However, before `removePermanent` is called, I create a deep copy of the permanent in the graveyard.

When the destructor for the `Zone` class is called it wouldn't know to delete the pointer to the non-token permanent that got erased from the battlefield.
 
## What I'd do differently next time

When I chose to implement this feature, I realized I was implementing three separate features at once. Each of these features needed methods in the `Zone` and `Game` classes, as well as changes to the `loadBoardState` function. Trying to get the AI to update all of these different parts of my code at once was not a good workflow.

In the future, I would focus in on one smaller area and ask the AI to focus in on that feature.
