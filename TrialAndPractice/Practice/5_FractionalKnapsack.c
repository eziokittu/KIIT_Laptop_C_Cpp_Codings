// Fractional Knapsack

#include <stdio.h>

struct item {
    int id;
    float cost;
    float qty;
    float ht;
    float ratio;
};

typedef struct item Item;

// bubble sort
void sortItems_bubbleSort(Item *items, int n){
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (items[i].ratio < items[j].ratio){
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main(){
    printf("Enter the no. of items: ");
    int n; scanf("%d", &n);

    Item items[n];
    printf("Enter the quantities and costs for the following:\n");
    for (int i=0; i<n; i++){
        printf("For Item %d: ", i+1);
        scanf("%f %f",&items[i].qty, &items[i].cost);
        items[i].id = i+1;
        items[i].ht = 0;
        items[i].ratio = items[i].cost / items[i].qty;
    }

    // sorting based on descending order of ratio
    // bubble sort
    sortItems_bubbleSort(items, n);


    printf("\nEnter the total weight of the backpack: ");
    float bp; scanf ("%f", &bp);
    float total=0;

    for (int i=0; i<n; i++){
        if (items[i].qty <= bp){
            items[i].ht = 1;
            total += items[i].ht * items[i].cost;
            bp = bp - items[i].qty;
        }
        else {
            items[i].ht = bp / items[i].qty;
            total += items[i].ht * items[i].cost;
            bp = 0;
            break;
        }
    }

    printf("ItemID\t\tqty\t\tcost\t\ttaken\t\tratio (cost/qty)");
    for (int i=0; i<n; i++){
        printf("\n%d\t\t%.6f\t%.6f\t%.6f\t%.6f\t",
            items[i].id, items[i].qty, items[i].cost, items[i].ht, items[i].ratio);
    }
    printf("\nTotal Cost: %f", total);

    return 0;
}

// OUTPUT - 1
// Enter the no. of items: 3
// Enter the quantities and costs for the following:
// For Item 1: 1 5
// For Item 2: 2 9
// For Item 3: 10 4

// Enter the total weight of the backpack: 5
// ItemID          qty             cost            taken           ratio (cost/qty)
// 1               1.000000        5.000000        1.000000        5.000000
// 2               2.000000        9.000000        1.000000        4.500000
// 3               10.000000       4.000000        0.200000        0.400000
// Total Cost: 14.800000

// OUTPUT - 2
// Enter the no. of items: 5
// Enter the quantities and costs for the following:
// For Item 1: 5 10
// For Item 2: 4 9
// For Item 3: 3 7
// For Item 4: 1 3 
// For Item 5: 6 13

// Enter the total weight of the backpack: 12
// ItemID          qty             cost            taken           ratio (cost/qty)
// 4               1.000000        3.000000        1.000000        3.000000
// 3               3.000000        7.000000        1.000000        2.333333
// 2               4.000000        9.000000        1.000000        2.250000
// 5               6.000000        13.000000       0.666667        2.166667
// 1               5.000000        10.000000       0.000000        2.000000
// Total Cost: 27.666666
