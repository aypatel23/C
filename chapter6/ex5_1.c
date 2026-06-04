/*Table lookup program from 6.6*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define HASHSIZE 101

struct nlist { /* table entry: */
	struct nlist *next; /* next entry in chain */
	char *name; /* defined name */
	char *defn; /* replacement text */
};


static struct nlist *hashtab[HASHSIZE]; /* pointer table */

unsigned hash(char *s);
struct nlist *lookup(char *);
struct nlist *install(char *name, char *defn);

int main(void)
{
	struct nlist *entry;

	printf("---Hash Table---\n");
	install("IN", "1");
	install("MAXWORD", "100");
	install("SIZE", "100");

	/*Test lookups*/
	printf("---Testing Lookups---\n");

	if ((entry = lookup("IN")) != NULL)
		printf("found: %s -> %s\n", entry->name, entry->defn);
	else
		printf("entry not found\n");

	if ((entry = lookup("SIZE")) != NULL)
		printf("found: %s -> %s\n", entry->name, entry->defn);

	/* test updating  value of size */
	printf("New value\n");
	install("SIZE", "50");

	if ((entry = lookup("SIZE")) != NULL)
		printf("Updated value: %s -> %s\n", entry->name, entry->defn);

	return 0;
}



/* hash: form hash value for string s */
unsigned hash(char *s)
{
	unsigned hashval;
	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
	struct nlist *np;
	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np; /* found */
	return NULL; /* not found */
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;
	if ((np = lookup(name)) == NULL) { /* not found */
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else /* already there */
		free((void *) np->defn); /*free previous defn */
	if ((np->defn = strdup(defn)) == NULL)
		return NULL;
	return np;
}
