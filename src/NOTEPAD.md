# September 21, 2019
Today I was able to wire the trim pot so it was able to produce 1024 measurements. I selected 4 of those inputs to represent different locations in a matrix.
When setting up the LED matrix, I wired it correctly, but figuring out the logic took a litle bit of time. I was wondering how to select a line to ground. Instead of doing this, you set the line to HIGH to "disconnect it from GND." So in an example where pin (0, 1) must be lit, the following must be the configuration:
- ROW0 set to LOW
- ROW1 set to HIGH
- COL0 set to LOW
- COL1 set to HIGH

Fun fact, use LED's that are only biased in one direction. It took me a long time to figure out the above solution because of the LED's I was using. These would be red when power was supplied from one direction, and green when it was applied from the other. Clearly very confusing output with the above solution.
