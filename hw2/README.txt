# Homework 2

## Project Goals
The goal of this project is to:
1.	Familiarize students with **linked lists**
2.  Familiarize students with **array storage** and **linked storage**.
3.  Practice **time complexity** analysis.

## Program
Add functionality for the incomplete data structure functions.  

Modify this README document with a paragraph (at least three complete sentences) explaining why the different storage methods are better for the different lists used in the driver.
# EXPLANATION GOES UNDER HERE 
Okay so as far as I can tell, the reasoning your todo list is dynamic is because it's a mile long and you don't know where it will end. However, your completion list ("done list" )
is actually a set size, cause let's be real, you and I both know we aren't gonna complete more than some set amount of things at a time. Though likely the less sarcastic reason is 
simply size. Your todo list, you can traverse as you need, and generally is done in order (kindof like a stack?). a Done list however, you might to out of order, where an Array is more useful. I remember somewhere in here was a time-complexity analysis, and while the algorithms for the array based implementation is far quicker (O of 1 iirc), it is a set size. While the linked implementation is O(n), since you must traverse the whole list to get to an entry. It is slower, but allows for dynamic sizing (for those todo lists that are almost literally infinite). 

## Submission details
If you are usinng git from the command line, execute the following commands:
1.	After accepting the assignment invitation, copy the clone URL
2.	Type 
```git clone clone URL```
3.	cd into your new assignment directory
4.	After working on your files
5.	When you’re ready, type the following commands: 
```
git add .
git commit -m “your commit message”
git push
```
## Academic Honesty
Academic dishonesty is against university as well as the system community standards. Academic dishonesty includes, but is not limited to, the following:
Plagiarism: defined as submitting the language, ideas, thoughts or work of another as one's own; or assisting in the act of plagiarism by allowing one's work to be used in this fashion.
Cheating: defined as (1) obtaining or providing unauthorized information during an examination through verbal, visual or unauthorized use of books, notes, text and other materials; (2) obtaining or providing information concerning all or part of an examination prior to that examination; (3) taking an examination for another student, or arranging for another person to take an exam in one's place; (4) altering or changing test answers after submittal for grading, grades after grades have been awarded, or other academic records once these are official.
Cheating, plagiarism or otherwise obtaining grades under false pretenses constitute academic
dishonesty according to the code of this university. Academic dishonesty will not be tolerated and
penalties can include cancelling a student’s enrolment without a grade, giving an F for the course, or for the assignment. For more details, see the University of Nevada, Reno General Catalog.
