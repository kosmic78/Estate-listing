# Estate listing
# About the application
For storing the data I used linked lists which I allocated dinamically. Every single estate is a node which has some attributes: type, number of rooms, number of bathrooms and a price. I thought that using linked lists is the best option because I had to store a lot of data for a single object and this is a efficient method. After that I did a method where I declare a estate object and copy all the attributes that we get as parameters into my current object and then I returned it. When the user inputs 1, the program reads from a text file the attributes, creates a "estate" type object and link it to a list. After getting to the end of the file, it prints out the list with the data. When the user inputs 2 he is asked which estate to select and then he has another 2 options: 1. save an estate and 2. buy an estate. For the first option I've made a function where I start searching from the first node in the list, to the node that user gave us early. When the program gets to the wanted estate it opens a new text file where it prints the attributes. For the second option I used a function where I search in the list for the wanted estate, then I copy it into a new node. After that I go over the list again and search for the wanted node, delete the node and copy all the data without my node to a temporary text file, and then back to the original file, this is for deleting from the "database". When the user inputs 3, it opens my saved estates text file, creates a node with that, then link the information to a new list. Then it prints the list with the attributes.
# Menu
![Menu](https://i.imgur.com/dQH0kUc.png)
# Show all the available estates.

User inputs 1 and it shows all the estates.
![Show](https://i.imgur.com/p7vya7D.png)
# Saving an estate into a favourite list and see all the estates that user has saved.
![Saving](https://i.imgur.com/u48WSGO.png)
# Buying an estate, moment when it gets deleted from my list and from the textfile.
![Buying](https://i.imgur.com/VGJAaeD.png)
