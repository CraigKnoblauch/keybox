# September 21, 2018
Today I was able to wire the trim pot so it was able to produce 1024 measurements. I selected 4 of those inputs to represent different locations in a matrix.
When setting up the LED matrix, I wired it correctly, but figuring out the logic took a litle bit of time. I was wondering how to select a line to ground. Instead of doing this, you set the line to HIGH to "disconnect it from GND." So in an example where pin (0, 1) must be lit, the following must be the configuration:
- ROW0 set to LOW
- ROW1 set to HIGH
- COL0 set to LOW
- COL1 set to HIGH

Fun fact, use LED's that are only biased in one direction. It took me a long time to figure out the above solution because of the LED's I was using. These would be red when power was supplied from one direction, and green when it was applied from the other. Clearly very confusing output with the above solution.

# September 22, 2018
Ross told me about something called Charlieplexing. It promises to allow me to control more LED's with less pins

# September 24, 2018
I experimented with the keyboard library today. It requires a 32u4 chip, so I'm using the Arduino Micro. The test passed without a hitch. Since I've been able to assemble all the parts without much trouble, I'm going to move on straight to NFC. But first... a TODO
- Order NFC bands/tags
- Order an NFC reader/writer
- Order a momentary switch
- Order a plate mount variable resistor (breadboard compatibility is a plus).
- Research how I'm going to generate string altering functions.

# September 25, 2018
I ordered this [writer/reader](https://www.amazon.com/HiLetgo-RFID-Kit-Arduino-Raspberry/dp/B01CSTW0IA/ref=pd_lutyp_cxhsh_3_2?_encoding=UTF8&pd_rd_i=B01CSTW0IA&pd_rd_r=4f88c399-b6b0-4f1e-95a5-2eda6b56cb4c&pd_rd_w=jalA7&pd_rd_wg=jgNqi&psc=1&refRID=ZPB2H49Z4D3BR6D9V1WS). We'll see what we can do with it when it gets here.
I was thinking about how to organize my functions, I think I'll make some custom libraries. Here were a few of the functions I was thinking of...
- setNumRows(int numRows)
- setNumColumns(int numColumns)
- turnOnLED(int row, int col)
- setSelection(int row, int col, String account) Tie the name of an account to a position in the matrix
    - I'm thinking I may need to implement a dictionary for this.
- resetMatrix(void)
- sendPassword(String password) A wrapper for Keyboard.print(String str)

It just hit me that I should really think through a matrix class. Since my matrix has specific use cases, it should really have a specific class. I'll do some more thinking on this later today.

## Later today
- I started on the TrimPot class. When testing I have some kind of bug (issue 2)
- @synackd suggested a useful feature today (issue 1)
- I began thinking about how to generate string modification functions today (these are just late night thoughts):
    - Have a general format
    - Randomly select one of the arithmetic operators to use
    - Modify a random character or append a modification of a random variable

# September 26, 2018
Ok, I'm calling it. The breadboard wins this day. I rewired the matrix so it's actually a matrix, and tried my hand at programming it. After weird errors that made me question whether the board was defective I proved that I could light up each individual LED, one by one. Doing so in a loop however, has been a massive challenge. The behavior I have right now is shown ![here][broken-matrix-1.gif].
As an interesting not, instead of doing the high for columns, low for rows approach I was doing before. I decided to do this approach:
1. 168 (3.3V) for column you want, 0 for column(s) you don't
2. 0 for row you want, 255 (5.5V) for row(s) you don't

# October 1, 2018
Per the advice of Dr. Meuth (@rmeuth01), I got rid of my scope resolvers inside Matrix.cpp. This was probably causing some errors. This did not solve the problem with the matrix however. I noticed that when I called my Matrix constructor, I was using `sizeof(array)` rather than `sizeof(array)/4`. I inspected the constructor and saw that providing too large a number for the rows or columns could potentially cause issues. When I fixed this mistake, I observed different behavior, but by no means correct behavior. "SCREW IT! I'll hardcode the values of row size and column size."... and then it worked.

I have no idea why hardcoding the values worked. If we look at the following code, I don't see why `sizeof(row)/4` would not return 2, and likewise why `sizeof(col)/4` would not return 4 (I tested that hypothesis in another program and proved it):
```
int col[4] = {12, 11, 10, 9};
int row[2] = {8, 7};

Matrix matrix = Matrix( sizeof(row)/4, row, sizeof(col)/4, col );
```
For the record, the above does not work, but the below does...  *¯\\_(ツ)_/¯*
```
int col[4] = {12, 11, 10, 9};
int row[2] = {8, 7};

Matrix matrix = Matrix( 2, row, 4, col );
```
## Later today, addressing the trimpot ([Issue 2](https://github.com/CraigKnoblauch/keybox/issues/2))
I setup the trimpot on the breadboard. I connected cw to pin 6, the wiper to A0, and ccw to ground. I wrote the cw high and observed the trimpot working with a multimeter. I then wrote a simple script that printed the trimpot's voltage readings to the serial monitor. This checked out. Now, I had confirmed that the trimpot was working and the arduino was set up correctly. The error had to be in `TrimPot::getSelection()`. The old solution, claimed that every trimpot setting was selection 0. I decided to rework the algorithm. This is what I came up with (taken right from TrimPot.cpp):
```
int TrimPot::getSelection() {
    int val = analogRead(wiper);

    /**
    * For some amount of selections N, the amount of possible values per selection,
    * m, is equal to 1024/N (I've decided to take the floor for now until I figure out
    * how to distribute the remainders).
    * Given this arrangement, the values are distributed like so:
    *
    * 0 to m-1, m to 2m-1, ..., (N-1)m to Nm - 1
    */

    int m = 1024/num_selections;

    // if none of the selections are matched, it's likely the remainders have accumulated
    // such that the val is not in the range, thus it will not be set in the loop, but should
    // still be the last selection
    int selection = num_selections - 1;

    for(int i = 1; i <= num_selections; i++) {
        if( val >= ( (i-1)*m ) && val <= ( i*m - 1 ) ) {
            selection = i - 1;
            break;
        }
    }

    return selection;
}
```
This solution also gives claims that the selection is always zero. I think to solve this one, and to make my life easier for the coming features, I'm going to have to transfer over to eclipse. I need a debugger.
