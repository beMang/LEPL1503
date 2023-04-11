void swap(int *i, int *j) {
    int buffer = *j;
    *j = *i;
    *i = *j;
}