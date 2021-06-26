## Authors

- [Francisco Bernad](https://github.com/FrBernad)
- [Nicolás Rampoldi](https://github.com/NicolasRampoldi) 
- [Agustín Manfredi](https://github.com/imanfredi)
- [Joaquín Legammare](https://github.com/JoacoLega)

The report can be found in the root directory under the name [informe.pdf](https://github.com/FrBernad/PERCY-PROJECT/blob/main/informe.pdf)

# Percy

**PercyCompiler** is a simple compiler implemented with Lex and Yacc for the **PercyLenguage** language. The **PercyLenguage** is a ***strongly-typed*** language that uses a syntax similar to javascript. This language allows you to generate simple ***static html*** files.

## Compilation

To generate the ***compiler executable***, standing on the root project folder run the command `make all`. This will generate the ***percy*** compiler executable.
To ***remove*** all the generated files, run the `make clean` command.

## How to use it ?

        ./percy [OPTION]
                OPTION:
                    -h                                 Prints the help and finishes.
                    -v                                 Prints the version and finishes.
                    -i <input-file>                    Sets the file to process, must have the '.percy' extension.
                    -o <output-file>                   Sets the output result file. The default is 'a.percyout'.


## Examples

In the `/examples` directory you can find some examples of the PercyLenguaje syntax and functionality:

- `do_while_example.percy`: shows the syntax and functionality of the "do while" cycle.

- `even_numbers_example.percy`: this file renders the first 6 even numbers.

- `for_example.percy`: shows the syntax and functionality of the "for" cycle.

- `if_example.percy `: shows the syntax and functionality of the "if-else" statement.

- `while_example.percy`: shows the syntax and functionality of the "while" cycle.

## Libraries

- [Khash](https://github.com/attractivechaos/klib/blob/master/khash.h)

