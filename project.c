#include "project.h"

int main() {
//firstly, we need to gather data from the f1
    struct data1 *head = 0;
    char a = ' ';
    char k;
    int op = open("data1.txt", O_RDONLY);
    if (op != -1)
    {
        int l = 1;
        int cnt = 0;
        while (l != 0)
        {
            l = read(op, &k, 1);
            cnt++;
        }
        close(op);

        int op1 = open("data1.txt", O_RDONLY);
        char f1[cnt];
        read(op1, f1, cnt);
        close(op1);

        for (int i = 0; i < cnt-2; i++)
        {
            if ((a == f1[i] && isdigit(f1[i+1])) || (i == 0 && isdigit(f1[0])))
            {
                add_1(&head, atoi(&f1[i]));
            }
            
        }
    } else {
        fprintf(stderr, "%s\n", strerror(errno));
    }


    struct data2 *head_s = 0;
    int op2 = open("data2.txt", O_RDONLY);
    if (op2 != -1)
    {
        int l2 = 1;
        int cnt2 = 0;
        while (l2 != 0)
        {
            l2 = read(op2, &k, 1);
            cnt2++;
        }
        close(op2);

        int op12 = open("data2.txt", O_RDONLY);
        char f2[cnt2];
        read(op12, f2, cnt2);
        close(op12);

        for (int j = 0; j < cnt2-2; j++)
        {
            if ((a == f2[j] && isdigit(f2[j+1])) || (j == 0 && isdigit(f2[0])))
            {
                add_2(&head_s, atoi(&f2[j]));
            }
            
        }
    } else {
        fprintf(stderr, "%s\n", strerror(errno));
    }


    int value, most;
    median(&head, &most, &value);
    printf("The best sold drone is with %dMP and it was sold %d times\n", value, most);

    double n, m;
    data1_size(&head, &n);
    data2_size(&head_s, &m);
    printf("The size of data1 is %.lf\n", n);
    printf("The size of data2 is %.lf\n", m);

    double mean, mean_s;
    data1_mean(&head, &mean, n);
    data2_mean(&head_s, &mean_s, n);
    printf("The mean of data1 is %lf\n", mean);
    printf("The mean of data2 is %lf\n", mean_s);

    double variance;
    variances(&head, &variance, mean, n);
    printf("The variance of the data1 is %lf\n", variance);

    double standard_dev;
    st_dev(&standard_dev, variance);
    printf("The standard deviation of the data1 is %lf\n", standard_dev);

    double variation_coef;
    var_coef(standard_dev, variance, &variation_coef);

    conf_interval(mean_s, standard_dev, m);

    p_interval(&head_s, 50, m); 

    free_1(&head);
    free_2(&head_s);

    return 0;
}
