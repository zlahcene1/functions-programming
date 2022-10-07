/*
** EPITECH PROJECT, 2020
** lib
** File description:
** int array
*/

int get_index(int *array, int size, int rec)
{
    int result = array[rec];
    int index  = rec;

    for (int i = rec + 1; i < size; i++) {
        if (array[i] < result) {
            result = array[i];
            index = i;
        }
    }
    return index;
}

void main_function(int *array, int size, int rec)
{
    int index = 0;
    int c = 0;

    if (rec == size)
        return;
    index = get_index(array, size, rec);
    c = array[index];
    array[index] = array[rec];
    array[rec] = c;
    main_function(array, size, rec + 1);
}

void my_sort_int_array(int *array, int size)
{
    main_function(array, size, 0);
}
