**Grocery Inventory Report System**

**Project Summary**

This project is a grocery reporting system. It is designed to read item data from an input text file and generate reports based on user input.
When run, the program allows the user to search for a specific item, display all data frequencies, and show a histogram of all item quantities.
The goal of this project was to build a simple reporting tool that demonstrates file handling using data structures in C++.

**Problem This Solves**

The problem this solves is taking a plain text inventory file that lists grocery items, usually more than once, and generate a useful report.
It processes the file, counts how many times the item appears, and presents the information in a clear, easy to understand way.
It also reloads the file before each user menu choice, which makes sure the reports are always accurate to real time data.

**What I Did Well**

I did well separating the responsibilities between classes, as well as keeping the code readable. The data is encapsulated in a clean and straightforward way,
and the inventory logic is handled separately, which keeps the program organized and reusable.
I also handled input validation well, making sure the user can only enter valid menu choices.

**Enhancements**

The code could be improved in a few areas. One enhancement could be to separate inventory management into its own dedicated class, to make the program more modular and easier to build on later.
Another improvement could be better input file data handling, to clean messy datasets and still allow processing while reporting the errors found.

**Challenging Parts**

Managing the inventory map and making sure the items were counted correctly was the most difficult part of this project.
I had difficulty iterating at first, but after some more study and practice on maps and iterating through them I overcame it.
I relied on the ZyBook, online references, and other documentation to build on my understanding.

**Tools and Resources**

I found many good resources, including C++ references, map and iterator tutorials, and other work and examples of map iteration.

**Maintainability and Readability**

I made the program maintainable and readable by keeping functions simple and reusable, using clear names, and organizing the code into logical sections.
The design is also able to be expanded with new data fields using the map structure I implemented, and can be done effectively without breaking the program.



