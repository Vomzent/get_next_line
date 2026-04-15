_This project has been created as part of the 42 curriculum by vcoevert_

# get_next_line
This function reads text from a file descriptor line by line.<br>
Once there is nothing more to read or an error occurs, it returns NULL.<br>
The goal of this project was to learn about static variables (and also to add get_next_line to my libft).<br>

# Instructions
When using this function you must compile it with `--D BUFFER_SIZE=` followed by a value.<br>
This value will be used as the amount of bytes [read(2)](https://linux.die.net/man/2/read) will try to read from the file on each call.<br>
Compiling without defining a `BUFFER_SIZE` yourself will default to a BUFFER_SIZE of 500<br>
The function is prototyped as follows: `char *get_next_line(int fd);`<br>
It takes a file descriptor as it's only parameter. And returns either a pointer to a [malloc(3)](https://linux.die.net/man/3/malloc)'d line or a pointer to NULL on error.

# Resources
My peers!! Including but not limited to:<br>
- biversen<br>
- ivan-der<br>
- mmelo<br>
- odschreu<br>

https://www.educative.io/answers/read-data-from-a-file-using-read-in-c<br>
https://www.w3schools.com/c/ref_keyword_static.php<br>
https://github.com/Tripouille/gnlTester<br>
https://www.gutenberg.org/browse/scores/top<br>

# The algorithm explained
`get_next_line` first checks if there are bytes inside it's buffer array. If there is not it will [read(2)](https://linux.die.net/man/2/read) to fill the buffer. Now that the we've ensured the buffer should be filled. We check if our buffer contains a newline or is empty. If it doesn't: we put everything in our buffer inside a malloc(3)'d array and read from the buffer again looping and each time appending the string we have in buffer to the string we have from our previous read(2) calls. Once we do find a newline or we stop recieving bytes from read(2), We append the last bit of our line to the string we created. Move everything after the newline in the buffer to the front. And that's about it :)
