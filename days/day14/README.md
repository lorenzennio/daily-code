# day14

## Problem
Alice wants to join her school's Probability Student Club. Membership dues are computed via one of two simple probabilistic games.

The first game: roll a die repeatedly. Stop rolling once you get a five followed by a six. Your number of rolls is the amount you pay, in dollars.

The second game: same, except that the stopping condition is a five followed by a five.

Which of the two games should Alice elect to play? Does it even matter? Write a program to simulate the two games and calculate their expected value.

## Notes

### Intuition
Intuitively, one might think both sequences have the same probability ($1/36$) and therefore the same expected value. However, the **5-5** game is more expensive (expected value 42) than the **5-6** game (expected value 36).

The reason lies in how the sequences overlap:
*   **Case 5-6:** If you roll a `5` (halfway there) and then roll another `5`, you fail to complete the `5-6` sequence, **BUT** you are still sitting on a `5`. You are still "halfway there" for the next attempt. The "failure" roll helps you.
*   **Case 5-5:** If you roll a `5` (halfway there) and then roll a `6`, you fail. You have lost your `5` and must start completely over from scratch.

### Mathematical Derivation
Let $x$ be the expected rolls from the start, and $y$ be the expected rolls after rolling a 5.

#### Game 1: Target 5-6
1.  **Start ($x$):** Roll 1. If 5 ($1/6$), go to $y$. Else ($5/6$), restart $x$.
    $$x = 1 + \frac{1}{6}y + \frac{5}{6}x$$
2.  **Halfway ($y$):** Roll 1. If 6 ($1/6$), done (0). If 5 ($1/6$), stay at $y$. Else ($4/6$), restart $x$.
    $$y = 1 + \frac{1}{6}(0) + \frac{1}{6}y + \frac{4}{6}x$$

**Result:** $x = 36$

#### Game 2: Target 5-5
1.  **Start ($x$):** Same as above.
    $$x = 1 + \frac{1}{6}y + \frac{5}{6}x$$
2.  **Halfway ($y$):** Roll 1. If 5 ($1/6$), done (0). Else ($5/6$), restart $x$ (because a 6, 4, 3, 2, or 1 breaks the chain).
    $$y = 1 + \frac{1}{6}(0) + \frac{5}{6}x$$

**Result:** $x = 42$