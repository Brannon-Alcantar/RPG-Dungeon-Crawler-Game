PROJECT NAME: RPG DUNGEON CRAWLER
STUDENT NAME: Brannon Alcantar

C++ Final Project
----------------------------------------------------
Description:
My project is called the RPG Dungeon Crawler. In this game, there are Five rooms total you can traverse. 
In each room there will be a randomized scenario of ten that will take place.

Strings:
Strings I used throughout my program. I used strings in arrays, maps, and loops.
The most noticeable string function is my welcome string that outputs all the characters
of the welcome text in intervals to have the effect of someone typing.

Classes and Constructors:
I have a parent class called Character and two child classes called Monster and Player.
The monster class has a Default and a Non-Default Constructor. The default is used for
the randomized monster and item for scenario 6. The non-default is used for monsters such
as the Mimic that I used to assign it a class.

Vectors:
It was difficult to find a way to make a vector of strings. Error would just keep coming up, 
so instead I used a vector of integers for the scene numbers. At the end of your run, there 
will be an output of all the scene numbers you had in your run.

Inheritance/Polymorphism:
Like I stated before. The character class is the parent of the Player and Monster classes.
I don't use the character class at all in the program. The player class and monster class
use functions in the Character class such as setHealth, setName and I even have overloaded
operators that subtract and add health to the Player class.

File:
Unfortunately, I could not utilize the use of Files in my program. I tried twice with the scenes
and a list of inventory items but I just kept on getting errors after errors, It wouldn't work so
I had to remove them.

Exception Handling:
For the scenarios that require the user to answer Y or N I made a try catch statement that 
throws an error message if the user puts something other than y, Y, n, or N. It outputs
ex: "M is an invalid choice!" to the user and it exits the program.

Templates:
I tried to implement the use of templates in my program towards the end of creating it, but
I couldn't find a meaningful way to implement it. 

Extra things:
-I included the use of Maps for the scenarios. An integer is the key and the scenario text is the
value.
-I used overloaded operators for the subtraction and addition of health to the player.
-I used two arrays for the names of monsters and names of items they drop.
-Used windows.h to add a delay to the intro screen.


Challenges:
This was not an easy program to write! It was difficult and tedious to write the logic for all the
different scenarios. Plus incorporating the classes and making them meaningful was also tough.
It helped to plan first on paper and then start to write the code.
I'm still disappointed that I was unable to get the files to work! I spent many hours trying to figure
it out but couldn't get it to work. Also another added challenge was finding a way to add vectors to my
program in a meaningful way. I thought it would be cool to have the scenario numbers shown at the end and
have others read what other scenarios they could have had.

Conclusion:
Coming up with the ideas for this program was pretty fun. I might continue to work on this project in
the future and make it better! Maybe add more scenarios and clean up the logic a bit more. I wasn't able 
to add Files or Templates to this program but I did add additional things like Maps, overloaded ops and
the Sleep command to my program that made it a lot easier to write.
