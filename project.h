#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <math.h>

//we get the z critical value from z table which is 1.96 for 95% confidence
const double z_critical = 1.96;

struct data1 {
    struct data1 *right;
    struct data1 *left;
    int value;
    double count;
};

struct data2 {
    struct data2 *right;
    struct data2 *left;
    int value;
    double count;
};
//to add data to data1.txt file
void add_1(struct data1 **head, int value) {
    if (*head == 0) 
    {
        *head = malloc(sizeof(struct data1)); //allocating memory
        (*head)->left = 0;
        (*head)->right = 0;
        (*head)->value = value;
        (*head)->count = 1;
    }else { 
        struct data1 * location = *head;
        struct data1 * newlocation = 0;
        int boolean = 0;

        while (boolean == 0)
        {
            if (value > location->value && location->right != 0)
            {
                location = location->right;
            } else if (value > location->value && location->right == 0)
            {
                newlocation = malloc(sizeof(struct data1));
                newlocation->left = 0;
                newlocation->right = 0;
                newlocation->value = value;
                newlocation->count = 1;
                location->right = newlocation;
                boolean = 1;
            } else if (value < location->value && location->left != 0)
            {
                location = location->left;
            } else if (value < location->value && location->left == 0)
            {
                newlocation = malloc(sizeof(struct data1));
                newlocation->left = 0;
                newlocation->right = 0;
                newlocation->value = value;
                newlocation->count = 1;
                location->left = newlocation;
                boolean = 1;
            } else {
                location->count += 1;
                boolean = 1;
            } 
        }
    }
    return;
}
//to add data to data2.txt file
void add_2(struct data2 **head, int value) {
    if (*head == 0) 
    {
        *head = malloc(sizeof(struct data2));
        (*head)->left = 0;
        (*head)->right = 0;
        (*head)->value = value;
        (*head)->count = 1;
    }else { 
        struct data2 * location = *head;
        struct data2 * newlocation = 0;
        int boolean = 0;

        while (boolean == 0)
        {
            if (value > location->value && location->right != 0)
            {
                location = location->right;
            } else if (value > location->value && location->right == 0)
            {
                newlocation = malloc(sizeof(struct data2));
                newlocation->left = 0;
                newlocation->right = 0;
                newlocation->value = value;
                newlocation->count = 1;
                location->right = newlocation;
                boolean = 1;
            } else if (value < location->value && location->left != 0)
            {
                location = location->left;
            } else if (value < location->value && location->left == 0)
            {
                newlocation = malloc(sizeof(struct data2));
                newlocation->left = 0;
                newlocation->right = 0;
                newlocation->value = value;
                newlocation->count = 1;
                location->left = newlocation;
                boolean = 1;
            } else {
                location->count += 1;
                boolean = 1;
            } 
        }
    }
    return;
}
//to free the allocated memory of the struct
void free_1(struct data1 **head) {
    if ((*head)->left != 0)
    {
        free_1(&(*head)->left);
    } 
    if ((*head)->right != 0)
    {
        free_1(&(*head)->right);
    } 
    free((*head));
    return;
}

void free_2(struct data2 **head) {
    if ((*head)->left != 0)
    {
        free_2(&(*head)->left);
    } 
    if ((*head)->right != 0)
    {
        free_2(&(*head)->right);
    } 
    free((*head));
    return;
}

void median(struct data1 **head, int *most, int *value) {
    struct data1 * location = *head;
    if (location->left != 0)
    {
        median(&location->left, most, value);
    } 
    if (location->right != 0)
    {
        median(&location->right, most, value);
    } 
    if (*most < location->count)
    {
        *most = location->count;
        *value = location->value;
    }
    return;
}
//we get the quantity of the file, the number of items
void data1_size(struct data1 **head, double *n) {
    struct data1 * location = *head;
    *n += location->count;
    if (location->left != 0)
    {
        data1_size(&location->left, n);
    } 
    if (location->right != 0)
    {
        data1_size(&location->right, n);
    }
    return;
}

void data2_size(struct data2 **head, double *n) {
    struct data2 * location = *head;
    *n += location->count;
    if (location->left != 0)
    {
        data2_size(&location->left, n);
    } 
    if (location->right != 0)
    {
        data2_size(&location->right, n);
    }
    return;
}
//we get the mean of the first file
void data1_mean(struct data1 **head, double *mean, int n) {
    struct data1 * location = *head;
    if (location->left != 0)
    {
        data1_mean(&location->left, mean, n);
    } 
    if (location->right != 0)
    {
        data1_mean(&location->right, mean, n);
    }
    *mean += (location->value) * (location->count) / n;
    return;
}

void data2_mean(struct data2 **head, double *mean, int n) {
    struct data2 * location = *head;
    if (location->left != 0)
    {
        data2_mean(&location->left, mean, n);
    } 
    if (location->right != 0)
    {
        data2_mean(&location->right, mean, n);
    }
    *mean += (location->value) * (location->count) / n;
    return;
}
//a function to calculate the variance
void variances(struct data1 **head, double *variance, double mean, int n) {
    struct data1 * location = *head;
    if (location->left != 0)
    {
        variances(&location->left, variance, mean, n);
    } 
    if (location->right!= 0)
    {
        variances(&location->right, variance, mean, n);
    }
    *variance += (location->value - mean) * (location->value - mean) * location->count / n;
    return;
}

//here we calculate the standard deviation which is the square root of variance
void st_dev(double *standard_dev, double variance) {
    *standard_dev = pow(variance, 1/2);
}

void var_coef(double standard_dev, double mean, double *variation_coef) {
    *variation_coef = standard_dev / mean * 100;

    if (*variation_coef <= 15)
    {
        printf("The mean is representative\n");
    } else if (*variation_coef > 15 && *variation_coef <= 33)
    {
        printf("The mean is weak representative\n");
    } else {
        printf("The mean is not representative\n");
    }
    return;
}

void conf_interval(double mean_s, double standard_dev, double m) {
    double lower, upper;
    lower = mean_s - (z_critical * standard_dev / pow(m, 0.5));
    upper = mean_s + (z_critical * standard_dev / pow(m, 0.5));
    printf("The data1 mean is between %lf and %lf\n", lower, upper);
    return;
}

void for_prop(struct data2 **head, int value, double *count) {
    struct data2 * location = *head;
    if (value > location->value)
    {
        for_prop(&location->right, value, count);
    } else if (value < location->value)
    {
        for_prop(&location->left, value, count);
    } else
    {
        *count = location->count;
    }
    return;
}

void p_interval(struct data2 **head, int value, double m) {
    double count, p_prop;
    for_prop(head, value, &count);
    p_prop = count / m;

    double lower, upper;
    lower = p_prop - (z_critical * pow((p_prop * (1 - p_prop) / m), 0.5));
    upper = p_prop + (z_critical * pow((p_prop * (1 - p_prop) / m), 0.5));
    printf("The data1 proportion interval is between %lf and %lf\n", lower, upper);
    return;
}