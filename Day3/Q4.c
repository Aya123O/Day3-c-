
#include <stdio.h>

int main() {
    int rows, cols;


    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);


    int arr[100];
     for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d\t", arr[i * cols + j]);
        }
        printf("\n");
    }
    


    printf("Enter the elements of the array:\n");
    for (int i = 0; i < rows * cols; i++) {
        printf("%d", &arr[i]);
    }


    printf("\nArray displayed as a table:\n");
   

    return 0;
}
