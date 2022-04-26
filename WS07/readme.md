# Workshop #7: Derived Classes

In this workshop, you will work with classes that make up a hierarchical structure. The base or parent class will be called `Container` that encapsulates a Container with a specific capacity in CCs, then the child class `Pack` that is a Container of several smaller units (like 24 Cans of soup or 12 bottles of Wine). In addition to this hierarchy, we will define custom input/output operators for these classes.


## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- Inherit a derived class from a base class
- Shadow the base class member functions with the derived class member functions
- Access shadowed member functions that are defined in a base class
- Utilize custom input/output operators with these classes
- Describe to your instructor what you have learned in completing this workshop



## Submission Policy


The workshop is divided into one coding part and one non-coding part:

- Part 1: worth 100% of the workshop's total mark, is due on **Thursday at 23:59:59** of the week of your scheduled lab.
- Part 2 (reflection): non-coding part, is due on **Sunday at 23:59:59** of the week of your scheduled lab. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

**The code that is submitted late receives 0%.**  
On Sunday at midnight the submission closes; if the workshop is incomplete when the submission closes (missing at least one of the coding or non-coding parts), **the mark for the entire workshop is 0%**.

## Citation

Every file that you submit must contain (as a comment) at the top:<br />
**your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

### For work that is done entirely by you (ONLY YOU)

If the file contains only your work or the work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

### For work that is done partially by you.

If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrongdoing.

> - Add the citation to the file in which you have the borrowed code
> - In the 'reflect.txt` submission of part 2 (DIY), add exactly what is added to which file and from where (or whom).

> :warning: This [Submission Policy](#submission-policy) only applies to the workshops. All other assessments in this subject have their own submission policies.

### If you have helped someone with your code

If you have helped someone with your code. Let them know of these regulations and in your 'reflect.txt' of part 2 (DIY), write exactly which part of your code was copied and who was the recipient of this code.<br />By doing this you will be clear of any wrongdoing if the recipient of the code does not honour these regulations.


## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as following to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind -s --leak-check=full ws
```

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> Note: All the code written in workshops and the project must be implemented in the **sdds** namespace.

# lab (part 1) (100%)


## The `Container` Module

Create a class called **Container** holding three attributes identifying a container.

### Attributes
- **Content:** a Cstring with a maximum of 50 characters holding the description of what the container is holding.
- **Capacity:** The maximum amount a container can hold in CCs.
- **Content volume:** The current amount the container is holding. Obviously, this value can not exceed the capacity.

### Construction
A Container can be created using either two or three arguments; **content**, **capacity** and **content volume** or only the first two, in which case the **content volume** is set to zero.

The container will be rendered invalid if the content description is null or the content volume exceeds the capacity. 

### Protected modifier and queries: (only accessible by derived classes)

#### setEmpty
Sets the Container to an invalid empty state

#### capacity
returns the capacity of the container

#### volume
returns the content volume of the container

### Public

#### Operations

##### operator+=
A value can be added to the Container. If the container has enough space for the value, it will be added to the  **content volume**. If not, only a portion of value will be added to fill the container to its capacity. 

This operation will return the actual amount that is added to the container. 

```text
Example 1:
Container C has a capacity of 1000 and a content volume of 700;
C+=200;
Will add 200 to the container setting the volume to 900 and return 200.
Example 2:
Container C has a capacity of 1000 and a content volume of 700;
C+=500;
Will add 300 to the container setting the volume to 1000 and return 300.
```

##### operator-=
A value can be deducted from the Container. If the container has enough amount, it will reduce the  **content volume** by the value. If not, the container will be emptied. 

This operation will return the actual reduced amount. 

```text
Example 1:
Container C has a capacity of 1000 and a content volume of 700;
C-=200;
Will reduce the content volume to 500 and return 200.
Example 2:
Container C has a capacity of 1000 and a content volume of 700;
C-=900;
Will empty the container and return 700.
```

##### bool type conversion.
Returns true if the Container is in a valid state or false if it is not.

#### Methods

### clear
Accepts two arguments: the capacity and the content description. If the capacity is a positive value and the content description is a valid cString, it will set the corresponding attributes and therefore making the Container valid.

### print
Receiving and returning an ostream reference, the print will display a valid container as follows:
```text
ABC: (XXcc/YY)
```
- ABC is the content description
- XX is the content volume
- YY is the capacity

Printing an invalid container will result in printing the following:<br />
`"****: (**cc/***)"`

### read
Receiving and returning an istream reference, read will get an amount to be added to the container as follows:

If the container is invalid it will print the following message and then exits the read function after the Enter key is pressed.<br />
`"Broken Container, adding aborted! Press <ENTER> to continue...."`

If the container is valid it will print the container, go to newline and print the prompt: `"> "`<br />
Then in a foolproof integer entry, it will receive an integer value between 1 and 220000 and add it to the container printing the message:<br />
`Added 999 CCs<NEWLINE>`<br />
**999** is the amount successfully added to the container using the += operator.

Fool-proof integer-entry error messages are as follows:  
- `"Invalid Integer, retry: "` if an invalid integer was entered
- `"Value out of range [1<=val<=999]: "` where **999** is the maximum acceptable value if an out of range integer is entered

### Insertions and extraction helper operator overloads
Overload operator<< and operator>> to be able to print and read A container using cout and cin.

## the `Pack` Module

A **Pack** class is a Container that holds a series of smaller **unit**s (like Cans of beverages or bottles of water).  Each unit (i.e can, bottle,...) will have a size of its own in CCs and therefore the capacity of the whole Pack is the sum of the size of all the units in it. 

Create a class called **Pack** out of a container that holds an additional attribute for the size (or capacity) of one of the units it holds. 

### Attribute
- **unitSize** is the capacity of one of the units in the Pack. (example: 330 CC for a can of coke, or 250 CC for a bottle of water)

> This attribute will be used in combination with the attributes of the Container to calculate the following:
>- **Size** of the Pack is **the capacity of container/unit size**
>- Number of units currently in the pack is **the content volume of the container/unit size**

### Construction
A Pack can be created using either two, three or four arguments (Using one constructor): 
- **content description** (same as container) 
- **size:** The maximum number of units the Pack can hold
- **unit size:** The capacity of each unit in the pack in CCs, defaulted to 330.
- **Number of units:** The number of units in the pack to the maximum of the **size** of the pack. Defaulted to **0**

Example: A Pack of 12, 250cc bottles of water with 3 of the bottles missing will have the following arguments in the constructor:
```Text
Content description: "Water Bottle"
size: 12
unit size: 250
number of units: 9
```

**Implementation**:

Initialize the Base Container class with:
- content description (directly passed to the container constructor)
- capacity (size * unit size)
- content volume (number of units * unit size)

Then validate the Pack only with the value of the unit size argument (since Container has the validation of its own); if the unit size argument is greater than zero, then set the attribute. Otherwise set the Pack to an empty state by calling the Base classes setEmpty function.


### Public

#### Operations

##### operator+=
Overrides (shadows) the operator+= of the Base class <br />
Receives a number to add units to the pack and returns the number of units successfully added. 

```text
Example 1:
P is a 12 Pack of Pepsi holding 7 cans
n = P += 2;
Now the Pack will have 9 cans and is missing 3 cans. n will hold 2. 
Example 2:
P is a 12 Pack of Pepsi holding 7 cans
n = P += 7;
Now the Pack will have 12 cans and is full. n will hold 5. 
```
**Implementation:**
Call the operator+= of the Bass class by passing the product of the argument multiplied to the unit size attribute.<br />Return the outcome of the base's operator+= divided by the unit size attribute.

##### operator-=
Overrides (shadows) the operator-= of the Base class <br />
Receives a number to remove units from the pack and returns the number of units successfully removed. 

```text
Example 1:
P is a 12 Pack of Pepsi holding 7 cans
n = P -= 3;
Now the Pack will have 4 cans and is missing 8 cans. n will hold 3. 
Example 2:
P is a 12 Pack of Pepsi holding 7 cans
n = P -= 9;
Now the Pack will be empty. n will hold 7. 
```
**Implementation:**
Call the operator-= of the Bass class by passing the product of the argument multiplied to the unit size attribute.<br />Return the outcome of the base's operator-= divided by the unit size attribute.


#### Queries

##### unit
returns the unit size attribute

##### noOfUntis 
returns the content volume of the Base class divided by the unit size

##### size
return the capacity of the base class divided by the unit size

#### Methods

### clear
Overloads the clear function of the Base class <br />
Accepts three arguments: **the Pack size**, **the unit size** and **the content description**. If the unit size is greater than zero it will call the clear of the base class passing **the product of pack size and the unit size** and **the content description**. Then it will set the unit size attribute to the unit size argument.

### print
Overrides (shadows) the print of the Base class <br />
Receiving and returning an ostream reference, the print will display a valid Pack as follows:

It will call the print of the base class, then if the current object is valid it will print: `", XX in a pack of YY"`, where **XX** is the number of units and **YY** is the pack size;

### read
Overrides (shadows) the read of the Base class <br />
Receiving and returning an istream reference, read will get a number for the count of the units to be added to the pack if the pack is valid and not full as follows:

If the container is invalid it will print the following message and then exits the read function after the Enter key is pressed.<br />
`"Broken Container, adding aborted! Press <ENTER> to continue...."`

If the container is valid then it will check if the number if units in the pack is less than size of the pack

- If true it will print the pack, go to newline and print the prompt: `"> "`<br />
Then in a foolproof integer entry, it will receive an integer value between 1 and the number of missing units of the pack. Then it will add the number to the pack using operator+= and prints the message:<br />
`Added 99<NEWLINE>`<br />
**99** is the number of units successfully added to the pack using the += operator.
- If false it will print the following message and then exits the read function after the Enter key is pressed.<br />
`"Pack is full!, press <ENTER> to continue..."`

Fool-proof integer-entry error messages are as follows:  
- `"Invalid Integer, retry: "` if an invalid integer was entered
- `"Value out of range [1<=val<=99]: "` where **99** is the number of missing units in the pack.



### Insertions and extraction helper operator overloads
Overload operator<< and operator>> to be able to print and read A Pack using cout and cin.



## Tester Program
```C++
/* ------------------------------------------------------
Workshop 7 part 1
Module: N/A
Filename: main.cpp
Version 1
Author: Fardad Soleimanloo  22/03/12
Revision History
-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/
#include <iostream>
#include "Container.h"
#include "Pack.h"
using namespace std;
using namespace sdds;
void ContainerTest();
void PackTest();

int main() {
   ContainerTest();
   PackTest();
}

void PackTest() {
   Pack P("Pepsi", 24);
   Pack W("Tomato Paste", 10, 150, 12);
   cout << "Pack Tester........................." << endl;
   cout << P << endl;
   cout << "Added " << (P += 14) << " cans of " << P.unit() << " CCs" << endl;
   cout << P << endl;
   cout << "Added " << (P += 14) << " cans of " << P.unit() << " CCs" << endl;
   cout << P << endl;
   cout << "Removed " << (P -= 14) << " cans of " << P.unit() << " CCs" << endl;
   cout << P << endl;
   cout << "Removed " << (P -= 14) << " cans of " << P.unit() << " CCs" << endl;
   cout << endl << "Enter 14" << endl;
   cin >> P;
   cout << P << endl;
   cout << endl << "Enter 14 and then 10" << endl;
   cin >> P;
   cout << P << endl;
   cin >> P;
   cin >> W;
   W.clear(12, 750, "Wine");
   W += 5;
   cout << W << endl;
}
void ContainerTest() {
   Container Bad("Bad one!", 200, 300);
   Container C("Milk", 250);
   cout << "Container Tester........................." << endl;
   cout << C << endl;
   cout << Bad << endl;
   cout << "Adding " << (C += 200) << " CCs" << endl;
   cout << C << endl;
   cout << "Adding another " << (C += 200) << " CCs" << endl;
   cout << C << endl;
   cout << "Removing " << (C -= 200) << " CCs" << endl;
   cout << C << endl;
   cout << "Removing another " << (C -= 200) << " CCs" << endl;
   cout << C << endl;
   cout << endl << "Enter 222" << endl;
   cin >> C;
   cout << C << endl;
   cout << endl << "Enter 222" << endl;
   cin >> C;
   cout << C << endl;
   cin >> Bad;
   Bad.clear(200, "Water");
   Bad += 150;
   cout << Bad << endl;
}
```
## Execution Sample
```text
Container Tester.........................
Milk: (0cc/250)
****: (**cc/***)
Adding 200 CCs
Milk: (200cc/250)
Adding another 50 CCs
Milk: (250cc/250)
Removing 200 CCs
Milk: (50cc/250)
Removing another 50 CCs
Milk: (0cc/250)

Enter 222
Add to Milk: (0cc/250)
> 222
Added 222 CCs
Milk: (222cc/250)

Enter 222
Add to Milk: (222cc/250)
> 222
Added 28 CCs
Milk: (250cc/250)
Broken Container, adding aborted! Press <ENTER> to continue....
Water: (150cc/200)
Pack Tester.........................
Pepsi: (0cc/7920), 0 in a pack of 24
Added 14 cans of 330 CCs
Pepsi: (4620cc/7920), 14 in a pack of 24
Added 10 cans of 330 CCs
Pepsi: (7920cc/7920), 24 in a pack of 24
Removed 14 cans of 330 CCs
Pepsi: (3300cc/7920), 10 in a pack of 24
Removed 10 cans of 330 CCs

Enter 14
Add to Pepsi: (0cc/7920), 0 in a pack of 24
> 14
Added 14
Pepsi: (4620cc/7920), 14 in a pack of 24

Enter 14 and then 10
Add to Pepsi: (4620cc/7920), 14 in a pack of 24
> 14
Value out of range [1<=val<=10]: 10
Added 10
Pepsi: (7920cc/7920), 24 in a pack of 24
Pack is full!, press <ENTER> to continue...
Broken Container, adding aborted! Press <ENTER> to continue....
Wine: (3750cc/9000), 5 in a pack of 12

```
## PART 1 Submission (lab)

### Files to submit:  

```Text
Container.cpp
Container.h
Pack.cpp
Pack.h
main.cpp
```
#### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in this workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.

### Data Entry

Follow the instructions in the tester program

### Submission Process:

Upload your the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account
- replace `profname.proflastname` with your professor’s Seneca userid
- replace **??** with your subject code (2**00** or 2**44**)
- replace **#** with the workshop number
- replace **X** with the workshop part number (**1** or **2**) 
```text
~profname.proflastname/submit 2??/w#/pX
```
and follow the instructions.

#### Submitting Utils Module
To have your Utils module compiled with your workshop and submitted, add a **u** to the part number of your workshop (i.e **u**p1 for part one and **u**p2 for part two) and issue the following submission command instead of the above:
```text
~profname.proflastname/submit 2??/w#/upX
```
See [Custom Code Submission](#custom-code-submission) section for more detail

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.





# PART2: Reflection

Study your final solutions for each deliverable of the workshop **and the most recent milestones of the project**, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and **the project milestones** and mention any issues that caused you difficulty.


## Reflection Submission (part 2)


Upload the **reflect.txt** to your `matrix` account. 

Then, run the following command from your account
- replace `profname.proflastname` with your professor’s Seneca userid
- replace **??** with your subject code (2**00** or 2**44**)
- replace **#** with the workshop number
- replace **X** with the workshop part number (**1** or **2**) 
```text
~profname.proflastname/submit 2??/w#/pX
```

and follow the instructions.

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.
