### Task

When compiling a program using gcc, one can use `-c`, `-S`, `-E` and `-o` flags. Write a small `C` program and demonstrate the use of these flags.

### Compiling and Linking

The GCC compiler chain works in the following fashion.

![GCC Compiling and Linking](https://www3.ntu.edu.sg/home/ehchua/programming/cpp/images/GCC_CompilationProcess.png)

#### `-E` flag

```
Stop after the preprocessing stage; do not run the compiler proper.  The output is in the form of preprocessed source code, which is sent to the standard output.
```

After using this flag on `main.c` file, the output generated is this:

```
# 1 "main.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "main.c"
# 1 "/usr/include/stdio.h" 1 3 4
# 27 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 367 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
# 410 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 411 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 368 "/usr/include/features.h" 2 3 4

...
```

In the image above, `-E` flag does only the "Preprocessing" part.

#### `-S` flag

```
Stop after the stage of compilation proper; do not assemble.  The output is in the form of an assembler code file for each non-assembler input file specified.

By default, the assembler file name for a source file is made by replacing the suffix .c, .i, etc., with .s.
```

This generates an assembly code. The use of this flag on `main.c` does the following:

```
	.file	"main.c"
	.section	.rodata
.LC0:
	.string	"Hello World!"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$.LC0, %edi
	call	puts
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
```

In the image about, `-S` flag means the process upto "Compilation" part.

#### `-c` flag

```
Compile or assemble the source files, but do not link.  The linking stage simply is not done.  The ultimate output is in the form of an object file for each source file.

By default, the object file name for a source file is made by replacing the suffix .c, .i, .s, etc., with .o.
```

This generates a file that is ready to be linked. After linking, the file can be executed. The output file generated is just binary data:

```
7f45 4c46 0201 0100 0000 0000 0000 0000
0100 3e00 0100 0000 0000 0000 0000 0000
0000 0000 0000 0000 a002 0000 0000 0000
0000 0000 4000 0000 0000 4000 0d00 0a00
5548 89e5 bf00 0000 00e8 0000 0000 b800
0000 005d c348 656c 6c6f 2057 6f72 6c64
2100 0047 4343 3a20 2855 6275 6e74 7520
352e 342e 302d 3675 6275 6e74 7531 7e31
362e 3034 2e34 2920 352e 342e 3020 3230
3136 3036 3039 0000 1400 0000 0000 0000
017a 5200 0178 1001 1b0c 0708 9001 0000
1c00 0000 1c00 0000 0000 0000 1500 0000
0041 0e10 8602 430d 0650 0c07 0800 0000
0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0100 0000 0400 f1ff
0000 0000 0000 0000 0000 0000 0000 0000

...
```

In the image above, `-c` flag is upto the "Assemble" part.

#### `-o` flag

```
Place output in file file.  This applies to whatever sort of output is being produced, whether it be an executable file, an object file, an assembler file or preprocessed C code.
```

If this flag is used without any other flag, it simple generates a compiled and linked executable. This is also just binary data, but the output file can be executed unlike `-c` flag.

In the image about, `-o` flag is upto the "Linking" part.