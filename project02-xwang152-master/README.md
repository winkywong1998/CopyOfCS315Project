# project02-xwang152

Description:
This program will take in a decimal number, binary number or hexadecimal number and give a out put like following:

$ nt 713
0000 0000 0000 0000 0000 0010 1100 1001 (base 2) 
0b00000000000000000000001011001001 (base 2) 
0x000002C9 (base 16)
713 (base 10 unsigned)
713 (base 10 signed)

This program will also support two flags: -r and -b.

-b: The default bit width output for nt is 32. You can change this default with the -b option, the following bit widths that are multiples of 4: 4, 8, 12, 16, 20, 24, 28, 32.
-r: You can select the range of bits to use for conversion using the -r option

Examples:
1.No flag
$ nt 713
0000 0000 0000 0000 0000 0010 1100 1001 (base 2) 
0b00000000000000000000001011001001 (base 2) 
0x000002C9 (base 16)
713 (base 10 unsigned)
713 (base 10 signed)

2.-r & -b
$ ./nt -1 -b 4  -r 4,12
This is the normalization output: -1
1111 (base 2)
0b1111 (base 2)
0xF (base 16)
15 (base 10 unsigned)
-1 (base 10 signed)

-1 is the value that the program takes in. Since the bit-width is 4, the program will only print for digits for binary. Since the range is from 4 to 12, it will only take in the digit from index 4 to index 12.

Compile: gcc -Wall nt.c -o nt
Run:./nt value -r <start, end> -b <bit width>
