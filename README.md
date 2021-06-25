# Percy

**PercyCompiler** is a simple compiler implemented with Lex and Yacc for the language **PercyLenguage**. Which is a strongly-typed language that uses a syntax similar to Javascript. This language allows you to generate exportable .html files from simple instructions


## Authors

- [Francisco Bernad](https://github.com/FrBernad)
- [Nicolás Rampoldi](https://github.com/NicolasRampoldi) 
- [Agustín Manfredi](https://github.com/imanfredi)
- [Joaquín Legammare](https://github.com/JoacoLega)


The report can be found in the root directory under the name `informe.pdf`.

## Compilation

To generate the executables and non-source files of the project, we dicided to use the GNU make tool. Standing on the root project folder run the command `make all` to compile. This will ejecute Lex, Yacc and will make the compilation of the genereated files afterwards.

Also you can clean all the generated files by the `make all` command by running `make clean`.

## How to use it ?

        ./percy [OPTION]
                OPTION:
                    -h                                 Prints the help and finishes.
                    -v                                 Prints the version and finishes.
                    -i <input-file>                    Sets the file to process.
                    -o <output-file>                   Sets the output result file. The default is 'a.percyout',


## Examples

In `/examples` directory you will find some examples of the PercyLenguaje syntax and the functionality of the PercyCompiler:

- `do_while_example.percy` : shows the syntax of the "do while" cycle and how it works. It renders an html tag , and three navbars in the .html file.

- `even_numbers_example.percy` : is a little implementation of a program that renders an html tag with the even numbers that are included in the range [0-6] in the .html file.

- `or_example.percy` :  shows the syntax of the "for" cycle and how it works. It renders an html tag , and three navbars in the .html file.

- `if_example.percy `: shows a simple example to display the syntax of an if statement.

- `while_example.percy`: shows the syntax of the "while" cycle and how it works. It renders an html tag , and three navbars in the .html file.

## Libraries

The only library used in the project that was not made by the developer team and needs to be mentioned is [Khash](https://github.com/attractivechaos/klib/blob/master/khash.h).

