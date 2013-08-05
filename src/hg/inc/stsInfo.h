/* stsInfo.h was originally generated by the autoSql program, which also 
 * generated stsInfo.c and stsInfo.sql.  This header links the database and
 * the RAM representation of objects. */

#ifndef STSINFO_H
#define STSINFO_H

struct stsInfo
/* Constant STS marker information */
    {
    struct stsInfo *next;  /* Next in singly linked list. */
    unsigned identNo;	/* UCSC identification number */
    char *name;	/* Official UCSC name */
    unsigned gbCount;	/* Number of related GenBank accessions */
    char **genbank;	/* Related GeneBank accessions */
    unsigned gdbCount;	/* Number of related GDB identifiers */
    char **gdb;	/* Related GDB identifies */
    unsigned nameCount;	/* Number of alias names */
    char **otherNames;	/* Alias names */
    unsigned dbSTSid;	/* ID number in UniSTS or dbSTS */
    unsigned otherDbstsCount;	/* Number of related dbSTS IDs */
    unsigned *otherDbSTS;	/* Related dbSTS IDs */
    char *leftPrimer;	/* 5' primer sequence */
    char *rightPrimer;	/* 3' primer sequence */
    char *distance;	/* Length of STS sequence */
    char *organism;	/* Organism for which STS discovered */
    unsigned sequence;	/* Whether the full sequence is available (1) or not (0) for STS */
    unsigned otherUCSCcount;	/* Number of related active UCSC ids */
    unsigned *otherUCSC;	/* Related active UCSC ids */
    unsigned mergeUCSCcount;	/* Number of merged inactive UCSC ids */
    unsigned *mergeUCSC;	/* Related merged inactive UCSC ids */
    char *genethonName;	/* Name in Genethon map */
    char *genethonChr;	/* Chromosome in Genethon map */
    float genethonPos;	/* Position in Genethon map */
    float genethonLOD;	/* LOD score in Genethon map */
    char *marshfieldName;	/* Name in Marshfield map */
    char *marshfieldChr;	/* Chromosome in Marshfield map */
    float marshfieldPos;	/* Position in Marshfield map */
    float marshfieldLOD;	/* LOD score in Marshfield map */
    char *wiyacName;	/* Name in WI YAC map */
    char *wiyacChr;	/* Chromosome in WI YAC map */
    float wiyacPos;	/* Position in WI YAC map */
    float wiyacLOD;	/* LOD score in WI YAC map */
    char *wirhName;	/* Name in WI RH map */
    char *wirhChr;	/* Chromosome in WI RH map */
    float wirhPos;	/* Position in WI RH map */
    float wirhLOD;	/* LOD score in WI RH map */
    char *gm99gb4Name;	/* Name in GeneMap99 GB4 map */
    char *gm99gb4Chr;	/* Chromosome in GeneMap99 GB4 map */
    float gm99gb4Pos;	/* Position in GeneMap99 GB4 map */
    float gm99gb4LOD;	/* LOD score in GeneMap99 GB4 map */
    char *gm99g3Name;	/* Name in GeneMap99 G3 map */
    char *gm99g3Chr;	/* Chromosome in GeneMap99 G3 map */
    float gm99g3Pos;	/* Position in GeneMap99 G3 map */
    float gm99g3LOD;	/* LOD score in GenMap99 G3 map */
    char *tngName;	/* Name in Stanford TNG map */
    char *tngChr;	/* Chromosome in Stanford TNG map */
    float tngPos;	/* Position in Stanford TNG map */
    float tngLOD;	/* LOD score in Stanford TNG map */
    };

struct stsInfo *stsInfoLoad(char **row);
/* Load a stsInfo from row fetched with select * from stsInfo
 * from database.  Dispose of this with stsInfoFree(). */

struct stsInfo *stsInfoLoadAll(char *fileName);
/* Load all stsInfo from a tab-separated file.
 * Dispose of this with stsInfoFreeList(). */

struct stsInfo *stsInfoCommaIn(char **pS, struct stsInfo *ret);
/* Create a stsInfo out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new stsInfo */

void stsInfoFree(struct stsInfo **pEl);
/* Free a single dynamically allocated stsInfo such as created
 * with stsInfoLoad(). */

void stsInfoFreeList(struct stsInfo **pList);
/* Free a list of dynamically allocated stsInfo's */

void stsInfoOutput(struct stsInfo *el, FILE *f, char sep, char lastSep);
/* Print out stsInfo.  Separate fields with sep. Follow last field with lastSep. */

#define stsInfoTabOut(el,f) stsInfoOutput(el,f,'\t','\n');
/* Print out stsInfo as a line in a tab-separated file. */

#define stsInfoCommaOut(el,f) stsInfoOutput(el,f,',',',');
/* Print out stsInfo as a comma separated list including final comma. */

#endif /* STSINFO_H */
