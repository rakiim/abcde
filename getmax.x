struct input_data {
    int a;
    int b;
};

program GETMAXPROG {
    version GETMAXVERS {
        int GETMAX(struct input_data data) = 1;
    } = 1;
} = 22855;