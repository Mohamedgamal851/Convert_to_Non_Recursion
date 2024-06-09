# Convert_to_Non_Recursion
This problem used to convert a recursion function to non recursion with some restrictions using c++

Consider the following recursive function:
------------------------------------------
int F(int n)<br>
{<br>
	if(n<=1) return 1;<br>
	int a=n*F(n-1)+7*F(n/2);<br>
	int b=F(n-3-a%2);<br>
	return a+b;<br>
}
------------------------------------------
* Write a C++ code that does the following:
* You are not allowed to use any built-in functions except: <cstdlib>, <cstdio>, <cstring>, <iostream>, <stack>.
* You are not allowed to use string class, vector, or anything from STL libraries except <stack>.
* Convert the above function to a non-recursive function using the simulating recursion method using stack in Lecture04_Subprograms.
* Simulate recursion as specified in our lecture, without using any recursive call directly or indirectly.
* You are not allowed to use any other method than the method described in Lecture04_Subprograms applied to the above function.
* Your code must be general to handle all input values.
* Use your implementation of everything.
* Use only standard C++.
* You are not allowed to include any files or built-in libraries, except for output.
* Write at least 20 test case statements (F(1),F(2),..,F(20)) that make sure that your output matches the original function output.
* Half the mark is dedicatd to comments explaining the code before each code line, test cases, and following the CodingStyle.pdf file.
