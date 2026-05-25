# Initial Feature Test Cases
 
## Feature: Initialize Boardstate
 
### Test 1: Normal Operation - test_good_boardstate()
- What it tests: a boardstate with a Creature on the battlefield and an Artifact in the graveyard can be loaded from a file.
- Result: graveyard and battlefield each contain the correct permanent with the correct attributes.
- Result: Pass
 
### Test 2: Edge Case - test_empty_boardstate()
- What it tests: If the boardstate file is empty, no permanents are added to the graveyard or battlefield.
- Expected result: graveyard and battlefield board vectors both have size 0 after loading operation.
- Result: Pass
 
### Test 3: Boundary Conditions - test_bad_file()
- What it tests: if the boardstate file is not found, throw a FileNotFound error.
- Expected result: FileNotFound error is thrown.
- Result: Pass
 
### CTest Output
UpdateCTestConfiguration  from :/Users/adriansh/Documents/mtg_turing/build/DartConfiguration.tcl
Test project /Users/adriansh/Documents/mtg_turing/build
Constructing a list of tests
Done constructing a list of tests
Updating test list for fixtures
Added 0 tests to meet fixture requirements
Checking test dependency graph...
Checking test dependency graph end
test 1
    Start 1: MtgTests

1: Test command: /Users/adriansh/Documents/mtg_turing/build/tests
1: Working Directory: /Users/adriansh/Documents/mtg_turing/build
1: Test timeout computed to be: 10000000
1: Running tests...
1: 
1: All tests completed.
1/1 Test #1: MtgTests .........................   Passed    0.12 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.12 sec

