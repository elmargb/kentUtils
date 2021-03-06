/* tr.h was originally generated by the autoSql program, which also 
 * generated tr.c and tr.sql.  This header links the database and the RAM 
 * representation of objects. */

#ifndef TR_H
#define TR_H

struct tomRough
/* Rough position of a disease gene */
    {
    struct tomRough *next;  /* Next in singly linked list. */
    int omimId;	/* OMIM database ID of gene */
    char *chromosome;	/* Short name of chromosome (Y not chrY) */
    char *startBand;	/* Starting band */
    char *endBand;	/* Ending band */
    char *description;	/* Descriptive sentence or two */
    };

void tomRoughStaticLoad(char **row, struct tomRough *ret);
/* Load a row from tomRough table into ret.  The contents of ret will
 * be replaced at the next call to this function. */

struct tomRough *tomRoughLoad(char **row);
/* Load a tomRough from row fetched with select * from tomRough
 * from database.  Dispose of this with tomRoughFree(). */

struct tomRough *tomRoughCommaIn(char **pS, struct tomRough *ret);
/* Create a tomRough out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new tomRough */

void tomRoughFree(struct tomRough **pEl);
/* Free a single dynamically allocated tomRough such as created
 * with tomRoughLoad(). */

void tomRoughFreeList(struct tomRough **pList);
/* Free a list of dynamically allocated tomRough's */

void tomRoughOutput(struct tomRough *el, FILE *f, char sep, char lastSep);
/* Print out tomRough.  Separate fields with sep. Follow last field with lastSep. */

#define tomRoughTabOut(el,f) tomRoughOutput(el,f,'\t','\n');
/* Print out tomRough as a line in a tab-separated file. */

#define tomRoughCommaOut(el,f) tomRoughOutput(el,f,',',',');
/* Print out tomRough as a comma separated list including final comma. */

#endif /* TR_H */

