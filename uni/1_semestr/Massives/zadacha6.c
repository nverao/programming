#include <stdio.h>
#include <stdlib.h>

void Func(int* a, int na, int* b, int nb, int *c, int *nc){
    *nc = 0;
    for (int i = 0; i < na; i++) {
        int exist = 0;
        for(int j = 0; j < *nc; j++) {
            if (c[j] == a[i]) {
                exist = 1;
                break;
            }
        }
        if (exist) continue;

        for (int j = 0; j < nb; j++) {
            if (a[i] == b[j]) {
                c[*nc]=a[i];
                (*nc)++;
                break;
            }
        }
    }
}

int main(void){
    FILE *fi, *o;
    int s, avr;
    FILE *A,*B,*fo;
	int *a,*b,x,i,na,nb;
	A = fopen("a.txt", "r");
	if (fscanf(A, "%d", &na) != 1)
	{
		fprintf(stderr, "Can't read parameter `n` ...\n");
		fclose(A);
		return -1;
	}
	if (na < 1)
	{
		fprintf(stderr, "Wrong parameter `n` ...\n");
		fclose(A);
		return -1;
	}
	a = malloc(sizeof(int) * na);
	if (!a)
	{
		fprintf(stderr, "Memory allocation error ...\n");
		fclose(A);
		return -1;
	}
	for (i = 0; i < na; i++)
		if (fscanf(A, "%d", a + i) != 1)
		{
			fprintf(stderr, "Can't read element ...\n");
			fclose(A);
			free(a);
			return -1;
		}
	if (fscanf(A, "%d", &x) != EOF)
	{
        printf("%d", x);
		fprintf(stderr, "Wrong input data1 ...\n");
		fclose(A);
		free(a);
		return -1;
	}
	fclose(A);
	B = fopen("b.txt", "r");
	if (fscanf(B, "%d", &nb) != 1)
	{
		fprintf(stderr, "Can't read parameter `n` ...\n");
		fclose(B);
		free(a);
		return -1;
	}
	if (nb < 1)
	{
		fprintf(stderr, "Wrong parameter `n` ...\n");
		fclose(B);
		free(a);
		return -1;
	}
	b = malloc(sizeof(int) * nb);
	if (!b)
	{
		fprintf(stderr, "Memory allocation error ...\n");
		fclose(B);
		free(a);
		return -1;
	}
	for (i = 0; i < nb; i++)
		if (fscanf(B, "%d", b + i) != 1)
		{
			fprintf(stderr, "Can't read element ...\n");
			fclose(B);
			free(b);
			free(a);
			return -1;
		}
	if (fscanf(B, "%d", &x) != EOF)
	{
		fprintf(stderr, "Wrong input data2 ...\n");
		fclose(B);
		free(a);
		free(b);
		return -1;
	}
	fclose(B);
	
    int nc;
    if (nb < na) nc = nb;
    else nc = na;

	int *c = malloc(sizeof(int) * nc); 
	if (!c)
	{
		fprintf(stderr, "Memory allocation error ...\n");
		free(a);
        free(b);
		return -1;
	}

	Func(a, na, b, nb, c, &nc);

	fo = fopen("output6.txt", "w");
	if (!fo)
	{
        free(a);
        free(b);
		fprintf(stderr, "Can't open output.txt ...\n");
		return -1;
	}
	fprintf(fo, "%d\n", nc);
    for (int i = 0; i < nc; i++) {
	    fprintf(fo, "%d ", c[i]);
    }
	fclose(fo);
    free(a);
    free(b);
    free(c);
	
    return 0;

}