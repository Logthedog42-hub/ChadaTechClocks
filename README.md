For my portfolio artifact, I selected Project One: ChadaTech C++ Clock. This project involved designing and implementing a program that displays a 12-hour and 24-hour digital clock side-by-side. Users can interact with the clock through a menu interface to add hours, minutes, or seconds, and the clock updates its displayed time accordingly.

The problem this project solves is creating a clean, functional, user-friendly digital clock system. It demonstrates my ability to work with time calculations, looping structures, formatting output, and building programs that respond to user input.

What I Did Well

I did particularly well with formatting the clocks so they are clear and easy to read. The structure of the program is logically organized, and I used functions to separate tasks such as time updating, menu display, and output formatting. This made the program more readable and easier to maintain.

I also think I handled the increment logic correctly, especially for rolling over seconds → minutes → hours, and switching between 12-hour and 24-hour clock formats.

Where I Could Enhance My Code

If I enhanced this project further, I would focus on:

Input validation to prevent invalid selections or unexpected user input.

Even better modularization, such as breaking out a separate Time class to handle all time logic.

Adding unit tests for rollover behavior (e.g., 11:59:59 PM → 12:00:00 AM).

These changes would make the program more robust, secure, and easier to scale into a larger application.

Most Challenging Code and How I Overcame It

The most challenging part of the project was handling time rollovers, especially switching between AM and PM while keeping the 24-hour format accurate. I overcame this by:

Writing the logic in small steps

Using print statements to test values

Reviewing the project example video

Checking the course resources for modular coding strategies

Debugging also helped reveal places where increments needed to wrap correctly.

I also added tools to my support network, including:

Visual Studio debugger

C++ reference documentation (cplusplus.com & cppreference.com)

Instructor walk-through videos

Transferable Skills

From this project, I strengthened several key skills that will help in future coursework and professional software development:

Modular program design

Loop and conditional logic

Debugging and testing small code segments

Formatting clean, readable console output

Using functions to organize code effectively

Working within C++ syntax and standards

These skills directly apply to larger projects in CS 210 and beyond.

How I Made This Program Maintainable and Readable

I focused on the following:

Consistent indentation and spacing

Clear, descriptive function names

Inline comments explaining complex logic

Separating the menu, display, and time logic into functions

Avoiding unnecessary repetition in the code

Overall, these choices make the code easier for another developer—or my future self—to understand and modify.
