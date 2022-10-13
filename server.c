#include "getmax.h"

static int result = 0;
int* getmax_1_svc(struct input_data *data, struct svc_req *svcreq)
{
    result = data->a > data->b ? data->a : data->b;
    return &result;
}