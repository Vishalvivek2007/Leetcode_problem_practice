typedef struct {
    int pos;
    int spd;
} Car;

int cmp(const void* a, const void* b) {
    Car* c1 = (Car*)a;
    Car* c2 = (Car*)b;
    return c1->pos - c2->pos;
}

int carFleet(int target, int* pos, int n, int* speed, int speedlen) {

    Car cars[n];

    for (int i = 0; i < n; i++) {
        cars[i].pos = pos[i];
        cars[i].spd = speed[i];
    }

    qsort(cars, n, sizeof(Car), cmp);

    int count = 0;
    float maxtime = -1;

    for (int i = n - 1; i >= 0; i--) {
        float time = (float)(target - cars[i].pos) / cars[i].spd;

        if (time > maxtime) {
            count++;
            maxtime = time;
        }
    }

    return count;
}
