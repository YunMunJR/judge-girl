#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int x, y;

    int mnx, mxx;
    int mny, mxy;

    struct Node *l;
    struct Node *r;
} Node;

Node *newNode(int x, int y)
{
    Node *u = (Node *)malloc(sizeof(Node));

    u->x = x;
    u->y = y;

    u->mnx = u->mxx = x;
    u->mny = u->mxy = y;

    u->l = u->r = NULL;

    return u;
}

void pull(Node *u)
{
    u->mnx = u->mxx = u->x;
    u->mny = u->mxy = u->y;

    if (u->l) {
        if (u->l->mnx < u->mnx) u->mnx = u->l->mnx;
        if (u->l->mxx > u->mxx) u->mxx = u->l->mxx;
        if (u->l->mny < u->mny) u->mny = u->l->mny;
        if (u->l->mxy > u->mxy) u->mxy = u->l->mxy;
    }

    if (u->r) {
        if (u->r->mnx < u->mnx) u->mnx = u->r->mnx;
        if (u->r->mxx > u->mxx) u->mxx = u->r->mxx;
        if (u->r->mny < u->mny) u->mny = u->r->mny;
        if (u->r->mxy > u->mxy) u->mxy = u->r->mxy;
    }
}

void insert(Node **root, int x, int y, int dep)
{
    if (*root == NULL) {
        *root = newNode(x, y);
        return;
    }

    Node *u = *root;

    if (dep & 1) {
        if (y < u->y)
            insert(&u->l, x, y, dep + 1);
        else
            insert(&u->r, x, y, dep + 1);
    } else {
        if (x < u->x)
            insert(&u->l, x, y, dep + 1);
        else
            insert(&u->r, x, y, dep + 1);
    }

    pull(u);
}

int pointDist(Node *u, int x, int y)
{
    int dx = abs(u->x - x);
    int dy = abs(u->y - y);
    return dx + dy;
}

int boxDist(Node *u, int x, int y)
{
    int d = 0;

    if (x < u->mnx)
        d += u->mnx - x;
    else if (x > u->mxx)
        d += x - u->mxx;

    if (y < u->mny)
        d += u->mny - y;
    else if (y > u->mxy)
        d += y - u->mxy;

    return d;
}

int best;

void query(Node *u, int x, int y)
{
    if (u == NULL)
        return;

    int d = pointDist(u, x, y);

    if (d < best)
        best = d;

    int dl = INT_MAX;
    int dr = INT_MAX;

    if (u->l)
        dl = boxDist(u->l, x, y);

    if (u->r)
        dr = boxDist(u->r, x, y);

    if (dl < dr) {

        if (dl < best)
            query(u->l, x, y);

        if (dr < best)
            query(u->r, x, y);

    } else {

        if (dr < best)
            query(u->r, x, y);

        if (dl < best)
            query(u->l, x, y);
    }
}

int main()
{
    int N;

    scanf("%d", &N);

    Node *A = NULL;
    Node *B = NULL;

    for (int i = 0; i < N; i++) {

        int ax, ay;
        int bx, by;

        scanf("%d %d", &ax, &ay);

        if (B != NULL) {
            best = INT_MAX;
            query(B, ax, ay);
            printf("%d\n", best);
        }

        insert(&A, ax, ay, 0);

        scanf("%d %d", &bx, &by);

        best = INT_MAX;
        query(A, bx, by);
        printf("%d\n", best);

        insert(&B, bx, by, 0);
    }

    return 0;
}