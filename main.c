#include <stdio.h>
#include <stdlib.h>

typedef struct book{
  char book_name[30];
  char author_name[30];
  char publisher[20];
  int year;
  float price;
} bk;

void func1(FILE *i);
void func2(FILE *i);
void func3(FILE *i);
void func4(FILE *i);
void func5(FILE *i);

int main()
{
    FILE *i;
    int num;

    if((i = fopen("HUST.txt","w+")) == NULL){
        printf("Error opening files");
        return 1;
    }

    printf("--------------------------------------------------\n");
    printf("--------------------------------------------------\n");
    printf("1.Enter information of n books of HUST\n");
    printf("2.Print the information of the entered books on the screen\n");
    printf("3.Sort descending information by year of publication and display\n");
    printf("4.Search for books by title\n");
    printf("5.Search books author's name\n");
    printf("6.Exit\n");
    printf("--------------------------------------------------\n");
    printf("--------------------------------------------------\n\n");

    printf("Enter a number: ");
    scanf("%d", &num);
    printf("\n");

    while(num != 6){
        if(num == 1){
            func1(i);
        }

        if(num == 2){
            func2(i);
        }

        if(num == 3){
            func3(i);
        }

        if(num == 4){
            func4(i);
        }

        if(num == 5){
            func5(i);
        }

        printf("Enter a number: ");
        scanf("%d", &num);
    }

    fclose(i);

    return 0;
}

void func1(FILE *i){
    int n, j;
    bk b1;

    printf("Enter the number of books: ");
    scanf("%d", &n);
    fprintf(i, "%d\n", n);

        for(j = 0; j < n; j++){
                printf("Enter book's name: ");
                scanf("%s", b1.book_name);
                printf("Enter author's name: ");
                scanf("%s", b1.author_name);
                printf("Enter publisher's name: ");
                scanf("%s", b1.publisher);
                printf("Enter year of publivation: ");
                scanf("%d", &b1.year);
                printf("Enter bookselling price: ");
                scanf("%f", &b1.price);
                printf("\n");

                fprintf(i,"%s\n", b1.book_name);
                fprintf(i, "%s\n", b1.author_name);
                fprintf(i, "%s\n", b1.publisher);
                fprintf(i, "%d\n%f\n\n", b1.year, b1.price);
           }
    printf("\n\n");
}

void func2(FILE *i){

    int n, j;
    bk b2;

    fseek(i, 0, SEEK_SET);
    fscanf(i, "%d", &n);
    printf("%d\n", n);
    printf("\n");

        for(j = 0; j < n; j++){
            fscanf(i, "%s", b2.book_name);
            fscanf(i, "%s", b2.author_name);
            fscanf(i, "%s", b2.publisher);
            fscanf(i,"%d", &b2.year);
            fscanf(i, "%f", &b2.price);

            printf("%30s", b2.book_name);
            printf("%30s", b2.author_name);
            printf("%20s", b2.publisher);
            printf("%10.d", b2.year);
            printf("%10.f\n", b2.price);
        }
            printf("\n\n");
}

void func3(FILE *i){
    int j, k, n;

    fseek(i, 0, SEEK_SET);
    fscanf(i, "%d", &n);

    bk b[n], temp;

    for(j = 0; j < n; j++){
        fscanf(i, "%s", b[j].book_name);
        fscanf(i, "%s", b[j].author_name);
        fscanf(i, "%s", b[j].publisher);
        fscanf(i, "%d", &b[j].year);
        fscanf(i, "%f", &b[j].price);
    }

    for(k = 0; k < n; k++){
        for(j = k + 1; j < n; j++){
            if((b[k].year < b[j].year) ||( (b[k].year = b[j].year) && (b[k].price < b[j].price) ) ){
                temp = b[k];
                b[k] = b[j];
                b[j] = temp;
            }
        }
    }

    printf("%d", n);
    for(k = 0; k < n; k ++){
        printf("%30s", b[k].book_name);
        printf("%30s", b[k].author_name);
        printf("%20s", b[k].publisher);
        printf("%10.d", b[k].year);
        printf("%10.f\n", b[k].price);
    }

    FILE *o;
    if((o= fopen("HUST2021.txt", "w+")) == NULL)
        printf("Error opening file");

    fprintf(o, "%d\n", n);
    for(k = 0; k < n; k ++){
        fprintf(o, "%30s", b[k].book_name);
        fprintf(o, "%30s", b[k].author_name);
        fprintf(o, "%20s", b[k].publisher);
        fprintf(o, "%10.d", b[k].year);
        fprintf(o, "%10.f\n", b[k].price);
    }

    printf("\n\n");
    fclose(o);

}

void func4(FILE *i){
    char name[30];
    int j, count, n;
    bk b2;

            printf("Enter book's name: ");
            scanf("%s", name);

            count = 0;
            fseek(i, 0, SEEK_SET);
            fscanf(i, "%d", &n);

            for(j = 0; j < n; j++){
                fscanf(i, "%s", b2.book_name);
                fscanf(i, "%s", b2.author_name);
                fscanf(i, "%s", b2.publisher);
                fscanf(i,"%d", &b2.year);
                fscanf(i, "%f", &b2.price);

            if(strcmp(name, b2.book_name) == 0){
                count++;
                printf("%s,", b2.book_name);
                printf("%s,", b2.author_name);
                printf("%s.\n", b2.publisher);
            }
            }

            if(count == 0)
                printf("No book is found\n");

            printf("\n\n");
}

void func5(FILE *i){
    char name[30];
    int n, j, count;
    bk b2;
            printf("Enter author's name: ");
            scanf("%s", name);

            count = 0;
            fseek(i, 0, SEEK_SET);
            fscanf(i, "%d", &n);

            for(j = 0; j < n; j++){
                fscanf(i, "%s", b2.book_name);
                fscanf(i, "%s", b2.author_name);
                fscanf(i, "%s", b2.publisher);
                fscanf(i,"%d", &b2.year);
                fscanf(i, "%f", &b2.price);

            if(strcmp(name, b2.author_name) == 0){
                count++;
                if(count == 1){
                    printf("%s,", b2.author_name);
                    printf("%s,", b2.book_name);
                }
            }
            }

            if(count == 0)
                printf("Not found this author\n");
                else
                    printf("%d\n", count);

            printf("\n\n");
}
