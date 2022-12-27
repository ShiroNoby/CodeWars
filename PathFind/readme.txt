You are at position [0, 0] 
in maze NxN and you can only move in one of the four cardinal directions (i.e. North, East, South, West). 
Return the minimal number of steps to exit position [N-1, N-1] 
if it is possible to reach the exit from the starting position. Otherwise, return -1.

Empty positions are marked .. 
Walls are marked W. 
Start and exit positions are guaranteed to be empty in all test cases.

/*
      Maze:
        .W.
        .W.
        ...
    */ Equals(4);

 /*
      Maze:
        .W.
        .W.
        W..
    */ Equals(-1)

/*
      Maze:
        ......
        ......
        ......
        ......
        ......
        ......
    */ Equals(10)