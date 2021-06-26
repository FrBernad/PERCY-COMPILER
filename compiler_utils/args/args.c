#include "args.h"

#include <errno.h>
#include <getopt.h>
#include <stdio.h>  /* for printf */
#include <stdlib.h> /* for exit */
#include <string.h> /* memset */

static void
version(void) {
    fprintf(stderr,
            "PERCY parser version 1.0\n"
            "ITBA TLA 2021/1\n");
}

static void
usage(char *progname) {
    fprintf(stderr,
            "Usage: %s [OPTION]...\n"
            "Options:\n"
            "   -h                                 Prints the help and finishes.\n\n"
            "   -v                                 Prints the version and finishes.\n\n"
            "   -i <input-file>                    Sets the file to process, must have the '.percy' extension.\n\n"
            "   -o <output-file>                   Sets the output result file. The default is 'a.percyout'\n",
            progname);

    exit(1);
}

void parse_args(int argc, char **argv, struct percy_args *args) {
    memset(args, 0, sizeof(*args));

    args->file_in = NULL;
    args->file_out= "a.percyout";

    int c;

    while (true) {
        int option_index = 0;

        c = getopt_long(argc, argv, "vhi:o:", NULL, &option_index);
        if (c == -1)
            break;

        switch (c) {
            case 'v':
                version();
                exit(0);
                break;
            case 'h':
                usage(argv[0]);
                break;
            case 'i':
                args->file_in = optarg;
                break;
            case 'o':
                args->file_out = optarg;
                break;
         
            default:
                fprintf(stderr, "unknown argument %d.\n", c);
                exit(1);
        }
    }
    if (optind < argc) {
        fprintf(stderr, "argument not accepted: ");
        while (optind < argc) {
            fprintf(stderr, "%s ", argv[optind++]);
        }
        fprintf(stderr, "\n");
        exit(1);
    }
}
