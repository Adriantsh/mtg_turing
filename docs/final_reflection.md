# Final Reflection 

## Plan vs Reality

> Lay out your original feature plan next to what you actually built. For each feature on your original list, briefly note its current state (done / partial / stubbed / not started). Then pick one or two features that turned out very differently from how you imagined them at the start — harder, easier, or just different in shape — and walk through what happened and what you decided to do about it.


Built:

> - Feature 1: Initialize Boardstate: Users can create a starting list of creatures, artifacts and enchantments that begin on the battlefield or in the graveyard. This is imputed in a separate .txt file. The boardstate can be displayed to the terminal using the display function.
> - Feature 2: Static effects + Remove Dead: Buffs, Type changing, removeDead function all work.

Not built:

> - Feature 3: Event class + deried classes and Action class + derived classes. Populate the event and action class and subclasses and allow the user to imput an initial action.
> - Feature 4: Triggered Abilities: Triggered abilities are triggered by certain events and create new actions, which go on the stack.
> - Feature 5: Multiple Triggered Abilities happen simulatiously: The user chooses the order they go on the stack.
> - Feature 6: Simulation Report: The program outputs a simulation report to a file after its done running.

Both features I implemented ended up being a lot more difficult then I imagined. For my first feature, I realized I was basically trying to implement two features in one. First the was the part of the program that read the initialiBoardState.txt file, and secondly there was the part of the program that displayed the boardstate to the terminal. In the future, I would implement these as two separate features. I implemented them as one feature for this project because I thought I would need the display() function to test that my file parsing was working but I think I could have actually just used assertions in the testing files to check this.

Because the first feature was so difficult, I decided to split the second feature up into two features. In hindsight, I think I would have broken up the second feature differently. Instead of breaking the second feature up into input and implementation for both type implication and creature buffing, I would have made type implication and creature buffing two separate features. Additionally, the `removeDeadCreatures` function could have been its own feature.

## Design Decisions You Would Change

> If you started this project over tomorrow, what would you design differently? Be specific. Name classes, relationships, or interfaces from your code. Examples of the kind of thing I'm looking for:
>
> * "I made X a base class for Y, but they don't actually share enough behavior to justify the inheritance — composition would have been cleaner."
> * "My Manager class ended up doing three jobs. I would split it into Loader, Storage, and UI controller."
> * "My data model and my display logic are tangled together. I would separate them so I could swap the UI later."
> 
> Vague answers ("I would write cleaner code") will not score well. Specific answers grounded in your actual UML and your actual code will.

If I started the project over tomorrow, I would have created a separate class for inputting the file. The `loadBoardState` function ended up being very large and unwieldy and harder to test. It also felt separate from the rest of the `Game` class. I would have put this function in its own class and also broken it up into several smaller functions. This would have reduced the number of things the `Game` class was doing.

I would have also added additional classes for buffs and type imply objects. The vector of pairs of int and string objects felt complex enough to have their own class.

## What You Learned

> Identify three specific things you learned during this project — one in each of the following categories:
> 
> * Technical: a C++ language feature, a library, or a tool you understand much better now than you did at the start.
> * Design: a software-design principle (encapsulation, separation of concerns, the open/closed principle, composition over inheritance, etc.) that became real to you because of something that happened in this project.
> * Process: something about how you work — debugging, version control, planning, testing — that changed across the project.
>
> For each one, give a short concrete example from your project. Generic statements ("I learned about classes") earn very few points; grounded statements earn full credit.

* **Technical:** I got a lot more familiar with the std vector class member functions. Using `erase` and `push_back` to edit vectors was not something I had done before. Specifically, reverse iterating through a vector to erase objects in it was a new paradigm to me.

* **Design:** I felt like I understood why polymorphism is useful. Because I had both base class objects (`Permanent`) and derived class objects (`Creature`) in the board vector, I needed to use a vector of pointers instead of a vector of class objects. This allowed me to write polymorphic functions for the `Permanent` and `Creature` classes. Before this project, I didn't really understand why pointers would need to be used, but this felt like a good use case for them.

* **Process:** I learned to rely more on explicit tests separate from the `main` function instead of printing the program state in main in order to debug. Because I felt like I needed a `display` function that was fully fleshed out to implement a first feature this feature ended up being a lot more difficult than I had anticipated. In the future, I think it would be easier to break up features into smaller chunks by using actual tests.

## What's Left to Finish

> Your project does not have to be finished — and from the start, you were encouraged to take on something ambitious enough that finishing was unlikely. So this prompt is a real plan, not a hypothetical: list the features, refactors, and polish work still needed to bring the project to a finished state. Order the list. For each item, give a one-sentence reason it matters. The goal is to show that you understand exactly where your project sits and what 'done' would actually look like.

The largest features that still need to be implemented are the `Event` and `Action` classes. These classes need to be interwoven with the rest of the program, for example the each `applyBuff` and `destroyDeadCreatures` call should create `Event` objects which might trigger `Trigger` objects. These `Trigger` objects would then create new `Action` objects. This would loop in the run function owned by the `Game` class. This is the main goal of the project and would be needed for the project to be useful to me to make a turing machine in Magic: The Gathering.

An additional feature that is not on the project plan that I think should also be implemented would be to have `Trigger` objects and buff static effects belong to `Permanent` objects. This way if permanents left the battlefield, their triggers would no longer go on the stack and their buffs would no longer apply.

Finally, I would also need to implement the stack and deal with the case when multiple triggers go on the stack at once.

## Workflow Reflection

> You have now done the feature-branch / pull-request / self-review / merge workflow at least three times. Reflect honestly:

> What about that workflow has actually become natural for you?

1. It was nice to use a branch for features so that when I was finished building them I felt a sense of achievement when I merged the branch. It created a natural stopping point to review my work and catch bugs and poor design decisions.

> What still feels awkward or slow?

2. GitHub would not let me approve my own pull requests, so I couldn't do this part. However, if I was submitting this to a senior dev, I understand how this could be a natural part of my workflow.

> If you were collaborating with another developer on this project, which parts of the workflow would matter more, and which would matter less?

3. I worked on this project solo.

## AI Use

> Write a short paragraph describing how you used AI on this assignment. Useful angles: what tasks you used it for (debugging? boilerplate? rubber-ducking design decisions back at yourself?), where it was actually helpful versus where it wasted your time, places where you had to override or correct what it suggested, and how you kept the design decisions in your own hands. If you didn't use AI on this assignment, just say so.

I found the AI more helpful than I expected. Not for writing code but for helping me plan the design of my code. For example, when working on the second feature (feature 2a.) the AI pointed out that because the order the subtype implications were applied changed the result, these should be stored in a vector, not a set.

In my third feature (feature 2b.) I decided not to use the AI. However because I had used the AI to plan the previous feature, I felt like the work for this feature went a lot more smoothly. I was glad that I kept overall control over the code as I had a very specific implementation in mind already and I think if the AI changed a lot about my specs, I would have found continuing to work on the project confusing.