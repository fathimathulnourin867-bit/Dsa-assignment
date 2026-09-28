#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    char name[20];
    struct Node *child[3];
    int n;
};

struct Node* create(char name[]) {
    struct Node *p = malloc(sizeof(struct Node));
    strcpy(p->name, name);
    p->n = 0;
    return p;
}

void add(struct Node *p, struct Node *c) {
    p->child[p->n++] = c;
}

void levelOrder(struct Node *root) {
    struct Node *q[20];
    int f = 0, r = 0, i;

    q[r++] = root;

    while (f < r) {
        struct Node *p = q[f++];
        printf("%s ", p->name);

        for (i = 0; i < p->n; i++)
            q[r++] = p->child[i];
    }
}

int linear(char a[][20], int n, char key[], int *c) {
    for (int i = 0; i < n; i++) {
        (*c)++;

        if (strcmp(a[i], key) == 0)
            return i;
    }
    return -1;
}

int binary(char a[][20], int n, char key[], int *c) {
    int l = 0, h = n - 1;

    while (l <= h) {
        int m = (l + h) / 2;
        (*c)++;

        if (strcmp(a[m], key) == 0)
            return m;

        if (strcmp(a[m], key) < 0)
            l = m + 1;
        else
            h = m - 1;
    }

    return -1;
}

int main() {
    struct Node *CEO = create("CEO");
    struct Node *HR = create("HR");
    struct Node *Finance = create("Finance");
    struct Node *IT = create("IT");
    struct Node *Dev = create("Development");
    struct Node *Test = create("Testing");
    struct Node *Front = create("Frontend");
    struct Node *Back = create("Backend");

    add(CEO, HR);
    add(CEO, Finance);
    add(CEO, IT);

    add(IT, Dev);
    add(IT, Test);

    add(Dev, Front);
    add(Dev, Back);

    printf("Level Order: ");
    levelOrder(CEO);

    char dept[][20] = {
        "Backend", "Development", "Finance",
        "Frontend", "HR", "IT", "Testing"
    };

    char key[20];
    int c1 = 0, c2 = 0;

    printf("\n\nEnter department to search: ");
    scanf("%s", key);

    linear(dept, 7, key, &c1);
    binary(dept, 7, key, &c2);

    printf("Linear Search Comparisons: %d\n", c1);
    printf("Binary Search Comparisons: %d\n", c2);

    return 0;
}
