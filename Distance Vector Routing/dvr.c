#include <stdio.h>

int n, costmatrix[20][20];
struct routers
{
    int distance[30];
    int nextNode[30];
} node[30];

void readCostMatrix()
{
    int i, j;
    printf("\nEnter the costmatrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &costmatrix[i][j]);
            // distance from i to i is 0
            costmatrix[i][i] = 0;
            node[i].distance[j] = costmatrix[i][j];
            node[i].nextNode[j] = j;
        }
    }
}

void calaculateRoutingTable()
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                // if the cost of the path from i to j is less than the cost of the path from i to k and k to j
                if (node[i].distance[j] > node[i].distance[k] + node[k].distance[j])
                {
                    // substitute with minimum distance
                    node[i].distance[j] = node[i].distance[k] + node[k].distance[j];
                    // substitute with minimum path
                    node[i].nextNode[j] = k;
                }
            }
        }
    }
}

void displayMatrix()
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        printf("\nRouter : %d\n", i + 1);
        for (j = 0; j < n; j++)
        {
            printf("Node %d via %d, Distance: %d\n", j + 1, node[i].nextNode[j] + 1, node[i].distance[j]);
        }
    }
}

int main()
{
    printf("Enter the number of nodes :");
    scanf("%d", &n);
    readCostMatrix();
    calaculateRoutingTable();
    displayMatrix();
    return 0;
}