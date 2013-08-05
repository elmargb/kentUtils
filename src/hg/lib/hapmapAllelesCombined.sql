# hapmapAllelesCombined.sql was originally generated by the autoSql program, which also 
# generated hapmapAllelesCombined.c and hapmapAllelesCombined.h.  This creates the database representation of
# an object which can be loaded and saved from RAM in a fairly 
# automatic way.

#HapMap allele counts by population
CREATE TABLE hapmapAllelesCombined (
    bin int unsigned not null,  # For browser speed up
    chrom varchar(255) not null,	# Chromosome
    chromStart int unsigned not null,	# Start position in chrom (0 based)
    chromEnd int unsigned not null,	# End position in chrom (1 based)
    name varchar(255) not null,	# Reference SNP identifier from dbSnp
    score int unsigned not null,	# Use for heterozygosity
    strand enum ('+', '-', '?') default '?' not null,	# Which genomic strand contains the observed alleles
    observed varchar(255) not null,	# Observed string from genotype file
    allele1 enum('A', 'C', 'G', 'T')  not null,	# This allele has been observed
    allele1CountCEU int unsigned not null,	# allele1 count for the CEU population
    allele1CountCHB int unsigned not null,	# allele1 count for the CHB population
    allele1CountJPT int unsigned not null,	# allele1 count for the JPT population
    allele1CountYRI int unsigned not null,	# allele1 count for the YRI population
    allele2 enum ('C', 'G', 'T', 'none') not null,	# This allele may not have been observed
    allele2CountCEU int unsigned not null,	# allele2 count for the CEU population
    allele2CountCHB int unsigned not null,	# allele2 count for the CHB population
    allele2CountJPT int unsigned not null,	# allele2 count for the JPT population
    allele2CountYRI int unsigned not null,	# allele2 count for the YRI population
    heteroCountCEU int unsigned not null,	# Count of CEU individuals who are heterozygous
    heteroCountCHB int unsigned not null,	# Count of CHB individuals who are heterozygous
    heteroCountJPT int unsigned not null,	# Count of JPT individuals who are heterozygous
    heteroCountYRI int unsigned not null	# Count of YRI individuals who are heterozygous
);