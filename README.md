<h1>Get Next Line</h1>

<h2>Introduction</h2>
<p>Welcome to the <strong>Get Next Line</strong> project, part of the 42 curriculum. This project aims to provide an in-depth understanding of file input/output operations in C, with a particular focus on reading lines from files or standard input efficiently.</p>

<h2>Objective</h2>
<p>The primary objective of this project is to implement a function, <code>get_next_line</code>, that reads and returns the next line from a file descriptor each time it is called. This function must handle various edge cases, manage memory efficiently, and support multiple file descriptors simultaneously.</p>

<h2>Function Prototype</h2>
<pre><code>int get_next_line(int fd, char **line);</code></pre>
<ul>
    <li><strong>fd</strong>: The file descriptor to read from.</li>
    <li><strong>line</strong>: A pointer to a string where the function will store the next line read from the file descriptor.</li>
</ul>

<h2>Return Values</h2>
<ul>
    <li><strong>1</strong>: A line has been read successfully.</li>
    <li><strong>0</strong>: The end of the file has been reached.</li>
    <li><strong>-1</strong>: An error occurred.</li>
</ul>

<h2>Key Concepts</h2>
<ul>
    <li><strong>Buffer Management</strong>: Efficiently reading chunks of data to minimize the number of read operations.</li>
    <li><strong>Memory Management</strong>: Dynamic allocation and deallocation to handle lines of arbitrary length without memory leaks.</li>
    <li><strong>File Descriptor Handling</strong>: Managing multiple file descriptors concurrently, ensuring correct line retrieval from different sources.</li>
</ul>

<h2>Challenges</h2>
<p>Implementing <code>get_next_line</code> involves tackling several challenges:</p>
<ul>
    <li>Handling partial lines that span multiple read operations.</li>
    <li>Managing the buffer to ensure no data is lost or duplicated.</li>
    <li>Properly freeing memory to avoid leaks and ensure efficient usage.</li>
    <li>Supporting multiple file descriptors and ensuring accurate line reading for each.</li>
</ul>

<h2>Usage</h2>
<p>To use the <code>get_next_line</code> function, include it in your project and call it with the appropriate file descriptor. Here is a simple example:</p>
<pre><code>#include &lt;fcntl.h&gt;
#include &lt;stdio.h&gt;

int main(void)
    {
        char *line;
        int fd = open("example.txt", O_RDONLY);
        if (fd == -1)
            return 1;
        while (get_next_line(fd, &line) == 1)
            {
                printf("%s\n", line);
                free(line);
            }
        close(fd);
        return 0;
    }
</code></pre>

<h2>Conclusion</h2>
<p>The <strong>Get Next Line</strong> project is an excellent exercise to deepen your understanding of low-level file I/O operations in C, dynamic memory management, and buffer handling. By completing this project, you will gain valuable skills that are crucial for efficient and effective C programming.</p>
<p>Feel free to explore the code, contribute, and share your thoughts!</p>
