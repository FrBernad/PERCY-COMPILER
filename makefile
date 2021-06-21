include makefile.inc
include source_dirs.inc

CFLAGS+=-I$(CURDIR)

SOURCES_C_LEX=lex.yy.c
SOURCES_C_YACC=y.tab.c
HEADER_C_YACC=y.tab.h

SOURCES_LEX=percy_project.l
SOURCES_YACC=percy_project.y

SOURCES_FILES=$(foreach dir,$(SOURCE_DIRS),$(wildcard $(dir)/*.c))
OBJECTS_FILES=$(SOURCES_FILES:.c=.o)

EXECUTABLE_COMPILER=percy

#MAIN DIRECTIVES
all: $(EXECUTABLE_COMPILER) 

$(EXECUTABLE_COMPILER): $(SOURCES_C_LEX) $(SOURCES_C_YACC) $(OBJECTS_FILES)
	$(CC) $(CFLAGS) $^ -o $@

$(SOURCES_C_LEX): $(SOURCES_LEX)
	flex $<

$(SOURCES_C_YACC): $(SOURCES_YACC)
	yacc -d -Wcounterexamples $<

#CLEAN DIRECTIVES
clean:
	rm -rf $(EXECUTABLE_COMPILER) $(SOURCES_C_YACC) $(SOURCES_C_LEX) $(HEADER_C_YACC) $(OBJECTS_FILES)

cleanTest: clean
	rm -rf test_results

.PHONY: all clean
