+++           # Input number (in fisrt cell)
[             # loop while first cell is not 0
 >[-]         # if second cell is null
 <[>>+<+<-]   # copy first cell in second and third and decrease it to 0
 >[<+>-]      # move second cell in first cell
 <-           # decrement input
]             # go to begin of while loop
>>            # the current cell now has the result